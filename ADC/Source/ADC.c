/*
 * ADC.c
 *
 * Created: 1/27/2018 10:18:10 PM
 *  Author: Developer
 */ 

#include "ADC.h"

//	an absolute error +-2 LSB
volatile uint16_t ADC_ResultOfConversion = 0;


void ADC_Init (void)
{
	ADMUX	|= 0 << REFS1 | 1 << REFS0	\
			| 0 << ADLAR	\
			| 0 << MUX3 | 0 << MUX2 | 0 << MUX1 | 0 << MUX0;
	
	ADCSRA	|= 0 << ADEN | 0 << ADSC | 0 << ADATE | 0 << ADIF | 0 << ADIE	\
			| 1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0;										//	ADC frequency = 125 KHz
	
	DIDR0	|= 1 << ADC0D;
}

#ifdef ADC_SINGLE_CONVERSION_MODE

void ADC_StartSingleConversion (uint8_t channel)
{
	ADMUX = ((ADMUX & 0xF8) | channel);
	ADCSRA |= 1 << ADEN | 1 << ADSC | 0 << ADATE | 0 << ADIF | 1 << ADIE;
	
	_delay_us(104);
}


ISR (ADC_vect)
{
	ADC_ResultOfConversion = ADCL;
	ADC_ResultOfConversion |= ADCH << 8;
}

#endif



#ifdef ADC_NORMAL_CONVERSION_MODE

void ADC_NormalConversion (uint8_t channel)
{
	ADMUX	= ((ADMUX & 0xF8) | channel);
	ADCSRA	|= 1 << ADEN | 1 << ADSC | 0 << ADATE | 0 << ADIF | 1 << ADIE;				//	Turn on ADC, start conversion, enable ADC interrupt
	
	_delay_us(104);																		//	Wait 13 ADC cycles, as written in data sheet
}

void ADC_StopConversion (void)
{
	ADCSRA	&= ~(1 << ADEN | 1 << ADSC | 0 << ADATE | 0 << ADIF | 1 << ADIE | 0 << ADPS2 | 0 << ADPS1 | 0 << ADPS0);
}


ISR (ADC_vect)
{
	ADC_ResultOfConversion = ADCL;
	ADC_ResultOfConversion |= ADCH << 8;
	
	ADCSRA |= 1 << ADSC;
}

#endif



#ifdef ADC_FREE_RUNNIG_CONVERSION_MODE

void ADC_StartFreeRunningConversion (uint8_t channel)
{
	ADMUX	= ((ADMUX & 0xF8) | channel);
	ADCSRA	|= 1 << ADEN | 1 << ADSC | 1 << ADATE | 1 << ADIE;
	
	_delay_us(104);
}

void ADC_StopConversion (void)
{
	ADCSRA	&= ~(1 << ADEN | 1 << ADSC | 1 << ADATE | 1 << ADIE | 0 << ADPS2 | 0 << ADPS1 | 0 << ADPS0);
}


ISR (ADC_vect)
{
	ADC_ResultOfConversion = ADCL;
	ADC_ResultOfConversion |= ADCH << 8;
}

#endif