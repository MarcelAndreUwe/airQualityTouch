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
// Also helpful is to rebuild Intelli-Sense by pressing: "CTRL" + "Shift" + "P". Then the search bar opens, select "PlatformIO - Rebuild IntelliSense index"
//
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
#include "AQI.h"
#include <SPIFFS.h>
#include <ESP32Time.h>
#include <iostream>
#include <rom/rtc.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>



#define IMG_BKGND_1               "/back.bmp"
#define IMG_BKGND_2               "/back2.bmp"
#define seconds() (millis()/1000)

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemCodeIn     = NULL;
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
gslc_tsElemRef* m_pElem_back_contin= NULL;
gslc_tsElemRef* m_pElem_back_info = NULL;
gslc_tsElemRef* m_pElem_back_iot  = NULL;
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
gslc_tsElemRef* m_pElem_label_measure_art77= NULL;
gslc_tsElemRef* m_pElem_label_pg_wifi_pwd= NULL;
gslc_tsElemRef* m_pElem_meas_interval= NULL;
gslc_tsElemRef* m_pElem_pm10_cont_max= NULL;
gslc_tsElemRef* m_pElem_pm10_continuous= NULL;
gslc_tsElemRef* m_pElem_pm10_value= NULL;
gslc_tsElemRef* m_pElem_pm25_cont_max= NULL;
gslc_tsElemRef* m_pElem_pm25_continuous= NULL;
gslc_tsElemRef* m_pElem_pm25_value= NULL;
gslc_tsElemRef* m_pElem_progress_measure= NULL;
gslc_tsElemRef* m_pElem_selected_ssid= NULL;
gslc_tsElemRef* m_pElem_temp_value= NULL;
gslc_tsElemRef* m_pElem_toggle_IoT= NULL;
gslc_tsElemRef* m_pElem_toggle_csv= NULL;
gslc_tsElemRef* m_pElem_toggle_dimmer= NULL;
gslc_tsElemRef* m_pElem_toggle_lock= NULL;
gslc_tsElemRef* m_pElem_toggle_measure= NULL;
gslc_tsElemRef* m_pElem_unlock    = NULL;
gslc_tsElemRef* m_pElem_wifi_gauge= NULL;
gslc_tsElemRef* popup_line1       = NULL;
gslc_tsElemRef* popup_line2       = NULL;
gslc_tsElemRef* m_pElemKeyPadNum  = NULL;
gslc_tsElemRef* m_pElemKeyPadAlpha= NULL;
//<Save_References !End!>


// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

//char ssid[MAX_STR];
//char password[MAX_STR];
char ip_address[16];
bool connecting = false;
char my_losant_webhook_url [] = "https://triggers.losant.com/webhooks/eAPNEsTpunTnn0AC5yuCfR54GbFXdFU8hxSUKYwL";




SDS_Sensor_Helper sds_sensor;
IoT_Helper IoT_webhook;
ESP32Time rtc;  
Adafruit_BME280 bme280; // I2C BME280 sensor

int wifi_progress_cnt = 1;
int helper_cnt = 0;
int t_minute = 0;
int t_hour = 1;
int year = 2022;
int month = 6;
int day = 6;
int inputLockCode = 0; // stores the input for the screen unclock code

//bool store_csv = false;
//bool do_upload = true;

int found_networks = -5;
bool scanning_wifi = false;
bool loading_anim_invert = false;
bool showAverage = false;
int16_t loading_anim_val = 0;

const char* pnt = ".";
char buff[10];
int ret;
//int meas_interval = 60000; // 1 minute
unsigned long interval_heatup = 20000; // 20sec wakeup intervall
unsigned long lastMeasure = 0;
unsigned long currentMillis;
unsigned long request_time = 0;
bool measure_request = false;
int error = 0;
float temp_val = 0.0;
float hum_val = 0.0;
float pm10_continuous = 1.0;
float pm25_continuous = 1.0;
float cont_max_pm10 = 1.0;
float cont_max_pm25 = 1.0;


bool graphPM10 = true;

unsigned long lastTouchEvent = 0;
int interval_dimmer = 20000; // default 20sec dimmer timer
bool dimmerActivated = false;
bool isDimmerRunning = false;
bool lock_enable = false;

