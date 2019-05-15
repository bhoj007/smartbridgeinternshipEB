/*
 * dc spd cntrl.c
 *
 * Created: 5/15/2019 3:14:02 PM
 * Author : bhoj007
 */ 

#include <avr/io.h>
#define F_CPU 1600000
#include <util/delay.h>
#include <stdlib.h>

void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}
int main(void)
{
	DDRC = 0xFF;
	DDRA = 0;
	DDRD = 0xFF;
	DDRB = 0xFF;
	_delay_ms(50);
	
	ADMUX |=(1<<REFS0)|(1<<REFS1);
	ADCSRA |=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	
	int COUNT = 200;
	int count12 = 255;
	PWM_init();
	while(1)
	{
		if((PINA & (1<<PA7))==0)
		{
			PORTB &= ~(1<<PB0);
			OCR0=COUNT;
			_delay_ms(100);
		}
		if((PINA & (1<<PA6))==0)
		{
			PORTB &= ~(1<<PB0);
			OCR0=count12;
			_delay_ms(100);
		}
		
	}
}






