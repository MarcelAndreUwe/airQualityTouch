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
// +++ IntelliSense & PlatformIO +++
// If you have trouble with the "code-assistence", then make sure that the right environment is selected.
// Therefore follow the stepts for the "project environment switcher" discribed in: https://docs.platformio.org/en/latest/integration/ide/vscode.html#project-tasks
//
// +++ ICONS +++
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
// +++ Calibrate TFT +++
// 1. Change in platformio.ini field src_dir to "examples/arduino/diag_ard_touch_calib"
// 2. Flash code
// 3. Follow instructions
// 4. Copy calib. data info file "\configs\esp-tftespi-default-xpt2046.h"
//
// +++ TFT DRIVER & PINOUT +++
// Pinout defined by TFT_eSPI's User_Setup.h ("\libdeps\ESP8266-TFT_eSPI-XPT2046\TFT_eSPI\User_Setup.h") 
// --> Only use platformio.ini to change pin configuration!!!

// Setup for Rotation, calibration & features: "\configs\esp-tftespi-default-xpt2046.h" 
//
// FLASH MODE:  
// use "DIO"-Flash mode to free up GPIO9 & 10, because SD_DATA2 and SD_DATA3 are not used in DIO-Mode!
//
// PINOUT ESP8266:
// Display SDO/MISO  leave disconnected
// Display LED       to NodeMCU pin SDD2 (also known as S2)
// Display SCK       to NodeMCU pin D5
// Display SDI/MOSI  to NodeMCU pin D7
// Display DC (RS/AO)to NodeMCU pin D3
// Display RESET     to NodeMCU pin RST
// Display CS        to NodeMCU pin D8 
// Display GND       to NodeMCU pin GND
// Display VCC       to NodeMCU 5V or 3.3V
// Touch CS          to NodeMCU pin D0 (GPIO 16)
//
//
//
// +++ CHANGE UI PROCEDURE +++
// Open GUIscliceBuilder application and open project.
// Save changes and build code: File -> Generate Code
// Open generated code from /documents/arduino/Test2/
// Copy the following code:
//
// ** application_GSLC.h **
//      <Includes !Start!>            -->   <Includes !End!>
//      <Enum !Start!>                -->   <Enum !End!>
//      <ElementDefines !Start!>      -->   <ElementDefines !End!>
//      <GUI_Extra_Elements !Start!>  -->   <GUI_Extra_Elements !End!>
//      <Extern_References !Start!>   -->   <Extern_References !End!>
//      Callback Methods
//      <InitGUI !Start!>             -->   <Startup !End!>
//
// ** application.ino **
//      <Save_References !Start!>     -->   <Save_References !End!>
//      <Button Enums !Start!>        -->   Only new cases
//      <Keypad Enums !Start!>        -->   Only new cases
//      
// ------------------------------------------------
// Headers to include
// ------------------------------------------------

#define ESP32

#include <Arduino.h>
#include "application_GSLC.h"
#ifdef ESP32
  #include <WiFi.h>
  #define SDS_TX 17 // Pin ESP-TX2 auf SDS-Rx
  #define SDS_RX 16 // Pin ESP-RX2 auf SDS-TX
  const int tft_led_pin = 4; // Pin D4 = GPIO4
#else
  #include <ESP8266WiFi.h>
  #define SDS_TX 16
  #define SDS_RX 5
  const int tft_led_pin = 10; // Pin SK = GPIO10
#endif

#include <string>
#include "sds011_helper.h"
#include "iot_helper.h"
#include <SPIFFS.h>
#include <ESP32Time.h>
#include <iostream>
#include <rom/rtc.h>


