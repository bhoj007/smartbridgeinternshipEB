/*
 * pot cntrl led.c
 *
 * Created: 5/15/2019 11:59:36 AM
 * Author : bhoj007
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
void PWM_init()
{
	
	TCCR0=(1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);
}

int main(void)
{
	DDRA=0x00;
	DDRB=0xFF;
	_delay_ms(50);
	ADMUX |=(1<<REFS0)|(1<<REFS1);
	ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	int16_t COUNTA=0;
	ADCSRA|=(1<<ADSC);
	PWM_init();
	while (1)
	{
		    COUNTA=ADC/4;
			if(COUNTA > 0)
			{
				OCR0 = COUNTA;
			}
		}	
	}
	



			
