/*
 * LED.c
 *
 * Created: 4/5/2023 2:00:41 AM
 *  Author: Mohamed Sayed
 */ 


#include "LED.h"
/****************************************Blank Configuartion***********************************************/
static u32 min_time=8200;
static u32 max_time=2050000;
static u8 TCNT_Value=100;
u32 Blank_typ[Max_noBlanks][2];
extern volatile u8 Flag_ON;
extern volatile u8 Blank;
/*********************************************************************************************************/
static void blank1(void);
static void blank2(void);
static void blank3(void);
static void blank4(void);
static void blank5(void);

void LED_ON (u8 LED )
{
	DIO_WRitePin(LED,HIGH);
}
void LED_OFF (u8 LED )
{
		DIO_WRitePin(LED,LOW);
}

Blank_Status LED_Blank_init(u32 Time_ON,u32 Time_Off,Blank_Type blank)
{
	if (((u32)(Time_Off+Time_ON)*1000)>max_time||((u32)(Time_Off+Time_ON)*1000)<min_time)
	{
		return Wrong_Time;
	}
	else 
	{
		Blank_typ[blank][0]=(Time_Off*1000)/5000;
		Blank_typ[blank][1]=(Time_ON*1000)/5000+Blank_typ[blank][0];
		return Done;
	}
}
void LED_Blank(Blank_Type Blank)
{
		timer0_set(TCNT_Value);
		
		switch (Blank)
		{
			case blank_1:
			TIMER0_OV_SetCallBack(blank1);
			Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_256);	

			break;
			case blank_2:
			TIMER0_OV_SetCallBack(blank2);
			Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_256);
			break;
			case blank_3:
			TIMER0_OV_SetCallBack(blank3);
			Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_256);
			break;
			case blank_4:
			TIMER0_OV_SetCallBack(blank4);
			Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_256);
			break;
			case blank_5:
			TIMER0_OV_SetCallBack(blank5);
			Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_256);
			break;
		}
	TIMER0_OV_InterruptEnable();
}
void LED_StopBlank(void)
{
	timer0_stop();
}
static void blank1(void)
{
	static u8 count=0;
	if (count==Blank_typ[blank_1][0])
	{
		Flag_ON=1;
	}
	else if (count==Blank_typ[blank_1][1])
	{
		Flag_ON=0;
		count=0;
	}
	count++;
	timer0_set(100);
}
static void blank2(void)
{
	static u8 count=0;
	if (count==Blank_typ[blank_2][0])
	{
		Flag_ON=1;
	}
	else if (count==Blank_typ[blank_2][1])
	{
		Flag_ON=0;
		count=0;
	}
	count++;
	timer0_set(100);
}
static void blank3(void)
{
	static u8 count=0;
	if (count==Blank_typ[blank_3][0])
	{
		Flag_ON=1;
	}
	else if (count==Blank_typ[blank_3][1])
	{
		Flag_ON=0;
		count=0;
	}
	count++;
	timer0_set(100);
}
static void blank4(void)
{
	static u8 count=0;
	if (count==Blank_typ[blank_4][0])
	{
		Flag_ON=1;
	}
	else if (count==Blank_typ[blank_4][1])
	{
		Flag_ON=0;
		count=0;
	}
	count++;
	timer0_set(100);
}
static void blank5(void)
{
	static u8 count=0;
	if (count==Blank_typ[blank_5][0])
	{
		Flag_ON=1;
	}
	else if (count==Blank_typ[blank_5][1])
	{
		Flag_ON=0;
		count=0;
	}
	count++;
	timer0_set(100);
}