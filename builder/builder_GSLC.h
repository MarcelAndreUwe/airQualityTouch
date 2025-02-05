//<File !Start!>
// FILE: [builder_GSLC.h]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XKeyPad_Alpha.h"
#include "elem/XKeyPad_Num.h"
#include "elem/XListbox.h"
#include "elem/XProgress.h"
#include "elem/XRingGauge.h"
#include "elem/XTextbox.h"
#include "elem/XTogglebtn.h"

// Ensure optional features are enabled in the configuration
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if !defined(DRV_DISP_TFT_ESPI)
  #error Project tab->Target Platform should be arduino
#endif
#include <TFT_eSPI.h>
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
#define IMG_BKGND                 "/back.bmp"
#define IMG_CONTROL               "/control"
#define IMG_CONTROL               "/control.bmp"
#define IMG_DASHBOARD             "/dashboard.bmp"
#define IMG_DASHBOARD_SEL         "/dashboard.bmp"
#define IMG_EXIT                  "/exit.bmp"
#define IMG_HUM                   "/hum.bmp"
#define IMG_INFO                  "/info.bmp"
#define IMG_INFO_SEL              "/info.bmp"
#define IMG_NOWIFI                "/no-wifi.bmp"
#define IMG_REUSE                 "/reuse.bmp"
#define IMG_TMP_1                 "/tmp_1.bmp"
#define IMG_WIFI                  "/wifi.bmp"
#define IMG_WIFI_SETUP            "/wifi_setup.bmp"
#define IMG_WIFI_SETUP_SEL        "/wifi_setup.bmp"
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_MAIN,E_PG_WIFI,E_PG_WIFI_PSWD,E_PG_OVERVIEW,E_PG_INFO
      ,E_PG_SYS_SET,E_PG_IOT_SET,E_PG_POPUP_DIMMER,E_PG_TIME,E_PG_LOCK
      ,E_PG_UPLOAD_POPUP,E_PG_Continuous,E_POP_KEYPAD_NUM
      ,E_POP_KEYPAD_ALPHA};
enum {E_DRAW_LINE1,E_DRAW_LINE11,E_DRAW_LINE12,E_DRAW_LINE13
      ,E_DRAW_LINE14,E_DRAW_LINE15,E_DRAW_LINE3,E_DRAW_LINE4
      ,E_DRAW_LINE5,E_DRAW_LINE6,E_DRAW_LINE8,E_ELEM_AQI
      ,E_ELEM_BACK_CONTIN,E_ELEM_BACK_INFO,E_ELEM_BACK_IOT
      ,E_ELEM_BACK_PG_WIFI,E_ELEM_BACK_SYSSET,E_ELEM_BACK_TIME
      ,E_ELEM_BACK_WIFI_PWD,E_ELEM_BOX2,E_ELEM_BTN_CONNECT
      ,E_ELEM_BTN_CONTINUOUS,E_ELEM_BTN_INFO,E_ELEM_BTN_IOT_SET
      ,E_ELEM_BTN_SAVE_TIME,E_ELEM_BTN_SCAN_WIFI,E_ELEM_BTN_SETTIME
      ,E_ELEM_BTN_SYS_SET,E_ELEM_BTN_WIFI_CONNECT,E_ELEM_BTN_WIFI_SETUP
      ,E_ELEM_BTN_dashboard,E_ELEM_CODE_INPUT,E_ELEM_CON_MSG
      ,E_ELEM_DEL_DATA,E_ELEM_DIMMER_TIMER,E_ELEM_DIM_OFF,E_ELEM_DIM_ON
      ,E_ELEM_HOME_BTN,E_ELEM_HUM_VALUE,E_ELEM_IMAGE6,E_ELEM_IMAGE8
      ,E_ELEM_IMG_NOWIFI,E_ELEM_IMG_WIFI,E_ELEM_INFOBOX
      ,E_ELEM_LABEL_SSID_PG_WIFI,E_ELEM_LABEL_SSID_PG_WIFI_PWD
      ,E_ELEM_MEASURE_BTN,E_ELEM_MEAS_INTERVAL,E_ELEM_NUM_DAY
      ,E_ELEM_NUM_HOUR,E_ELEM_NUM_MINUTE,E_ELEM_NUM_MONTH
      ,E_ELEM_NUM_YEAR,E_ELEM_PM10_VALUE,E_ELEM_PM10_continuous
      ,E_ELEM_PM25_VALUE,E_ELEM_PM25_continuous,E_ELEM_POPUP_L1
      ,E_ELEM_POPUP_L2,E_ELEM_PRINT_DATA,E_ELEM_PROGRESS_MEASURE
      ,E_ELEM_PSWD_INPUT,E_ELEM_RINGGAUGE_PM10,E_ELEM_RINGGAUGE_PM25
      ,E_ELEM_SAVE_SET,E_ELEM_SHUTDOWN,E_ELEM_TEMP_VALUE,E_ELEM_TEXT33
      ,E_ELEM_TEXT34,E_ELEM_TEXT36,E_ELEM_TEXT37,E_ELEM_TEXT39
      ,E_ELEM_TEXT41,E_ELEM_TEXT42,E_ELEM_TEXT43,E_ELEM_TEXT44
      ,E_ELEM_TEXT45,E_ELEM_TEXT55,E_ELEM_TEXT56,E_ELEM_TEXT57
      ,E_ELEM_TEXT58,E_ELEM_TEXT59,E_ELEM_TEXT60,E_ELEM_TEXT61
      ,E_ELEM_TEXT62,E_ELEM_TEXT63,E_ELEM_TEXT64,E_ELEM_TEXT65
      ,E_ELEM_TEXT69,E_ELEM_TEXT70,E_ELEM_TEXT77,E_ELEM_TEXT78
      ,E_ELEM_TEXT80,E_ELEM_TEXT81,E_ELEM_TEXT82,E_ELEM_TEXT84
      ,E_ELEM_TEXT88,E_ELEM_TEXT91,E_ELEM_TEXT92,E_ELEM_TEXT93
      ,E_ELEM_TEXT94,E_ELEM_TEXTPM25,E_ELEM_TEXT_AQI
      ,E_ELEM_TEXT_HUM_UNIT,E_ELEM_TEXT_MEASURE_ART
      ,E_ELEM_TEXT_MEASURING,E_ELEM_TEXT_PASSWORD,E_ELEM_TEXT_PM10
      ,E_ELEM_TEXT_PM10_UNIT,E_ELEM_TEXT_PM25_UNIT,E_ELEM_TEXT_SSID
      ,E_ELEM_TEXT_SSID_PG_WIFI,E_ELEM_TEXT_TEMP_UNIT
      ,E_ELEM_TITEL_PG_WIFI,E_ELEM_TITLE_INFO,E_ELEM_TITLE_PG_OVERVIEW
      ,E_ELEM_TIT_WIFI_PWD,E_ELEM_TOGGLE_CSV,E_ELEM_TOGGLE_DIMMER
      ,E_ELEM_TOGGLE_IOT,E_ELEM_TOGGLE_LOCK,E_ELEM_TOGGLE_MEASURE
      ,E_ELEM_UNLOCK,E_ELEM_WIFI_GAUGE,E_ELEM_WIFI_LIST
      ,E_ELEM_KEYPAD_NUM,E_ELEM_KEYPAD_ALPHA};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN5X8,E_FREESANS12,E_FREESANS9
      ,E_FREESANSBOLD12,E_FREESANSBOLD9,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                14

