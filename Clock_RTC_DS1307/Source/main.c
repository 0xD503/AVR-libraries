/*
 * I2C.c
 *
 * Created: 3/21/2018 4:12:09 PM
 * Author : Developer
 */ 

#include "main.h"

void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	I2C_Init(I2C_SCL_FREQUENCY, I2C_PRESCALER_BITS);
	SPI_Master_Init();
	
	LCD_Nokia_Init();
	
	sei();
}

int main (void)
{
	setup();
	
	LCD_Nokia_DrawUnfilledRectangle(0, 0, 83, 40, 4);
	
	while (1)
	{
		DS1307_LCD_Nokia_OutTime();
		
		_delay_ms(10000);
	}
}