#include "DHT11.h"

uint8_t DHT11_Data[5];
uint8_t DHT11_ErrorCode = 0x30;

void DHT11_Init (void)
{
	_delay_ms(1000);
}

void DHT11_StartComunication (void)
{
	DHT11_PORT |= 1 << DHT11_PIN;
	DHT11_DDR |= 1 << DHT11_PIN;
	_delay_ms(DHT11_RESET_TIME);
	
	DHT11_PORT &= ~(1 << DHT11_PIN);
	_delay_ms(DHT11_START_SIGNAL_TIME);
	
	DHT11_PORT |= 1 << DHT11_PIN;
	DHT11_DDR &= ~(1 << DHT11_PIN);
	_delay_us(DHT11_WAIT_FOR_RESPONSE_TIME);
}

uint8_t DHT11_Response (void)
{
	uint8_t DHT_Respond;
	
	_delay_us(40);
	if (!(DHT11_PINS & (1 << DHT11_PIN)))
	{
		_delay_us(80);
		if ((DHT11_PINS & (1 << DHT11_PIN)))
		{
			DHT_Respond = DHT11_RESPOND;
			_delay_us(40);
		}
		else	DHT_Respond = DHT11_DOES_NOT_RESPOND;
	}
	else	DHT_Respond = DHT11_DOES_NOT_RESPOND;
	
	return (DHT_Respond);
}

uint8_t DHT11_ReceiveData (void)
{
	cli();
	for (uint8_t i = 0; i < 5; i++)
	{
		DHT11_Data[i] = 0x00;
		for (int8_t j = 7; j >= 0; j--)
		{
			while (!(DHT11_PINS & (1 << DHT11_PIN)));
			_delay_us(30);
			if (DHT11_PINS & (1 << DHT11_PIN))
			{
				DHT11_Data[i] |= 1 << j;
				while (DHT11_PINS & (DHT11_PIN));
			}
			else	DHT11_Data[i] &= ~(1 << j);
		}
	}
	sei();
	
	uint8_t dataCorrect;
	if (DHT11_Data[4] == DHT11_Data[0] + DHT11_Data[1] + DHT11_Data[2] + DHT11_Data[3])	dataCorrect = 0xFF;
	else
	{
		dataCorrect = 0x00;
//		DHT11_ErrorCode = DHT11_CODE_2;
	}
	
	while(!(DHT11_PINS & (1 << DHT11_PIN)));
	
	return (dataCorrect);
}

void DHT11_ReadData (void)
{
	DHT11_StartComunication();
	if (DHT11_Response())
	{
		if (DHT11_ReceiveData()) DHT11_ErrorCode = 0x30;
		else	DHT11_ErrorCode = DHT11_CODE_2;
	}
	else	DHT11_ErrorCode = DHT11_CODE_1;
}