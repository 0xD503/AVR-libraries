/*
 * LCD_Nokia_5110.c
 *
 * Created: 3/4/2018 1:29:14 PM
 * Author : Developer
 */ 

#include "main.h"

void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	SPI_Master_Init();
	LCD_Nokia_Init();
	
	sei();
}

int main (void)
{
	setup();
	
	//LCD_Nokia_SetPixelPosition(52, 32);
	//LCD_Nokia_SendCharString((int8_t* ) "Hello, Ruslan!! Let's GO!");
	LCD_Nokia_Send12CharString((int8_t* ) "12.43162");
	//LCD_Nokia_SendImage(SparkfunLogo);
//	LCD_Nokia_UpdateScreen(23, 4, 75, 5);
	
	//LCD_Nokia_DrawUnfilledRectangle(43, 40, 27, 10);
	LCD_Nokia_UpdateFullScreen();
	_delay_ms(500);
	
	while (1)
	{
		
	}
}