/*
 * DIO.c
 *
 * Created: 4/5/2023 1:57:07 AM
 * Author : Mohamed Sayed
 */ 


#include "DIO_Interface.h"

extern const PIN_Status Pin_StatusArray [PINs_Total];

void DIO_InitPin (PIn_name pin ,PIN_Status status)
{
 
 switch(status)
 {
	 case OUTPUT:
	 if(pin/8 == 0)
	 {
		 Set_Bit(DDRA,pin%8);
		 CLR_Bit(PORTA,pin%8);
	 }
	 else if(pin/8 == 1)
	 {
		 Set_Bit(DDRB,pin%8);
		 CLR_Bit(PORTB,pin%8);
	 }
	 else if(pin/8 == 2)
	 {
		 Set_Bit(DDRC,pin%8);
		 CLR_Bit(PORTC,pin%8);
	 }
	 else if(pin/8 == 3)
	 {
		 Set_Bit(DDRD,pin%8);
		 CLR_Bit(PORTD,pin%8);
	 }
	 break;
	 case INFREE:
	 if(pin/8 == 0)
	 {
		 CLR_Bit(DDRA,pin%8);
		 CLR_Bit(PORTA,pin%8);
	 }
	 else if(pin/8 == 1)
	 {
		 CLR_Bit(DDRB,pin%8);
		 CLR_Bit(PORTB,pin%8);
	 }
	 else if(pin/8 == 2)
	 {
		 CLR_Bit(DDRC,pin%8);
		 CLR_Bit(PORTC,pin%8);
	 }
	 else if(pin/8 == 3)
	 {
		 CLR_Bit(DDRD,pin%8);
		 CLR_Bit(PORTD,pin%8);
	 }
	 break;
	 case INPUT:
	 if(pin/8 == 0)
	 {
		 CLR_Bit(DDRA,pin%8);
		 Set_Bit(PORTA,pin%8);
	 }
	 else if(pin/8 == 1)
	 {
		 CLR_Bit(DDRB,pin%8);
		 Set_Bit(PORTB,pin%8);
	 }
	 else if(pin/8 == 2)
	 {
		 CLR_Bit(DDRC,pin%8);
		 Set_Bit(PORTC,pin%8);
	 }
	 else if(pin/8 == 3)
	 {
		 CLR_Bit(DDRD,pin%8);
		 Set_Bit(PORTD,pin%8);
	 }
	 break;
 }
}



void DIO_init (void)
{
	PIn_name p;
	for (p=PINA0;p<PINs_Total;p++)
	{
		DIO_InitPin (p ,Pin_StatusArray[p]);
	}
}



void DIO_WRitePin (PIn_name pin ,Voltage_type s)
{
	switch (s)
	{
		case HIGH:
		if(pin/8 == 0)
		{
			Set_Bit (PORTA,pin%8);
		}
		else if(pin/8 == 1)
		{
			Set_Bit (PORTB,pin%8);
		}
		else if(pin/8 == 2)
		{
			Set_Bit (PORTC,pin%8);
		}
		else if(pin/8 == 3)
		{
			Set_Bit (PORTD,pin%8);
		}
		break;
		case LOW:
		if(pin/8 == 0)
		{
			CLR_Bit (PORTA,pin%8);
		}
		else if(pin/8 == 1)
		{
			CLR_Bit (PORTB,pin%8);
		}
		else if(pin/8 == 2)
		{
			CLR_Bit (PORTC,pin%8);
		}
		else if(pin/8 == 3)
		{
			CLR_Bit (PORTD,pin%8);
		}
		break;
	}
	
}

void DIO_WritePort(PORT_Type Port,u8 data)
{
	switch (Port)
	{
		case PA:
		PORTA =data;
		break;
		case PB:
		PORTB =data;
		break;
		case PC:
		PORTC =data;
		break;
		case PD:
		PORTD =data;
		break;
		
	}
	
}

Voltage_type DIO_ReadPin(PIn_name pin)
{
	Voltage_type volt=LOW;
	if(pin/8 == 0)
	{
		volt=Read_Bit(PINA,pin%8);
	}
	else if(pin/8 == 1)
	{
		volt=Read_Bit(PINB,pin%8);
	}
	else if(pin/8 == 2)
	{
		volt=Read_Bit(PINC,pin%8);
	}
	else if(pin/8 == 3)
	{
		volt=Read_Bit(PIND,pin%8);
	}
	return volt;
	
}


