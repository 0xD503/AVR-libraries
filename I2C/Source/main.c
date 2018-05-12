/*
 * I2C.c
 *
 * Created: 3/21/2018 4:12:09 PM
 * Author : Developer
 */ 

#include "main.h"

void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	I2C_Init(I2C_SCL_FREQUENCY, I2C_PRESCALER);
	
	sei();
}

int main (void)
{
	setup();
	
	
	
	while (1)
	{
		
	}
}