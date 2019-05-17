
#define F_CPU 8000000UL					/* Define CPU Frequency e.g. here its 8MHz */

#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>					/* Include Delay header file */
#include <stdio.h>
#include <string.h>

#include "LCD_16x2_H_file.h"			/* Include LCD header file */
#include "SPI_Master_H_file.h"			/* Include SPI master header file */


int main(void)
{
	DDRC = 0XFF;
	DDRD =0xFF;
	uint8_t count;
	char buffer[5];

	LCD_Command (0x38);								/* Initialize 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);								/* Display ON, Cursor OFF command */
	LCD_Command (0x06);								/* Auto Increment cursor */
	LCD_Command (0x01);								/* Clear LCD command */
	LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */

	//LCD_Init();

	SPI_Init();
	
	LCD_String_xy(1, 0, "Master Device");
	LCD_String_xy(2, 0, "Sending Data: CSK ");
	SS_Enable;
	count = 0;
	while (1)
	{
		SPI_Write(count);
		sprintf(buffer, "%d   ", count);
		LCD_String_xy(2, 13, buffer);
		count++;
		_delay_ms(500);
	}
		
}