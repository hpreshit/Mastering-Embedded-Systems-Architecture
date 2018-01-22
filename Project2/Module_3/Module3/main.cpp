/*!
* ECEN 5803 Mastering Embedded System Architecture                            
* Project 2 Module 3                                                     
* Microcontroller Firmware                                                    
*******************************************************************************/

/*! 
*\file main.cpp
*\brief Integrate SPI, UART, LCD, LED functions run them concurrently 
*		in the mbed RTOS. The following four threads are implemented:
*		1. Display the temperature on the LCD and to the PC
*		2. Adjust the brightness of the RGB LED using a potentiometer
*		3. Display an incrementing counter on the LCD and to the PC
*		4. Blink an LED
*@author Preshit Harlikar and Shiril Tichkule  
*@date 11/04/2017  
*Target Microcontroller: STM32F401RE 
*Tools used: ARM mbed compiler
*             ARM mbed SDK
*             STM32F401RE
*******************************************************************************/

#include "mbed.h"
#include "rtos.h"
#include "DS1631.h"
#include "NHD_0216HZ.h"
#include "pindef.h"

/*!
*@brief Definition of Mutex
*/
Mutex lcd_mutex;

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

/*!
*@brief Definition for on-board LED LD2
*/
DigitalOut led1(LED1);

/*!
*@brief Analog input for Potentiometer 1
*/
AnalogIn pot1(Ain0);

/*!
*@brief Analog output for PWM 
*/
PwmOut mypwm(Dout0);


#pragma O0
int count=1;

/*!
*@brief Thread to display temperature on LCD
*/
void temp_thread(void const *args){
	float temp;
	while (true){
		lcd_mutex.lock();	
		temp=tempsensor.read();
		mylcd.set_cursor(0,0);
		mylcd.printf("Temp: %f",temp);
		pc.printf("Temperature: %f\n",temp);
		lcd_mutex.unlock();
		Thread::wait(1000);
	}
}

/*!
*@brief Thread to adjust brightness of external LED
*/
void adjust_brightness(void const *args){
	while (true){
		Thread::wait(1000);
		v=pot1.read();
		mypwm=(0.5*v);
		}
}

/*!
*@brief Thread to blink on-board LED LD2
*/
void led1_thread(void const *args){
	while (true){
		led1=!led1;
		Thread::wait(1000);
		}
}

/*!
*@brief Thread to display count on LCD
*/
void count_thread(void const *args){
	while(true){
		lcd_mutex.lock();
		mylcd.set_cursor(0,1);
		mylcd.printf("Count: %d",count);
		pc.printf("Count is: %d\n",count);
		count++;
		lcd_mutex.unlock();
		Thread::wait(1000);
		}
}

/*!
*@brief Main function to start all the threads for real time application
*/
int main(){
	mylcd.init_lcd();
	mylcd.clr_lcd();
	
	Thread thread1(led1_thread);
	Thread thread2(adjust_brightness);
	Thread thread3(temp_thread);
	Thread thread4(count_thread);
	
	while (true){
	Thread::wait(100);
	}
}