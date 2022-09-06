//<App !Start!>
// FILE: [test2.ino]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

//
// ICONS:
// First download a 32x32 icon (.png)
// Optional: Change the color of the PNG image by uploading it to https://pinetools.com/colorize-image
// Download the new colorized image as png
// Upload this png to https://onlinepngtools.com/change-png-color and replace transparent (0,0,0,0) with white (255,255,255)
// Download edited .png file
// Upload .png to https://online-converting.com/image/convert2bmp/#
// Download .bmp and save to SPIFFS by putting it into the "data" folder.
//
// Blue Color: Hex: 8cb6ff
//

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "application_GSLC.h"
#include "C:/Users/Marcel/.platformio/packages/framework-arduinoespressif8266/libraries/ESP8266WiFi/src/ESP8266WiFi.h"
#include <SDS011.h>
#include <string>



#define IMG_BKGND_1               "/back.bmp"
#define IMG_BKGND_2               "/back2.bmp"

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemIn_PASSWORD= NULL;
gslc_tsElemRef* m_pElemXRingGaugePM10= NULL;
gslc_tsElemRef* m_pElemXRingGaugePM25= NULL;
gslc_tsElemRef* m_pElem_Measuring = NULL;
gslc_tsElemRef* m_pElem_WIFI_LIST = NULL;
gslc_tsElemRef* m_pElem_aqi_val   = NULL;
gslc_tsElemRef* m_pElem_btn_WIFI_setup= NULL;
gslc_tsElemRef* m_pElem_btn_back_PG_WIFI_PWD= NULL;
gslc_tsElemRef* m_pElem_btn_back_pg_wifi= NULL;
gslc_tsElemRef* m_pElem_btn_dashboard= NULL;
gslc_tsElemRef* m_pElem_btn_info  = NULL;
gslc_tsElemRef* m_pElem_btn_measure= NULL;
gslc_tsElemRef* m_pElem_btn_setup = NULL;
gslc_tsElemRef* m_pElem_con_msg   = NULL;
gslc_tsElemRef* m_pElem_hum_val   = NULL;
gslc_tsElemRef* m_pElem_img_nowifi= NULL;
gslc_tsElemRef* m_pElem_img_wifi  = NULL;
gslc_tsElemRef* m_pElem_label_measure_art= NULL;
gslc_tsElemRef* m_pElem_label_pg_wifi_pwd= NULL;
gslc_tsElemRef* m_pElem_pm10_value= NULL;
gslc_tsElemRef* m_pElem_pm25_value= NULL;
gslc_tsElemRef* m_pElem_progress_measure= NULL;
gslc_tsElemRef* m_pElem_selected_ssid= NULL;
gslc_tsElemRef* m_pElem_temp_value= NULL;
gslc_tsElemRef* m_pElem_toggle_measure= NULL;
gslc_tsElemRef* m_pElem_wifi_gauge= NULL;
gslc_tsElemRef* m_pElemKeyPadAlpha= NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

char ssid[MAX_STR];
char password[MAX_STR];
char ip_address[16];
bool connecting = false;
SDS011 sds;
float pm10, pm25;

int cnt = 1;
int cnt2 = 1;
int r1 = 0;
int r2 = 50;
int cnt3 = 1;
bool r1_ = false;
bool r2_ = false;

int found_networks = -5;
bool scanning_wifi = false;
bool wifi_gauge_invert = false;
int wifi_gauge_val = 0;

const char* pnt = ".";
char buff[10];
int ret;
const unsigned long interval = 60000; // 1 minute
unsigned long interval_heatup = 20000; // 20sec wakeup intervall
unsigned long lastMeasure = 0;
unsigned long currentMillis;
unsigned long request_time = 0;
bool measure_request = false;
int error = 0;

#define background_color (gslc_tsColor) {0, 228, 171}


