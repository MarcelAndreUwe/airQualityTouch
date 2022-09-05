//<File !Start!>
// FILE: [test2_GSLC.h]
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
#include "elem/XListbox.h"
#include "elem/XProgress.h"
#include "elem/XRingGauge.h"
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
enum {E_PG_MAIN,E_PG_WIFI,E_PG_WIFI_PSWD,E_PG_OVERVIEW
      ,E_POP_KEYPAD_ALPHA};
enum {E_DRAW_LINE1,E_DRAW_LINE2,E_DRAW_LINE3,E_ELEM_AQI
      ,E_ELEM_BTN_BACK_PG_WIFI,E_ELEM_BTN_BACK_PG_WIFI_PWD
      ,E_ELEM_BTN_CONNECT,E_ELEM_BTN_INFO,E_ELEM_BTN_SCAN_WIFI
      ,E_ELEM_BTN_WIFI_CONNECT,E_ELEM_BTN_WIFI_SETUP
      ,E_ELEM_BTN_dashboard,E_ELEM_CON_MSG,E_ELEM_HUM_VALUE
      ,E_ELEM_IMAGE6,E_ELEM_IMAGE8,E_ELEM_IMG_NOWIFI,E_ELEM_IMG_WIFI
      ,E_ELEM_LABEL_SSID_PG_WIFI,E_ELEM_LABEL_SSID_PG_WIFI_PWD
      ,E_ELEM_MEASURE_BTN,E_ELEM_PM10_VALUE,E_ELEM_PM25_VALUE
      ,E_ELEM_PROGRESS_MEASURE,E_ELEM_PSWD_INPUT,E_ELEM_RINGGAUGE_PM10
      ,E_ELEM_RINGGAUGE_PM25,E_ELEM_SETTINGS_BTN,E_ELEM_TEMP_VALUE
      ,E_ELEM_TEXTPM25,E_ELEM_TEXT_AQI,E_ELEM_TEXT_HUM_UNIT
      ,E_ELEM_TEXT_MEASURE_ART,E_ELEM_TEXT_MEASURING
      ,E_ELEM_TEXT_PASSWORD,E_ELEM_TEXT_PM10,E_ELEM_TEXT_PM10_UNIT
      ,E_ELEM_TEXT_PM25_UNIT,E_ELEM_TEXT_SSID,E_ELEM_TEXT_SSID_PG_WIFI
      ,E_ELEM_TEXT_TEMP_UNIT,E_ELEM_TITEL_PG_WIFI
      ,E_ELEM_TITEL_PG_WIFI_PWD,E_ELEM_TITLE_PG_OVERVIEW
      ,E_ELEM_TOGGLE_MEASURE,E_ELEM_WIFI_GAUGE,E_ELEM_WIFI_LIST
      ,E_ELEM_KEYPAD_ALPHA};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN15X24,E_BUILTIN5X8,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                5

#define MAX_ELEM_PG_MAIN 3 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM

#define MAX_ELEM_PG_WIFI 8 // # Elems total on page
#define MAX_ELEM_PG_WIFI_RAM MAX_ELEM_PG_WIFI // # Elems in RAM

#define MAX_ELEM_PG_WIFI_PSWD 8 // # Elems total on page
#define MAX_ELEM_PG_WIFI_PSWD_RAM MAX_ELEM_PG_WIFI_PSWD // # Elems in RAM

