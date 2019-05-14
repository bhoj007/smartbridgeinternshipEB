

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
#define enable 5
#define regselect 7
void sendcommand(unsigned char command);
void sendcharacter(unsigned char character);
void sendstring(char *string_of_characters);



int main(void)
{
    /* Replace with your application code */
	DDRC=0xFF;
		DDRA=0x00;
		DDRD=0xFF;
		DDRB=0xFF;
	_delay_ms(50);
	ADMUX |=(1<<REFS0)|(1<<REFS1);
	ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	int16_t COUNTA=0;
	char SHOWA[3];
	sendcommand(0x01);
	_delay_ms(50);
	sendcommand(0x38);
	_delay_ms(50);
	sendcommand(0b00001111);
	_delay_ms(50);
	ADCSRA|=(1<<ADSC);
    while (1) 
    {
		COUNTA=ADC/4;
		if(COUNTA > 250)
		{
			PORTB=0xFF;
		}
		else
		{
			
			PORTB=0x00;
		}
		sendstring("smartbridge");
		sendcommand(0x80+0x40+0);
		_delay_ms(2000);
		sendstring("LDR=");
		sendcommand(0x80+0x40+8);
		itoa(COUNTA,SHOWA,10);
		sendstring(SHOWA);
		sendstring("");
		sendcommand(0x80+26);
		_delay_ms(2000);
    }
}

void sendcommand(unsigned char command)

{
	PORTC=	command;
	PORTD&=~(1<<regselect);
	PORTD|=(1<<enable);
	_delay_ms(20);
	PORTD&=~(1<<enable);
	PORTC=0;
	
}
void sendcharacter(unsigned char character)
{
	PORTC=	character;
	PORTD|=(1<<regselect);
	PORTD|=(1<<enable);
	_delay_ms(20);
	PORTD&=~(1<<enable);
	PORTC=0;
	
}
void sendstring(char* string_of_characters)
{
	while(*string_of_characters>0)
	{
		sendcharacter(*string_of_characters++);
	}
}
