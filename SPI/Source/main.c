#include "main.h"

void IO_Init (void)
{
	DDRD |= 0x01;
}

void setup (void)
{
	IO_Init();
	LCD_Init();
	SPI_Master_Init();
	
	sei();
}

int main(void)
{
    setup();
	
	int8_t* str = (int8_t* ) "Hello, GitHub!";
	
	while (1) 
    {
		_delay_ms(1000);
		
		
		SPI_SendData(str);
		
		LCD_SetPosition(1, 1);
		LCD_SendString(SPI_ReceiveBuffer);
    }
}

