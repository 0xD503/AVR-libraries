#include "main.h"

void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	LCD_Init();
	ADC_Init();
	
	sei();
}

int main (void)
{
	setup();
	
	uint16_t res  = 0;
	//ADC_NormalConversion(0);
	ADC_StartFreeRunningConversion(0);
	
	while (1)
	{
//		ADC_StartSingleConversion(0);
		res = ((ADC_ResultOfConversion % 1024) * ADC_REFERENCE_VOLTAGE);
		
		LCD_SetPosition(1, 1);
		
		LCD_SendString((int8_t *) "Voltage: ");
		
		LCD_PutByte((res / 1000) + ASCII_NULL);
		LCD_PutByte('.');
		
		LCD_PutByte(((res % 1000) / 100) + ASCII_NULL);
		LCD_PutByte((((res % 1000) % 100) / 10) + ASCII_NULL);
		LCD_PutByte((((res % 1000) % 100) % 10) + ASCII_NULL);
		
		_delay_ms(10);
	}
}