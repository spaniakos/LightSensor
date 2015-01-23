/*
 Copyright (C) 2014 G. Spanos <spaniakos@gmail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */
 
#include "LightSensor_config.h"
#include "LightSensor.h"

/****************************************************************************/

LightSensor::LightSensor(uint8_t pin,int thres){
		pinLight = pin;
		LUX = 0;
		sensorValue = 0;
		Old_LUX = 0;
		Rensor = 0;
		LightThres = thres;
}

LightSensor::LightSensor(uint8_t pin){
		pinLight = pin;
		LUX = 0;
		sensorValue = 0;
		Old_LUX = 0;
		Rensor = 0;
		LightThres = 1;
}
	
void LightSensor::begin(){
	pinMode(pinLight, OUTPUT);
}

void LightSensor::Read_Light(){
	sensorValue = analogRead(pinLight);
	#if defined(SERIAL_DEBUG_LUX)
		printf_P(PSTR("sensorValue: %i\n"), sensorValue);
	#endif
}
	
void LightSensor::Light_To_Lux(){
	Read_Light();
	CalcRensor();
	LUX = round(10000.0f / (float) pow((Rensor*10.0f),(4.0f/3.0f)));
	#if defined(SERIAL_DEBUG_LUX)
			printf_P(PSTR("pow: %f\n"), (float) pow((Rensor*10.0f),(4.0f/3.0f)) );
			printf_P(PSTR("LUX: %i\n"), LUX);
	#endif
}
	
void LightSensor::Save_Old(){
	#if defined(SERIAL_DEBUG_LUX)
			printf_P(PSTR("old LUX saved: %lu <- %lu\n"), LUX,Old_LUX);
	#endif
	Old_LUX = LUX;
}
	
int LightSensor::cmp_values(){
	#if defined(SERIAL_DEBUG_LUX)
			printf_P(PSTR("\nTests 1: %i \t 2: %i \t Thres: %i \n"), (LUX-Old_LUX),(Old_LUX-LUX),LightThres);
	#endif
	if ( (LUX - Old_LUX >= LightThres) || (Old_LUX - LUX >= LightThres) ){
		Save_Old();
		return 1;
	}else return 0;
}

int LightSensor::Value(){
	return LUX;
}

int LightSensor::Old_Value(){
	return Old_LUX;
}

void LightSensor::CalcRensor(){
	Rensor = ( (float) (1023 - sensorValue) * 10.0f / (float) sensorValue);
	#if defined(SERIAL_DEBUG_LUX)
		printf_P(PSTR("Rensor: %f\n"), Rensor);
	#endif
}

float LightSensor::get_Rensor(){
	return Rensor;
}

int LightSensor::get_Threshold(){
	return LightThres;
}

void LightSensor::calibrate(){
	Light_To_Lux();
	cmp_values();
	Light_To_Lux();
	cmp_values();
	Light_To_Lux();
	cmp_values();
}


