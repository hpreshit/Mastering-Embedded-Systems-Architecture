/**----------------------------------------------------------------------------
 
   \file main.cpp

--                                                                           --
--              ECEN 5803 Mastering Embedded System Architecture             --
--                  Project 1 Module 3                                       --
--                Microcontroller Firmware                                   --
--                      main.cpp                                            --
--                                                                           --
-------------------------------------------------------------------------------
--
--  Designed for:  University of Colorado at Boulder
--               
--                
--  Designed by:  Tim Scherr
--  Revised by:  Vikrant Waje and Preshit Harlikar
-- 
-- Version: 2.1
-- Date of current revision:  2017-09-20  
-- Target Microcontroller: Freescale MKL25ZVMT4 
-- Tools used:  ARM mbed compiler
--              ARM mbed SDK
--              Freescale FRDM-KL25Z Freedom Board
--               
-- 
-- Functional Description:  Main code file generated by mbed, and then
--                           modified to implement a super loop bare metal OS.
--
--      Copyright (c) 2015, 2016 Tim Scherr  All rights reserved.
--
*/
#include "mbed.h"

#include"MKL25Z4.h"
#define MAIN
#include "shared.h"
#undef MAIN
//#include "CPU_Usage.h"

extern volatile uint16_t SwTimerIsrCounter; 



Ticker Every100micro;           
                                                    
Timer t;


Serial pc(USBTX, USBRX);   

 
void flip()  
{      
          
    
    timer0();

}
 
int main() 
{
   //.start();
    
/****************      ECEN 5803 add code as indicated   ***************/
      

     
    uint32_t  count = 0;  
     
    
// initialize serial buffer pointers
   rx_in_ptr =  rx_buf; /* pointer to the receive in data */
   rx_out_ptr = rx_buf; /* pointer to the receive out data*/
   tx_in_ptr =  tx_buf; /* pointer to the transmit in data*/
   tx_out_ptr = tx_buf; /* pointer to the transmit out */
    
   
  // Print the initial banner
    pc.printf("\r\nHello World!\n\n\r");
    
    /****************      ECEN 5803 add code as indicated   ***************/
                  
   
   UART_direct_msg_put("\r\nSystem Reset\r\nCode ver. ");
   UART_direct_msg_put( CODE_VERSION );
   UART_direct_msg_put("\r\n");
   UART_direct_msg_put( COPYRIGHT );
   UART_direct_msg_put("\r\n");

   set_display_mode(); 
                   /* int b=r0;
               int r0=number(b);
               pc.printf("R0:");
               pc.printf("%d",r0); */
                  
       
Every100micro.attach(&flip,1);             //  Add code to call timer0 function every 100 uS
while(1)       /// Cyclical Executive Loop
    {

        count++;               // counts the number of times through the loop
//      __enable_interrupts();
//      __clear_watchdog_timer();

   
    
    
        chk_UART_msg();     // checks for a serial port message received
        monitor();           // Sends serial port output messages depending
        serial();            // Polls the serial port
                    
       
    



        if ((SwTimerIsrCounter & 0x1FFF) > 0x0FFF)
    
        {
            flip();  // Toggle Green LED
        }
         /*stop();
         pc.printf("The time taken was %f seconds\n", t.read());*/
    } 
       
}

