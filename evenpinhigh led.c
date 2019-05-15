/*
 * even static.c
 *
 * Created: 5/10/2019 9:55:47 AM
 * Author : bhoj007
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRB= 0x55;
    while (1) 
    {
		PORTB = 0xFF;
		_delay_ms(100);
    }
}

