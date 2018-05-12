/*
 * HC595.h
 *
 * Created: 12/10/2017 11:46:46 AM
 *  Author: Developer
 */ 


#ifndef HC595_H_
#define HC595_H_

#include "main.h"

//	Set HC595 ports and pins
#define HC595_DDR DDRB
#define HC595_PORT PORTB
#define HC595_PINS PINB

#define HC595_DATA_PIN 0
#define HC595_OUTPUT_ENABLE_PIN 1
#define HC595_LATCH_CLOCK_PIN 2
#define HC595_SHIFT_CLOCK_PIN 3
#define HC595_RESET_PIN 4

//	#####################################################

//	Macros for controlling HC595

#define HC595_RESET HC595_PORT &= ~(1 << HC595_RESET_PIN)
#define HC595_CLEAR_RESET HC595_PORT |= 1 << HC595_RESET_PIN
#define HC595_SHIFT_CLOCK_HIGH HC595_PORT |= 1 << HC595_SHIFT_CLOCK_PIN
#define HC595_SHIFT_CLOCK_LOW HC595_PORT &= ~(1 << HC595_SHIFT_CLOCK_PIN)
#define HC595_LATCH_CLOCK_HIGH HC595_PORT |= 1 << HC595_LATCH_CLOCK_PIN
#define HC595_LATCH_CLOCK_LOW HC595_PORT &= ~(1 << HC595_LATCH_CLOCK_PIN)
#define HC595_OUTPUT_ENABLE HC595_PORT &= ~(1 << HC595_OUTPUT_ENABLE_PIN)
#define HC595_OUTPUT_DISABLE HC595_PORT |= 1 << HC595_OUTPUT_ENABLE_PIN

//	#####################################################

// typedef struct HC595_DataPins
// {
// 	uint8_t bit0:1;
// 	uint8_t bit1:1;
// 	uint8_t bit2:1;
// 	uint8_t bit3:1;
// 	uint8_t bit4:1;
// 	uint8_t bit5:1;
// 	uint8_t bit6:1;
// 	uint8_t bit7:1;
// };

void HC595_Init (void);
void HC595_PutByteWithoutScrolling (uint8_t byte);
void HC595_PutByteWithScrolling (uint8_t byte);


#endif /* HC595_H_ */