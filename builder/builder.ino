//<App !Start!>
// FILE: [builder.ino]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

//
// ARDUINO NOTES:
// - GUIslice_config.h must be edited to match the pinout connections
//   between the Arduino CPU and the display controller (see ADAGFX_PIN_*).
//

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "builder_GSLC.h"



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
        break;
      case E_ELEM_BTN_dashboard:
        gslc_SetPageCur(&m_gui, E_PG_OVERVIEW);
        break;
      case E_ELEM_BTN_INFO:
        gslc_SetPageCur(&m_gui, E_PG_INFO);
        break;
      case E_ELEM_BTN_SCAN_WIFI:
        break;
      case E_ELEM_BTN_WIFI_CONNECT:
        gslc_SetPageCur(&m_gui, E_PG_WIFI_PSWD);
        break;
      case E_ELEM_BACK_PG_WIFI:
        break;
      case E_ELEM_PSWD_INPUT:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, m_pElemIn_PASSWORD);
        break;
      case E_ELEM_BTN_CONNECT:
        break;
      case E_ELEM_BACK_WIFI_PWD:
        break;
      case E_ELEM_TOGGLE_MEASURE:
        // TODO Add code for Toggle button ON/OFF state
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_measure)) {
          ;
        }
        break;
      case E_ELEM_MEASURE_BTN:
        break;
      case E_ELEM_HOME_BTN:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        break;
      case E_ELEM_TOGGLE_LOCK:
        // TODO Add code for Toggle button ON/OFF state
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_lock)) {
          ;
        }
        break;
      case E_ELEM_BTN_SYS_SET:
        gslc_SetPageCur(&m_gui, E_PG_SYS_SET);
        break;
      case E_ELEM_BTN_IOT_SET:
        gslc_SetPageCur(&m_gui, E_PG_IOT_SET);
        break;
      case E_ELEM_BACK_INFO:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        break;
      case E_ELEM_DIMMER_TIMER:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_dimmer_timer);
        break;
      case E_ELEM_TOGGLE_DIMMER:
        // TODO Add code for Toggle button ON/OFF state
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_dimmer)) {
          ;
        }
        break;
      case E_ELEM_DIM_ON:
        gslc_PopupShow(&m_gui, E_PG_POPUP_DIMMER, true);
        break;
      case E_ELEM_BACK_SYSSET:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        break;
      case E_ELEM_DEL_DATA:
        gslc_PopupShow(&m_gui, E_PG_POPUP_DIMMER, true);
        break;
      case E_ELEM_PRINT_DATA:
        gslc_PopupShow(&m_gui, E_PG_POPUP_DIMMER, true);
        break;
      case E_ELEM_TOGGLE_CSV:
        // TODO Add code for Toggle button ON/OFF state
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_csv)) {
          ;
        }
        break;
      case E_ELEM_SHUTDOWN:
        break;
      case E_ELEM_SAVE_SET:
        break;
      case E_ELEM_BTN_CONTINUOUS:
        break;
      case E_ELEM_MEAS_INTERVAL:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElem_meas_interval);
        break;
      case E_ELEM_BACK_IOT:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        break;
      case E_ELEM_TOGGLE_IOT:
        // TODO Add code for Toggle button ON/OFF state
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElem_toggle_IoT)) {
          ;
        }
        break;
      case E_ELEM_BTN_SETTIME:
        gslc_PopupShow(&m_gui, E_PG_POPUP_TIME, true);
        break;
      case E_ELEM_DIM_OFF:
        gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_DAY:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemDay);
        break;
      case E_ELEM_NUM_MONTH:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemMonth);
        break;
      case E_ELEM_NUM_YEAR:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemYear);
        break;
      case E_ELEM_NUM_HOUR:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemHour);
        break;
      case E_ELEM_NUM_MINUTE:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemMinute);
        break;
      case E_ELEM_BTN_SAVE_TIME:
        break;
      case E_ELEM_BACK_TIME:
        gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_CODE_INPUT:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemCodeIn);
        break;
      case E_ELEM_UNLOCK:
        break;
      case E_ELEM_BACK_CONTIN:
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}
// Checkbox / radio callbacks
// - Creating a callback function is optional, but doing so enables you to
//   detect changes in the state of the elements.
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState)
{
  gslc_tsGui*     pGui      = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef  = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem     = gslc_GetElemFromRef(pGui,pElemRef);
  if (pElemRef == NULL) {
    return false;
  }
  
  boolean bChecked = gslc_ElemXCheckboxGetState(pGui,pElemRef);

  // Determine which element issued the callback
  switch (pElem->nId) {
//<Checkbox Enums !Start!>

//<Checkbox Enums !End!>
    default:
      break;
  } // switch
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
  if (nState == XKEYPAD_CB_STATE_DONE) {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId) {
//<Keypad Enums !Start!>

      case E_ELEM_PSWD_INPUT:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemIn_PASSWORD, pvData);
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
      case E_ELEM_NUM_MONTH:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemMonth, pvData);
	    gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_DAY:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemDay, pvData);
	    gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_YEAR:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemYEAR, pvData);
	    gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_HOUR:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemHour, pvData);
	    gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUM_MINUTE:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemMinute, pvData);
	    gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_CODE_INPUT:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemCodeIn, pvData);
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


void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
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



}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{

  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------
  
  //TODO - Add update code for any text, gauges, or sliders
  
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
    
}

