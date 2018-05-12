/*
 * Stepper.c
 *
 * Created: 11/20/2017 11:02:51 PM
 * Author : Developer
 */ 

#include "main.h"


void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	Stepper_Init();
	
	sei();
}

int main(void)
{
	setup();
	
	Stepper_Rotate(-45);
	
    while (1) 
    {
		
    }
}