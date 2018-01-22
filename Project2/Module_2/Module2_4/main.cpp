/*!
* ECEN 5803 Mastering Embedded System Architecture                            
* Project 2 Module 2.4                                                       
* Microcontroller Firmware                                                    
*******************************************************************************/

/*! 
*\file main.cpp
*\brief Display the temperature from the virtual DS1631 temperature sensor on the virtual LCD   
*        Input: virtual DS1631 temperature sensor
* 		 Output: virtual LCD display
*@author Preshit Harlikar and Shiril Tichkule  
*@date 11/02/2017  
*Target Microcontroller: STM32F401RE 
*Tools used: ARM mbed compiler
*             ARM mbed SDK
*             STM32F401RE
*******************************************************************************/

#include "NHD_0216HZ.h"
#include "DS1631.h"
#include "pindef.h"
#include "mbed.h"


/*!
*@brief Definition for LCD unit
*/
NHD_0216HZ mylcd(SPI_CS,SPI_MOSI,SPI_SCLK);


/*!
*@brief Definition for temperature sensor
*/
DS1631 tempsensor(I2C_SDA,I2C_SCL,0x90);


/*!
*@brief Serial communication with PC
*/
Serial pc(USBTX, USBRX);

float temp;

/*!
*@brief Main function to display temperature on lcd using temperature sensor and SPI
*/
int main() {
	mylcd.init_lcd();
	mylcd.clr_lcd();
	mylcd.set_cursor(0,0);
	mylcd.printf("Hello LCD");
	pc.printf("Hello mbed!!\n");
	
	
	while(1){	
		temp=tempsensor.read();
		mylcd.set_cursor(0,1);
		mylcd.printf("Temp: %f",temp);
		pc.printf("Temperature is: %f\n",temp);	
	}
}
