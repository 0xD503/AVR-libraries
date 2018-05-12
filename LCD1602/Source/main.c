#include "main.h"

void io_Ini (void)
{
	
}

void setup (void)
{
	io_Ini();
//	HC595_Init();
	LCD_Init();
	
	sei();
}

int main (void)
{
	setup();
	
//	int8_t a = 51;
// 	LCD_PutByte((a / 10) + ASCII_NULL);
// 	LCD_PutByte((a % 10) + ASCII_NULL);
	LCD_SetDDRAM(0x02);
	char string[] = "Pointers :)";
	LCD_SendString((int8_t *) string);
	LCD_SetPosition(1, 2);
	LCD_SendInteger(-7777);
	//LCD_SendString((int8_t *) "Are the best");
	
	while (1)
	{
		
	}
}