#ifndef _IOT_HELPER_H
#define _IOT_HELPER_H

#include <Arduino.h>
#include <string.h>

/***
 * IoT Helper class to handle measurement data-sets.
 * Will store the data in SPIFFS if no network is available or sending failed.
 * 
 * Bulk (sending whole data-set of stored data):
 * Sends POST request to Losant cloud. 
 * The string must escape the "\n" with the URL code "%0A" after every data-set.
 * CSV contains the fields: "csv=", h -> Hour, m -> Minute, pm10, pm25
 * E.G.:
 * "csv=h,m,pm10,pm25%0A20,30,7.80,5.00%0A20,31,8.30,5.50"
 * 
 * Single data-set:
 * Sending as Http Get request with the fields: h -> hour, m -> minute, pm10, pm25
 * E.G.:
 * "<LOSANT-URL>?pm10=2.20&pm25=3.41&h=15&m=13"
 * 
 * Notes:
 * Type: Http post request
 * Http content-type: application/x-www-form-urlencoded
 * 
*/
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
    @brief  Public function to trigger an data-upload to the cloud.
    @note   Stores given values as csv in SPIFFS if upload failes and sends the stored offline data 
            as csv payload at next call of this function. 
    @param pm10 :   PM10 value
    @param pm25 :   PM25 value 
    @param th   :   Time hour
    @param tm   :   Time minute
    @return : void
    */
    void pm_update(float pm10, float pm25, int th, int tm);


  private:
  /**
   * @brief Helper func to send all the stored offline data to cloud
   * @note  Sending as HTTP-POST request
   * 
   * @return int Http-return code
  */
    int send_offline_data();

    /**
     * @brief Helper func to reset the SPIFFS data file
     * @note  Resets the offline_stored flag to false
    */
    void clear_offline_data();

    /**
     * @brief Helper func to get the given data set from spiffs file. 
     * @return ** String 
    */
    String get_offline_data();

    /**
     * @brief Helper func to store the given data-set in SPIFFS. 
     * @param pm10 
     * @param pm25 
     * @param th 
     * @param tm 
     * @return ** int 
    */
    int store_offline_data(float* pm10, float* pm25, int* th, int* tm);

    /**
     * @brief Helper function for sending data to cloud.
     * @note  Function tries 3 times to send the data. Using call-by-reference.  
     * @param data String to send
     * @param post_request Send as post request
     * @return HTTP return code. default -1, 200 = Success
    */
    int send_to_cloud(String* data, bool post_request=false);
    String webhook_url = "";
    String tmp_data = "";
    bool offline_stored = false;
    String url_end_sign = "%0A";
    
};


#endif _IOT_HELPER_H