bool progressbar_flag = false;
bool continuousMode = false;

//void show_value(bool pm10_val=false);
void printCSV();
void resetCSV();
void showInfo();

size_t getCSVsize();
bool connect_wifi(const char *wifi_name);
void setBacklight(bool state);
void shutdown();
void update_display_values();
void saveConfig();
void prepareConfig();
void update_aqi();

typedef struct {
  char ssid[60];
  char password[30];
  bool store_csv;
  bool do_upload;
  int meas_interval; 
} Configuration;
Configuration config = {"","", false, false, 60000}; // default configuration

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
  if(dimmerActivated || lock_enable){
      lastTouchEvent = millis();
  }

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
      //<Button Enums !Start!>
      case E_ELEM_BTN_WIFI_SETUP:{
        gslc_SetPageCur(&m_gui, E_PG_WIFI);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_BTN_dashboard:{
        gslc_SetPageCur(&m_gui, E_PG_OVERVIEW);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_BTN_INFO:	{
        showInfo();
        gslc_SetPageCur(&m_gui, E_PG_INFO);	
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_BTN_SCAN_WIFI:{
        scanning_wifi = true;
        break;}

      case E_ELEM_BTN_WIFI_CONNECT:{
        gslc_SetPageCur(&m_gui, E_PG_WIFI_PSWD);
        delay(70);
        break;}

      case E_ELEM_BACK_PG_WIFI:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_BTN_CONTINUOUS:{
        gslc_SetPageCur(&m_gui, E_PG_Continuous);
        continuousMode = true;
        break;}
      case E_ELEM_BACK_CONTIN:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        #ifdef ESP32
          sds_sensor.quit_continuous();
        #else
          sds_sensor.quit_continuous(SDS_TX, SDS_RX);
        #endif
        continuousMode = false;
        break;}


      case E_ELEM_PSWD_INPUT:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, m_pElemIn_PASSWORD);
        delay(70);
        break;}

      case E_ELEM_BTN_CONNECT:{
        delay(70);
        connect_wifi();
        break;}

      case E_ELEM_SAVE_SET:{
        delay(70);
        saveConfig();
        break;}

      case E_ELEM_BACK_WIFI_PWD:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_TOGGLE_MEASURE:{
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_measure)) {
          showAverage = true;
          update_display_values();
        }
        else{
          showAverage = false;
          update_display_values();
        }
        delay(70);
        break;}

      case E_ELEM_HOME_BTN:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_MEASURE_BTN:{
        if(!sds_sensor.is_measurement_running()){
          sds_sensor.request_measure(millis());
        }
        delay(70);
        break;}

      case E_ELEM_BTN_SYS_SET:{	
        gslc_SetPageCur(&m_gui, E_PG_SYS_SET);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;	}

      case E_ELEM_BTN_IOT_SET:{	
        gslc_SetPageCur(&m_gui, E_PG_IOT_SET);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;	}

      case E_ELEM_DIMMER_TIMER:	{
        // Clicked on edit field, so show popup box and associate with this text field	
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_dimmer_timer);	
        delay(70);
        break;	}

      case E_ELEM_TOGGLE_DIMMER:{
        dimmerActivated = gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_dimmer);
        isDimmerRunning = dimmerActivated;
        delay(70);
        break;	}

      case E_ELEM_DIM_ON:	
        setBacklight(false);
        delay(70);
        break;	

      case E_ELEM_MEAS_INTERVAL:{	
        // Clicked on edit field, so show popup box and associate with this text field	
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_meas_interval);	
        delay(70);
        break;}

      case E_ELEM_DIM_OFF:{	
        gslc_PopupHide(&m_gui);	
        setBacklight(true);
        delay(70);
        break;}

      case E_ELEM_BACK_IOT:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;
      

      case E_ELEM_BACK_SYSSET:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_BACK_INFO:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}
      
      case E_ELEM_DEL_DATA:{
        resetCSV();
        delay(70);
        break;}

      case E_ELEM_PRINT_DATA:{
        printCSV();
        delay(70);
        break;}

      case E_ELEM_TOGGLE_CSV:{
        config.store_csv = gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_csv);
        delay(70);
        break;}

      case E_ELEM_TOGGLE_IOT:{
        config.do_upload = gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_IoT);
        delay(70);
        break;}
      
      case E_ELEM_BTN_SETTIME:{
        gslc_SetPageCur(&m_gui, E_PG_TIME);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_NUM_MONTH:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemMonth);
        delay(70);
        break;}

      case E_ELEM_NUM_DAY:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemDay);
        delay(70);
        break;}

      case E_ELEM_NUM_YEAR:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemYear);
        delay(70);
        break;}

      case E_ELEM_NUM_HOUR:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemHour);
        delay(70);
        break;}

      case E_ELEM_NUM_MINUTE:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemMinute);
        delay(70);
        break;}

      case E_ELEM_BACK_TIME:{
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_BTN_SAVE_TIME:{
        Serial.printf("Set RTC time = %i:%i  |  Date = %i/%i/%i\n",t_hour, t_minute, day, month, year);
        rtc.setTime(0, t_minute, t_hour, day, month, year);
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        delay(70);
        break;}

      case E_ELEM_SHUTDOWN:{
        delay(70);
        shutdown();
        break;}
      case E_ELEM_CODE_INPUT:{
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemCodeIn);
        delay(70);
        break;}
      case E_ELEM_TOGGLE_LOCK:{
        set_lockscreen(gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_lock));
        delay(70);
        break;}

      case E_ELEM_UNLOCK:{
        // only disable lockscreen if code input is right
        if(inputLockCode == 628){
          set_lockscreen(false);
          inputLockCode = 0; // reset code input
        }
        delay(70);
        break;}
      
      //<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}


