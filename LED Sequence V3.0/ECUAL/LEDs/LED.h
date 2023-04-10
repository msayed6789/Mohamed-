/*
 * LED.h
 *
 * Created: 4/5/2023 2:01:12 AM
 *  Author: AIO
 */ 


#ifndef LED_H_
#define LED_H_
#include "DIO_Interface.h"
#include "Timers.h"
/*****************************************LED Configuration*************************************************/
#define  LED1      PINA0
#define  LED2      PINA1
#define  LED3      PINA2
#define  LED4      PINA3
#define  LED5      PINA4
#define  LED6      PINA5
/*****************************************Blank Configuration************************************************/
#define Max_noBlanks           5              //The Maximum number of blanks that you can use is 5
/*
Description the blank function:-
The CPU Frequency = 8MHz
The Prescaler = 256
The Minimum Blank Time = 8.2ms
The Maximum Blank Time = 2050ms
*/
/************************************************************************************************************/
typedef enum{
	blank_1=0,
	blank_2,
	blank_3,
	blank_4,
	blank_5
}Blank_Type;
typedef enum{
	Wrong_Time,
	Done
}Blank_Status;
void LED_ON (u8 LED );
void LED_OFF (u8 LED );
void LED_StopBlank(void);
Blank_Status LED_Blank_init(u32 Time_ON,u32 Time_Off,Blank_Type blank);
void LED_Blank(Blank_Type Blank);


#endif /* LED_H_ */