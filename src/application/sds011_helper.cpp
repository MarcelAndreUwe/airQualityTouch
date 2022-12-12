#include "sds011_helper.h"
#include <stdint.h>
#include <Arduino.h>

SDS_Sensor_Helper::SDS_Sensor_Helper(void){}

void SDS_Sensor_Helper::setup(int tx_pin, int rx_pin, unsigned long wakeup_time, int meas_interval){
    this->pm10_sum = 0.0;
    this->pm25_sum = 0.0;
    this->pm10_last_val = 0.0;
    this->pm25_last_val = 0.0;
    this->pm10_sum_24h = 0.0;
    this->pm25_sum_24h = 0.0;
    this->pm10_last_24h_average = 0.0;
    this->pm25_last_24h_average = 0.0;
    this->runtime_meas_cnt = 0;    
    this->meas_cnt_24h = 0;
    #ifdef ESP32
        // ESP32 must use HardwareSerial
        this->sds_sensor.begin(&Serial2);
        delay(1000);
        this->sds_sensor.sleep();
    #else
        this->sds_sensor.begin(rx_pin, tx_pin); 
        delay(100);
        this->sds_sensor.sleep();
    #endif
    this->measurement_is_running = false;
    this->wakeup_time = wakeup_time;
    this->measurement_starting_time = 0;
    this->meas_interval = meas_interval;
}

bool SDS_Sensor_Helper::update(unsigned long current_millis){
    bool ret = false;
    if(!this->measurement_is_running && (current_millis - this->last_meas_request) > this->meas_interval)
    {
        //Serial.println("SDS Wakeup");
        this->sds_sensor.wakeup();
        this->measurement_is_running = true;
        this->measurement_starting_time = current_millis;
        this->last_meas_request = current_millis;
    }
    else if (this->measurement_is_running)
    {
        // check if wakup-intervall time has expired
        if((current_millis - this->measurement_starting_time) > this->wakeup_time)
        {
            // Wakup-time has expired, do measurement
            this->do_measurement();
            this->measurement_is_running = false;
            ret = true;
        }
    }
    return ret;
}


bool SDS_Sensor_Helper::is_measurement_running(){
    return this->measurement_is_running;
}




bool SDS_Sensor_Helper::request_measure(unsigned long current_millis){
    //Serial.println("SDS Wakeup");
    delay(2);
    this->sds_sensor.wakeup();
    this->measurement_is_running = true;
    this->measurement_starting_time = current_millis;
    return true;
}


float SDS_Sensor_Helper::get_last_value(bool pm10){
    if(pm10){ return this->pm10_last_val;}
    else{ return this->pm25_last_val; }
}


float SDS_Sensor_Helper::get_value(bool pm10, bool _24h){
    if(_24h)
    {
        // get the last average for the last 24 hours
        if(pm10)
        { 
            return this->pm10_last_24h_average;
        }
        else
        { 
            return this->pm25_last_24h_average; 
        }
    }
    else
    {
        // get the current value
        if(pm10)
        { 
            return this->pm10_last_val ;
        }
        else
        { 
            return this->pm25_last_val ;
        }
    }
    
}   



int SDS_Sensor_Helper::get_measure_cnt(bool _24h){
    if(_24h){
        return this->meas_cnt_24h;
    }
    else{
        return this->runtime_meas_cnt;
    }
}

bool SDS_Sensor_Helper::is_measure_finished(unsigned long current_millis){
    if(this->measurement_is_running)
    {
        // check if wakup-intervall time is up
        if((current_millis - this->measurement_starting_time) > this->wakeup_time)
        {
            // Wakup-time is over, do measurement
            this->do_measurement();
            this->measurement_is_running = false;
        }
    }

    return this->measurement_is_running;
}

void SDS_Sensor_Helper::do_measurement(){
    // do measurement and set SDS to sleep
    //Serial.println("SDS Measurement");
    int error = this->sds_sensor.read(&this->pm25_last_val, &this->pm10_last_val);
    if (!error) 
    {
        this->pm10_sum += this->pm10_last_val;
        this->pm25_sum += this->pm25_last_val;
        this->runtime_meas_cnt++;

        // calculate 24h average
        unsigned long meas_time_sum = this->meas_cnt_24h * (this->meas_interval + this->wakeup_time);
        int is_24h = (int) ((meas_time_sum / this->hour_ms) % 24); // calculate if timespan for measurements is greater than 24 hours
        if(is_24h > 0)
        {
            this->pm10_last_24h_average = this->pm10_sum_24h / this->meas_cnt_24h;
            this->pm25_last_24h_average = this->pm25_sum_24h / this->meas_cnt_24h;
            // reset 24h measurement values 
            this->meas_cnt_24h = 0; 
            this->pm10_sum_24h = 0.0;
            this->pm25_sum_24h = 0.0;

        }
        else
        {
            this->meas_cnt_24h++; 
            this->pm10_sum_24h += this->pm10_last_val;
            this->pm25_sum_24h += this->pm25_last_val;
        }

    }
    else
    {
        Serial.println("SDS error");
    }
    this->sds_sensor.sleep();
}


void SDS_Sensor_Helper::set_measure_interval(int interval_ms){
    this->meas_interval = interval_ms;
}

int SDS_Sensor_Helper::get_interval_sec(){
    return (this->meas_interval * 1000);
}


