/*!
*\file DS1631.cpp
*\brief MAXIM DS1631 2-wire temperature sensor library
*@author Prof. Timothy Scherr  
*@date 10/28/2017
******************************************************************************/

#include "mbed.h"
#include "DS1631.h"

DS1631::DS1631(PinName sda, PinName scl, int addr) : temp_sensor(sda, scl), _addr(addr){
}

char cmd1= 0x51;
char cmd2= 0xAA;
char read_temp[2];

float DS1631::read(){
	temp_sensor.write(_addr, &cmd1, 1);
	wait(0.5);
	temp_sensor.write(_addr, &cmd2, 1);
	temp_sensor.read(_addr, read_temp, 2);
		
	float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
	
	return temp;