bool connect_wifi(const char *wifi_name);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
//<Button Enums !Start!>
      case E_ELEM_BTN_WIFI_SETUP:
        gslc_SetPageCur(&m_gui, E_PG_WIFI);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;

      case E_ELEM_BTN_dashboard:
        gslc_SetPageCur(&m_gui, E_PG_OVERVIEW);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;

      case E_ELEM_BTN_SCAN_WIFI:
        scanning_wifi = true;
        break;

      case E_ELEM_BTN_WIFI_CONNECT:
        gslc_SetPageCur(&m_gui, E_PG_WIFI_PSWD);
        break;

      case E_ELEM_BTN_BACK_PG_WIFI:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;

      case E_ELEM_PSWD_INPUT:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, m_pElemIn_PASSWORD);
        break;

      case E_ELEM_BTN_CONNECT:
        connect_wifi(ssid);
        break;

      case E_ELEM_BTN_BACK_PG_WIFI_PWD:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;

      case E_ELEM_TOGGLE_MEASURE:
        // TODO Add code for Toggle button ON/OFF state
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_measure)) {
          ;
        }
        break;

      case E_ELEM_SETTINGS_BTN:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;

      case E_ELEM_MEASURE_BTN:
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}

//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
// KeyPad Input Ready callback
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)pvGui;
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  // From the pvData we can get the ID element that is ready.
  int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
  if (nState == XKEYPAD_CB_STATE_DONE) {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId) {
//<Keypad Enums !Start!>

      case E_ELEM_PSWD_INPUT:
        strcpy(password,gslc_ElemXKeyPadInputGet(pGui, m_pElemIn_PASSWORD, pvData));
	    gslc_PopupHide(&m_gui);
        break;
//<Keypad Enums !End!>
      default:
        break;
    }
  } else if (nState == XKEYPAD_CB_STATE_CANCEL) {
    // User escaped from popup, so don't update values
    gslc_PopupHide(&m_gui);
  }
  return true;
}
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui, pElemRef);
  char            acTxt[MAX_STR + 1];
  
  if (pElemRef == NULL) {
    return false;
  }

  // From the element's ID we can determine which listbox was active.
  switch (pElem->nId) {
//<Listbox Enums !Start!>
    case E_ELEM_WIFI_LIST:
      if (nSelId != XLISTBOX_SEL_NONE) {
        gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
        snprintf(ssid, MAX_STR, acTxt);
        gslc_ElemSetTxtStr(pGui, m_pElem_selected_ssid, acTxt);
        gslc_ElemSetTxtStr(pGui, m_pElem_label_pg_wifi_pwd, acTxt);
      }
      else{
        snprintf(acTxt, MAX_STR, "Please select SSID");
        gslc_ElemSetTxtStr(pGui, m_pElem_selected_ssid, acTxt);
        gslc_ElemSetTxtStr(pGui, m_pElem_label_pg_wifi_pwd, acTxt);
      }
      break;

//<Listbox Enums !End!>
    default:
      break;
  }
  return true;
}
//<Draw Callback !Start!>
//<Draw Callback !End!>
//<Slider Callback !Start!>
//<Slider Callback !End!>
//<Tick Callback !Start!>
//<Tick Callback !End!>



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




