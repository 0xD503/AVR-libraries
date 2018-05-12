/*
 * ADC.h
 *
 * Created: 1/27/2018 10:17:51 PM
 *  Author: Developer
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "main.h"

#define ADC_DDR DDRC
#define ADC_PORT PORTC
#define ADC_PINS PINC

#define ADC_PRESCALER 1024
#define ADC_FREQUENCY (F_CPU / ADC_PRESCALER)

#define ADC_REFERENCE_VOLTAGE 5

extern volatile uint16_t ADC_ResultOfConversion;


void ADC_Init (void);

#ifdef ADC_SINGLE_CONVERSION_MODE

void ADC_StartSingleConversion (uint8_t channel);

#endif


#ifdef ADC_NORMAL_CONVERSION_MODE

void ADC_NormalConversion (uint8_t channel);
void ADC_StopConversion (void);

#endif

#ifdef ADC_FREE_RUNNIG_CONVERSION_MODE

void ADC_StartFreeRunningConversion (uint8_t channel);
void ADC_StopConversion (void);

#endif

#endif /* ADC_H_ */