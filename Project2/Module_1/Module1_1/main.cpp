/*!
* ECEN 5803 Mastering Embedded System Architecture                            
* Project 2 Module 1.1                                                         
* Microcontroller Firmware                                                    
*******************************************************************************/

/*! 
*\file main.cpp
*\brief Blinking led(LD2)
*@author Preshit Harlikar and Shiril Tichkule  
*@date 10/28/2017  
*Target Microcontroller: STM32F401RE 
*Tools used: ARM mbed compiler
*             ARM mbed SDK
*             STM32F401RE
*******************************************************************************/


#include "mbed.h"

/*!
*@brief Definition for on-board LED LD2
*/
DigitalOut led1(LED1);

// main() runs in its own thread in the OS
int main() {
    while (true) {
        led1 = !led1;
        wait(0.5);
    }
}

