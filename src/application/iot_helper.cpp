#include "iot_helper.h"
#include <Arduino.h>
#include <string.h>
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

int IoT_Helper::send_pm_update(float pm10, float pm25, int th, int tm, bool store_failed_uploads){
    int httpResponseCode = -1;

    // Check for offline data
    if(this->offline_stored){
        // Data available, append new data and try to send all offline data
        this->offline_data += String(th) + "," + String(tm) + "," + String(pm10) + "," + String(pm25) + "%0A";
        httpResponseCode = send_offline_data();
    }
    else{
        // No offline data available, send normal request
        if(WiFi.status()== WL_CONNECTED){
            this->tmp_data = String(this->webhook_url) + "?pm10=" + String(pm10) + "&pm25=" + String(pm25) + "&th=" + String(th) + "&tm=" + String(tm);
            HTTPClient http;
            bool ready = http.begin(String(this->tmp_data));
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
            if(httpResponseCode != 200){
                // Faiiled to send, store offline data
                this->offline_data += String(th) + "," + String(tm) + "," + String(pm10) + "," + String(pm25) + "%0A";
                this->offline_stored = true;
            }
        }

        else {
            // No internet available, store offline data
            this->offline_data += String(th) + "," + String(tm) + "," + String(pm10) + "," + String(pm25) + "%0A";
            this->offline_stored = true;
            Serial.println("WiFi Disconnected");
        }
    }

    return httpResponseCode;
}


int IoT_Helper::send_offline_data(){
    int httpResponseCode = -1;
    if(WiFi.status()== WL_CONNECTED){
        this->tmp_data = String(this->webhook_url) + "?bulk=1&csv=" + String(this->offline_data);
        Serial.println(String(this->tmp_data));
        HTTPClient http;
        bool ready = http.begin(String(this->tmp_data));
        if(ready){
            // try 3 times to send
            for (size_t i = 0; i <= 2; i++)
            {
                httpResponseCode = http.GET();
                if (httpResponseCode==200) {
                     // Reset data & flasg
                    this->offline_data = "HH,MM,PM10,PM25%0A";
                    this->offline_stored = false;
                    break;
                }
                delay(500);
            }
        }
        http.end();
    }
    return httpResponseCode;
}