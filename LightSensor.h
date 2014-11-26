/*
 Copyright (C) 2014 G. Spanos <spaniakos@gmail.com

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

/**
 * @file LightSensor.h
 *
 * Class declaration for LightSensor and helper enums
 */

#ifndef __LightSensor_H__
#define __LightSensor_H__

#include "LightSensor_config.h"

class LightSensor{
	private:
		uint8_t pinLight;
	    int LUX;
		int sensorValue;
		int Old_LUX;
		float Rensor;
		int LightThres;
	public:
	/* class constructor
	 * 
	 */
	LightSensor(uint8_t pin,int thres);
	
	/* set the pin and begin readings
	 * 
	 */
	void begin(void);
	/* reads value from sensor
	 * the value is saved to sensorValue
	 */
	void Read_Light(void);
	
	/* converts sensor value to LUX
	* 
	*/
	void Light_To_Lux(void);
	
	/* set Old_LUX equal to LUX
	 * 
	 */
	void Save_Old(void);
	
	/* compair LUX values
	 * return 0 if equal , 1 if not
	 */
	int cmp_values(void);
	
	/* get the LUX valule
	 * 
	 */
	 int Value(void);
	 
	 /* get the Old_LUX valule
	 * 
	 */
	 int Old_Value(void);
	 
	 /* Calculate the Rensor
	 * 
	 */
	 void CalcRensor();
	 
	 /* returns the Rensor value
	 * 
	 */
	 float get_Rensor();
	 
	 /* Calculate the Rensor
	 * 
	 */
	 int get_Threshold();
	 
	 /* calibrate the sensor and readings
	  * 
	  */
	 void calibrate();
};
#endif //LightSensor


