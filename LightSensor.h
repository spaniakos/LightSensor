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
		uint8_t pinLight;/**< holds the Pin number of the board */
	    int LUX;/**< holds the LUX value  after the convertion from te reading */
		int sensorValue;/**< holds the reading value from the sensor */
		int Old_LUX;/**< holds the old LUX value, mainly used from cmp_values */
		float Rensor;/**< holds the rensor value */
		int LightThres;/**< hold the Threshold, mainly used from cmp_values */
	public:
	/**
	 * class constructor.
	 * 
	 * @param pin uint8_t Number of the pin to be used for reading
	 * @param thres int value of the threshold that will be used
	 */
	LightSensor(uint8_t pin,int thres);
	
	/**
	 * class constructor.
	 * 
	 * Threasold initializes to 1.
	 * @param pin uint8_t Number of the pin to be used for reading
	 */
	LightSensor(uint8_t pin); /*thres = 1*/
	
	/**
	 * Initialized the base grove class with the balues given in the constructor.
	 * 
	 */
	void begin(void);
	
	/** reads value from sensor.
	 * the value is saved to sensorValue
	 */
	void Read_Light(void);
	
	/** Reads the Value from the pin using 
	 *  @code Read_Light(); @endcode
	 *  Calculates the Rensor using
	 *  @code CalcRensor(); @endcode
	 *  end Saves the LUX value. 
	 */
	void Light_To_Lux(void);
	
	/** set Old_LUX equal to current LUX.
	 * 
	 */
	void Save_Old(void);
	
	/** compare LUX and OLD_LUX values.
	 *  @return int 0 if equal , 1 if not
	 */
	int cmp_values(void);
	
	/** Gets the LUX valule.
	 *  @return LUX value.
	 */
	 int Value(void);
	 
	 /** get the Old_LUX value.
	  *  @return OLD_LUX value.
	  */
	 int Old_Value(void);
	 
	 /** Calculate the Rensor.
	  *  The value is saved inside the class.
	  */
	 void CalcRensor();
	 
	 /** GETS the Rensor value.
	  *  @return Rensor value.
	  */
	 float get_Rensor();
	 
	 /** Gets the Threshold.
	  *  @return LightThres as integer
	  */
	 int get_Threshold();
	 
	 /** calibrate the sensor and readings.
	  *  Does initial readings in order to calibrate the sensor.
	  */
	 void calibrate();
};

/**
 * @example LUX.ino
 * <b>For Arduino</b><br />
 * <b> updated: spaniakos 2015</b><br />
 *
 * In this example a simple readingof the sensor value is printed into Serial.<br />
 * the valueis first converted to LUX using class functions.
 */

/**
  * @mainpage grove LightSensor (GL5528 LDR) library for arduino
  *
  * @section Goals Design Goals
  *
  * This library is designed to:
  * @li extend the basic grove library
  * @li be able to compare Values in order to optimize the prosses
  *
  *section News News
  *
  * If issues are discovered with the documentation please report them <a href="https://github.com/spaniakos/spaniakos.github.io/issues"> here</a>
  * 
  * @section Useful Useful References
*
* Please refer to:
*
* @li <a href="http://spaniakos.github.io/LightSensor/classLightSensor.html"><b>LCD</b> Class Documentation</a>
* @li <a href="https://github.com/spaniakos/LightSensor/archive/master.zip"><b>Download</b></a>
* @li <a href="https://github.com/spaniakos/LightSensor/"><b>Source Code</b></a>
* @li <a href="http://spaniakos.github.io/">All spaniakos Documentation Main Page</a>
*
* @section Board_Support Board Support
*
* Most standard Arduino based boards are supported:
* - Arduino
* - Intel Galileo support
* 
* * @section Sensor_support Sensor Support
* 
* It supports:
* - The grove Light sensor.
* - Every Light sensor equiped with the GL5528 LDR sensor.
*/

#endif //LightSensor


