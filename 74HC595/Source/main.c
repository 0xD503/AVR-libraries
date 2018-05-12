#include "main.h"


void IO_Init (void)
{
	
}

void setup (void)
{
	IO_Init();
	HC595_Init();
	
	sei();
}

int main(void)
{
	setup();
	
  	int8_t r = 0b10100111;
	HC595_PutByteWithoutScrolling(r);
//	HC595_PutByteWithScrolling(r);
	
    while (1) 
    {
		
    }
}

