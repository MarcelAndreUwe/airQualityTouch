#ifndef _WIFI_HELPER_H
#define _WIFI_HELPER_H

//#include <ESP8266WiFi.h>

#ifdef ESP32
  #include <WiFi.h>
#else
 #include <ESP8266WiFi.h>
#endif
#include "application/application_GSLC.h"


bool connecting = false;
int found_networks = -5;
int cnt = 1;
bool scanning_wifi = false;
bool loading_anim_invert = false;
int loading_anim_val = 0;
const char* pnt = ".";
char ssid[100];
char password[50];
char ip_address[16];

void list_wifi_networks()
{ 
    int n = found_networks;
    int o = n;
    int loops = 0;
    int indices[n];
    int skip[n];
    
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // sort by rssi
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
        if (WiFi.RSSI(indices[j]) > WiFi.RSSI(indices[i])) {
            loops++;
            std::swap(indices[i], indices[j]);  
            std::swap(skip[i], skip[j]);  
        }
        }
    }
        
    // remove doubles, List only first 6 elements
    for (int i = 0; i < 7; i++) {
        if(indices[i] == -1){
        --o;
        continue;
        }
        char name[MAX_STR];
        strncpy(name,WiFi.SSID(indices[i]).c_str(),25);
        gslc_ElemXListboxAddItem(&m_gui, m_pElem_WIFI_LIST, name); 
    }

    found_networks = -5; // reset
    WiFi.scanDelete();
}

bool connect_wifi(const char *wifi_name)
{
    char msg[MAX_STR]; 
    strncpy(msg,"Connecting ",12);
    gslc_ElemSetTxtStr(&m_gui, m_pElem_con_msg, msg);
    WiFi.begin(ssid, password);
    
    connecting = true;

    return true;
}



void handle_wifi_scan(){
    if (found_networks < 0 ){
      // WiFi scan requested but not finished or started

      if(found_networks == -2){
        // WiFi scan requested but not started
        gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, true);
        gslc_ElemXListboxReset(&m_gui, m_pElem_WIFI_LIST);
        WiFi.scanNetworks(true); // Do async scan
      }

      // Loading animation with Ring-Gauge
      if(!loading_anim_invert){
        if(loading_anim_val < 360){
          loading_anim_val++;
        }
        else{
          // spin beckwards, swap active/inactive colors
          loading_anim_invert = true; 
          gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GRAY_LT3);
          gslc_ElemXRingGaugeSetColorInactive(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GREEN_DK1);
          loading_anim_val = 0;
        }
      }
      else{
        if(loading_anim_val < 360){
          loading_anim_val++;
        }else{
          // spin forwards, swap active/inactive colors
          loading_anim_invert = false;
          gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GREEN_DK1);
          gslc_ElemXRingGaugeSetColorInactive(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GRAY_LT3);
          loading_anim_val = 0;
        }
      }

      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElem_wifi_gauge,(int16_t) loading_anim_val);
      found_networks = WiFi.scanComplete(); // returns: -2 when no scan started, -1 when scan is running
      delay(1);
    }
    
    if(found_networks >= 0){
      // WiFi scan completed
      gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, false);
      gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GREEN_DK1);
      gslc_ElemXRingGaugeSetColorInactive(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GRAY_LT3);
      loading_anim_val = 0;
      scanning_wifi = false;
      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElem_wifi_gauge,(int16_t) loading_anim_val);
      list_wifi_networks();
    }
}



void handle_wifi_connection(){
    if(WiFi.status() != WL_CONNECTED && cnt <= 15){
        // Let WiFi-Connection MSG Item blink
        delay(250);
        char *msg = gslc_ElemGetTxtStr(&m_gui, m_pElem_con_msg);
        strncat(msg,pnt,MAX_STR+1);
        gslc_ElemSetTxtStr(&m_gui, m_pElem_con_msg, msg);
        gslc_ElemSetVisible(&m_gui, m_pElem_con_msg, (cnt % 2 == 0));
        cnt++;
    }
    else{
        if(WiFi.status() == WL_CONNECTED){
            char msg[50];
            strncpy(ip_address, WiFi.localIP().toString().c_str(), 16);
            strncpy(msg,"Connected! IP: ",16);
            strncat(msg,ip_address,MAX_STR);
            gslc_ElemSetTxtStr(&m_gui, m_pElem_con_msg, msg);
            gslc_ElemSetVisible(&m_gui, m_pElem_con_msg, true);
            gslc_ElemSetVisible(&m_gui, m_pElem_img_nowifi, false);
            gslc_ElemSetVisible(&m_gui, m_pElem_img_wifi, true);
            gslc_SetPageCur(&m_gui, E_PG_OVERVIEW);

        }
        else{
            gslc_ElemSetTxtStr(&m_gui, m_pElem_con_msg, "Failed to connect!");
            gslc_ElemSetVisible(&m_gui, m_pElem_img_nowifi, true);
            gslc_ElemSetVisible(&m_gui, m_pElem_img_wifi, false);
            gslc_ElemSetVisible(&m_gui, m_pElem_con_msg, true);
        }
        connecting = false;
        cnt = 0;
    }
    
}

#endif