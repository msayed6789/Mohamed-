/*
 * App.c
 *
 * Created: 4/5/2023 3:32:12 AM
 *  Author: Mohamed Sayed
 */ 
#include "App.h"
volatile u8 Press_count=0;
void APP_Init()
{
	DIO_init();
}
void APP_Start()
{
	if (Button_Check(Button1)==Pressed)
	{
		Press_count+=1;
		if (Press_count==9)
		{
			Press_count=1;
		}
	}
	else
	{
		//do nothing
	}
	switch(Press_count)
	{
		case 1:
		LED_ON(LED1);
		break;
		case 2:
		LED_ON(LED2);
		break;
		case 3:
		LED_ON(LED3);
		break;
		case 4:
		LED_ON(LED4);
		break;
		case 5:
		LED_OFF(LED1);
		break;
		case 6:
		LED_OFF(LED2);
		break;
		case 7:
		LED_OFF(LED3);
		break;
		case 8:
		LED_OFF(LED4);
		break;
	}
	
}