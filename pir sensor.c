/*
 * pir sensor.c
 *
 * Created: 5/13/2019 10:47:11 AM
 * Author : neetutater3
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#include <avr/io.h>
#define LED_OUTPUT		PORTB
#define PIR_Input		PINC

int main(void)
{
	DDRC = 0x00;	/* Set the PIR port as input port */
	DDRB = 0xFF;	/* Set the LED port as output port */

	while(1)
	{
		LED_OUTPUT = PIR_Input;
	}
}
