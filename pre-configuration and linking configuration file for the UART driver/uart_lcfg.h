/*
 * uart_lcfg.h
 *
 * Created: 5/10/2023 12:47:55 PM
 *  Author: Mohamed Sayed 
 */ 


#ifndef UART_LCFG_H_
#define UART_LCFG_H_

/**********************************Define the CPU Frequency to detect the Baudrate********************************************************************************/
#define F8MHZ   8
#define F4MHZ   4

#define FCPU   F8MHZ                         //The CPU Frequency in MHz

/*****************************************The Defination of Baudrate**********************************************************************************************/
typedef enum {
	Baudrate2400,
	Baudrate4800,
	Baudrate9600,
	Baudrate144K,
	Baudrate_Total
}Uart_BaudRate_en;
/****************************************The uart speed************************************************************************************************************/
typedef enum {
	Normal_Speed,
	Double_Speed,
	Speed_Total
}Uart_Speed_en;
/***************************************The uart mode**************************************************************************************************************/
typedef enum{
	Asynchronous,
	Synchronous
}Uart_Mode_en;
/***************************************Parity bit******************************************************************************************************************/
typedef enum{
	Even,
	Odd,
	No_Parity
}Uart_Parity_en;
/*************************************Stop bit**********************************************************************************************************************/
typedef enum{
	StopBit_1,
	StopBit_2
}Uart_StopBit_en;
/***********************************Number of data bit**************************************************************************************************************/
typedef enum{
	DataBit_5,
	DataBit_6,
	DataBit_7,
	DataBit_8,
	DataBit_9
}Uart_DataBit_en;
/**********************************Enable for transmitter & reciever************************************************************************************************/
typedef enum{
	Transmitter,
	Reciever,
	TR
}Uart_Enable_en;

/********************************The value of uart register based on the baudrate**********************************************************************************/ 
#if FCPU==8
static u16 BaudRate_arr[Baudrate_Total][Speed_Total]={
	{207,416},
	{103,207},
	{51,103},
	{34,68},
};
#elif FCPU==4
static u16 BaudRate_arr[Baudrate_Total][Speed_Total]={
	{103,207},
	{51,103},
	{25,51},
	{16,34},
};
#endif
/*******************************************************************************************************************************************************************/


#endif /* UART_LCFG_H_ */