// KeyPad Input Ready callback
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)pvGui;
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  // From the pvData we can get the ID element that is ready.
  int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
  if(dimmerActivated || lock_enable){
      lastTouchEvent = millis();
  }

  if (nState == XKEYPAD_CB_STATE_DONE) {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId) {

      case E_ELEM_PSWD_INPUT:
        strncpy(config.password, gslc_ElemXKeyPadInputGet(pGui, m_pElemIn_PASSWORD, pvData), sizeof(config.password));
        //strcpy(config.password,gslc_ElemXKeyPadInputGet(pGui, m_pElemIn_PASSWORD, pvData));
	      gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_DIMMER_TIMER:	
        gslc_ElemXKeyPadInputGet(pGui, m_pElem_dimmer_timer, pvData);	
	      gslc_PopupHide(&m_gui);	
        break;	
      case E_ELEM_MEAS_INTERVAL:	
        config.meas_interval = atoi(gslc_ElemXKeyPadInputGet(pGui, m_pElem_meas_interval, pvData)) * 60000;
        sds_sensor.set_measure_interval(config.meas_interval);
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
      case E_ELEM_CODE_INPUT:
        inputLockCode = atoi(gslc_ElemXKeyPadInputGet(pGui,  m_pElemCodeIn, pvData));
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
  if(dimmerActivated || lock_enable){
      lastTouchEvent = millis();
  }

  // From the element's ID we can determine which listbox was active.
  switch (pElem->nId) {
//<Listbox Enums !Start!>
    case E_ELEM_WIFI_LIST:
      if (nSelId != XLISTBOX_SEL_NONE) {
        gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
        strncpy(config.ssid, acTxt, sizeof(config.ssid));
        //snprintf(config.ssid, 60, acTxt);
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


/// @brief Updating AQI-Value by mapping Value to the AQI-Table. Setting color.
void update_aqi()                 
{
  float aqi_25 = calc_aqipm25(sds_sensor.getPM25value(showAverage));
  float aqi_10 = calc_aqipm25(sds_sensor.getPM10value(showAverage));

  int aqi_index = mapAqiToIndex(aqi_25);
  int aqi_index2 = mapAqiToIndex(aqi_10);
  // selcet the higest value
  if(aqi_index < aqi_index2){
    aqi_index = aqi_index2;
  }
  Serial.print("AQI 25 value: ");
  Serial.print(aqi_25);
  Serial.print("  |  AQI 10 value: ");
  Serial.println(aqi_10);
  Serial.print("AQI 25 index: ");
  Serial.print(aqi_index);
  Serial.print("  |  AQI 10 index: ");
  Serial.println(aqi_index2);


  
  switch(aqi_index) {
  case 0:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "Very good");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_GREEN_DK1);
    break;}
  case 1:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "Good");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_GREEN_DK1);
    break;}
  case 2:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "Moderate");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_YELLOW);
    break;}
  case 3:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "Unhealthy");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_ORANGE);
    break;}
  case 4:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "Very unhealthy");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_RED_DK1);
    break;}
  case 5:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "Risky");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_PURPLE);
    break;}
  case 6:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "Dangerous!");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_RED_DK3);
    break;}
  case 7:{
    gslc_ElemSetTxtStr(&m_gui, m_pElem_aqi_val, "UNSAFE!");
    gslc_ElemSetTxtCol(&m_gui, m_pElem_aqi_val, GSLC_COL_RED_DK3);
    break;}
  default:
    ;
  }
}



