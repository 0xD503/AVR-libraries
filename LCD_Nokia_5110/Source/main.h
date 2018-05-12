#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPI_MASTER_MODE

#include "SPI.h"
#include "LCD_Nokia_5110.h"
#include "LCD_Nokia_5110_charset.h"

#endif /* MAIN_H_ */