#define MAX_ELEM_PG_MAIN 3 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM

#define MAX_ELEM_PG_WIFI 8 // # Elems total on page
#define MAX_ELEM_PG_WIFI_RAM MAX_ELEM_PG_WIFI // # Elems in RAM

#define MAX_ELEM_PG_WIFI_PSWD 8 // # Elems total on page
#define MAX_ELEM_PG_WIFI_PSWD_RAM MAX_ELEM_PG_WIFI_PSWD // # Elems in RAM

#define MAX_ELEM_PG_OVERVIEW 29 // # Elems total on page
#define MAX_ELEM_PG_OVERVIEW_RAM MAX_ELEM_PG_OVERVIEW // # Elems in RAM

#define MAX_ELEM_PG_INFO 7 // # Elems total on page
#define MAX_ELEM_PG_INFO_RAM MAX_ELEM_PG_INFO // # Elems in RAM

#define MAX_ELEM_PG_SYS_SET 18 // # Elems total on page
#define MAX_ELEM_PG_SYS_SET_RAM MAX_ELEM_PG_SYS_SET // # Elems in RAM

#define MAX_ELEM_PG_IOT_SET 12 // # Elems total on page
#define MAX_ELEM_PG_IOT_SET_RAM MAX_ELEM_PG_IOT_SET // # Elems in RAM

#define MAX_ELEM_PG_POPUP_DIMMER 1 // # Elems total on page
#define MAX_ELEM_PG_POPUP_DIMMER_RAM MAX_ELEM_PG_POPUP_DIMMER // # Elems in RAM

#define MAX_ELEM_PG_TIME 17 // # Elems total on page
#define MAX_ELEM_PG_TIME_RAM MAX_ELEM_PG_TIME // # Elems in RAM

#define MAX_ELEM_PG_LOCK 4 // # Elems total on page
#define MAX_ELEM_PG_LOCK_RAM MAX_ELEM_PG_LOCK // # Elems in RAM

#define MAX_ELEM_PG_UPLOAD_POPUP 3 // # Elems total on page
#define MAX_ELEM_PG_UPLOAD_POPUP_RAM MAX_ELEM_PG_UPLOAD_POPUP // # Elems in RAM

