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
#include <SPIFFS.h>



#define IMG_BKGND_1               "/back.bmp"
#define IMG_BKGND_2               "/back2.bmp"
#define seconds() (millis()/1000)

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemIn_PASSWORD= NULL;
gslc_tsElemRef* m_pElemXRingGaugePM10= NULL;
gslc_tsElemRef* m_pElemXRingGaugePM25= NULL;
gslc_tsElemRef* m_pElem_INFO_BOX  = NULL;
gslc_tsElemRef* m_pElem_Measuring = NULL;
gslc_tsElemRef* m_pElem_WIFI_LIST = NULL;
gslc_tsElemRef* m_pElem_aqi_val   = NULL;
gslc_tsElemRef* m_pElem_btn_WIFI_setup= NULL;
gslc_tsElemRef* m_pElem_btn_back_PG_WIFI_PWD= NULL;
gslc_tsElemRef* m_pElem_btn_back_main_34= NULL;
gslc_tsElemRef* m_pElem_btn_back_main_37= NULL;
gslc_tsElemRef* m_pElem_btn_back_main_38= NULL;
gslc_tsElemRef* m_pElem_btn_back_pg_wifi= NULL;
gslc_tsElemRef* m_pElem_btn_dashboard= NULL;
gslc_tsElemRef* m_pElem_btn_home  = NULL;
gslc_tsElemRef* m_pElem_btn_info  = NULL;
gslc_tsElemRef* m_pElem_btn_measure= NULL;
gslc_tsElemRef* m_pElem_con_msg   = NULL;
gslc_tsElemRef* m_pElem_dimmer_timer= NULL;
gslc_tsElemRef* m_pElem_enable_dimmer= NULL;
gslc_tsElemRef* m_pElem_hum_val   = NULL;
gslc_tsElemRef* m_pElem_img_nowifi= NULL;
gslc_tsElemRef* m_pElem_img_wifi  = NULL;
gslc_tsElemRef* m_pElem_label_measure_art= NULL;
gslc_tsElemRef* m_pElem_label_measure_art38_39= NULL;
gslc_tsElemRef* m_pElem_label_measure_art38_39_43= NULL;
gslc_tsElemRef* m_pElem_label_pg_wifi_pwd= NULL;
gslc_tsElemRef* m_pElem_meas_interval= NULL;
gslc_tsElemRef* m_pElem_pm10_value= NULL;
gslc_tsElemRef* m_pElem_pm25_value= NULL;
gslc_tsElemRef* m_pElem_progress_measure= NULL;
gslc_tsElemRef* m_pElem_selected_ssid= NULL;
gslc_tsElemRef* m_pElem_temp_value= NULL;
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
//SDS011 sds;
float pm10, pm25;


SDS_Sensor_Helper sds_sensor;

int cnt = 1;
int cnt2 = 1;
int r1 = 0;
int r2 = 50;
int cnt3 = 1;
bool r1_ = false;
bool r2_ = false;

int found_networks = -5;
bool scanning_wifi = false;
bool loading_anim_invert = false;
bool show_24h_average = false;
int loading_anim_val = 0;

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

unsigned long lastTouchEvent = 0;
unsigned long interval_dimmer = 20000; // default 20sec dimmer timer
bool dimmerActivated = false;



