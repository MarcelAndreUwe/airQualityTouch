#ifndef _SDS011_HELPER_H
#define _SDS011_HELPER_H

#include <Arduino.h>
#include <stdint.h>
#include <SDS011.h>


class SDS_Sensor_Helper
{
  public: 
    SDS_Sensor_Helper(void);    //default constructor

    /**
    * @brief Setup SDS011 sensor class
    * @note  On ESP32 the tx/rx pins are unused! SDS011 will use the Serial2 interface (RXD2 & TXD2) on ESP32!
    * @param tx_pin 
    * @param rx_pin 
    * @param wakeup_time   :   Wating time bevore measurement to clean/heatup sensor.
    * @param meas_interval :   Interval for measurement
    */
    #ifndef ESP32
      void setup(int tx_pin, int rx_pin, unsigned long wakeup_time, int meas_interval);
    #endif
    #ifdef ESP32
      void setup(unsigned long wakeup_time, int meas_interval);
    #endif

 
    /// @brief To manually start a measurement. 
    /// @note  The function is_measure_finished() starts the measurement when the configured wakeup-intervall has expired
    /// @param current_millis 
    void request_measure(unsigned long current_millis);


    /// @brief  Get the measured PM10 pollution value
    /// @param _average Set true to get the average over the last hour, false to get the most recent value
    /// @return Pollution in µg/m³
    float getPM10value(bool _average);


    /// @brief  Get the measured PM25 pollution value
    /// @param _average Set true to get the average over the last hour, false to get the most recent value
    /// @return Pollution in µg/m³
    float getPM25value(bool _average);


    /// @brief Get the count of measurements for the last hour or device runtime
    /// @return Measurement count
    int get_measure_cnt(bool for_1_hour = true);

    /// @brief To update the SDS-class and getting the current state of the running measurement
    /// Necessary to handle the measurement depending on the wakup-time. 
    bool is_measure_finished(unsigned long current_millis);

    /// @brief Set the interval for measurements. 
    /// @note  Only for internal calculation of the 1 hour average value.
    void set_measure_interval(int interval_ms);

    /// @brief  Check if new measurement-values available.
    ///         If measurement-interval is over, the SDS sensor will be wake up.
    ///         If wake-up interval is over, the measurement starts.
    /// @note   Needed to periodically update / check if measurement interval is over and measurement is necessary!
    /// @param current_millis 
    /// @return True if new values are available, else false.
    bool update(unsigned long current_millis);

    /// @brief True if measurement or wakeup is running
    bool is_measurement_running();
    
    /// @brief  Get the configured measurement interval
    /// @return Measurement interval
    int get_interval_sec();

    void setContinuous();
    void readContinuous(float* pm10, float*pm25);
    void quit_continuous();

    private:   
    SDS011 sds_sensor;
    /// @brief  Helper function for the measuring. 
    ///         After measurement the SDS sensor will be set to sleep.
    void do_measurement();
    bool measurement_is_running;
    float pm10_sum;                     // sum of measured values
    float pm25_sum;                     // sum of measured values
    float pm10_last_val;                // last measured value
    float pm25_last_val;                // last measured value
    float pm10_sum_1h;                 // sum of measured values for the last 1h
    float pm25_sum_1h;                 // sum of measured values for the last 1h
    float pm10_last_average;        // last average value for the last 1h
    float pm25_last_average;        // last average value for the last 1h
    uint32_t runtime_meas_cnt;          // counts the measurements since device is started
    unsigned long meas_cnt_1h;          // counts the measurements for the last hour
    unsigned long wakeup_time;          // (millis) interval how long the SDS-sensor should take for wake up 
    unsigned long measurement_starting_time; // (millis) when measurement was requested, to calculate when wake-up interval has expired
    unsigned long last_meas_request;    // (millis) last time when a measurement was requested 
    unsigned long last_hour_millis;     // (millis) last time when a hour has passed
    int meas_interval;                 // Interval for measurements, only for internal calculations
    unsigned long hour_ms = 1000*60*60; // For internal calculations only
};


#endif