#define IMG_BKGND_1               "/back.bmp"
#define IMG_BKGND_2               "/back2.bmp"
#define seconds() (millis()/1000)

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemDay        = NULL;
gslc_tsElemRef* m_pElemHour       = NULL;
gslc_tsElemRef* m_pElemIn_PASSWORD= NULL;
gslc_tsElemRef* m_pElemMinute     = NULL;
gslc_tsElemRef* m_pElemMonth      = NULL;
gslc_tsElemRef* m_pElemXRingGaugePM10= NULL;
gslc_tsElemRef* m_pElemXRingGaugePM25= NULL;
gslc_tsElemRef* m_pElemYear       = NULL;
gslc_tsElemRef* m_pElem_Measuring = NULL;
gslc_tsElemRef* m_pElem_WIFI_LIST = NULL;
gslc_tsElemRef* m_pElem_aqi_val   = NULL;
gslc_tsElemRef* m_pElem_back_WIFI_PWD= NULL;
gslc_tsElemRef* m_pElem_back_iot  = NULL;
gslc_tsElemRef* m_pElem_back_info= NULL;
gslc_tsElemRef* m_pElem_back_pg_wifi= NULL;
gslc_tsElemRef* m_pElem_back_sysset= NULL;
gslc_tsElemRef* m_pElem_back_time = NULL;
gslc_tsElemRef* m_pElem_btn_WIFI_setup= NULL;
gslc_tsElemRef* m_pElem_btn_dashboard= NULL;
gslc_tsElemRef* m_pElem_btn_home  = NULL;
gslc_tsElemRef* m_pElem_btn_info  = NULL;
gslc_tsElemRef* m_pElem_btn_measure= NULL;
gslc_tsElemRef* m_pElem_btn_save_time= NULL;
gslc_tsElemRef* m_pElem_con_msg   = NULL;
gslc_tsElemRef* m_pElem_dimmer_timer= NULL;
gslc_tsElemRef* m_pElem_hum_val   = NULL;
gslc_tsElemRef* m_pElem_img_nowifi= NULL;
gslc_tsElemRef* m_pElem_img_wifi  = NULL;
gslc_tsElemRef* m_pElem_infobox   = NULL;
gslc_tsElemRef* m_pElem_label_measure_art= NULL;
gslc_tsElemRef* m_pElem_label_measure_art38_39= NULL;
gslc_tsElemRef* m_pElem_label_pg_wifi_pwd= NULL;
gslc_tsElemRef* m_pElem_meas_interval= NULL;
gslc_tsElemRef* m_pElem_pm10_value= NULL;
gslc_tsElemRef* m_pElem_pm25_value= NULL;
gslc_tsElemRef* m_pElem_progress_measure= NULL;
gslc_tsElemRef* m_pElem_selected_ssid= NULL;
gslc_tsElemRef* m_pElem_temp_value= NULL;
gslc_tsElemRef* m_pElem_toggle_IoT= NULL;
gslc_tsElemRef* m_pElem_toggle_csv= NULL;
gslc_tsElemRef* m_pElem_toggle_dimmer= NULL;
gslc_tsElemRef* m_pElem_toggle_measure= NULL;
gslc_tsElemRef* m_pElem_wifi_gauge= NULL;
gslc_tsElemRef* m_pElemKeyPadNum  = NULL;
gslc_tsElemRef* m_pElemKeyPadAlpha= NULL;
//<Save_References !End!>


// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

char ssid[MAX_STR];
char password[MAX_STR];
char ip_address[16];
bool connecting = false;
char my_losant_webhook_url [] = "https://triggers.losant.com/webhooks/eAPNEsTpunTnn0AC5yuCfR54GbFXdFU8hxSUKYwL";




SDS_Sensor_Helper sds_sensor;
IoT_Helper IoT_webhook;
ESP32Time rtc;  

int cnt = 1;
int cnt2 = 1;
int r1 = 0;
int r2 = 50;
int cnt3 = 1;
int t_minute = 0;
int t_hour = 1;
int year = 2022;
int month = 6;
int day = 6;

bool r1_ = false;
bool r2_ = false;
bool store_csv = false;
bool do_upload = true;

int found_networks = -5;
bool scanning_wifi = false;
bool loading_anim_invert = false;
bool show_24h_average = false;
int loading_anim_val = 0;

const char* pnt = ".";
char buff[10];
int ret;
int interval = 60000; // 1 minute
unsigned long interval_heatup = 20000; // 20sec wakeup intervall
unsigned long lastMeasure = 0;
unsigned long currentMillis;
unsigned long request_time = 0;
bool measure_request = false;
int error = 0;

unsigned long lastTouchEvent = 0;
unsigned long interval_dimmer = 20000; // default 20sec dimmer timer
bool dimmerActivated = false;



void show_value(bool pm10_val=false);
void printCSV();
void resetCSV();
void showInfo();
void setCSV(bool enable);
size_t getCSVsize();
bool connect_wifi(const char *wifi_name);
void setBacklight(bool state);

