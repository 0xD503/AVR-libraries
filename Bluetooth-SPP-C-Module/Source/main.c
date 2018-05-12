#include "main.h"


#define LED_DDR DDRD
#define LED_PORT PORTD
#define LED_PINS PIND

#define LED_PIN 7

// const int8_t* ledOn = (int8_t* ) "Led is on";
// const int8_t* ledOff = (int8_t* ) "Led is off";

void IO_Init (void)
{
	LED_DDR |= 1 << LED_PIN;
	LED_PORT &= ~(1 << LED_PIN);
}

void setup (void)
{
	IO_Init();
	USART_Init();
	//LCD_Init();
	
	sei();
}

int main(void)
{
	setup();
	
	int8_t var;
	
//	USART_SendString((int8_t* )"AT+RESET\r\n");
	
	
    while (1) 
    {
//		while (USART_GetByte() == 0);
	    var = USART_GetByte();
		
		switch (var)
		{
			case 'a':
			{
				LED_PORT &= ~(1 << LED_PIN);
				//USART_PutByte('l');
				USART_SendString((int8_t* ) "LED: OFF");
				var = 0x00;	break;
			}
			
			case 'b':
			{
				LED_PORT |= 1 << LED_PIN;
				//USART_PutByte('k');
				USART_SendString((int8_t* ) "LED: ON");
				var = 0x00;	break;
			}
				
			default:	break;
		}
    }
}

