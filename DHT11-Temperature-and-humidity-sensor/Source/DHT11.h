/*
 * DHT11.h
 *
 * Created: 1/13/2018 11:43:38 AM
 *  Author: Developer
 */ 


#ifndef DHT11_H_
#define DHT11_H_

#include "main.h"

#define DHT11_DDR DDRC
#define DHT11_PORT PORTC
#define DHT11_PINS PINC

#define DHT11_PIN 0

#define DHT11_RESPOND 0xFF
#define DHT11_DOES_NOT_RESPOND 0x00

#define	DHT11_CODE_1 0x31
#define	DHT11_CODE_2 0x32

#define DHT11_RESET_TIME 20
#define DHT11_START_SIGNAL_TIME 18
#define DHT11_WAIT_FOR_RESPONSE_TIME 30

extern uint8_t DHT11_Data[5];
extern uint8_t DHT11_ErrorCode;

void DHT11_Init (void);
void DHT11_ReadData (void);

#endif /* DHT11_H_ */