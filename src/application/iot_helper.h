#ifndef _IOT_HELPER_H
#define _IOT_HELPER_H

#include <Arduino.h>
#include <string.h>


class IoT_Helper
{
  public: 
    IoT_Helper(void);    //default constructor

    /*
    Init IoT instance
    @param webhook_url:   Personal Losant Webhook URL
    */
    void setup(char* webhook_url);  

    /*
    To send PM measurement data via HTTP-GET request.
    If internet connection is available and previous failed uploads were temporary stored, 
    this function will send all these unsended update-values automatically.
    Use "store_failed_uploads" to temporary store the unsended updates. 
    Returns the HTTP return code.
    
    @param pm10:                    PM10 concentration
    @param pm25:                    PM10 concentration
    @param th:                      Current time hour
    @param tm:                      Current time minute
    @param store_failed_uploads:    Bool to indicate if failed uploads should be temporary stored and sended later.
    @return:                        HTTP return code
    */
    int send_pm_update(float pm10, float pm25, int th, int tm, bool store_failed_uploads=true);


  private:
    /* 
    Only called internal to send data of failed uploads in bulk. 
    @return:        HTTP return code
    */
    int send_offline_data();
    String webhook_url = "";
    String tmp_data = "";
    String offline_data = "HH,MM,PM10,PM25%0A";  // %0A => UML escape for \n
    bool offline_stored = false;
    
};


#endif _IOT_HELPER_H