#include "AQI.h"
#include <bits/stdc++.h>
#include <Arduino.h>
#include <string.h>
using namespace std;


// For AQI calculation. Verified with https://www.airnow.gov/aqi/aqi-calculator-concentration/
// Info about AQI: https://www.airnow.gov/aqi/aqi-calculator-concentration/



/// @brief Calculate the AQI value of particulate matter PM2.5
/// @param pm25_value 
/// @return AQI value
float calc_aqipm25(float pm25_value)          
{
	float c;
	if(pm25_value>=0.0&&pm25_value<=12.0)
	{
		c=(4.166*(pm25_value-0.0))+0;
		return c;
	}
	else if(pm25_value>=12.1&&pm25_value<=35.4)
	{
		c=(2.103*(pm25_value-12.1))+51;
		return c;	
	}
	else if(pm25_value>=35.5&&pm25_value<=55.4)
	{
		c=(2.462*(pm25_value-35.5))+101;
		return c;	
	}
	else if(pm25_value>=55.5&&pm25_value<=150.4)
	{
		c=(0.516*(pm25_value-55.5))+151;
		return c;
	}
	else if(pm25_value>=150.5&&pm25_value<=250.4)
	{
		c=(0.990*(pm25_value-150.5))+201;
		return c;
	}
	else if(pm25_value>=250.5&&pm25_value<=500.4)
	{
		c=(0.796*(pm25_value-250.5))+301;
		return c;	
	}
}

/// @brief Calculate the AQI value of particulate matter PM10
/// @param pm10_value 
/// @return AQI value
float calc_aqipm10(float pm10_value)                         
{
   float c;
	if(pm10_value>=0&&pm10_value<=30){
        c=(0.926*(pm10_value-0))+0;
        return c;	
	}
	else if(pm10_value>=31&&pm10_value<=60)
	{
		c=(0.495*(pm10_value-55))+51;
        return c;	
	}
	else if(pm10_value>=61&&pm10_value<=90)
	{
		c=(0.495*(pm10_value-155))+101;
        return c;
	}
	else if(pm10_value>=91&&pm10_value<=120)
	{
		c=(0.495*(pm10_value-255))+151;
        return c;
	}
	else if(pm10_value>=121&&pm10_value<=250)
	{
		c=(1.434*(pm10_value-355))+201;
        return c;
	}
	else if(pm10_value>=251&&pm10_value<=380)
	{
		c=(1.112*(pm10_value-425))+301;
        return c;	
	}
}

/// @brief Mapping the AQI-Value to the AQI-Table
/// @param aqi_value 
/// @return int: 0=Very good (below 25), 1= Good, 2=Moderate, 3=Unhealthy, 4=Very unhealthy, 5=Risky, 6=Hazardous!, 7=UNSAFE!
int mapAqiToIndex(float aqi_value)                 
{
	if(aqi_value>=0&&aqi_value<=25){
		return 0;
	}
	if(aqi_value>=25&&aqi_value<=50){
		return 1;
	}
	if(aqi_value>=51&&aqi_value<=100){
		return 2;
	}
	if(aqi_value>=101&&aqi_value<=150){
		return 3;
	}
	if(aqi_value>151&&aqi_value<=200){
		return 4;
	}
	if(aqi_value>=201&&aqi_value<=300){
		return 5;
	}
	if(aqi_value>=301&&aqi_value<=500){
		return 6;
	}
    if(aqi_value>500){
        return 7;
    }
}