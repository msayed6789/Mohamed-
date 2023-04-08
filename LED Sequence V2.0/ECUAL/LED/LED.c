/*
 * LED.c
 *
 * Created: 4/5/2023 2:00:41 AM
 *  Author: Mohamed Sayed
 */ 

#include "LED.h"

/*
 void LED_init(LED_Num LED)
{
		DIO_InitPin(LED,OUTPUT);
}
void LED_init1All()
{
	u8 i;
	for (i=LED_1;i<LED_Total;i++)
	{
		LED_init(i);
	}
}
*/
void LED_ON (u8 LED )
{
	DIO_WRitePin(LED,HIGH);
}
void LED_OFF (u8 LED )
{
		DIO_WRitePin(LED,LOW);
}