#define background_color (gslc_tsColor) {0, 228, 171}



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
    if(dimmerActivated){
      lastTouchEvent = millis();
    }

    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
      //<Button Enums !Start!>
      case E_ELEM_BTN_WIFI_SETUP:{
        gslc_SetPageCur(&m_gui, E_PG_WIFI);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_BTN_dashboard:{
        gslc_SetPageCur(&m_gui, E_PG_OVERVIEW);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_BTN_INFO:	{
        showInfo();
        gslc_SetPageCur(&m_gui, E_PG_INFO);	
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_BTN_SCAN_WIFI:{
        scanning_wifi = true;
        break;}

      case E_ELEM_BTN_WIFI_CONNECT:{
        gslc_SetPageCur(&m_gui, E_PG_WIFI_PSWD);
        break;}

      case E_ELEM_BACK_PG_WIFI:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_PSWD_INPUT:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, m_pElemIn_PASSWORD);
        break;}

      case E_ELEM_BTN_CONNECT:{
        connect_wifi(ssid);
        break;}

      case E_ELEM_BACK_WIFI_PWD:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_TOGGLE_MEASURE:{
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_measure)) {
          show_24h_average = true;
          show_value(true);
          show_value(false);
        }
        else{
          show_24h_average = false;
          show_value(true);
          show_value(false);
        }
        break;}

      case E_ELEM_HOME_BTN:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_MEASURE_BTN:{
        int ret = IoT_webhook.send_pm_update(sds_sensor.get_last_value(true), sds_sensor.get_last_value(false), 10,05);
        Serial.print("Return code: ");
        Serial.println(ret);
        break;}

      case E_ELEM_BTN_SYS_SET:{	
        gslc_SetPageCur(&m_gui, E_PG_SYS_SET);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;	}

      case E_ELEM_BTN_IOT_SET:{	
        gslc_SetPageCur(&m_gui, E_PG_IOT_SET);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;	}

      case E_ELEM_DIMMER_TIMER:	{
        // Clicked on edit field, so show popup box and associate with this text field	
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_dimmer_timer);	
        break;	}

      case E_ELEM_TOGGLE_DIMMER:{
        dimmerActivated = gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_dimmer);
        break;	}

      case E_ELEM_DIM_ON:	
        setBacklight(false);
        break;	

      case E_ELEM_MEAS_INTERVAL:{	
        // Clicked on edit field, so show popup box and associate with this text field	
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_meas_interval);	
        break;}

      case E_ELEM_DIM_OFF:{	
        gslc_PopupHide(&m_gui);	
        setBacklight(true);
        break;}

      case E_ELEM_BACK_IOT:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;
      

      case E_ELEM_BACK_SYSSET:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_BACK_INFO:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;}
      
      case E_ELEM_DEL_DATA:{
        resetCSV();
        break;}

      case E_ELEM_PRINT_DATA:{
        printCSV();
        break;}

      case E_ELEM_TOGGLE_CSV:{
        setCSV(gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_csv));
        break;}

      case E_ELEM_TOGGLE_IOT:{
        do_upload = gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_IoT);
        break;}
      
      case E_ELEM_BTN_SETTIME:{
        gslc_SetPageCur(&m_gui, E_PG_TIME);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_NUM_MONTH:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemMonth);
        break;}

      case E_ELEM_NUM_DAY:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemDay);
        break;}

      case E_ELEM_NUM_YEAR:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemYear);
        break;}

      case E_ELEM_NUM_HOUR:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemHour);
        break;}

      case E_ELEM_NUM_MINUTE:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemMinute);
        break;}

      case E_ELEM_BACK_TIME:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;}

      case E_ELEM_BTN_SAVE_TIME:{
        Serial.printf("Set RTC time = %i:%i  |  Date = %i/%i/%i\n",t_hour, t_minute, day, month, year);
        rtc.setTime(0, t_minute, t_hour, day, month, year);
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;}
      
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

      case E_ELEM_PSWD_INPUT:
        strcpy(password,gslc_ElemXKeyPadInputGet(pGui, m_pElemIn_PASSWORD, pvData));
	      gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_DIMMER_TIMER:	
        gslc_ElemXKeyPadInputGet(pGui, m_pElem_dimmer_timer, pvData);	
	      gslc_PopupHide(&m_gui);	
        break;	
      case E_ELEM_MEAS_INTERVAL:	
        sds_sensor.set_measure_interval(atoi(gslc_ElemXKeyPadInputGet(pGui, m_pElem_meas_interval, pvData)) * 60000);
        gslc_PopupHide(&m_gui);
        break;
      
      case E_ELEM_NUM_MONTH:
        month = atoi(gslc_ElemXKeyPadInputGet(pGui, m_pElemMonth, pvData));
	      gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_DAY:
        day = atoi(gslc_ElemXKeyPadInputGet(pGui, m_pElemDay, pvData));
	      gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_YEAR:
        year = atoi(gslc_ElemXKeyPadInputGet(pGui, m_pElemYear, pvData));
	      gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_HOUR:
        t_hour = atoi(gslc_ElemXKeyPadInputGet(pGui, m_pElemHour, pvData));
	      gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_MINUTE:
        t_minute = atoi(gslc_ElemXKeyPadInputGet(pGui, m_pElemMinute, pvData));
	      gslc_PopupHide(&m_gui);
        break;

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

