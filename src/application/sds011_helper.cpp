#include "sds011_helper.h"
#include <stdint.h>
#include <Arduino.h>

SDS_Sensor_Helper::SDS_Sensor_Helper(void) {}

/**
 * @brief Setup SDS011 sensor class
 * @note  On ESP32 the tx/rx pins are unused! SDS011 will use the Serial2 interface (RXD2 & TXD2)
 * @param tx_pin
 * @param rx_pin
 * @param wakeup_time   :   Wating time bevore measurement to clean/heatup sensor.
 * @param meas_interval :   Interval for measurement
 */
#ifndef ESP32
void SDS_Sensor_Helper::setup(int tx_pin, int rx_pin, unsigned long wakeup_time, int meas_interval)
{
    this->pm10_sum = 0.0;
    this->pm25_sum = 0.0;
    this->pm10_last_val = 0.0;
    this->pm25_last_val = 0.0;
    this->pm10_sum_1h = 0.0;
    this->pm25_sum_1h = 0.0;
    this->pm10_last_average = 0.0;
    this->pm25_last_average = 0.0;
    this->runtime_meas_cnt = 0;
    this->meas_cnt_1h = 0;
    this->sds_sensor.begin(rx_pin, tx_pin);
    delay(100);
    this->sds_sensor.sleep();
    this->measurement_is_running = false;
    this->wakeup_time = wakeup_time;
    this->measurement_starting_time = 0;
    this->meas_interval = meas_interval;
    this->last_hour_millis = 0;
}

#endif

#ifdef ESP32
void SDS_Sensor_Helper::setup(unsigned long wakeup_time, int meas_interval)
{
    this->pm10_sum = 0.0;
    this->pm25_sum = 0.0;
    this->pm10_last_val = 0.0;
    this->pm25_last_val = 0.0;
    this->pm10_sum_1h = 0.0;
    this->pm25_sum_1h = 0.0;
    this->pm10_last_average = 0.0;
    this->pm25_last_average = 0.0;
    this->runtime_meas_cnt = 0;
    this->meas_cnt_1h = 0;
    this->last_hour_millis = 0;

    // ESP32 must use HardwareSerial
    this->sds_sensor.begin(&Serial2);
    delay(100);
    this->sds_sensor.sleep();
    this->measurement_is_running = false;
    this->wakeup_time = wakeup_time;
    this->measurement_starting_time = 0;
    this->meas_interval = meas_interval;
}

#endif

/// @brief  Check if new measurement-values available.
///         If measurement-interval is over, the SDS sensor will be wake up.
///         If wake-up interval is over, the measurement starts.
/// @param current_millis
/// @return True if new values are available, else false.
bool SDS_Sensor_Helper::update(unsigned long current_millis)
{
    bool ret = false;
    if (!this->measurement_is_running && (current_millis - this->last_meas_request) > this->meas_interval)
    {
        Serial.println("SDS Wakeup");
        this->sds_sensor.wakeup();
        this->measurement_is_running = true;
        this->measurement_starting_time = current_millis;
        this->last_meas_request = current_millis;
    }
    else if (this->measurement_is_running)
    {
        // check if wakup-intervall time has expired
        if ((current_millis - this->measurement_starting_time) > this->wakeup_time)
        {
            // Wakup-time has expired, do measurement
            this->do_measurement();
            this->measurement_is_running = false;
            ret = true;
        }
    }
    return ret;
}

void SDS_Sensor_Helper::setContinuous()
{
    this->sds_sensor.wakeup();
}

void SDS_Sensor_Helper::readContinuous(float *pm10, float *pm25)
{
    this->sds_sensor.read(pm25, pm10);
}

bool SDS_Sensor_Helper::is_measurement_running()
{
    return this->measurement_is_running;
}

void SDS_Sensor_Helper::request_measure(unsigned long current_millis)
{
    Serial.println("Manual SDS Wakeup");
    this->sds_sensor.wakeup();
    this->measurement_is_running = true;
    this->measurement_starting_time = current_millis;
    this->last_meas_request = current_millis;
}

float SDS_Sensor_Helper::getPM10value(bool _average)
{
    if (_average)
    {
        return this->pm10_last_average;
    }
    else
    {
        return this->pm10_last_val; // current value
    }
}

float SDS_Sensor_Helper::getPM25value(bool _average)
{
    if (_average)
    {
        return this->pm25_last_average;
    }
    else
    {
        return this->pm25_last_val; // current value
    }
}

int SDS_Sensor_Helper::get_measure_cnt(bool for_1_hour)
{
    if (for_1_hour)
    {
        return this->meas_cnt_1h;
    }
    else
    {
        return this->runtime_meas_cnt;
    }
}

bool SDS_Sensor_Helper::is_measure_finished(unsigned long current_millis)
{
    if (this->measurement_is_running)
    {
        // check if wakup-intervall time is up
        if ((current_millis - this->measurement_starting_time) > this->wakeup_time)
        {
            // Wakup-time is over, do measurement
            this->do_measurement();
            this->measurement_is_running = false;
        }
    }
    return this->measurement_is_running;
}

/// @brief  Helper function for the measuring.
///         After measurement the SDS sensor will be set to sleep.
void SDS_Sensor_Helper::do_measurement()
{
    Serial.println("Doing SDS Measurement");
    int error = this->sds_sensor.read(&this->pm25_last_val, &this->pm10_last_val);
    if (!error)
    {
        this->runtime_meas_cnt++;
        if (millis() - this->last_hour_millis >= 3600000)
        {
            // 1 hour has passed
            this->last_hour_millis = millis();
            this->pm10_last_average = this->pm10_sum_1h / this->meas_cnt_1h;
            this->pm25_last_average = this->pm25_sum_1h / this->meas_cnt_1h;
            // reset 1h measurement values
            this->meas_cnt_1h = 0;
            this->pm10_sum_1h = 0.0;
            this->pm25_sum_1h = 0.0;
        }
        else
        {
            this->meas_cnt_1h += 1;
            this->pm10_sum_1h += this->pm10_last_val;
            this->pm25_sum_1h += this->pm25_last_val;
        }

        /*
        // calculate 1h average
        unsigned long meas_time_sum = this->meas_cnt_1h * (this->meas_interval + this->wakeup_time);
        int is_24h = (int)((meas_time_sum / this->hour_ms) % 24); // calculate if timespan for measurements is greater than 24 hours
        if (is_24h > 0)
        {
            this->pm10_last_average = this->pm10_sum_1h / this->meas_cnt_1h;
            this->pm25_last_average = this->pm25_sum_1h / this->meas_cnt_1h;
            // reset 24h measurement values
            this->meas_cnt_1h = 0;
            this->pm10_sum_1h = 0.0;
            this->pm25_sum_1h = 0.0;
        }
        else
        {
            this->meas_cnt_1h++;
            this->pm10_sum_1h += this->pm10_last_val;
            this->pm25_sum_1h += this->pm25_last_val;
        }

        */
    }
    else
    {
        Serial.println("SDS error");
    }
    this->sds_sensor.sleep();
    Serial.println("SDS set to sleep");
}

void SDS_Sensor_Helper::quit_continuous()
{
    this->sds_sensor.sleep();
}

void SDS_Sensor_Helper::set_measure_interval(int interval_ms)
{
    this->meas_interval = interval_ms;
}

int SDS_Sensor_Helper::get_interval_sec()
{
    return (this->meas_interval / 1000);
}