void setup()
{
    // ------------------------------------------------
    // Initialize
    // ------------------------------------------------
    sds.begin(5, 16); //RX, TX

    Serial.begin(9600);
    // Wait for USB Serial 
    //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

    gslc_InitDebug(&DebugOut);


    // ------------------------------------------------
    // Load Fonts
    // ------------------------------------------------

    // ------------------------------------------------
    // Create graphic elements
    // ------------------------------------------------
    InitGUIslice_gen();

    
    // Hide images and disable image-button glow (to avoid slow rendering)
    gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, false);
    gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, false);
    gslc_ElemSetVisible(&m_gui, m_pElem_img_wifi, false );
    gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_setup,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_measure,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_back_PG_WIFI_PWD,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_dashboard,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_WIFI_setup,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_info,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_back_pg_wifi,false);










}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{

    // ------------------------------------------------
    // Update GUI Elements
    // ------------------------------------------------
        
    if (scanning_wifi && found_networks < 0 ){
      // WiFi scan requested but not finished or started

      if(found_networks == -2){
        // WiFi scan requested but not started
        gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, true);
        gslc_ElemXListboxReset(&m_gui, m_pElem_WIFI_LIST);
        WiFi.scanNetworks(true); // Do async scan
      }

      // Loading animation with Ring-Gauge
      if(!wifi_gauge_invert){
        if(wifi_gauge_val < 360){
          wifi_gauge_val++;
        }
        else{
          // spin beckwards, swap active/inactive colors
          wifi_gauge_invert = true; 
          gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GRAY_LT3);
          gslc_ElemXRingGaugeSetColorInactive(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GREEN_DK1);
          wifi_gauge_val = 0;
        }
      }
      else{
        if(wifi_gauge_val < 360){
          wifi_gauge_val++;
        }else{
          // spin forwards, swap active/inactive colors
          wifi_gauge_invert = false;
          gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GREEN_DK1);
          gslc_ElemXRingGaugeSetColorInactive(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GRAY_LT3);
          wifi_gauge_val = 0;
        }
      }

      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElem_wifi_gauge,(int16_t) wifi_gauge_val);
      found_networks = WiFi.scanComplete(); // returns: -2 when no scan started, -1 when scan is running
      delay(1);
    }
    
    if(scanning_wifi && found_networks >= 0){
      // WiFi scan completed
      gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, false);
      gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GREEN_DK1);
      gslc_ElemXRingGaugeSetColorInactive(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GRAY_LT3);
      wifi_gauge_val = 0;
      scanning_wifi = false;
      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElem_wifi_gauge,(int16_t) wifi_gauge_val);
      list_wifi_networks();
    }
      




   
    



    if ( connecting ) 
    { 
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


    currentMillis = millis();

    
    if(!measure_request && (currentMillis - lastMeasure > interval)){
        // Wakeup SDS and request a measurement
        Serial.println("SDS Wakeup");
        delay(5);
        sds.wakeup();
        measure_request = true;
        request_time = currentMillis;
        gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, true);
        gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, true);


    }

    if(measure_request){
        // Progressbar animation while SDS-Sensor measurement
        gslc_ElemXProgressSetVal(&m_gui, m_pElem_progress_measure, (int16_t) ((currentMillis - request_time) / 1000.0));
    }

    if(measure_request && (currentMillis - request_time > interval_heatup)){
        // do measurement and set SDS to sleep
        Serial.println("SDS Measurement");
        gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, false);
        gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, false);
        lastMeasure = currentMillis;
        measure_request = false;
        error = sds.read(&pm25, &pm10);
        if (!error) {
            ret = snprintf(buff, 10, "%f", pm25);
            if(ret){
                gslc_ElemSetTxtStr(&m_gui, m_pElem_pm25_value, buff);
                if((int)pm25 > 1.5){
                    gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM25, (int)pm25);
                }
                else{
                    // To show a littlebit green
                    gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM25, 1.5);
                }
                Serial.println('PM 25 Measure:' + String(pm25));
            }
            ret = snprintf(buff, 10, "%f", pm10);
            if(ret){
                gslc_ElemSetTxtStr(&m_gui, m_pElem_pm10_value, buff);
                if((int)pm10 > 1.5){
                    gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM10, (int)pm10);
                }
                else{
                    // To show a littlebit green
                    gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM10, 1.5);
                }
                Serial.println('PM 10 Measure: ' + String(pm10));
            }
        }
        else{
            Serial.println("Error while SDS measure!");
        }
        sds.sleep();
    }
    
    // ------------------------------------------------
    // Periodically call GUIslice update function
    // ------------------------------------------------
    gslc_Update(&m_gui);
    
}