String getResetReason(RESET_REASON reason){
  // Helper function to return reset reason
  switch (reason)
  {
    case 1 : return "POWERON_RESET";          /**<1,  Vbat power on reset*/
    case 3 : return "SW_RESET";               /**<3,  Software reset digital core*/
    case 4 : return "OWDT_RESET";             /**<4,  Legacy watch dog reset digital core*/
    case 5 : return "DEEPSLEEP_RESET";        /**<5,  Deep Sleep reset digital core*/
    case 6 : return "SDIO_RESET";             /**<6,  Reset by SLC module, reset digital core*/
    case 7 : return "TG0WDT_SYS_RESET";       /**<7,  Timer Group0 Watch dog reset digital core*/
    case 8 : return "TG1WDT_SYS_RESET";       /**<8,  Timer Group1 Watch dog reset digital core*/
    case 9 : return "RTCWDT_SYS_RESET";       /**<9,  RTC Watch dog Reset digital core*/
    case 10 : return "INTRUSION_RESET";       /**<10, Instrusion tested to reset CPU*/
    case 11 : return "TGWDT_CPU_RESET";       /**<11, Time Group reset CPU*/
    case 12 : return "SW_CPU_RESET";          /**<12, Software reset CPU*/
    case 13 : return "RTCWDT_CPU_RESET";      /**<13, RTC Watch dog Reset CPU*/
    case 14 : return "EXT_CPU_RESET";         /**<14, for APP CPU, reseted by PRO CPU*/
    case 15 : return "RTCWDT_BROWN_OUT_RESET";/**<15, Reset when the vdd voltage is not stable*/
    case 16 : return "RTCWDT_RTC_RESET";      /**<16, RTC Watch dog reset digital core and rtc module*/
    default : return "NO_MEAN";
  }
}


void showInfo(){
  // Print text to info-textbox
  gslc_ElemXTextboxReset(&m_gui,m_pElem_infobox);
  unsigned int sec = seconds();

  // split long url
  String url_p1 = String(my_losant_webhook_url).substring(0,39);
  String url_p2 = String(my_losant_webhook_url).substring(39,78);
  String url_p3 = String(my_losant_webhook_url).substring(78,116);
  
  // load reset reason
  String reason_cpu0 = getResetReason(rtc_get_reset_reason(0));
  String reason_cpu1 = getResetReason(rtc_get_reset_reason(1));
  
  String wifi_connected = (WiFi.isConnected()) ? "True" : "False"; 
  
  String text = "Date:     " + rtc.getDate() + " - " + rtc.getTime() + "\nUptime:   " + String(sec/60) + ":" + String(sec%60) + " - Meas cnt: " + String(sds_sensor.get_measure_cnt());
  text += " - Interval: " + String((uint32_t)sds_sensor.get_interval_sec() * 60) + " min";
  text += "\nCPU0 RST: " + reason_cpu0 + "\nCPU1 RST: " + reason_cpu1 + "\nMEM (KB): HEAP: " + String(ESP.getFreeHeap()/1000) + "/" + String(ESP.getHeapSize()/1000);
  text += " | Lowest: " + String(esp_get_minimum_free_heap_size()/1000) + " | CSV: " + String(getCSVsize());
  text += "\nCPU Freq: " + String(ESP.getCpuFreqMHz()) + " MHz - Model: " + String(ESP.getChipModel());
  text += "\nIoT-URL:  " + url_p1;
  text += "\n          " + url_p2 + "\n          " + url_p3;
  text += "\nWiFi:     Connected? - " + wifi_connected + "\nSSID:     " + String(ssid) + " IP: " + String(ip_address); 
  
  //snprintf(m_acTextboxBuf1,200,(char*)"Uptime: %u sec.\nFree DRAM: %i kb\ndata.csv: %i kb\nMeas count: %u\n", seconds(), ESP.getFreeHeap()/1000, getCSVsize(), sds_sensor.get_measure_cnt(false));
  //snprintf(m_acTextboxBuf1,600,text.c_str());
  gslc_ElemXTextboxAdd(&m_gui,m_pElem_infobox,(char*)text.c_str());
  delay(100);

}


