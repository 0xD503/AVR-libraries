/*
 * DS1307.c
 *
 * Created: 4/5/2018 8:40:50 AM
 *  Author: Developer
 */ 

#include "DS1307.h"

struct DS1307_TimeRegisters TimeRegistersTransmitBuffer = {0};
struct DS1307_TimeRegisters TimeRegistersReceiveBuffer = {0};

struct DS1307_TimeRegisters* TimeRegPointer = NULL;


uint8_t binToBCD (uint8_t binNumber)
{
	uint8_t highDigit = (binNumber / 10) << 4;
	uint8_t lowDigit = binNumber % 10;
	return (highDigit | lowDigit);
}

uint8_t BCDToBin (uint8_t BCDNumber)
{
	uint8_t highDigit = BCDNumber >> 4;
	uint8_t lowDigit = BCDNumber & (~(0xF0));
	return (highDigit * 10 + lowDigit);
}



void DS1307_PutByte (int8_t byte, uint8_t DS1307_RAMAddress)
{
	int8_t* DS1307_DataString = NULL;
	DS1307_DataString[0] = DS1307_WRITE_ADDRESS;
	DS1307_DataString[1] = DS1307_RAMAddress;
	DS1307_DataString[2] = byte;
	I2C_MT_TransmitData(DS1307_DataString, 3);
}

void DS1307_PutTimeByte (uint8_t byte, uint8_t DS1307_RAMAddress)
{
	byte = binToBCD(byte);
	DS1307_PutByte((uint8_t) byte, DS1307_RAMAddress);
}


void DS1307_SetSeconds (uint8_t seconds)
{
	DS1307_PutTimeByte(seconds, 0x00);
}

void DS1307_SetMinutes (uint8_t minutes)
{
	DS1307_PutTimeByte(minutes, 0x01);
}

void DS1307_SetHours (uint8_t hours)
{
	DS1307_PutTimeByte(hours, 0x02);
}

void DS1307_SetWeekday (uint8_t weekday)
{
	DS1307_PutTimeByte(weekday, 0x03);
}

void DS1307_SetDate (uint8_t date)
{
	DS1307_PutTimeByte(date, 0x04);
}

void DS1307_SetMonth (uint8_t month)
{
	DS1307_PutTimeByte(month, 0x05);
}

void DS1307_SetYear (uint8_t year)
{
	DS1307_PutTimeByte(year, 0x06);
}




void DS1307_ReceiveData (int8_t* placeToReceive, uint8_t DS1307_RAMAddress, uint8_t numberOfBytes)
{
	static int8_t* DS1307_DataString = NULL;
	DS1307_DataString[0] = DS1307_WRITE_ADDRESS;
	DS1307_DataString[1] = DS1307_RAMAddress;
	I2C_MT_TransmitData(DS1307_DataString, 2);
	DS1307_DataString[0] = DS1307_READ_ADDRESS;
	I2C_MT_TransmitData(DS1307_DataString, numberOfBytes);
	
	I2C_MR_ReceiveData(placeToReceive, numberOfBytes);
}

void DS1307_ReceiveTimeData (void)
{
	TimeRegPointer = &TimeRegistersReceiveBuffer;
	DS1307_ReceiveData((int8_t* ) TimeRegPointer, 0, 8);
	TimeRegPointer->seconds = BCDToBin(TimeRegPointer->seconds);
	TimeRegPointer->minutes = BCDToBin(TimeRegPointer->minutes);
	TimeRegPointer->hours = BCDToBin(TimeRegPointer->hours);
	TimeRegPointer->weekday = BCDToBin(TimeRegPointer->weekday);
	TimeRegPointer->date = BCDToBin(TimeRegPointer->date);
	TimeRegPointer->month = BCDToBin(TimeRegPointer->month);
	TimeRegPointer->year = BCDToBin(TimeRegPointer->year);
}


void DS1307_UpdateTime (void)
{
	DS1307_SetSeconds(TimeRegistersTransmitBuffer.seconds);
	DS1307_SetMinutes(TimeRegistersTransmitBuffer.minutes);
	DS1307_SetHours(TimeRegistersTransmitBuffer.hours);
	DS1307_SetWeekday(TimeRegistersTransmitBuffer.weekday);
	DS1307_SetDate(TimeRegistersTransmitBuffer.date);
	DS1307_SetMonth(TimeRegistersTransmitBuffer.month);
	DS1307_SetYear(TimeRegistersTransmitBuffer.year);
}


void DS1307_SetTime (void)
{
	DS1307_ReceiveTimeData();
	TimeRegPointer = &TimeRegistersReceiveBuffer;
	TimeRegistersTransmitBuffer.seconds = TimeRegPointer->seconds;
	TimeRegistersTransmitBuffer.minutes = TimeRegPointer->minutes;
	TimeRegistersTransmitBuffer.hours = TimeRegPointer->hours;
	TimeRegistersTransmitBuffer.weekday = TimeRegPointer->weekday;
	TimeRegistersTransmitBuffer.date = TimeRegPointer->date;
	TimeRegistersTransmitBuffer.month = TimeRegPointer->month;
	TimeRegistersTransmitBuffer.year = TimeRegPointer->year;
	
	DS1307_UpdateTime();
}

void DS1307_SelectWeekday (uint8_t weekday)
{
	switch (weekday)
	{
		
	}
}





void DS1307_LCD_Nokia_OutTime (void)
{
	DS1307_ReceiveTimeData();
	LCD_Nokia_SetPixelPosition(12, 8);
	LCD_Nokia_Send5CharString((int8_t* ) "Time: ");
	LCD_Nokia_Send5Integer(TimeRegPointer->hours);
	LCD_Nokia_Put5Char(':');
	LCD_Nokia_Send5Integer(TimeRegPointer->minutes);
	LCD_Nokia_SetPixelPosition(12, 16);
	LCD_Nokia_Send5CharString((int8_t* ) "Date: ");
	LCD_Nokia_Send5Integer(TimeRegPointer->month);
	LCD_Nokia_Put5Char('.');
	LCD_Nokia_Send5Integer(TimeRegPointer->date);
	LCD_Nokia_Put5Char('.');
	LCD_Nokia_Send5Integer(TimeRegPointer->year);
	LCD_Nokia_SetPixelPosition(12, 24);
	LCD_Nokia_Send5Integer(TimeRegPointer->weekday);
	LCD_Nokia_UpdateFullScreen();
}


void DS1307_SetTwelveHourMode (void)
{
	//	Set time format to 12 or 24 hour
	
}

// void DS1307_Clock (void)
// {
// 	//	Set CH bit to 1 or 0 in the 00h RTC register
// 	DS1307_PutByte(DS1307_CLOCK_HALT, 0x00);
// }

// void DS1307_EnableSQW (uint8_t frequency)
// {
	//	
	
// }