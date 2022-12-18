#ifndef _AQI_H
#define _AQI_H

#include <Arduino.h>
#include <string.h>

/***
 * Helper functions to calculate AQI-Value from measured pollution (µg/m³).
 * Will calculate the raw AQI value and can also map the raw value to the AQI-table.
 * Verified the calculation with https://www.airnow.gov/aqi/aqi-calculator-concentration/
 * More info about AQI-Caluclation: https://www.airnow.gov/aqi/aqi-calculator-concentration/
*/

/// @brief Calculate the AQI value of particulate matter PM2.5
/// @param pm25_value 
/// @return AQI value
float calc_aqipm25(float pm25_value);


/// @brief Calculate the AQI value of particulate matter PM10
/// @param pm10_value 
/// @return AQI value
float calc_aqipm10(float pm10_value);

/// @brief Mapping the AQI-Value to the AQI-Table
/// @param aqi_value 
/// @return int: 1= Good, 2=Moderate, 3=Unhealthy, 4=Very unhealthy, 5=Risky, 6=Hazardous!, 7=UNSAFE!
int mapAqiToIndex(float aqi_value);        

#endif _AQI_H