void show_value(bool pm10_val){
  ret = snprintf(buff, 10, "%f", sds_sensor.get_value(pm10_val, show_24h_average));
  if(pm10_val){
    gslc_ElemSetTxtStr(&m_gui, m_pElem_pm10_value, buff);
    if((int)sds_sensor.get_value(pm10_val, show_24h_average) > 1.5){
        gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM10, (int)sds_sensor.get_value(pm10_val, show_24h_average));
    }
    else{
        // To show a littlebit green
        gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM10, 1.5);
    }
  }
  else{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_pm25_value, buff);
    if((int)sds_sensor.get_value(pm10_val, show_24h_average) > 1.5){
        gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM25, (int)sds_sensor.get_value(pm10_val, show_24h_average));
    }
    else{
        // To show a littlebit green
        gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM25, 1.5);
    }
  }
}

void updateCSV(unsigned long currentSec){
    if(store_csv){
      delay(1);
      fs::File file = SPIFFS.open("/data.csv", "a");
      file.printf("%s,", rtc.getTime().c_str());
      file.printf("%.2f,", sds_sensor.get_last_value(true));
      file.printf("%.2f \n", sds_sensor.get_last_value(false));
      file.close();
    }
}

// To get the size of the csv file in KB.
size_t getCSVsize(){
  if(store_csv){
    fs::File file = SPIFFS.open("/data.csv", "r");
    size_t size = file.size();
    file.close();
    return (size / 1000);
  }
  else{
    return 1;
  }
}

void printCSV(){
  if(store_csv){

    Serial.println("\n============================================");
    Serial.println("========   Measurement data START   ========");
    Serial.println("============================================\n\n");

    fs::File file = SPIFFS.open("/data.csv", "r");
    while(file.available()){
      Serial.write(file.read());
    }
    file.close();
    Serial.println("\n\n============================================");
    Serial.println("========    Measurement data END    ========");
    Serial.println("============================================\n\n");

    delay(200);
  }
  else{
    Serial.println("CSV support deactivated!");
  }
}

void resetCSV(){
  if(store_csv){
    SPIFFS.remove("/data.csv");
    delay(100);
    fs::File file = SPIFFS.open("/data.csv", "w");
    file.printf("relative_time,pm10,pm25\n");
    file.close();
    delay(100);
  }

}

void setCSV(bool enable){
  // Creating a CSV indicator on SPIFFS, in order to recognize CSV setting at startup.
    if(enable){
      if(!SPIFFS.exists("/csv")){
        fs::File file = SPIFFS.open("/csv", "w");
        file.close();
      }
    }
    else{
      SPIFFS.remove("/csv");
    }
    store_csv = enable;
}

bool is_csv_enabled(){
  if(SPIFFS.exists("/csv")){
    Serial.println("Found CSV flag!");
    return true;
  }
  else{
    Serial.println("Not found CSV flag!");
    return false;
  }
}

void setBacklight(bool state){
  // To enable/disable the TFT backlight LED
  if (state){
    digitalWrite(tft_led_pin, HIGH);
  }
  else{
    digitalWrite(tft_led_pin, LOW);
    gslc_PopupShow(&m_gui, E_PG_POPUP_DIMMER, true);	
  }
}


void handleDimmer(unsigned long _currentMillis){
  if(dimmerActivated && (_currentMillis - lastTouchEvent) > interval_dimmer){
    setBacklight(false);
  }
}


void uploadCloud(){
  if(do_upload){
    IoT_webhook.send_pm_update(sds_sensor.get_last_value(true), sds_sensor.get_last_value(false), rtc.getHour(true), rtc.getMinute());
  }
}





