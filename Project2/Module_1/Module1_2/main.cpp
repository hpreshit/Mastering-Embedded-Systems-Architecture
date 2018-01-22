/*!
* ECEN 5803 Mastering Embedded System Architecture                            
* Project 2 Module 1.2                                                         
* Microcontroller Firmware                                                    
*******************************************************************************/

/*! 
*\file main.cpp
*\brief Display date and time on the terminal
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

DigitalOut myled(LED1);

/*!
*@brief Serial communicataion with the terminal 
*/

Serial pc(USBTX, USBRX);

int main() {
     
    set_time(1508250840); // Set RTC time to 17 October 2017
    pc.printf("Date and time are set.\n");

    while(1) {

        time_t seconds = time(NULL);
        
        pc.printf("Date: %s", ctime(&seconds));

        myled = !myled;      
        wait(1);
    }
}
