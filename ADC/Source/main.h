#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>

#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

//	#define ADC_SINGLE_CONVERSION_MODE
//	#define ADC_NORMAL_CONVERSION_MODE
#define ADC_FREE_RUNNIG_CONVERSION_MODE

#include "LCD_328.h"
#include "ADC.h"


#endif /* MAIN_H_ */