#define MAX_ELEM_PG_OVERVIEW 28 // # Elems total on page
#define MAX_ELEM_PG_OVERVIEW_RAM MAX_ELEM_PG_OVERVIEW // # Elems in RAM
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
gslc_tsElem                     m_asKeypadAlphaElem[1];
gslc_tsElemRef                  m_asKeypadAlphaElemRef[1];
gslc_tsXKeyPad                  m_sKeyPadAlpha;
gslc_tsXListbox                 m_sListbox1;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf1[100 + XLISTBOX_BUF_OH_R];
gslc_tsXRingGauge               m_sXRingGauge3;
gslc_tsXTogglebtn               m_asXToggle2;
gslc_tsXRingGauge               m_sXRingGauge1;
gslc_tsXRingGauge               m_sXRingGauge2;
gslc_tsXProgress                m_sXBarGauge1;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemIn_PASSWORD;
extern gslc_tsElemRef* m_pElemXRingGaugePM10;
extern gslc_tsElemRef* m_pElemXRingGaugePM25;
extern gslc_tsElemRef* m_pElem_Measuring;
extern gslc_tsElemRef* m_pElem_WIFI_LIST;
extern gslc_tsElemRef* m_pElem_aqi_val;
extern gslc_tsElemRef* m_pElem_btn_WIFI_setup;
extern gslc_tsElemRef* m_pElem_btn_back_PG_WIFI_PWD;
extern gslc_tsElemRef* m_pElem_btn_back_pg_wifi;
extern gslc_tsElemRef* m_pElem_btn_dashboard;
extern gslc_tsElemRef* m_pElem_btn_info;
extern gslc_tsElemRef* m_pElem_btn_measure;
extern gslc_tsElemRef* m_pElem_btn_setup;
extern gslc_tsElemRef* m_pElem_con_msg;
extern gslc_tsElemRef* m_pElem_hum_val;
extern gslc_tsElemRef* m_pElem_img_nowifi;
extern gslc_tsElemRef* m_pElem_img_wifi;
extern gslc_tsElemRef* m_pElem_label_measure_art;
extern gslc_tsElemRef* m_pElem_label_pg_wifi_pwd;
extern gslc_tsElemRef* m_pElem_pm10_value;
extern gslc_tsElemRef* m_pElem_pm25_value;
extern gslc_tsElemRef* m_pElem_progress_measure;
extern gslc_tsElemRef* m_pElem_selected_ssid;
extern gslc_tsElemRef* m_pElem_temp_value;
extern gslc_tsElemRef* m_pElem_toggle_measure;
extern gslc_tsElemRef* m_pElem_wifi_gauge;
extern gslc_tsElemRef* m_pListSlider1;
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
    if (!gslc_FontSet(&m_gui,E_BUILTIN15X24,GSLC_FONTREF_PTR,NULL,3)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);
  gslc_PageAdd(&m_gui,E_PG_WIFI,m_asPage2Elem,MAX_ELEM_PG_WIFI_RAM,m_asPage2ElemRef,MAX_ELEM_PG_WIFI);
  gslc_PageAdd(&m_gui,E_PG_WIFI_PSWD,m_asPage3Elem,MAX_ELEM_PG_WIFI_PSWD_RAM,m_asPage3ElemRef,MAX_ELEM_PG_WIFI_PSWD);
  gslc_PageAdd(&m_gui,E_PG_OVERVIEW,m_asPage4Elem,MAX_ELEM_PG_OVERVIEW_RAM,m_asPage4ElemRef,MAX_ELEM_PG_OVERVIEW);
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
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BTN_dashboard,E_PG_MAIN,(gslc_tsRect){8,168,64,64},
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
    (gslc_tsRect){5,50,95,20},(char*)"Scan",0,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TITEL_PG_WIFI text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITEL_PG_WIFI,E_PG_WIFI,(gslc_tsRect){0,5,320,18},
    (char*)"Network settings",0,E_BUILTIN10X16);
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
    (gslc_tsRect){5,90,95,20},(char*)"Connect",0,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TEXT_SSID_PG_WIFI text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_SSID_PG_WIFI,E_PG_WIFI,(gslc_tsRect){20,180,61,18},
    (char*)"SSID:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_LABEL_SSID_PG_WIFI runtime modifiable text
  static char m_sDisplayText3[26] = "Nothing selected";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_LABEL_SSID_PG_WIFI,E_PG_WIFI,(gslc_tsRect){110,180,151,20},
    (char*)m_sDisplayText3,26,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_selected_ssid = pElemRef;
  
  // Create E_ELEM_BTN_BACK_PG_WIFI button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BTN_BACK_PG_WIFI,E_PG_WIFI,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_back_pg_wifi = pElemRef;

  // Create ring gauge E_ELEM_WIFI_GAUGE 
  static char m_sRingText3[2] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ELEM_WIFI_GAUGE,E_PG_WIFI,&m_sXRingGauge3,
          (gslc_tsRect){185,85,50,50},
          (char*)m_sRingText3,2,E_BUILTIN5X8);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 360);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetThickness(&m_gui,pElemRef, 5);
  gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui,pElemRef, GSLC_COL_GREEN_DK1);
  gslc_ElemXRingGaugeSetColorInactive(&m_gui,pElemRef, GSLC_COL_GRAY_LT2);
  gslc_ElemSetVisible(&m_gui, pElemRef, false);
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
  
  // Create E_ELEM_TITEL_PG_WIFI_PWD text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITEL_PG_WIFI_PWD,E_PG_WIFI_PSWD,(gslc_tsRect){0,5,320,18},
    (char*)"Network settings",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_SSID text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_SSID,E_PG_WIFI_PSWD,(gslc_tsRect){20,50,61,18},
    (char*)"SSID:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PASSWORD text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PASSWORD,E_PG_WIFI_PSWD,(gslc_tsRect){0,75,109,18},
    (char*)"Password:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_LABEL_SSID_PG_WIFI_PWD runtime modifiable text
  static char m_sDisplayText12[26] = "Nothing selected";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_LABEL_SSID_PG_WIFI_PWD,E_PG_WIFI_PSWD,(gslc_tsRect){115,50,200,20},
    (char*)m_sDisplayText12,26,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_label_pg_wifi_pwd = pElemRef;
  
  // create E_ELEM_BTN_CONNECT button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_CONNECT,E_PG_WIFI_PSWD,
    (gslc_tsRect){115,110,95,20},(char*)"Connect",0,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK3,GSLC_COL_BLUE_LT4,GSLC_COL_GRAY_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_CON_MSG runtime modifiable text
  static char m_sDisplayText13[51] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_CON_MSG,E_PG_WIFI_PSWD,(gslc_tsRect){10,150,300,18},
    (char*)m_sDisplayText13,51,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_con_msg = pElemRef;
  
  // Create E_ELEM_BTN_BACK_PG_WIFI_PWD button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_BTN_BACK_PG_WIFI_PWD,E_PG_WIFI_PSWD,(gslc_tsRect){2,205,32,32},
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_EXIT,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_back_PG_WIFI_PWD = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_OVERVIEW
  
  
  // Create E_ELEM_TITLE_PG_OVERVIEW text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITLE_PG_OVERVIEW,E_PG_OVERVIEW,(gslc_tsRect){10,0,300,18},
    (char*)"Air quality",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PM10 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PM10,E_PG_OVERVIEW,(gslc_tsRect){0,34,160,18},
    (char*)"PM 1.0",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXTPM25 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXTPM25,E_PG_OVERVIEW,(gslc_tsRect){160,34,160,18},
    (char*)"PM 2.5",0,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create toggle button E_ELEM_TOGGLE_MEASURE
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE_MEASURE,E_PG_OVERVIEW,&m_asXToggle2,
    (gslc_tsRect){235,124,40,18},GSLC_COL_GRAY,GSLC_COL_GREEN_DK1,GSLC_COL_GRAY_LT2,
    true,false,&CbBtnCommon);
  m_pElem_toggle_measure = pElemRef;
  
  // Create E_ELEM_PM10_VALUE runtime modifiable text
  static char m_sDisplayText17[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_PM10_VALUE,E_PG_OVERVIEW,(gslc_tsRect){35,60,49,18},
    (char*)m_sDisplayText17,5,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_pm10_value = pElemRef;
  
  // Create E_ELEM_PM25_VALUE runtime modifiable text
  static char m_sDisplayText18[5] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_PM25_VALUE,E_PG_OVERVIEW,(gslc_tsRect){195,60,49,18},
    (char*)m_sDisplayText18,5,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_pm25_value = pElemRef;
  
  // Create E_ELEM_TEXT_MEASURE_ART text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_MEASURE_ART,E_PG_OVERVIEW,(gslc_tsRect){220,140,70,20},
    (char*)"24h average",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_label_measure_art = pElemRef;

  // Create E_DRAW_LINE1 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE1,E_PG_OVERVIEW,2,120,157,120);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);

  // Create E_DRAW_LINE2 line 
  pElemRef = gslc_ElemCreateLine(&m_gui,E_DRAW_LINE2,E_PG_OVERVIEW,80,18,240,18);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_GRAY_LT2,GSLC_COL_GRAY_LT2);
  
  // Create E_ELEM_AQI runtime modifiable text
  static char m_sDisplayText22[11] = "Good";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_AQI,E_PG_OVERVIEW,(gslc_tsRect){70,95,181,26},
    (char*)m_sDisplayText22,11,E_BUILTIN15X24);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_aqi_val = pElemRef;
  
  // Create E_ELEM_TEMP_VALUE runtime modifiable text
  static char m_sDisplayText24[6] = "23.5";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEMP_VALUE,E_PG_OVERVIEW,(gslc_tsRect){70,134,61,18},
    (char*)m_sDisplayText24,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_temp_value = pElemRef;
  
  // Create E_ELEM_HUM_VALUE runtime modifiable text
  static char m_sDisplayText25[6] = "48.2";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_HUM_VALUE,E_PG_OVERVIEW,(gslc_tsRect){70,170,61,18},
    (char*)m_sDisplayText25,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_hum_val = pElemRef;
  
  // Create E_ELEM_TEXT_TEMP_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_TEMP_UNIT,E_PG_OVERVIEW,(gslc_tsRect){130,134,20,18},
    (char*)"C",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_HUM_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_HUM_UNIT,E_PG_OVERVIEW,(gslc_tsRect){130,170,13,18},
    (char*)"%",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PM10_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PM10_UNIT,E_PG_OVERVIEW,(gslc_tsRect){88,60,31,20},
    (char*)"ug/m3",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_PM25_UNIT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_PM25_UNIT,E_PG_OVERVIEW,(gslc_tsRect){248,60,31,20},
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
    (gslc_tsRect){100,222,120,12},0,20,0,GSLC_COL_GREEN_DK1,false);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK1,GSLC_COL_GRAY_LT2,GSLC_COL_WHITE);
  m_pElem_progress_measure = pElemRef;
  
  // Create E_ELEM_TEXT_MEASURING text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_MEASURING,E_PG_OVERVIEW,(gslc_tsRect){100,208,120,15},
    (char*)"Measuring",0,E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElem_Measuring = pElemRef;
  
  // Create E_ELEM_TEXT_AQI text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_AQI,E_PG_OVERVIEW,(gslc_tsRect){8,100,49,18},
    (char*)"AQI:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
 
  // Create E_ELEM_IMG_NOWIFI using Image 
  pElemRef = gslc_ElemCreateImg(&m_gui,E_ELEM_IMG_NOWIFI,E_PG_OVERVIEW,(gslc_tsRect){143,40,32,32},
    gslc_GetImageFromFile(IMG_NOWIFI,GSLC_IMGREF_FMT_BMP24));
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_img_nowifi = pElemRef;
 
  // Create E_ELEM_IMG_WIFI using Image 
  pElemRef = gslc_ElemCreateImg(&m_gui,E_ELEM_IMG_WIFI,E_PG_OVERVIEW,(gslc_tsRect){143,40,32,32},
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
  
  // Create E_ELEM_SETTINGS_BTN button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_SETTINGS_BTN,E_PG_OVERVIEW,(gslc_tsRect){284,206,32,32},
          gslc_GetImageFromFile(IMG_CONTROL,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromFile(IMG_CONTROL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElem_btn_setup = pElemRef;
 
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
