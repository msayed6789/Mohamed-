/*
 * LED.h
 *
 * Created: 4/5/2023 2:01:12 AM
 *  Author: AIO
 */ 


#ifndef LED_H_
#define LED_H_
#include "DIO_Interface.h"
/***************************LED Configuration******************************************************/
#define  LED1      PINA0
#define  LED2      PINA1
#define  LED3      PINA2
#define  LED4      PINA3
#define  LED5      PINA4
#define  LED6      PINA5
/*************************************************************************************************/
/*
typedef enum {
	LED_1=LED1,
	LED_2,
	LED_3,
	LED_4,
	LED_5,
	LED_6,
	LED_Total
}LED_Num;
void LED_init1All(void);      //The LED PINS must be behind each other  
void LED_init(LED_Num LED);
*/
typedef enum{
	blank_1,
	blank_2,
	blank_3,
	blank_4,
	blank_5
}Blank_Type;
void LED_Blank(Blank_Type Blank);
void LED_StopBlank(void);
//void blank(void);
void LED_ON (u8 LED );
void LED_OFF (u8 LED );


#endif /* LED_H_ */