void set_lockscreen(bool state){
  if(state){
    lock_enable = true;
    gslc_SetPageCur(&m_gui, E_PG_LOCK);
    gslc_ElemXTogglebtnSetState(&m_gui, m_pElem_toggle_lock, true);
  }
  else{
    lock_enable = false;
    gslc_SetPageCur(&m_gui, E_PG_OVERVIEW);
    gslc_ElemXTogglebtnSetState(&m_gui, m_pElem_toggle_lock, false);
  }
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




bool connect_wifi()
{
    char msg[30]; 
    strncpy(msg,"Connecting ",12);
    gslc_ElemSetTxtStr(&m_gui, m_pElem_con_msg, msg);
    WiFi.begin(config.ssid, config.password);
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
  text += " - Interval: " + String((uint32_t)sds_sensor.get_interval_sec() / 60) + " min";
  text += "\nCPU0 RST: " + reason_cpu0 + "\nCPU1 RST: " + reason_cpu1 + "\nMEM (KB): HEAP: " + String(ESP.getFreeHeap()/1000) + "/" + String(ESP.getHeapSize()/1000);
  text += " | Lowest: " + String(esp_get_minimum_free_heap_size()/1000) + " | CSV: " + String(getCSVsize());
  text += "\nCPU Freq: " + String(ESP.getCpuFreqMHz()) + " MHz - Model: " + String(ESP.getChipModel());
  text += "\nIoT-URL:  " + url_p1;
  text += "\n          " + url_p2 + "\n          " + url_p3;
  text += "\nWiFi:     Connected? - " + wifi_connected + "\nSSID:     " + String(config.ssid) + " IP: " + String(ip_address); 
  
  gslc_ElemXTextboxAdd(&m_gui,m_pElem_infobox,(char*)text.c_str());
  delay(100);

}


/**
 * @brief Helper function to update the display with the new values
 * Updating PM10 & PM25 text + Gauge and the temperature/humidity text.
 * PM Gauges will be set in relationship to the value size, to show a bit green if value is to small.
 */
void update_display_values(){
  // Updating PM10 value
  float pm10_val = sds_sensor.getPM10value(showAverage);
  gslc_ElemSetTxtStr(&m_gui, m_pElem_pm10_value, String(pm10_val).c_str());

  if((int)pm10_val > 1.5){
      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM10, (int)pm10_val);
  }
  else{
      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM10, 1.5);
  }
  
  // Updating pm25 
  float pm25_val = sds_sensor.getPM25value(showAverage);
  gslc_ElemSetTxtStr(&m_gui, m_pElem_pm25_value, String(pm25_val).c_str());

  if((int)pm25_val > 1.5){
      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM25, (int)pm25_val);
  }
  else{
      gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGaugePM25, 1.5); // To show a littlebit green
  }

  // Updating temp
  gslc_ElemSetTxtStr(&m_gui, m_pElem_temp_value, String(temp_val).c_str());


  // Updating humidity
  gslc_ElemSetTxtStr(&m_gui, m_pElem_hum_val, String(hum_val).c_str());

  update_aqi();
}

