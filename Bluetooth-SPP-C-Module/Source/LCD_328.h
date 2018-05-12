/*
 * LCD_4_bit.c
 *
 * Created: 10/19/2017 2:36:17 PM
 *  Author: Developer
 */ 

#ifndef LCD_328_H_
#define LCD_328_H_

#include "main.h"

#define LCD_DDR DDRB
#define LCD_PORT PORTB
#define LCD_PINS PINB

#define LCD_ENABLE_PIN 3
#define LCD_RW_PIN 2
#define LCD_RS_PIN 1


#define LCD_PORT_INIT LCD_PORT |= 0xFE

#define LCD_CLEAR_DATA_PINS LCD_PORT &= ~(0xF0)

#define LCD_STROBE_UP LCD_PORT |= (1 << LCD_ENABLE_PIN)
#define LCD_STROBE_DOWN LCD_PORT &= ~ (1 << LCD_ENABLE_PIN)

#define LCD_DATA LCD_PORT |= (1 << LCD_RS_PIN);
#define LCD_INSTRUCTION LCD_PORT &= ~ (1 << LCD_RS_PIN)

#define LCD_WRITE LCD_PORT &= ~ (1 << LCD_RW_PIN);
#define LCD_READ LCD_PORT |= (1 << LCD_RW_PIN);

#define ASCII_NUL 0x30

void LCD_Init (void);
void LCD_putData (int8_t data);
void LCD_sendString (int8_t* string);
void LCD_setPosition (uint8_t x, uint8_t y);
void LCD_setDDRAM (uint8_t address);
void LCD_clearDisplay (void);

#endif /* LCD_328_H_ */