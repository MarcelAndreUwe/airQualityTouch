#include "iot_helper.h"
#include <Arduino.h>
#include <string.h>
#include <SPIFFS.h>

#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
#endif


IoT_Helper::IoT_Helper(void){}

void IoT_Helper::setup(char* webhook_url){
    this->webhook_url = String(webhook_url);
}


/**
    @brief  Public function to trigger an data-upload to the cloud.
    @note   Stores given values as csv in SPIFFS if upload failes and sends the stored offline data 
            as csv payload at next call of this function. 
    @param pm10 :   PM10 value
    @param pm25 :   PM25 value 
    @param th   :   Time hour
    @param tm   :   Time minute
    @return : Void
**/
void IoT_Helper::pm_update(float pm10, float pm25, int th, int tm){
    // Check for offline data
    if(this->offline_stored){
        this->store_offline_data(&pm10, &pm25, &th, &tm);
        this->send_offline_data();
    }
    else{
        // No offline data available, send normal request
        String tmp_data = String(this->webhook_url) + "?pm10=" + String(pm10) + "&pm25=" + String(pm25) + "&h=" + String(th) + "&m=" + String(tm);
        int ret = send_to_cloud(&tmp_data);
        if(ret != 200){
            // Faiiled to send, store offline data
            this->store_offline_data(&pm10, &pm25, &th, &tm);
        }
    }
}

/**
 * @brief Helper function for sending data to cloud.
 * @note  Function tries 3 times to send the data. Using call-by-reference.  
 * @param data String to send
 * @return HTTP return code. default -1, 200 = Success
 */
int IoT_Helper::send_to_cloud(String* data, bool post_request){
    int httpResponseCode = -1;
    if(WiFi.status()== WL_CONNECTED){
        HTTPClient http;

        if(post_request){
            Serial.println("Sending HTTP POST request:");
            Serial.print(*data);
            bool ready = http.begin(this->webhook_url);
            http.addHeader("Content-Type", "application/x-www-form-urlencoded");
            if(ready){
                // try 3 times to send
                for (size_t i = 0; i <= 2; i++)
                {
                    httpResponseCode = http.POST(*data);
                    if (httpResponseCode==200) {
                        break;
                    }
                    delay(500);
                }
            }

        }
        else{
            Serial.println("Sending HTTP GET request:");
            Serial.print(*data);
            bool ready = http.begin(*data);
            if(ready){
                // try 3 times to send
                for (size_t i = 0; i <= 2; i++)
                {
                    httpResponseCode = http.GET();
                    if (httpResponseCode==200) {
                        break;
                    }
                    delay(500);
                }
            }
            http.end();
        }
    }
    return httpResponseCode;
}

/**
 * @brief Helper func to send all the stored offline data to cloud
 * @note  Sending as HTTP-POST request
 * 
 * @return int 
 */
int IoT_Helper::send_offline_data(){
    String tmp_data = String(this->get_offline_data());
    int ret = send_to_cloud(&tmp_data, true);
    if (ret==200) {
        // Reset data & flags
        this->clear_offline_data();
    }
    return ret;
}


/**
 * @brief Helper func to store the given data-set in SPIFFS. 
 * @param pm10 
 * @param pm25 
 * @param th 
 * @param tm 
 * @return ** int 
 */
int IoT_Helper::store_offline_data(float* pm10, float* pm25, int* th, int* tm){
    this->offline_stored = true;
    if(SPIFFS.exists("/tmp.txt")){
        fs::File file = SPIFFS.open("/tmp.txt", "a");
        file.printf("%i,%i,%.2f,%.2f%s", *th, *tm, *pm10, *pm25, this->url_end_sign); // store given data
        file.close();
    }
    else{
        fs::File file = SPIFFS.open("/tmp.txt", "w");
        file.printf("csv=h,m,pm10,pm25%s", this->url_end_sign.c_str()); // prepare webrequest
        file.printf("%i,%i,%.2f,%.2f%s", *th, *tm, *pm10, *pm25, this->url_end_sign); // store given data
        file.close();
    }
}



/**
 * @brief Helper func to get the given data set from spiffs file. 
 * @return ** String 
 */
String IoT_Helper::get_offline_data(){
    String tmp_data = "";
    if(SPIFFS.exists("/tmp.txt")){
        fs::File file = SPIFFS.open("/tmp.txt", "r");
        tmp_data = file.readString();
        file.close();
    }
    return tmp_data;
}

/**
 * @brief Helper func to reset the SPIFFS data file
 * @note  Resets the offline_stored flag to false
 */
void IoT_Helper::clear_offline_data(){
    fs::File file = SPIFFS.open("/tmp.txt", "w");
    file.printf("csv=h,m,pm10,pm25%s", this->url_end_sign.c_str()); // prepare for http body
    file.close();
    this->offline_stored = false;
}