void shutdown(){
  // store settings
  saveConfig();
  gslc_Quit(&m_gui);
  SPIFFS.end();
  setBacklight(false);
  Serial.end();
  while(1){
    delay(100);
  }
}


void updateCSV(){
    if(config.store_csv){
      fs::File file = SPIFFS.open("/data.csv", "a");
      file.printf("%s,", rtc.getTime().c_str());
      file.printf("%.2f,", sds_sensor.getPM10value(false));
      file.printf("%.2f \n", sds_sensor.getPM25value(false));
      file.close();
    }
}

// To get the size of the csv file in KB.
size_t getCSVsize(){
  if(config.store_csv){
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
  if(config.store_csv){

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
  
  delay(70);
}

void resetCSV(){
  SPIFFS.remove("/data.csv");
  delay(100);
  fs::File file = SPIFFS.open("/data.csv", "w");
  file.printf("time,pm10,pm25\n");
  file.close();
  delay(100);
  SPIFFS.remove("/tmp.txt");
  SPIFFS.remove("/conf.txt");

  
}



/**
 * @brief Set the TFT Backlight LED.
 * @note  If backlight is turned off, the dimmer-popup screen is active!
 * 
 * @param state 
 */
void setBacklight(bool state){
  if (state){
    digitalWrite(tft_led_pin, HIGH);
    isDimmerRunning = false;
  }
  else{
    digitalWrite(tft_led_pin, LOW);
    gslc_PopupShow(&m_gui, E_PG_POPUP_DIMMER, true);	
    isDimmerRunning = true;
  }
}


/**
 * @brief Enable dimmer if last touchevent was more than meas_interval-time ago
 * @note  If lockscreen is enabled, display will be dimmed after 4 seconds!
 * 
 * @param _currentMillis 
 */
void handleDimmer(unsigned long _currentMillis){
  if(lock_enable){
    if((_currentMillis - lastTouchEvent) > 4000){
      setBacklight(false);
    }
  }
  else{
    if(dimmerActivated && (_currentMillis - lastTouchEvent) > interval_dimmer){
      setBacklight(false);
    }
  }

}

/**
 * @brief Helper func for cloud upload
 * @note  Shows popup page if dimmer is not running. Workaraond because "close_popup" would close the dimmer popup too.
 */
void uploadCloud(){
  if(config.do_upload){
    if(isDimmerRunning == false && WiFi.isConnected()){
      gslc_PopupShow(&m_gui, E_PG_UPLOAD_POPUP, true);
      gslc_ElemSetTxtStr(&m_gui, popup_line1, "Uploading data to cloud!");
      gslc_ElemSetTxtStr(&m_gui, popup_line2, "Please wait...");
      gslc_PageRedrawGo(&m_gui);
      delay(250);
      IoT_webhook.pm_update(sds_sensor.getPM10value(false), sds_sensor.getPM25value(false), rtc.getHour(true), rtc.getMinute());
      gslc_PopupHide(&m_gui);
    }
    else{
      IoT_webhook.pm_update(sds_sensor.getPM10value(false), sds_sensor.getPM25value(false), rtc.getHour(true), rtc.getMinute());
    }
  }
}


void prepareConfig(){
  if(SPIFFS.exists("/conf.txt")){
    Serial.println("Found configuration, loading settings!");
    fs::File file = SPIFFS.open("/conf.txt", FILE_READ);
    //Serial.println(file.readString());
    file.read((byte *)&config, sizeof(config));
    file.close();
    /*
    String tmp = file.readStringUntil('\n');
    Serial.println(tmp);
    strncpy(config.ssid, tmp.c_str(), sizeof(config.ssid));
    tmp = file.readStringUntil('\n');
    Serial.println(tmp);
    strncpy(config.password, tmp.c_str(), sizeof(config.password));
    tmp = file.readStringUntil('\n');
    Serial.println(tmp);
    config.do_upload = tmp.toInt();
    tmp = file.readStringUntil('\n');
    Serial.println(tmp);
    config.store_csv = tmp.toInt();
    tmp = file.readStringUntil('\n');
    Serial.println(tmp);
    config.meas_interval = tmp.toInt();
    file.close();
    Serial.printf("read: %s, %s, %i,%i, %i\n", config.ssid, config.password, config.do_upload, config.store_csv, config.meas_interval);
    */
  }
}

void saveConfig(){
  Serial.print("Saving config to SPIFFS: ");
  fs::File file = SPIFFS.open("/conf.txt", FILE_WRITE);
  file.write((byte *)&config, sizeof(config));
  file.close();
  
  gslc_PopupShow(&m_gui, E_PG_UPLOAD_POPUP, true);	
  gslc_ElemSetTxtStr(&m_gui, popup_line1, "Saved settings!");
  gslc_ElemSetTxtStr(&m_gui, popup_line2, "");
  gslc_PageRedrawGo(&m_gui);
  delay(1500);
  gslc_PopupHide(&m_gui);	
}


void setup()
{ 
    Serial.begin(9600);
    delay(500);
    Serial.println(">>> Starting setup procedure");
    pinMode(tft_led_pin, OUTPUT);
    setBacklight(false);
    Serial.println("Init guislice");
    delay(100);
    gslc_InitDebug(&DebugOut);
    InitGUIslice_gen();
    delay(20);
    prepareConfig(); // loading config from SPIFFS
 
    // default BME280 settings -> SCL = D22 & SDA = D21
    if (!bme280.begin(0x76)) {
      Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
    bme280.setSampling(bme280.MODE_NORMAL,
                    bme280.SAMPLING_X1, // temperature
                    bme280.SAMPLING_X1, // pressure
                    bme280.SAMPLING_X1, // humidity
                    bme280.FILTER_OFF);
    //bme280.setTemperatureCompensation();
    delay(50);

    #ifndef ESP32
      sds_sensor.setup(SDS_TX, SDS_RX, interval_heatup, config.meas_interval);
    #else
      sds_sensor.setup(interval_heatup,config.meas_interval);
    #endif
    Serial.println("IOT setup");
    IoT_webhook.setup(my_losant_webhook_url);
    Serial.println("Finished IOT setup");
    //Serial.println("Checking CSV flag");
    //store_csv = is_csv_enabled(); // load indicator from spiffs
    
    if(config.store_csv){ 
      Serial.println("Setup data.csv");
      
      if(SPIFFS.exists("/data.csv")){
        fs::File file = SPIFFS.open("/data.csv", "a");
        file.printf("\n\n\n+++   RESTART - NEW DATASET   +++\n\n");
        file.printf("time,pm10,pm25\n");
        file.close();
      }
      else{
        fs::File file = SPIFFS.open("/data.csv", "w");
        file.printf("time,pm10,pm25\n");
        file.close();
      }
    }

    gslc_ElemXTogglebtnSetState(&m_gui, m_pElem_toggle_csv, config.store_csv); // set indicator
    gslc_ElemXTogglebtnSetState(&m_gui, m_pElem_toggle_IoT, config.do_upload); // set indicator


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
    gslc_GuiRotate(&m_gui, 3);
    setBacklight(true);

    if(String(config.ssid) != ""){
      Serial.print("Found ssid in config: ");
      Serial.println(config.ssid);
      WiFi.begin(config.ssid, config.password);
      gslc_PopupShow(&m_gui, E_PG_UPLOAD_POPUP, true);
      gslc_ElemSetTxtStr(&m_gui, popup_line1, "Connecting to WiFi:");
      gslc_ElemSetTxtStr(&m_gui, popup_line2, String(config.ssid).c_str());
      gslc_PageRedrawGo(&m_gui);
      delay(5000);
      gslc_PopupHide(&m_gui);
      if(WiFi.status() == WL_CONNECTED){
        gslc_ElemSetVisible(&m_gui, m_pElem_img_nowifi, false);
        gslc_ElemSetVisible(&m_gui, m_pElem_img_wifi, true);
      }
    }
}

int graph_cnt = 0;
// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{
    if(continuousMode){
      sds_sensor.setContinuous();
    }
    while(continuousMode){
      sds_sensor.readContinuous(&pm10_continuous, &pm25_continuous);
      Serial.printf("PM10: %.2f   PM25: %.2f\n", pm10_continuous, pm25_continuous);
      
      if(pm25_continuous > cont_max_pm25){
        cont_max_pm25 = pm25_continuous;
        gslc_ElemSetTxtStr(&m_gui, m_pElem_pm25_cont_max, String(cont_max_pm25).c_str());
      }

      if(pm10_continuous > cont_max_pm10){
        cont_max_pm10 = pm10_continuous;
        gslc_ElemSetTxtStr(&m_gui, m_pElem_pm10_cont_max, String(cont_max_pm10).c_str());
      }
      gslc_ElemSetTxtStr(&m_gui, m_pElem_pm10_continuous, String(pm10_continuous).c_str());
      gslc_ElemSetTxtStr(&m_gui, m_pElem_pm25_continuous, String(pm25_continuous).c_str());
      
      // wait 1sec
      for (size_t i = 0; i < 8; i++)
      {
        gslc_Update(&m_gui);    
        delay(125);
      }  
    }



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
        if(WiFi.status() != WL_CONNECTED && wifi_progress_cnt <= 15){
            // Let WiFi-Connection MSG Item blink
            delay(250);
            char *msg = gslc_ElemGetTxtStr(&m_gui, m_pElem_con_msg);
            strncat(msg,pnt,MAX_STR+1);
            gslc_ElemSetTxtStr(&m_gui, m_pElem_con_msg, msg);
            gslc_ElemSetVisible(&m_gui, m_pElem_con_msg, (wifi_progress_cnt % 2 == 0));
            wifi_progress_cnt++;
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
                saveConfig();
            }
            else{
                gslc_ElemSetTxtStr(&m_gui, m_pElem_con_msg, "Failed to connect!");
                gslc_ElemSetVisible(&m_gui, m_pElem_img_nowifi, true);
                gslc_ElemSetVisible(&m_gui, m_pElem_img_wifi, false);
                gslc_ElemSetVisible(&m_gui, m_pElem_con_msg, true);
            }
            connecting = false;
            wifi_progress_cnt = 0;
        }
    }
    
    currentMillis = millis();

    
    if(sds_sensor.update(currentMillis))
    {
      // new meas-values available

      // reset loading animation colors / values
      if(gslc_ElemGetVisible(&m_gui, m_pElem_Measuring)){
        gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, false);
        gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, false);
      }
      loading_anim_invert = false;
      gslc_ElemSetCol(&m_gui,m_pElem_progress_measure,GSLC_COL_GRAY_DK1,GSLC_COL_GRAY_LT2,GSLC_COL_WHITE);
      gslc_ElemXProgressSetGaugeCol(&m_gui,m_pElem_progress_measure, GSLC_COL_GREEN_DK1);

      // handle values
      update_display_values();
      updateCSV();
      uploadCloud();
      helper_cnt = 0;
    }
    
    else if(sds_sensor.is_measurement_running())
    {
      // Progressbar animation while SDS-Sensor measurement
      if(!gslc_ElemGetVisible(&m_gui, m_pElem_Measuring)){
        gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, true);
        gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, true);
      }
      if(!loading_anim_invert){
        if(loading_anim_val < 400){
          loading_anim_val++;
          helper_cnt += 1;  // count invertions and use it as reference for the BME temperatur measurement start point
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

      if(helper_cnt == 1600){
        // Now the fan of the SDS sensor was turned on for approx. 10 seconds 
        // -> Now measure temperature with BME280 because the "old" air is flushed out
        temp_val = bme280.readTemperature();
        hum_val = bme280.readHumidity();
        helper_cnt += 1; // to avoid running this code-block again
      }
      if(progressbar_flag){
        gslc_ElemXProgressSetVal(&m_gui, m_pElem_progress_measure,loading_anim_val);
        gslc_Update(&m_gui);
        delay(3);
      }else{
        gslc_Update(&m_gui);
        delay(3);
      }
      progressbar_flag = !progressbar_flag;
    }
    
    handleDimmer(currentMillis);
    gslc_Update(&m_gui);    // Periodically call GUIslice update function
    
}

