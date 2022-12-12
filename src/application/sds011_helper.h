#ifndef _SDS011_HELPER_H
#define _SDS011_HELPER_H

#include <Arduino.h>
#include <stdint.h>
#include <SDS011.h>


class SDS_Sensor_Helper
{
  public: 
    SDS_Sensor_Helper(void);    //default constructor

    /*
    Setup SDS-Sensor.
    @param tx_pin TX Pin
    @param rx_pin RX Pin
    @param wakeup_time Time in ms how long the sensor should take for wakeup
    @param meas_interval Time in ms for the interval of measurements
    */
    void setup(int tx_pin, int rx_pin, unsigned long wakeup_time, int meas_interval);  

    /*
    To start a measurement.
    The SDS-sensor is awakened. The function is_measure_finished() starts the measurement when the wakeup-intervall has expired
    */
    bool request_measure(unsigned long current_millis);

    /*
    Returns the last measured value
    */
    float get_last_value(bool pm10=false);

    /*
    Returns the average value for the device-runtime or the last 24h
    */
    float get_value(bool pm10=false, bool _24h=true); 

    /*
    Returns the count of measurements for the last 24h or device runtime
    */
    int get_measure_cnt(bool _24h = true);

    /*
    To update the SDS-class and getting the current state of the running measurement
    Necessary to handle the measurement depending on the wakup-time. 
    */
    bool is_measure_finished(unsigned long current_millis);

    /*
    Set the interval for measurements. 
    Only for internal calculation of the 24 hour average value.
    */
    void set_measure_interval(int interval_ms);

    /*
    Check if new measurement is necessary
    @return True if new values are available
    */
    bool update(unsigned long current_millis);

    bool is_measurement_running();
    
    int get_interval_sec();





    private:   
    SDS011 sds_sensor;
    /* 
    Only called internal after wakeup-intervall has expired. 
    This function makes the measurement and stores the values. 
    */
    void do_measurement();
    bool measurement_is_running;
    float pm10_sum;                     // sum of measured values
    float pm25_sum;                     // sum of measured values
    float pm10_last_val;                // last measured value
    float pm25_last_val;                // last measured value
    float pm10_sum_24h;                 // sum of measured values for the last 24h
    float pm25_sum_24h;                 // sum of measured values for the last 24h
    float pm10_last_24h_average;        // last average value for the last 24h
    float pm25_last_24h_average;        // last average value for the last 24h
    uint32_t runtime_meas_cnt;          // counts the measurements since device is started
    unsigned long meas_cnt_24h;              // counts the measurements for the last 24 hours
    unsigned long wakeup_time;          // (millis) interval how long the SDS-sensor should need for wake up 
    unsigned long measurement_starting_time; // (millis) when measurement was requested, to calculate when wake-up interval has expired
    unsigned long last_meas_request;    // (millis) last time when a measurement was requested 
    int meas_interval;                 // Interval for measurements, only for internal calculations
    unsigned long hour_ms = 1000*60*60; // For internal calculations only
};


#endif