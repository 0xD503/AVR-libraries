#include "main.h"

void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	USART_Init();
	
	sei();
}

int main (void)
{
	setup();
	
	int8_t* a = (int8_t* ) "tau";
	//USART_PutByte (a);
	
	while (1)
	{
		_delay_ms(1000);
		USART_SendString((int8_t* ) a);
	}
}