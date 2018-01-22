/*!
* ECEN 5803 Mastering Embedded System Architecture                            
* Project 2 Module 2.1                                                         
* Microcontroller Firmware                                                    
*******************************************************************************/

/*! 
*\file main.cpp
*\brief Blinking led(LD2) and an external led with 4 switches using Bus_In and Bus_Out interface   
*@author Preshit Harlikar and Shiril Tichkule  
*@date 10/28/2017  
*Target Microcontroller: STM32F401RE 
*Tools used: ARM mbed compiler
*             ARM mbed SDK
*             STM32F401RE
*******************************************************************************/

#include "mbed.h"
#include "pindef.h"

/*!
*@brief Definition for BusIn interface
*/
BusIn My_Bus_In(Din3, Din2, Din1, Din0);

/*!
*@brief Definition for BusOut interface
*/
BusOut My_Bus_Out(Dout2);

/*!
*@brief Definition for on-board LED LD2
*/
DigitalOut led1(LED1);

/*!
*@brief Main function to control LEDs with external switches using Bus_In and Bus_Out interface
*/
int main(){
	
	My_Bus_Out=1;
	led1=1;
	
	while(1){
		
			
		if(My_Bus_In==0x01)
		{
			led1=1;
		}
		
		if(My_Bus_In==0x02)
		{
			led1=0;
		}
		
		if(My_Bus_In==0x04)
		{
			My_Bus_Out=1;
		}
		
		if(My_Bus_In==0x08)
		{
			My_Bus_Out=0;
		}
		
	}
}