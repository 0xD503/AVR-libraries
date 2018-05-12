#include "main.h"

void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	LCD_Init();
	
	sei();
}

int main (void)
{
	setup();
	
//	EEPROM_WriteString((int8_t* ) "wqw", 413);
//	int8_t* f = NULL;
	int8_t r = 0xFF;
	for (uint8_t i = 0; i <= 100; i++)	EEPROM_PutByte(r, i);
	
	while (1)
	{
//		EEPROM_ReadString(f, 413);
		//r = EEPROM_GetByte(413);
		
		//LCD_SetPosition(1, 1);
//		LCD_SendString(f);
		//LCD_PutByte(r);
		
		//_delay_ms(1000);
	}
}