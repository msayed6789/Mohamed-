/*
 * Timers.h
 *
 * Created: 4/9/2023 4:53:57 AM
 *  Author: M.Sayed
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "Standard_Type.h"
#include "MEMMAP.h"
#include "Utlise.h"

/**************************************Timer_0************************************************************/
typedef enum {
TIMER0_NORMAL_MODE=0,
TIMER0_PHASECORRECT_MODE,
TIMER0_CTC_MODE,
TIMER0_FASTPWM_MODE	
}Timer0Mode_type;

typedef enum {
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING		
}Timer0Scaler_type;

typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;

void Timer0_init (Timer0Mode_type mode ,Timer0Scaler_type scaler);
void TIMER0_OC0Mode(OC0Mode_type mode);
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
void TIMER0_OV_SetCallBack(void(*local_fptr)(void));
void TIMER0_OCR_SetCallBack(void(*local_fptr)(void));

#define timer0_set(value)         TCNT0=value
#define timer0_OCR_set(value)     OCR0=value
#define timer0_stop()             TCCR0&=0xf8     //11111000

#endif /* TIMERS_H_ */