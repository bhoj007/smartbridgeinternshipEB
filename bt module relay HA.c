/*
 * bt relay usart.c
 *
 * Created: 16-05-2019 01:16:13 PM
 * Author : bhoj007
 */ 


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define RELAY PORTB
char buffer[10];

void USARTInit(uint16_t ubrr_value)
{
	
	UBRRL = ubrr_value;
	UBRRH = (ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)| (1 << UCSZ1);
	UCSRB=(1<<RXEN)|(1<<TXEN);
}
char USARTReadchar()
{
	
	while(!(UCSRA & (1<<RXC)))
	{
	}
	return UDR;
}

void USARTWritechar(char data)
{
	while(!(UCSRA & (1<<UDRE)))
	{
		
	}
	UDR=data;
}
int main()
{
	USARTInit(77);
	DDRB=0xff;
	char data;
	RELAY = 0;
	while(1)
	{
		
		data=USARTReadchar();
		if(data =='1' || data =='3')
		{
			RELAY |= 0xff;
		}
		else if(data =='2' || data =='4')
		{
			RELAY = 0x00;
		}
	}
	return 0;
}

