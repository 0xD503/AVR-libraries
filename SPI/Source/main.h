#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>

#define F_CPU 8000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#define SPI_MASTER_MODE

#include "LCD_328.h"
#include "SPI.h"

#endif /* MAIN_H_ */