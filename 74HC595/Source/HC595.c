#include "HC595.h"

void HC595_ResetShiftRegister (void)
{
	HC595_RESET;				//	RESET PIN = 0
	/*_delay_ms(10);*/			//	For low frequency MCU clock wait 10 ms
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	HC595_CLEAR_RESET;			//	RESET PIN = 1
	/*_delay_ms(10);*/
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
}

void HC595_Init (void)
{
	HC595_DDR |= 1 << HC595_DATA_PIN | 1 << HC595_OUTPUT_ENABLE_PIN | 1 << HC595_LATCH_CLOCK_PIN | 1 << HC595_SHIFT_CLOCK_PIN | 1 << HC595_RESET_PIN;		//	Set HC595 pins as outputs
	HC595_ResetShiftRegister();																																//	RESET
	HC595_OUTPUT_ENABLE;																																	//	Output Enable = 0
}

void HC595_Shift (void)
{
	HC595_SHIFT_CLOCK_HIGH;				//	SC = 1
	//_delay_ms(10);
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	HC595_SHIFT_CLOCK_LOW;				//	SC = 0
	//_delay_ms(10);
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
}

void HC595_Latch (void)
{
	HC595_LATCH_CLOCK_HIGH;				//	Latch pin = 1
	//_delay_ms(10);
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	HC595_LATCH_CLOCK_LOW;				// Latch pin = 0
	//_delay_ms(10);
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
	asm ("nop");
}

uint8_t HC595_MirrorByte (uint8_t byte)
{
	uint8_t temp = 0;
	uint8_t mirrorByte = 0;
	for (int8_t i = 7; i >= 0; i--)
	{
		temp = byte & 0x01;
		byte >>= 1;
		if (temp)	mirrorByte |= (1 << i);
		else mirrorByte &= ~(1 << i);
	}
	
	return (mirrorByte);
}

void HC595_PutByteWithoutScrolling (uint8_t byte)										//	In this function the latch occurs after the transmission of the whole byte
{
	uint8_t temp = 0;
	byte = HC595_MirrorByte(byte);
	for (uint8_t i = 0; i < 8; i++)
	{
		temp = byte & 0x01;
		byte >>= 1;
		if (temp)	HC595_PORT |= 1 << HC595_DATA_PIN;
		else	HC595_PORT &= ~(1 << HC595_DATA_PIN);
		HC595_Shift();
	}
	HC595_Latch();
}

void HC595_PutByteWithScrolling (uint8_t byte)										//	In this function the latch occurs after the transmission of each bit
{
	uint8_t temp;
	byte = HC595_MirrorByte(byte);
	for (uint8_t i = 0; i < 8; i++)
	{
		temp = byte & 0x01;
		byte >>= 1;
		if (temp)	HC595_PORT |= 1 << HC595_DATA_PIN;
		else	HC595_PORT &= ~(1 << HC595_DATA_PIN);
		HC595_Shift();
		HC595_Latch();
	}
}