#define MAX_ELEM_PG_Continuous 15 // # Elems total on page
#define MAX_ELEM_PG_Continuous_RAM MAX_ELEM_PG_Continuous // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsElem                     m_asPage2Elem[MAX_ELEM_PG_WIFI_RAM];
gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_PG_WIFI];
gslc_tsElem                     m_asPage3Elem[MAX_ELEM_PG_WIFI_PSWD_RAM];
gslc_tsElemRef                  m_asPage3ElemRef[MAX_ELEM_PG_WIFI_PSWD];
gslc_tsElem                     m_asPage4Elem[MAX_ELEM_PG_OVERVIEW_RAM];
gslc_tsElemRef                  m_asPage4ElemRef[MAX_ELEM_PG_OVERVIEW];
gslc_tsElem                     m_asPage5Elem[MAX_ELEM_PG_INFO_RAM];
gslc_tsElemRef                  m_asPage5ElemRef[MAX_ELEM_PG_INFO];
gslc_tsElem                     m_asPage6Elem[MAX_ELEM_PG_SYS_SET_RAM];
gslc_tsElemRef                  m_asPage6ElemRef[MAX_ELEM_PG_SYS_SET];
gslc_tsElem                     m_asPage7Elem[MAX_ELEM_PG_IOT_SET_RAM];
gslc_tsElemRef                  m_asPage7ElemRef[MAX_ELEM_PG_IOT_SET];
gslc_tsElem                     m_asPopup2Elem[MAX_ELEM_PG_POPUP_DIMMER_RAM];
gslc_tsElemRef                  m_asPopup2ElemRef[MAX_ELEM_PG_POPUP_DIMMER];
gslc_tsElem                     m_asPage8Elem[MAX_ELEM_PG_TIME_RAM];
gslc_tsElemRef                  m_asPage8ElemRef[MAX_ELEM_PG_TIME];
gslc_tsElem                     m_asPage9Elem[MAX_ELEM_PG_LOCK_RAM];
gslc_tsElemRef                  m_asPage9ElemRef[MAX_ELEM_PG_LOCK];
gslc_tsElem                     m_asPopup4Elem[MAX_ELEM_PG_UPLOAD_POPUP_RAM];
gslc_tsElemRef                  m_asPopup4ElemRef[MAX_ELEM_PG_UPLOAD_POPUP];
gslc_tsElem                     m_asPage10Elem[MAX_ELEM_PG_Continuous_RAM];
gslc_tsElemRef                  m_asPage10ElemRef[MAX_ELEM_PG_Continuous];
gslc_tsElem                     m_asKeypadNumElem[1];
gslc_tsElemRef                  m_asKeypadNumElemRef[1];
gslc_tsElem                     m_asKeypadAlphaElem[1];
gslc_tsElemRef                  m_asKeypadAlphaElemRef[1];
gslc_tsXKeyPad                  m_sKeyPadNum;
gslc_tsXKeyPad                  m_sKeyPadAlpha;
gslc_tsXListbox                 m_sListbox1;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf1[100 + XLISTBOX_BUF_OH_R];
gslc_tsXRingGauge               m_sXRingGauge3;
gslc_tsXTogglebtn               m_asXToggle2;
gslc_tsXRingGauge               m_sXRingGauge1;
gslc_tsXRingGauge               m_sXRingGauge2;
gslc_tsXProgress                m_sXBarGauge1;
gslc_tsXTogglebtn               m_asXToggle7;
gslc_tsXTextbox                 m_sTextbox1;
char                            m_acTextboxBuf1[780]; // NRows=13 NCols=60
gslc_tsXTogglebtn               m_asXToggle3;
gslc_tsXTogglebtn               m_asXToggle5;
gslc_tsXTogglebtn               m_asXToggle6;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemCodeIn;
extern gslc_tsElemRef* m_pElemDay;
extern gslc_tsElemRef* m_pElemHour;
extern gslc_tsElemRef* m_pElemIn_PASSWORD;
extern gslc_tsElemRef* m_pElemMinute;
extern gslc_tsElemRef* m_pElemMonth;
extern gslc_tsElemRef* m_pElemXRingGaugePM10;
extern gslc_tsElemRef* m_pElemXRingGaugePM25;
extern gslc_tsElemRef* m_pElemYear;
extern gslc_tsElemRef* m_pElem_Measuring;
extern gslc_tsElemRef* m_pElem_WIFI_LIST;
extern gslc_tsElemRef* m_pElem_aqi_val;
extern gslc_tsElemRef* m_pElem_back_WIFI_PWD;
extern gslc_tsElemRef* m_pElem_back_contin;
extern gslc_tsElemRef* m_pElem_back_info;
extern gslc_tsElemRef* m_pElem_back_iot;
extern gslc_tsElemRef* m_pElem_back_pg_wifi;
extern gslc_tsElemRef* m_pElem_back_sysset;
extern gslc_tsElemRef* m_pElem_back_time;
extern gslc_tsElemRef* m_pElem_btn_WIFI_setup;
extern gslc_tsElemRef* m_pElem_btn_dashboard;
extern gslc_tsElemRef* m_pElem_btn_home;
extern gslc_tsElemRef* m_pElem_btn_info;
extern gslc_tsElemRef* m_pElem_btn_measure;
extern gslc_tsElemRef* m_pElem_btn_save_time;
extern gslc_tsElemRef* m_pElem_con_msg;
extern gslc_tsElemRef* m_pElem_dimmer_timer;
extern gslc_tsElemRef* m_pElem_hum_val;
extern gslc_tsElemRef* m_pElem_img_nowifi;
extern gslc_tsElemRef* m_pElem_img_wifi;
extern gslc_tsElemRef* m_pElem_infobox;
extern gslc_tsElemRef* m_pElem_label_measure_art;
extern gslc_tsElemRef* m_pElem_label_measure_art38_39;
extern gslc_tsElemRef* m_pElem_label_measure_art77;
extern gslc_tsElemRef* m_pElem_label_pg_wifi_pwd;
extern gslc_tsElemRef* m_pElem_meas_interval;
extern gslc_tsElemRef* m_pElem_pm10_cont_max;
extern gslc_tsElemRef* m_pElem_pm10_continuous;
extern gslc_tsElemRef* m_pElem_pm10_value;
extern gslc_tsElemRef* m_pElem_pm25_cont_max;
extern gslc_tsElemRef* m_pElem_pm25_continuous;
extern gslc_tsElemRef* m_pElem_pm25_value;
extern gslc_tsElemRef* m_pElem_progress_measure;
extern gslc_tsElemRef* m_pElem_selected_ssid;
extern gslc_tsElemRef* m_pElem_temp_value;
extern gslc_tsElemRef* m_pElem_toggle_IoT;
extern gslc_tsElemRef* m_pElem_toggle_csv;
extern gslc_tsElemRef* m_pElem_toggle_dimmer;
extern gslc_tsElemRef* m_pElem_toggle_lock;
extern gslc_tsElemRef* m_pElem_toggle_measure;
extern gslc_tsElemRef* m_pElem_unlock;
extern gslc_tsElemRef* m_pElem_wifi_gauge;
extern gslc_tsElemRef* m_pListSlider1;
extern gslc_tsElemRef* m_pTextSlider1;
extern gslc_tsElemRef* popup_line1;
extern gslc_tsElemRef* popup_line2;
extern gslc_tsElemRef* m_pElemKeyPadNum;
extern gslc_tsElemRef* m_pElemKeyPadAlpha;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN10X16,GSLC_FONTREF_PTR,NULL,2)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANS12,GSLC_FONTREF_PTR,&FreeSans12pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANS9,GSLC_FONTREF_PTR,&FreeSans9pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD12,GSLC_FONTREF_PTR,&FreeSansBold12pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD9,GSLC_FONTREF_PTR,&FreeSansBold9pt7b,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);
  gslc_PageAdd(&m_gui,E_PG_WIFI,m_asPage2Elem,MAX_ELEM_PG_WIFI_RAM,m_asPage2ElemRef,MAX_ELEM_PG_WIFI);
  gslc_PageAdd(&m_gui,E_PG_WIFI_PSWD,m_asPage3Elem,MAX_ELEM_PG_WIFI_PSWD_RAM,m_asPage3ElemRef,MAX_ELEM_PG_WIFI_PSWD);
  gslc_PageAdd(&m_gui,E_PG_OVERVIEW,m_asPage4Elem,MAX_ELEM_PG_OVERVIEW_RAM,m_asPage4ElemRef,MAX_ELEM_PG_OVERVIEW);
  gslc_PageAdd(&m_gui,E_PG_INFO,m_asPage5Elem,MAX_ELEM_PG_INFO_RAM,m_asPage5ElemRef,MAX_ELEM_PG_INFO);
  gslc_PageAdd(&m_gui,E_PG_SYS_SET,m_asPage6Elem,MAX_ELEM_PG_SYS_SET_RAM,m_asPage6ElemRef,MAX_ELEM_PG_SYS_SET);
  gslc_PageAdd(&m_gui,E_PG_IOT_SET,m_asPage7Elem,MAX_ELEM_PG_IOT_SET_RAM,m_asPage7ElemRef,MAX_ELEM_PG_IOT_SET);
  gslc_PageAdd(&m_gui,E_PG_POPUP_DIMMER,m_asPopup2Elem,MAX_ELEM_PG_POPUP_DIMMER_RAM,m_asPopup2ElemRef,MAX_ELEM_PG_POPUP_DIMMER);
  gslc_PageAdd(&m_gui,E_PG_TIME,m_asPage8Elem,MAX_ELEM_PG_TIME_RAM,m_asPage8ElemRef,MAX_ELEM_PG_TIME);
  gslc_PageAdd(&m_gui,E_PG_LOCK,m_asPage9Elem,MAX_ELEM_PG_LOCK_RAM,m_asPage9ElemRef,MAX_ELEM_PG_LOCK);
  gslc_PageAdd(&m_gui,E_PG_UPLOAD_POPUP,m_asPopup4Elem,MAX_ELEM_PG_UPLOAD_POPUP_RAM,m_asPopup4ElemRef,MAX_ELEM_PG_UPLOAD_POPUP);
  gslc_PageAdd(&m_gui,E_PG_Continuous,m_asPage10Elem,MAX_ELEM_PG_Continuous_RAM,m_asPage10ElemRef,MAX_ELEM_PG_Continuous);
  gslc_PageAdd(&m_gui,E_POP_KEYPAD_NUM,m_asKeypadNumElem,1,m_asKeypadNumElemRef,1);  // KeyPad
  gslc_PageAdd(&m_gui,E_POP_KEYPAD_ALPHA,m_asKeypadAlphaElem,1,m_asKeypadAlphaElemRef,1);  // KeyPad

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);
  
  // Set Background to an image
  gslc_SetBkgndImage(&m_gui,gslc_GetImageFromFile(IMG_BKGND,GSLC_IMGREF_FMT_BMP24));

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  
  // Create E_ELEM_BTN_WIFI_SETUP button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BTN_WIFI_SETUP,E_PG_MAIN,(gslc_tsRect){250,170,64,64},
          gslc_GetImageFromFile(IMG_WIFI_SETUP,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_WIFI_SETUP_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_WIFI_setup = pElemRef;
  
  // Create E_ELEM_BTN_dashboard button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BTN_dashboard,E_PG_MAIN,(gslc_tsRect){8,170,64,64},
          gslc_GetImageFromFile(IMG_DASHBOARD,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_DASHBOARD_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_dashboard = pElemRef;
  
  // Create E_ELEM_BTN_INFO button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BTN_INFO,E_PG_MAIN,(gslc_tsRect){128,170,64,64},
          gslc_GetImageFromFile(IMG_INFO,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_INFO_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_info = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_WIFI
  
  
  // create E_ELEM_BTN_SCAN_WIFI button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_SCAN_WIFI,E_PG_WIFI,
    (gslc_tsRect){5,50,95,24},(char*)"Scan",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TITEL_PG_WIFI text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITEL_PG_WIFI,E_PG_WIFI,(gslc_tsRect){0,0,320,30},
    (char*)"Network settings",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
   
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ELEM_WIFI_LIST,E_PG_WIFI,&m_sListbox1,
    (gslc_tsRect){110,50,200,120},E_BUILTIN5X8,
    (uint8_t*)&m_acListboxBuf1,sizeof(m_acListboxBuf1),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 6, 1); // 6 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, XLISTBOX_SIZE_AUTO, XLISTBOX_SIZE_AUTO);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 0);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  m_pElem_WIFI_LIST = pElemRef;
  
  // create E_ELEM_BTN_WIFI_CONNECT button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_WIFI_CONNECT,E_PG_WIFI,
    (gslc_tsRect){5,90,95,24},(char*)"Connect",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TEXT_SSID_PG_WIFI text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_SSID_PG_WIFI,E_PG_WIFI,(gslc_tsRect){20,180,61,18},
    (char*)"SSID:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_LABEL_SSID_PG_WIFI runtime modifiable text
  static char m_sDisplayText3[26] = "Nothing selected";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_LABEL_SSID_PG_WIFI,E_PG_WIFI,(gslc_tsRect){110,176,151,24},
    (char*)m_sDisplayText3,26,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_selected_ssid = pElemRef;
  
  // Create E_ELEM_BACK_PG_WIFI button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BACK_PG_WIFI,E_PG_WIFI,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_back_pg_wifi = pElemRef;

  // Create ring gauge E_ELEM_WIFI_GAUGE 
  static char m_sRingText3[2] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ELEM_WIFI_GAUGE,E_PG_WIFI,&m_sXRingGauge3,
          (gslc_tsRect){176,76,70,70},
          (char*)m_sRingText3,2,E_BUILTIN5X8);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 360);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetThickness(&m_gui,pElemRef, 8);
  gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui,pElemRef, GSLC_COL_GREEN_DK1);
  gslc_ElemXRingGaugeSetColorInactive(&m_gui,pElemRef, GSLC_COL_GRAY_LT3);
  m_pElem_wifi_gauge = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_WIFI_PSWD
  
  
  // Create E_ELEM_PSWD_INPUT text input field
  static char m_sInputText2[51] = "---";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_PSWD_INPUT,E_PG_WIFI_PSWD,(gslc_tsRect){115,75,200,22},
    (char*)m_sInputText2,51,E_BUILTIN5X8);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElemIn_PASSWORD = pElemRef;
  
  // Create E_ELEM_TIT_WIFI_PWD text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TIT_WIFI_PWD,E_PG_WIFI_PSWD,(gslc_tsRect){0,0,320,30},
    (char*)"Network settings",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_SSID text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_SSID,E_PG_WIFI_PSWD,(gslc_tsRect){20,50,50,17},
    (char*)"SSID:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PASSWORD text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PASSWORD,E_PG_WIFI_PSWD,(gslc_tsRect){4,75,100,18},
    (char*)"Password:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_LABEL_SSID_PG_WIFI_PWD runtime modifiable text
  static char m_sDisplayText12[26] = "Nothing selected";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_LABEL_SSID_PG_WIFI_PWD,E_PG_WIFI_PSWD,(gslc_tsRect){115,48,205,22},
    (char*)m_sDisplayText12,26,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_label_pg_wifi_pwd = pElemRef;
  
  // create E_ELEM_BTN_CONNECT button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_CONNECT,E_PG_WIFI_PSWD,
    (gslc_tsRect){115,110,95,24},(char*)"Connect",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_CON_MSG runtime modifiable text
  static char m_sDisplayText13[51] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_CON_MSG,E_PG_WIFI_PSWD,(gslc_tsRect){10,150,300,22},
    (char*)m_sDisplayText13,51,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_con_msg = pElemRef;
  
  // Create E_ELEM_BACK_WIFI_PWD button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BACK_WIFI_PWD,E_PG_WIFI_PSWD,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_back_WIFI_PWD = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_OVERVIEW
  
  
  // Create E_ELEM_TITLE_PG_OVERVIEW text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITLE_PG_OVERVIEW,E_PG_OVERVIEW,(gslc_tsRect){0,0,320,30},
    (char*)"Air quality",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PM10 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PM10,E_PG_OVERVIEW,(gslc_tsRect){0,34,160,16},
    (char*)"PM 10",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXTPM25 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXTPM25,E_PG_OVERVIEW,(gslc_tsRect){160,34,160,16},
    (char*)"PM 2.5",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create toggle button E_ELEM_TOGGLE_MEASURE
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE_MEASURE,E_PG_OVERVIEW,&m_asXToggle2,
    (gslc_tsRect){190,120,40,18},GSLC_COL_GRAY,GSLC_COL_GREEN_DK1,GSLC_COL_GRAY_LT2,
    true,false,&CbBtnCommon);
  m_pElem_toggle_measure = pElemRef;
  
  // Create E_ELEM_PM10_VALUE runtime modifiable text
  static char m_sDisplayText17[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_PM10_VALUE,E_PG_OVERVIEW,(gslc_tsRect){35,60,51,20},
    (char*)m_sDisplayText17,5,E_FREESANS12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_pm10_value = pElemRef;
  
  // Create E_ELEM_PM25_VALUE runtime modifiable text
  static char m_sDisplayText18[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_PM25_VALUE,E_PG_OVERVIEW,(gslc_tsRect){195,60,51,20},
    (char*)m_sDisplayText18,5,E_FREESANS12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_pm25_value = pElemRef;
  
  // Create E_ELEM_TEXT_MEASURE_ART text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_MEASURE_ART,E_PG_OVERVIEW,(gslc_tsRect){240,120,43,18},
    (char*)"Average",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_label_measure_art = pElemRef;

  // Create E_DRAW_LINE1 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE1,E_PG_OVERVIEW,2,120,157,120);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_AQI runtime modifiable text
  static char m_sDisplayText22[15] = "Good";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_AQI,E_PG_OVERVIEW,(gslc_tsRect){60,95,209,20},
    (char*)m_sDisplayText22,15,E_FREESANSBOLD12);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_aqi_val = pElemRef;
  
  // Create E_ELEM_TEMP_VALUE runtime modifiable text
  static char m_sDisplayText24[6] = "23.5";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEMP_VALUE,E_PG_OVERVIEW,(gslc_tsRect){60,134,61,18},
    (char*)m_sDisplayText24,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_temp_value = pElemRef;
  
  // Create E_ELEM_HUM_VALUE runtime modifiable text
  static char m_sDisplayText25[6] = "48.2";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_HUM_VALUE,E_PG_OVERVIEW,(gslc_tsRect){60,170,61,18},
    (char*)m_sDisplayText25,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_hum_val = pElemRef;
  
  // Create E_ELEM_TEXT_TEMP_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_TEMP_UNIT,E_PG_OVERVIEW,(gslc_tsRect){120,134,13,18},
    (char*)"C",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_HUM_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_HUM_UNIT,E_PG_OVERVIEW,(gslc_tsRect){120,170,16,18},
    (char*)"%",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PM10_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PM10_UNIT,E_PG_OVERVIEW,(gslc_tsRect){90,65,31,20},
    (char*)"ug/m3",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PM25_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PM25_UNIT,E_PG_OVERVIEW,(gslc_tsRect){250,65,31,20},
    (char*)"ug/m3",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);

  // Create ring gauge E_ELEM_RINGGAUGE_PM25 
  static char m_sRingText1[11] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ELEM_RINGGAUGE_PM25,E_PG_OVERVIEW,&m_sXRingGauge1,
          (gslc_tsRect){225,10,90,90},
          (char*)m_sRingText1,11,E_BUILTIN10X16);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 25);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetThickness(&m_gui,pElemRef, 12);
  gslc_ElemXRingGaugeSetAngleRange(&m_gui,pElemRef, 130, -130, false);
  gslc_ElemXRingGaugeSetColorActiveGradient(&m_gui, pElemRef, GSLC_COL_GREEN_DK1, GSLC_COL_RED);
  gslc_ElemXRingGaugeSetColorInactive(&m_gui,pElemRef, GSLC_COL_GRAY_LT2);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  m_pElemXRingGaugePM25 = pElemRef;

  // Create ring gauge E_ELEM_RINGGAUGE_PM10 
  static char m_sRingText2[11] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ELEM_RINGGAUGE_PM10,E_PG_OVERVIEW,&m_sXRingGauge2,
          (gslc_tsRect){5,10,90,90},
          (char*)m_sRingText2,11,E_BUILTIN10X16);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 25);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetThickness(&m_gui,pElemRef, 12);
  gslc_ElemXRingGaugeSetAngleRange(&m_gui,pElemRef, 230, 130, false);
  gslc_ElemXRingGaugeSetColorActiveGradient(&m_gui, pElemRef, GSLC_COL_GREEN_DK1, GSLC_COL_RED);
  gslc_ElemXRingGaugeSetColorInactive(&m_gui,pElemRef, GSLC_COL_GRAY_LT2);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  m_pElemXRingGaugePM10 = pElemRef;

  // Create progress bar E_ELEM_PROGRESS_MEASURE 
  pElemRef = gslc_ElemXProgressCreate(&m_gui,E_ELEM_PROGRESS_MEASURE,E_PG_OVERVIEW,&m_sXBarGauge1,
    (gslc_tsRect){100,222,120,12},0,400,0,GSLC_COL_GREEN_DK1,false);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK1,GSLC_COL_GRAY_LT2,GSLC_COL_WHITE);
  m_pElem_progress_measure = pElemRef;
  
  // Create E_ELEM_TEXT_MEASURING text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_MEASURING,E_PG_OVERVIEW,(gslc_tsRect){100,212,120,10},
    (char*)"Measuring",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  m_pElem_Measuring = pElemRef;
  
  // Create E_ELEM_TEXT_AQI text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_AQI,E_PG_OVERVIEW,(gslc_tsRect){8,95,35,20},
    (char*)"AQI:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
 
  // Create E_ELEM_IMG_NOWIFI using Image 
  pElemRef = gslc_ElemCreateImg(&m_gui,E_ELEM_IMG_NOWIFI,E_PG_OVERVIEW,(gslc_tsRect){144,40,32,32},
    gslc_GetImageFromFile(IMG_NOWIFI,GSLC_IMGREF_FMT_BMP24));
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_img_nowifi = pElemRef;
 
  // Create E_ELEM_IMG_WIFI using Image 
  pElemRef = gslc_ElemCreateImg(&m_gui,E_ELEM_IMG_WIFI,E_PG_OVERVIEW,(gslc_tsRect){144,40,32,32},
    gslc_GetImageFromFile(IMG_WIFI,GSLC_IMGREF_FMT_BMP24));
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_img_wifi = pElemRef;
  
  // Create E_ELEM_MEASURE_BTN button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_MEASURE_BTN,E_PG_OVERVIEW,(gslc_tsRect){4,206,32,32},
          gslc_GetImageFromFile(IMG_REUSE,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_REUSE,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_measure = pElemRef;
  
  // Create E_ELEM_HOME_BTN button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_HOME_BTN,E_PG_OVERVIEW,(gslc_tsRect){284,206,32,32},
          gslc_GetImageFromFile(IMG_CONTROL,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_CONTROL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_home = pElemRef;
 
  // Create E_ELEM_IMAGE6 using Image 
  pElemRef = gslc_ElemCreateImg(&m_gui,E_ELEM_IMAGE6,E_PG_OVERVIEW,(gslc_tsRect){6,128,32,32},
    gslc_GetImageFromFile(IMG_TMP_1,GSLC_IMGREF_FMT_BMP24));
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
 
  // Create E_ELEM_IMAGE8 using Image 
  pElemRef = gslc_ElemCreateImg(&m_gui,E_ELEM_IMAGE8,E_PG_OVERVIEW,(gslc_tsRect){20,160,32,32},
    gslc_GetImageFromFile(IMG_HUM,GSLC_IMGREF_FMT_BMP24));
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);

  // Create E_DRAW_LINE3 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE3,E_PG_OVERVIEW,58,160,158,160);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_TEXT77 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT77,E_PG_OVERVIEW,(gslc_tsRect){240,143,67,20},
    (char*)"Lock screen",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_label_measure_art77 = pElemRef;
  
  // Create toggle button E_ELEM_TOGGLE_LOCK
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE_LOCK,E_PG_OVERVIEW,&m_asXToggle7,
    (gslc_tsRect){190,143,40,18},GSLC_COL_GRAY,GSLC_COL_GREEN_DK1,GSLC_COL_GRAY_LT2,
    true,false,&CbBtnCommon);
  m_pElem_toggle_lock = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_INFO
  
   
  // Create textbox
  pElemRef = gslc_ElemXTextboxCreate(&m_gui,E_ELEM_INFOBOX,E_PG_INFO,&m_sTextbox1,
    (gslc_tsRect){10,35,300,130},E_BUILTIN5X8,
    (char*)&m_acTextboxBuf1,13,60);
  gslc_ElemXTextboxWrapSet(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT3,GSLC_COL_GRAY_LT3);
  m_pElem_infobox = pElemRef;
  
  // Create E_ELEM_TITLE_INFO text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITLE_INFO,E_PG_INFO,(gslc_tsRect){0,0,320,30},
    (char*)"Info",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // create E_ELEM_BTN_SYS_SET button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_SYS_SET,E_PG_INFO,
    (gslc_tsRect){55,205,90,24},(char*)"System",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // create E_ELEM_BTN_IOT_SET button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_IOT_SET,E_PG_INFO,
    (gslc_tsRect){175,205,90,24},(char*)"IoT",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TEXT33 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT33,E_PG_INFO,(gslc_tsRect){0,165,320,30},
    (char*)"Settings",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);

  // Create E_DRAW_LINE4 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE4,E_PG_INFO,50,199,270,199);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_BACK_INFO button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BACK_INFO,E_PG_INFO,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_back_info = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_SYS_SET
  
  
  // Create E_ELEM_TEXT34 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT34,E_PG_SYS_SET,(gslc_tsRect){0,0,320,30},
    (char*)"System settings",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_DIMMER_TIMER numeric input field
  static char m_sInputNumber1[4] = "1";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_DIMMER_TIMER,E_PG_SYS_SET,(gslc_tsRect){130,60,27,15},
    (char*)m_sInputNumber1,4,E_BUILTIN5X8);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,10);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_GRAY_LT3,GSLC_COL_GRAY_LT2);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElem_dimmer_timer = pElemRef;
  
  // Create E_ELEM_TEXT36 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT36,E_PG_SYS_SET,(gslc_tsRect){10,30,124,23},
    (char*)"Display dimmer",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_TEXT37 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT37,E_PG_SYS_SET,(gslc_tsRect){160,60,25,15},
    (char*)"sec.",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create toggle button E_ELEM_TOGGLE_DIMMER
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE_DIMMER,E_PG_SYS_SET,&m_asXToggle3,
    (gslc_tsRect){18,60,45,18},GSLC_COL_GRAY,GSLC_COL_GREEN_DK1,GSLC_COL_GRAY_LT2,
    true,false,&CbBtnCommon);
  m_pElem_toggle_dimmer = pElemRef;
  
  // Create E_ELEM_TEXT39 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT39,E_PG_SYS_SET,(gslc_tsRect){90,60,37,15},
    (char*)"Timer:",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_label_measure_art38_39 = pElemRef;

  // Create E_DRAW_LINE5 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE5,E_PG_SYS_SET,10,55,240,55);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // create E_ELEM_DIM_ON button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_DIM_ON,E_PG_SYS_SET,
    (gslc_tsRect){210,60,60,18},(char*)"Dim now",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_BACK_SYSSET button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BACK_SYSSET,E_PG_SYS_SET,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_back_sysset = pElemRef;
  
  // Create E_ELEM_TEXT45 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT45,E_PG_SYS_SET,(gslc_tsRect){10,100,153,23},
    (char*)"Measurement Data",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);

  // Create E_DRAW_LINE8 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE8,E_PG_SYS_SET,10,125,240,125);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // create E_ELEM_DEL_DATA button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_DEL_DATA,E_PG_SYS_SET,
    (gslc_tsRect){10,130,70,18},(char*)"Reset data",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // create E_ELEM_PRINT_DATA button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_PRINT_DATA,E_PG_SYS_SET,
    (gslc_tsRect){90,130,70,18},(char*)"Print data",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create toggle button E_ELEM_TOGGLE_CSV
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE_CSV,E_PG_SYS_SET,&m_asXToggle5,
    (gslc_tsRect){200,130,40,18},GSLC_COL_GRAY,GSLC_COL_GREEN_DK1,GSLC_COL_GRAY_LT2,
    true,true,&CbBtnCommon);
  m_pElem_toggle_csv = pElemRef;
  
  // Create E_ELEM_TEXT55 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT55,E_PG_SYS_SET,(gslc_tsRect){188,148,61,10},
    (char*)"Store data",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // create E_ELEM_SHUTDOWN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_SHUTDOWN,E_PG_SYS_SET,
    (gslc_tsRect){240,210,70,25},(char*)"Shutdown",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_RED,GSLC_COL_BROWN,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create E_ELEM_SAVE_SET button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_SAVE_SET,E_PG_SYS_SET,
    (gslc_tsRect){130,210,90,25},(char*)"Save settings",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // create E_ELEM_BTN_CONTINUOUS button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_CONTINUOUS,E_PG_SYS_SET,
    (gslc_tsRect){10,158,150,18},(char*)"Continuous measure mode",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);

  // -----------------------------------
  // PAGE: E_PG_IOT_SET
  
  
  // Create E_ELEM_TEXT41 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT41,E_PG_IOT_SET,(gslc_tsRect){0,0,320,30},
    (char*)"IoT settings",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT42 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT42,E_PG_IOT_SET,(gslc_tsRect){10,30,230,23},
    (char*)"Timer",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);

  // Create E_DRAW_LINE6 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE6,E_PG_IOT_SET,10,55,240,55);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_TEXT43 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT43,E_PG_IOT_SET,(gslc_tsRect){10,60,103,15},
    (char*)"Measure interval:",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_MEAS_INTERVAL numeric input field
  static char m_sInputNumber2[3] = "1";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MEAS_INTERVAL,E_PG_IOT_SET,(gslc_tsRect){120,60,27,15},
    (char*)m_sInputNumber2,3,E_BUILTIN5X8);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,10);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_GRAY_LT3,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElem_meas_interval = pElemRef;
  
  // Create E_ELEM_TEXT44 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT44,E_PG_IOT_SET,(gslc_tsRect){150,60,25,15},
    (char*)"min.",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_BACK_IOT button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BACK_IOT,E_PG_IOT_SET,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_back_iot = pElemRef;
  
  // Create toggle button E_ELEM_TOGGLE_IOT
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE_IOT,E_PG_IOT_SET,&m_asXToggle6,
    (gslc_tsRect){25,134,40,18},GSLC_COL_GRAY,GSLC_COL_GREEN_DK1,GSLC_COL_GRAY_LT2,
    true,true,&CbBtnCommon);
  m_pElem_toggle_IoT = pElemRef;
  
  // Create E_ELEM_TEXT56 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT56,E_PG_IOT_SET,(gslc_tsRect){10,154,73,10},
    (char*)"Cloud upload",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // create E_ELEM_BTN_SETTIME button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_SETTIME,E_PG_IOT_SET,
    (gslc_tsRect){120,134,100,18},(char*)"Set date&time",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TEXT57 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT57,E_PG_IOT_SET,(gslc_tsRect){10,100,46,23},
    (char*)"Cloud",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);

  // Create E_DRAW_LINE11 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE11,E_PG_IOT_SET,10,126,240,126);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);

  // -----------------------------------
  // PAGE: E_PG_POPUP_DIMMER
  
  
  // create E_ELEM_DIM_OFF button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_DIM_OFF,E_PG_POPUP_DIMMER,
    (gslc_tsRect){0,0,320,240},(char*)".",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);

  // -----------------------------------
  // PAGE: E_PG_TIME
  
  
  // Create E_ELEM_TEXT58 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT58,E_PG_TIME,(gslc_tsRect){0,0,320,30},
    (char*)"Setup date & time",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT59 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT59,E_PG_TIME,(gslc_tsRect){10,45,37,15},
    (char*)"Date",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);

  // Create E_DRAW_LINE12 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE12,E_PG_TIME,10,63,240,63);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_TEXT60 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT60,E_PG_TIME,(gslc_tsRect){10,80,35,15},
    (char*)"Day:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_NUM_DAY numeric input field
  static char m_sInputNumber8[3] = "06";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUM_DAY,E_PG_TIME,(gslc_tsRect){52,73,30,30},
    (char*)m_sInputNumber8,3,E_FREESANS9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_GRAY_LT3,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemDay = pElemRef;
  
  // Create E_ELEM_TEXT61 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT61,E_PG_TIME,(gslc_tsRect){100,80,53,15},
    (char*)"Month:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_NUM_MONTH numeric input field
  static char m_sInputNumber9[3] = "06";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUM_MONTH,E_PG_TIME,(gslc_tsRect){160,73,30,30},
    (char*)m_sInputNumber9,3,E_FREESANS9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_GRAY_LT3,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemMonth = pElemRef;
  
  // Create E_ELEM_TEXT62 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT62,E_PG_TIME,(gslc_tsRect){205,80,42,15},
    (char*)"Year:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_NUM_YEAR numeric input field
  static char m_sInputNumber10[5] = "2022";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUM_YEAR,E_PG_TIME,(gslc_tsRect){255,73,50,30},
    (char*)m_sInputNumber10,5,E_FREESANS9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_GRAY_LT3,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemYear = pElemRef;
  
  // Create E_ELEM_TEXT63 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT63,E_PG_TIME,(gslc_tsRect){10,130,39,15},
    (char*)"Time",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);

  // Create E_DRAW_LINE13 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE13,E_PG_TIME,10,147,240,147);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_TEXT64 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT64,E_PG_TIME,(gslc_tsRect){10,162,42,15},
    (char*)"Hour:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_NUM_HOUR numeric input field
  static char m_sInputNumber11[3] = "11";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUM_HOUR,E_PG_TIME,(gslc_tsRect){60,155,30,30},
    (char*)m_sInputNumber11,3,E_FREESANS9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_GRAY_LT3,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemHour = pElemRef;
  
  // Create E_ELEM_TEXT65 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT65,E_PG_TIME,(gslc_tsRect){120,162,57,15},
    (char*)"Minute:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  
  // Create E_ELEM_NUM_MINUTE numeric input field
  static char m_sInputNumber12[3] = "15";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_NUM_MINUTE,E_PG_TIME,(gslc_tsRect){184,155,30,30},
    (char*)m_sInputNumber12,3,E_FREESANS9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_GRAY_LT3,GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemMinute = pElemRef;
  
  // create E_ELEM_BTN_SAVE_TIME button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_SAVE_TIME,E_PG_TIME,
    (gslc_tsRect){220,205,95,32},(char*)"Save",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_GREEN_DK2,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  m_pElem_btn_save_time = pElemRef;
  
  // Create E_ELEM_BACK_TIME button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BACK_TIME,E_PG_TIME,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_back_time = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_LOCK
  
  
  // Create E_ELEM_TEXT69 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT69,E_PG_LOCK,(gslc_tsRect){0,0,320,30},
    (char*)"Screen locked!",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT70 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT70,E_PG_LOCK,(gslc_tsRect){84,60,152,15},
    (char*)"Enter code >0628<",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_CODE_INPUT numeric input field
  static char m_sInputNumber14[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_CODE_INPUT,E_PG_LOCK,(gslc_tsRect){125,100,70,30},
    (char*)m_sInputNumber14,5,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_MAGENTA);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT3,GSLC_COL_GRAY_LT2);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemCodeIn = pElemRef;
  
  // create E_ELEM_UNLOCK button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_UNLOCK,E_PG_LOCK,
    (gslc_tsRect){112,170,95,32},(char*)"Unlock",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_GREEN_DK2,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  m_pElem_unlock = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_UPLOAD_POPUP
  
   
  // Create E_ELEM_BOX2 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX2,E_PG_UPLOAD_POPUP,(gslc_tsRect){10,50,300,80});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_LT3,GSLC_COL_GRAY_LT3,GSLC_COL_GRAY_LT3);
  
  // Create E_ELEM_POPUP_L2 runtime modifiable text
  static char m_sDisplayText75[26] = "Please wait...";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_POPUP_L2,E_PG_UPLOAD_POPUP,(gslc_tsRect){43,95,234,20},
    (char*)m_sDisplayText75,26,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GREEN_DK1);
  popup_line2 = pElemRef;
  
  // Create E_ELEM_POPUP_L1 runtime modifiable text
  static char m_sDisplayText76[26] = "Uploading / saving data!";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_POPUP_L1,E_PG_UPLOAD_POPUP,(gslc_tsRect){8,60,303,20},
    (char*)m_sDisplayText76,26,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GREEN_DK1);
  popup_line1 = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_Continuous
  
  
  // Create E_ELEM_TEXT78 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT78,E_PG_Continuous,(gslc_tsRect){0,0,320,30},
    (char*)"Continuous measuring",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_PM10_continuous runtime modifiable text
  static char m_sDisplayText79[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_PM10_continuous,E_PG_Continuous,(gslc_tsRect){35,80,51,20},
    (char*)m_sDisplayText79,5,E_FREESANS12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  m_pElem_pm10_continuous = pElemRef;
  
  // Create E_ELEM_TEXT80 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT80,E_PG_Continuous,(gslc_tsRect){95,80,31,20},
    (char*)"ug/m3",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT81 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT81,E_PG_Continuous,(gslc_tsRect){0,50,160,16},
    (char*)"PM 10",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT82 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT82,E_PG_Continuous,(gslc_tsRect){160,50,160,18},
    (char*)"PM 25",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_PM25_continuous runtime modifiable text
  static char m_sDisplayText83[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_PM25_continuous,E_PG_Continuous,(gslc_tsRect){200,80,51,20},
    (char*)m_sDisplayText83,5,E_FREESANS12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  m_pElem_pm25_continuous = pElemRef;
  
  // Create E_ELEM_TEXT84 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT84,E_PG_Continuous,(gslc_tsRect){260,80,31,20},
    (char*)"ug/m3",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);

  // Create E_DRAW_LINE14 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE14,E_PG_Continuous,160,50,160,100);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);

  // Create E_DRAW_LINE15 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE15,E_PG_Continuous,20,110,300,110);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_BACK_CONTIN button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BACK_CONTIN,E_PG_Continuous,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_back_contin = pElemRef;
  
  // Create E_ELEM_TEXT88 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT88,E_PG_Continuous,(gslc_tsRect){0,120,320,18},
    (char*)"Max",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT91 runtime modifiable text
  static char m_sDisplayText91[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT91,E_PG_Continuous,(gslc_tsRect){35,150,51,20},
    (char*)m_sDisplayText91,5,E_FREESANS12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  m_pElem_pm10_cont_max = pElemRef;
  
  // Create E_ELEM_TEXT92 runtime modifiable text
  static char m_sDisplayText92[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT92,E_PG_Continuous,(gslc_tsRect){200,150,51,20},
    (char*)m_sDisplayText92,5,E_FREESANS12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  m_pElem_pm25_cont_max = pElemRef;
  
  // Create E_ELEM_TEXT93 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT93,E_PG_Continuous,(gslc_tsRect){260,150,31,20},
    (char*)"ug/m3",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT94 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT94,E_PG_Continuous,(gslc_tsRect){95,150,31,20},
    (char*)"ug/m3",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_BOT_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: E_POP_KEYPAD_NUM
  
  static gslc_tsXKeyPadCfg_Num sCfg;
  sCfg = gslc_ElemXKeyPadCfgInit_Num();
  gslc_ElemXKeyPadCfgSetFloatEn_Num(&sCfg, false);
  gslc_ElemXKeyPadCfgSetSignEn_Num(&sCfg, false);
  gslc_ElemXKeyPadCfgSetButtonSz((gslc_tsXKeyPadCfg*)&sCfg, 40, 40);
  gslc_ElemXKeyPadCfgSetButtonSpace((gslc_tsXKeyPadCfg*)&sCfg, 3, 3);
  m_pElemKeyPadNum = gslc_ElemXKeyPadCreate_Num(&m_gui, E_ELEM_KEYPAD_NUM, E_POP_KEYPAD_NUM,
    &m_sKeyPadNum, 0, 75, E_BUILTIN5X8, &sCfg);
  gslc_ElemXKeyPadValSetCb(&m_gui, m_pElemKeyPadNum, &CbKeypad);

  // -----------------------------------
  // PAGE: E_POP_KEYPAD_ALPHA
  
  static gslc_tsXKeyPadCfg_Alpha sCfgTx;
  sCfgTx = gslc_ElemXKeyPadCfgInit_Alpha();
  gslc_ElemXKeyPadCfgSetButtonSz((gslc_tsXKeyPadCfg*)&sCfgTx, 16, 32);
  gslc_ElemXKeyPadCfgSetButtonSpace((gslc_tsXKeyPadCfg*)&sCfgTx, 1, 3);
  m_pElemKeyPadAlpha = gslc_ElemXKeyPadCreate_Alpha(&m_gui, E_ELEM_KEYPAD_ALPHA, E_POP_KEYPAD_ALPHA,
    &m_sKeyPadAlpha, 0, 55, E_BUILTIN5X8, &sCfgTx);
  gslc_ElemXKeyPadValSetCb(&m_gui, m_pElemKeyPadAlpha, &CbKeypad);
//<InitGUI !End!>

//<Startup !Start!>
  gslc_SetTransparentColor(&m_gui, GSLC_COL_WHITE);
  gslc_GuiRotate(&m_gui, 1);
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
