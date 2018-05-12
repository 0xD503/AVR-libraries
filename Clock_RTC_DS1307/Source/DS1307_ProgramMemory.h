/*
 * DS1307_ProgramMemory.h
 *
 * Created: 4/9/2018 8:49:53 AM
 *  Author: Developer
 */ 


#ifndef DS1307_PROGRAMMEMORY_H_
#define DS1307_PROGRAMMEMORY_H_

#include <avr/pgmspace.h>

static const int8_t* DS1307_StringsOfWeekday[7] PROGMEM = {
	"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
};

static const int8_t* DS1307_StringsOfWeekday[12] PROGMEM = {
	"January"
};


#endif /* DS1307_PROGRAMMEMORY_H_ */