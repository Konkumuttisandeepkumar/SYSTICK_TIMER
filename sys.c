//This project was implemented on STM32f401RB custom board and infenion XMC4400 platform to kit to toggle the led with delay 
// generic for any cortex M4 series MCU 
// just change the Mcu clock in systick.h file according to our MCU clk speed
//This is an main.c file

#include<stdint.h>
#include"sys.h"


#define STK_CTRL *((int*))0xE000E010;    //status and control registers
#define STK_LOAD *((int*))0xE000E014;    //load value
#define STK_VAL *((int*))0xE000E018;      //systick current value register

void init_systick_timer(void)
{
	STK_CTRL  = 0x0;   //clearing the control register bits
	STK_LOAD  = 0x0;
	STK_CTRL |= 0x5;   //set the 0th and 2nd position in control register
}

void delay_ms(uint16_t delay)    //milli seconds delay
{
	STK_LOAD = (ms*delay)-1;
	STK_VAL  = 0x0;
	while((STK_CTRL & 0x10000)==0)      //Set 16th position count flag in control register
	{
		;
	}

}


void delay_us(uint16_t delay)    //micro seconds delay
{
	STK_LOAD = (us*delay)-1;
	STK_VAL  = 0x0;
	while((STK_CTRL & 0x10000)==0)
	{
		;
	}

}
