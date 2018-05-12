#include "main.h"

void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	LCD_Init();
	DHT11_Init();
	
	sei();
}

int main (void)
{
	setup();
	
	
	
	while (1)
	{
		DHT11_ReadData();
 		
		LCD_SetPosition(1,1);
		LCD_SendString((int8_t* ) "Temperature: ");
		LCD_PutByte((DHT11_Data[2] / 10) + ASCII_NULL);
		LCD_PutByte((DHT11_Data[2] % 10) + ASCII_NULL);
		LCD_SendString((int8_t* ) "°C");
		
		LCD_SetPosition(1,2);
		LCD_SendString((int8_t* ) "Humidity: ");
		LCD_PutByte((DHT11_Data[0] / 10) + ASCII_NULL);
		LCD_PutByte((DHT11_Data[0] % 10) + ASCII_NULL);
		LCD_PutByte('%');
		
		LCD_SetPosition(15, 2);
		LCD_PutByte(DHT11_ErrorCode);

		_delay_ms(100);
	}
}