/*
 * odd static.c
 *
 * Created: 5/14/2019 12:58:10 PM
 * Author : bhoj007
 */ 


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRB= 0xAA;
    while (1) 
    {
		PORTB = 0xFF;
		_delay_ms(100);
    }
}