void show_value(bool pm10_val=false);
void printCSV();
void resetCSV();
void showInfo();
size_t getCSVsize();

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
    if(dimmerActivated){
      lastTouchEvent = millis();
    }

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

      case E_ELEM_BTN_INFO:	
        showInfo();
        gslc_SetPageCur(&m_gui, E_PG_INFO);	
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
        break;

      case E_ELEM_HOME_BTN:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;

      case E_ELEM_MEASURE_BTN:
        // TODO: Add code for manual measure trigger
        break;

      case E_ELEM_BTN_SYSTEM_SETTINGS:	
        gslc_SetPageCur(&m_gui, E_PG_SYSTEM_SETTINGS);	
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;	

      case E_ELEM_BTN_IOT_SETTINGS:	
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_2,GSLC_IMGREF_FMT_BMP24));
        break;	
      case E_ELEM_DIMMER_TIMER:	
        // Clicked on edit field, so show popup box and associate with this text field	
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_dimmer_timer);	
        break;	
      case E_ELEM_ENABLE_DIMMER:
        dimmerActivated = gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_enable_dimmer);
        break;	

      case E_ELEM_DIM_ON:	
        setBacklight(false);
        break;	

      case E_ELEM_MEAS_INTERVAL:	
        // Clicked on edit field, so show popup box and associate with this text field	
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_meas_interval);	
        break;	

      case E_ELEM_DIM_OFF:	
        gslc_PopupHide(&m_gui);	
        setBacklight(true);
        break;

      case E_ELEM_BACK34:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;
      case E_ELEM_BACK37:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;
      case E_ELEM_BACK38:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND_1,GSLC_IMGREF_FMT_BMP24));
        break;
      
      case E_ELEM_DEL_DATA:
        resetCSV();
        break;
      case E_ELEM_PRINT_DATA:
        printCSV();
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
      case E_ELEM_DIMMER_TIMER:	
        gslc_ElemXKeyPadInputGet(pGui, m_pElem_dimmer_timer, pvData);	
	      gslc_PopupHide(&m_gui);	
        break;	
      case E_ELEM_MEAS_INTERVAL:	
        gslc_ElemXKeyPadInputGet(pGui, m_pElem_meas_interval, pvData);
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

void showInfo(){
  // Print text to info-textbox
  gslc_ElemXTextboxReset(&m_gui,m_pElem_INFO_BOX);
  //m_acTextboxBuf1 [200];
  String text = "Uptime: " + String(seconds()) + "sec.\nFree DRAM: " + String(ESP.getFreeHeap()/1000) + " KB\nMeas count: " + String(sds_sensor.get_measure_cnt()) + "\nData.csv size: " + String(getCSVsize()) + " KB\n";
  //snprintf(m_acTextboxBuf1,200,(char*)"Uptime: %u sec.\nFree DRAM: %i kb\ndata.csv: %i kb\nMeas count: %u\n", seconds(), ESP.getFreeHeap()/1000, getCSVsize(), sds_sensor.get_measure_cnt(false));
  //snprintf(m_acTextboxBuf1,600,text.c_str());
  gslc_ElemXTextboxAdd(&m_gui,m_pElem_INFO_BOX,(char*)text.c_str());
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
  delay(100);
  fs::File file = SPIFFS.open("/data.csv", "a");
  file.printf("%u,", currentSec);
  file.printf("%.2f,", sds_sensor.get_value(true,false));
  file.printf("%.2f \n", sds_sensor.get_value(false, false));
  file.close();
}

size_t getCSVsize(){
  // To get the size of the csv file in KB.
  fs::File file = SPIFFS.open("/data.csv", "r");
  size_t size = file.size();
  file.close();
  return (size / 1000);
}

void printCSV(){
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

  delay(1000);
}

void resetCSV(){
  SPIFFS.remove("/data.csv");
  delay(100);
  fs::File file = SPIFFS.open("/data.csv", "w");
  file.printf("relative_time,pm10,pm25\n");
  file.close();
  delay(100);
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



void setup()
{ 
    Serial.begin(2400);
    delay(1000);
    Serial.println(">>> Starting setup procedure");
    delay(1000);
    sds_sensor.setup(SDS_TX, SDS_RX, interval_heatup, interval);

    delay(500);
    // Wait for USB Serial 
    //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used
    pinMode(tft_led_pin, OUTPUT);
    setBacklight(true);
    //delay(1000);
    gslc_InitDebug(&DebugOut);
    delay(500);
    InitGUIslice_gen();
    delay(2000);
    
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
    
    
 
    
    // Hide images and disable image-button glow (to avoid slow rendering)
    gslc_ElemSetVisible(&m_gui, m_pElem_Measuring, false);
    gslc_ElemSetVisible(&m_gui, m_pElem_progress_measure, false);
    gslc_ElemSetVisible(&m_gui, m_pElem_img_wifi, false );
    gslc_ElemSetVisible(&m_gui, m_pElem_wifi_gauge, false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_home,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_measure,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_back_PG_WIFI_PWD,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_dashboard,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_WIFI_setup,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_info,false);
    gslc_ElemSetGlowEn(&m_gui,m_pElem_btn_back_pg_wifi,false);
    delay(1000);
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
    // ------------------------------------------------
    // Periodically call GUIslice update function
    // ------------------------------------------------
    gslc_Update(&m_gui);
    
}

