/*
 * 7segdisp.c
 *
 * Created: 5/14/2019 10:26:07 AM
 * Author : bhoj007
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0xFF;
    while (1) 
    {
		PORTC = 0b11111100;
		_delay_ms(1000);
		PORTC = 0b01100000;
		_delay_ms(1000);
		PORTC = 0b11011010;
		_delay_ms(1000);
		PORTC = 0b11110010;
		_delay_ms(1000);
		PORTC = 0b01100110;
		_delay_ms(1000);
		PORTC = 0b10110110;
		_delay_ms(1000);
		PORTC = 0b10111110;
		_delay_ms(1000);
		PORTC = 0b11100000;
		_delay_ms(1000);
		PORTC = 0b11111110;
		_delay_ms(1000);
		PORTC = 0b11100110;
		_delay_ms(1000);
		PORTC = 0b11101110;
		_delay_ms(1000);
		PORTC = 0b00111110;
		_delay_ms(1000);
		PORTC = 0b10011101;
		_delay_ms(1000);
		PORTC = 0b01111010;
		_delay_ms(1000);
		PORTC = 0b10011110;
		_delay_ms(1000);
		PORTC = 0b10001110;
		_delay_ms(1000);
    }
}

