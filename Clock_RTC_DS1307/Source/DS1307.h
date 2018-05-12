/*
 * DS1307.h
 *
 * Created: 4/5/2018 8:40:29 AM
 *  Author: Developer
 */ 


#ifndef DS1307_H_
#define DS1307_H_

#include "main.h"

#define DS1307_WRITE_ADDRESS 0b11010000
#define DS1307_READ_ADDRESS 0b11010001

#define DS1307_CLOCK_HALT 0x80

#define DS1307_SUCCESS
#define DS1307_FAIL

struct DS1307_TimeRegisters
{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t weekday;
	uint8_t date;
	uint8_t month;
	uint8_t year;
};

struct DS1307_TimeRegisters TimeRegistersTransmitBuffer;
struct DS1307_TimeRegisters TimeRegistersReceiveBuffer;

struct DS1307_TimeRegisters* TimeRegPointer;


void DS1307_PutByte (int8_t byte, uint8_t DS1307_RAMAddress);
void DS1307_SendData (int8_t* data, uint8_t DS1307_RAMAddress, uint8_t numberOfBytes);

void DS1307_ReceiveData (int8_t* placeToReceive, uint8_t DS1307_RAMAddress, uint8_t numberOfBytes);
void DS1307_ReceiveTimeData (void);

void DS1307_SetTime (void);
void DS1307_UpdateTime (void);

void DS1307_LCD_Nokia_OutTime (void);

#endif /* DS1307_H_ */