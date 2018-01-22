/*!
* ECEN 5803 Mastering Embedded System Architecture                            
* Project 2 Module 2.3                                                       
* Microcontroller Firmware                                                    
*******************************************************************************/

/*! 
*\file main.cpp
*\brief Use two potentiometers to adjust the volume and pitch of the output sound wave   
*        Inputs: Virtual potentiometers 1 and 2
*	     Output: Virtual speaker, Real PC
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
*@brief Analog output for PWM 
*/
PwmOut mypwm(Dout0);

/*!
*@brief Analog input for Potentiometer 1
*/
AnalogIn pot1(Ain0);

/*!
*@brief Analog input for Potentiometer 2
*/
AnalogIn pot2(Ain1);

/*!
*@brief Serial communication with PC
*/
Serial pc(USBTX, USBRX);


float i;
double v1,v2,d,p;

/*!
*@brief Main function to adjust the volume and pitch of speaker using potentiometers
*/
int main(){
	while(1){
		
		pc.printf("value of 1st potentiometer: %f\n",v1);
		pc.printf("value of 2nd potentiometer: %f\n",v2);
		
		v1=pot1.read();
		p=(0.003*v1)+0.000125;
		mypwm.period(p);
		
		for(i=0;i<=1;i+=p)
		{
			mypwm=i;
		}
		
		v2=pot2.read();
		d=100*v2;
		mypwm.pulsewidth((d*p)/100);
	}
}