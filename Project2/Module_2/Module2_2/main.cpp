/*!
* ECEN 5803 Mastering Embedded System Architecture                            
* Project 2 Module 2.2                                                        
* Microcontroller Firmware                                                    
*******************************************************************************/

/*! 
*\file main.cpp
*\brief Blinking led(LD2) and an external led with 4 switches by Interrupts   
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
*@brief Definition for on-board LED LD2
*/
DigitalOut led1(LED1);

/*!
*@brief Definition for BusOut interface
*/
BusOut My_Bus_Out(Dout2);


InterruptIn button_1_press(Din3);
InterruptIn button_2_press(Din2);
InterruptIn button_3_press(Din1);
InterruptIn button_4_press(Din0);

/*!
*@brief Interrupt routine for switch 1
*/
void button_1_handler(){
	led1=!led1;
}

/*!
*@brief Interrupt routine for switch 2
*/
void button_2_handler(){
	led1=!led1;
}

/*!
*@brief Interrupt routine for switch 3
*/
void button_3_handler(){
	My_Bus_Out=1;
}

/*!
*@brief Interrupt routine for switch 4
*/
void button_4_handler(){
	My_Bus_Out=0;
}


/*!
*@brief Main function to control LEDs with external switches by interrupts
*/
int main(){
	
	__enable_irq();			
	
	led1=0;
	My_Bus_Out=0;
	
		
	button_1_press.rise(&button_1_handler);
	wfi();
	button_2_press.rise(&button_2_handler);
	wfi();
	button_3_press.rise(&button_3_handler);
	wfi();
	button_4_press.rise(&button_4_handler);
	wfi();
	
	while(1);
		
	
}