void setup()
{ 
    Serial.begin(9600);
    delay(500);
    Serial.println(">>> Starting setup procedure");
    sds_sensor.setup(SDS_TX, SDS_RX, interval_heatup, interval);
    Serial.println("IOT setup");
    delay(100);
    IoT_webhook.setup(my_losant_webhook_url);

    delay(100);
    Serial.println("Finished IOT setup");

    
    
    pinMode(tft_led_pin, OUTPUT);
    setBacklight(true);

    Serial.println("Init guislice");
    delay(100);
    gslc_InitDebug(&DebugOut);
    InitGUIslice_gen();

    delay(500);
    Serial.println("Checking CSV flag");
    delay(50);
    store_csv = is_csv_enabled(); // load indicator from spiffs
    gslc_ElemXTogglebtnSetState(&m_gui, m_pElem_toggle_csv, store_csv); // set indicator
    if(store_csv){ 
      Serial.println("Setup data.csv");
      
      if(SPIFFS.exists("/data.csv")){
        fs::File file = SPIFFS.open("/data.csv", "a");
        file.printf("\n\n\n+++   RESTART - NEW DATASET   +++\n\n");
        file.printf("relative_time,pm10,pm25\n");
        file.close();
      }
      else{
        fs::File file = SPIFFS.open("/data.csv", "w");
        file.printf("relative_time,pm10,pm25\n");
        file.close();
      }
    }

    // Hide images and disable image-button glow (to avoid slow rendering)
    gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, false);
    gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, false);
    gslc_ElemSetVisible(&m_gui, m_pElem_img_wifi, false );
    gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_home,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_measure,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_back_WIFI_PWD,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_dashboard,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_WIFI_setup,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_info,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_back_pg_wifi,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_back_iot,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_back_info,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_back_sysset,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_back_time,false);
    delay(100);
    gslc_SetPageCur(&m_gui, E_PG_TIME);
    gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
    Serial.println(">>> Setup finished <<<");
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
    
    if(scanning_wifi && found_networks >= 0){
      // WiFi scan completed
      gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, false);
      gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GREEN_DK1);
      gslc_ElemXRingGaugeSetColorInactive(&m_gui, m_pElem_wifi_gauge, GSLC_COL_GRAY_LT3);
      loading_anim_val = 0;
      scanning_wifi = false;
      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElem_wifi_gauge,(int16_t) loading_anim_val);
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

    
    if(sds_sensor.update(currentMillis))
    {
      // new meas-values available

      // reset loading animation colors / values
      gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, false);
      gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, false);
      loading_anim_invert = false;
      gslc_ElemSetCol(&m_gui,m_pElem_progress_measure,GSLC_COL_GRAY_DK1,GSLC_COL_GRAY_LT2,GSLC_COL_WHITE);
      gslc_ElemXProgressSetGaugeCol(&m_gui,m_pElem_progress_measure, GSLC_COL_GREEN_DK1);

      // handle values
      show_value(true);
      show_value(false);
      updateCSV(seconds());
      uploadCloud();
    }
    else{
      if(sds_sensor.is_measurement_running())
      {
          // Progressbar animation while SDS-Sensor measurement
          gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, true);
          gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, true);

          if(!loading_anim_invert){
            if(loading_anim_val < 400){
              loading_anim_val++;
            }
            else{
              // spin beckwards, swap active/inactive colors
              loading_anim_invert = true; 
              gslc_ElemSetCol(&m_gui,m_pElem_progress_measure,GSLC_COL_GRAY_DK1,GSLC_COL_GREEN_DK1,GSLC_COL_WHITE);
              gslc_ElemXProgressSetGaugeCol(&m_gui,m_pElem_progress_measure, GSLC_COL_GRAY_LT2);
              loading_anim_val = 0;
            }
          }
          else{
            if(loading_anim_val < 400){
              loading_anim_val++;
            }
            else{
              // spin forwards, swap active/inactive colors to default
              loading_anim_invert = false;
              gslc_ElemSetCol(&m_gui,m_pElem_progress_measure,GSLC_COL_GRAY_DK1,GSLC_COL_GRAY_LT2,GSLC_COL_WHITE);
              gslc_ElemXProgressSetGaugeCol(&m_gui,m_pElem_progress_measure, GSLC_COL_GREEN_DK1);
              loading_anim_val = 0;
            }
          }
        delay(1.5);
        gslc_ElemXProgressSetVal(&m_gui, m_pElem_progress_measure,(int16_t) loading_anim_val);
      }
    }
    
    handleDimmer(currentMillis);
    delay(1);
    // ------------------------------------------------
    // Periodically call GUIslice update function
    // ------------------------------------------------
    gslc_Update(&m_gui);
    
}

