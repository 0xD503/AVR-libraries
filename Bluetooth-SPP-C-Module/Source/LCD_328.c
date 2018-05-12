#include "LCD_328.h"

uint8_t LCD_Address;
uint8_t LCD_Data;

void LCD_getAddressAndBFStatus ()
{
	LCD_DDR = (LCD_DDR & 0x0F) | (0x0E);	//
	LCD_PORT &= ~ (0xF0);	// Clear Data pins
	LCD_READ;	// Read mode
	LCD_INSTRUCTION;	// RS = 0
	
	LCD_STROBE_UP;
	asm("nop");	// Waiting for 
	asm("nop");
	LCD_Address = LCD_PINS;	// Get high nibble
	LCD_STROBE_DOWN;	// Strobe
	asm("nop");
	asm("nop");
	LCD_Address &= ~ (0x0F);	// Prepare low nibble
	LCD_STROBE_UP;
	asm("nop");
	asm("nop");
	uint8_t lowNibble = LCD_PINS;	// Get low nibble
	LCD_STROBE_DOWN;
	lowNibble >>= 4;	//
	LCD_Address |= lowNibble;	//
	
	LCD_DDR |= 0xF0;
}

void checkBF (void)
{
	loop:
	LCD_getAddressAndBFStatus();	// Get address and BF status
	while (0x80 & LCD_Address)	goto loop;
}

void LCD_sendInstructionAndData (uint8_t byte, uint8_t mode)
{
	LCD_WRITE;
	if (mode == 0)	LCD_INSTRUCTION;
	else	LCD_DATA;
	
	uint8_t lowNibble = byte << 4;
	byte &= ~(0x0F);
	LCD_CLEAR_DATA_PINS;
	LCD_PORT |= byte;
	LCD_STROBE_UP;
	asm("nop");
	asm("nop");
	asm("nop");
	LCD_STROBE_DOWN;
	asm("nop");
	asm("nop");
	LCD_CLEAR_DATA_PINS;
	LCD_PORT |= lowNibble;
	LCD_STROBE_UP;
	asm("nop");
	asm("nop");
	asm("nop");
	LCD_STROBE_DOWN;
	
	checkBF();
}

void LCD_putInstruction (uint8_t instruction)
{
	LCD_sendInstructionAndData(instruction, 0);
}

void LCD_putData (int8_t data)
{
	LCD_sendInstructionAndData(data, 1);
}

void LCD_sendString (int8_t* string)
{
	while (* string != '\0')
	{
		LCD_putData(* string);
		string++;
	}
}

void LCD_setPosition (uint8_t x, uint8_t y)
{
	uint8_t position = ((x - 1) + (y - 1) * 0x40) | 0x80;
	LCD_putInstruction(position);
}

void LCD_setDDRAM (uint8_t address)
{
	address |= 0x80;
	LCD_putInstruction(address);
}

void clearDisplay (void)
{
	LCD_putInstruction(0x01);
}

void LCD_getData ()
{
	LCD_DDR = (LCD_DDR & 0x0F) | (0x0E);
	LCD_READ;
	LCD_DATA;
	
	LCD_STROBE_UP;
	asm("nop");
	asm("nop");
	LCD_Data = LCD_PINS;
	LCD_STROBE_DOWN;
	asm("nop");
	asm("nop");
	LCD_Data &= ~ (0x0E);
	LCD_STROBE_UP;
	asm("nop");
	asm("nop");
	uint8_t lowNibble = LCD_PINS;
	LCD_STROBE_DOWN;
	lowNibble >>= 4;
	LCD_Data |= lowNibble;
	
	LCD_DDR |= 0xF0;
	checkBF();
}

void sendInstructionLCD8 (uint8_t byte)
{
	LCD_PORT = byte;
	LCD_STROBE_UP;
	asm ("nop");
	asm ("nop");
	asm ("nop");
	LCD_STROBE_DOWN;
}

void LCD_Init (void)
{
	_delay_ms(16);
	sendInstructionLCD8(0x30);	// 8-bit mode
	_delay_us(4500);
	sendInstructionLCD8(0x30);	// 8-bit mode
	_delay_us(115);
	sendInstructionLCD8(0x30);	// 8-bit mode
	checkBF();	// Busy Flag waiting
	sendInstructionLCD8(0x20);	// 4-bit mode
	checkBF();	// 
	LCD_putInstruction(0x28);	// 4-bit mode, 2 lines, caracter font 5x8
	LCD_putInstruction(0x14);	// 
	LCD_putInstruction(0x0F);	// Display on, cursor on, blinking on
	LCD_putInstruction(0x06);	// 
	LCD_putInstruction(0x10);	// Entry mode set
	LCD_putInstruction(0x01);	// Clear display
}