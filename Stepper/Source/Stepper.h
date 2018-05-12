/*
 * Stepper.h
 *
 * Created: 11/20/2017 11:04:52 PM
 *  Author: Developer
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#include "main.h"

#define STEPPER_STEP_ANGLE 1
#define STEPPER_STEP_LIMITER_LOOP (90 / STEPPER_STEP_ANGLE)

#define STEPPER_DDR DDRB
#define STEPPER_PORT PORTB

#define STEPPER_IN_A PORTB0
#define STEPPER_IN_B PORTB1
#define STEPPER_IN_C PORTB2
#define STEPPER_IN_D PORTB3

#define STEPPER_DELAY _delay_ms(5)


void Stepper_Init (void);

void Stepper_Step_1 (void);
void Stepper_Step_2 (void);
void Stepper_Step_3 (void);
void Stepper_Step_4 (void);
void Stepper_Step_5 (void);
void Stepper_Step_6 (void);
void Stepper_Step_7 (void);
void Stepper_Step_8 (void);

void Stepper_HalfStepping_ClockWise (void);
void Stepper_HalfStepping_AntiClockWise (void);

void Stepper_TwoPhase_Clockwise (void);
void Stepper_TwoPhase_AntiClockwise (void);

void Stepper_OnePhase_ClockWise (void);
void Stepper_OnePhase_AntiClockWise (void);

void Stepper_Rotate (int16_t angle);

#endif /* STEPPER_H_ */