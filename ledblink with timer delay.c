/*
 * ledblink with timer delay.c
 *
 * Created: 5/15/2019 10:38:05 AM
 * Author : bhoj007
 */ 

#include <avr/io.h>
#define  LED PB0


int main(void)
{
	uint8_t timeroverflowcount=0;
	DDRB=0XFF;
	TCNT0=0X00;
	TCCR0=(1<<CS00)|(1<<CS02);
	while(1)
	{
		while((TIFR & 0X01) == 0);
		TCNT0 = 0X00;
		TIFR = 0X01;
		timeroverflowcount++;
		if(timeroverflowcount>=5)
		{
			PORTB ^=(0X01 << LED);
			timeroverflowcount=0;
		}
	}
}

