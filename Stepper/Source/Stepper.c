#include "Stepper.h"

void Stepper_Init (void)
{
	STEPPER_DDR |= 1 << STEPPER_IN_A | 1 << STEPPER_IN_B | 1 << STEPPER_IN_C | 1 << STEPPER_IN_D;
	STEPPER_PORT &= ~(1 << STEPPER_IN_A | 1 << STEPPER_IN_B | 1 << STEPPER_IN_C | 1 << STEPPER_IN_D);
}

void Stepper_Step_1 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_A | 1 << STEPPER_IN_B;
	STEPPER_DELAY;
}

void Stepper_Step_2 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_B;
	STEPPER_DELAY;
}

void Stepper_Step_3 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_B | 1 << STEPPER_IN_C;
	STEPPER_DELAY;
}

void Stepper_Step_4 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_C;
	STEPPER_DELAY;
}

void Stepper_Step_5 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_C | 1 << STEPPER_IN_D;
	STEPPER_DELAY;
}

void Stepper_Step_6 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_D;
	STEPPER_DELAY;
}

void Stepper_Step_7 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_D | 1 << STEPPER_IN_A;
	STEPPER_DELAY;
}

void Stepper_Step_8 (void)
{
	STEPPER_PORT = 1 << STEPPER_IN_A;
	STEPPER_DELAY;
}

void Stepper_HalfStepping_ClockWise (void)
{
	Stepper_Step_8();
	Stepper_Step_7();
	Stepper_Step_6();
	Stepper_Step_5();
	Stepper_Step_4();
	Stepper_Step_3();
	Stepper_Step_2();
	Stepper_Step_1();
}

void Stepper_HalfStepping_AntiClockWise (void)
{
	Stepper_Step_1();
	Stepper_Step_2();
	Stepper_Step_3();
	Stepper_Step_4();
	Stepper_Step_5();
	Stepper_Step_6();
	Stepper_Step_7();
	Stepper_Step_8();
}

void Stepper_TwoPhase_Clockwise (void)
{
	Stepper_Step_7();
	Stepper_Step_5();
	Stepper_Step_3();
	Stepper_Step_1();
}

void Stepper_TwoPhase_AntiClockwise (void)
{
	Stepper_Step_1();
	Stepper_Step_3();
	Stepper_Step_5();
	Stepper_Step_7();
}

void Stepper_OnePhase_ClockWise (void)
{
	Stepper_Step_8();
	Stepper_Step_6();
	Stepper_Step_4();
	Stepper_Step_2();
}

void Stepper_OnePhase_AntiClockWise (void)
{
	Stepper_Step_2();
	Stepper_Step_4();
	Stepper_Step_6();
	Stepper_Step_8();
}

void Stepper_Rotate (int16_t angle)
{
	uint8_t stepCounter;
	if ((angle < 181) && (angle > 0))
	{
		stepCounter = angle / 4;
	} 
	else if ((angle > 180) && (angle < 361))
	{
		stepCounter = (((angle - 180) / 4) + 45);
	}
	else if ((angle < 0) && (angle > (-181)))
	{
		stepCounter = ((abs(angle)) / 4);
	} 
	else if ((angle < (-180)) && (angle > (-360)))
	{
		stepCounter = ((((abs(angle)) - 180) / 4) + 45);
	}
	else	;
	
	stepCounter /= STEPPER_STEP_ANGLE;
	for (uint8_t counter = 0; counter < stepCounter; counter++)
	{
		if (angle > 0)
		{
			Stepper_TwoPhase_AntiClockwise();
		} 
		else
		{
			Stepper_TwoPhase_Clockwise();
		}
	}
}