/*
 Copyright (C) 2014 G. Spanos <spaniakos@gmail.com

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 * 
 */

#ifndef __LightSensor_CONFIG_H__
#define __LightSensor_CONFIG_H__

	/*** USER DEFINES:  ***/  
	//#define SERIAL_DEBUG_LUX
	/**********************/

	#if defined (__ARDUINO_X86__)
		#define printf_P printf
		#define PSTR(x) (x)
	#endif
	#include <stdint.h>
	#include <stdio.h>
	#include <string.h>
	#include <SPI.h>
	#include <math.h>

#endif //LightSensor_CONFIG
