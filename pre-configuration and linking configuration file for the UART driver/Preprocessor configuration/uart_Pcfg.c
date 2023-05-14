/*
 * uart_Pcfg.c
 *
 * Created: 5/10/2023 12:47:55 PM
 *  Author: Mohamed Sayed 
 */ 


/**********************************Define the CPU Frequency to detect the Baudrate********************************************************************************/
#define F8MHZ   8
#define F4MHZ   4

#define FCPU   F8MHZ                         //The CPU Frequency in MHz

/********************************The value of uart register based on the baudrate**********************************************************************************/
#if FCPU==F8MHZ
static u16 BaudRate_arr[Baudrate_Total][Speed_Total]={
	{207,416},
	{103,207},
	{51,103},
	{34,68},
};
#elif FCPU==F4MHZ
static u16 BaudRate_arr[Baudrate_Total][Speed_Total]={
	{103,207},
	{51,103},
	{25,51},
	{16,34},
};
/*****************************************The Defination of Baudrate**********************************************************************************************/
typedef enum {
	Baudrate2400,
	Baudrate4800,
	Baudrate9600,
	Baudrate144K,
	Baudrate_Total
}Uart_BaudRate_en;

#define Uart_BaudRate   Baudrate9600
/****************************************The uart speed************************************************************************************************************/
typedef enum {
	Normal_Speed,
	Double_Speed,
	Speed_Total
}Uart_Speed_en;

#define  Uart_Speed   Normal_Speed
/***************************************The uart mode**************************************************************************************************************/
typedef enum{
	Asynchronous,
	Synchronous
}Uart_Mode_en;

#define  Uart_Mode    Asynchronous
/***************************************Parity bit******************************************************************************************************************/
typedef enum{
	Even,
	Odd,
	No_Parity
}Uart_Parity_en;

#define   Uart_Parity  Even
/*************************************Stop bit**********************************************************************************************************************/
typedef enum{
	StopBit_1,
	StopBit_2
}Uart_StopBit_en;

 #define   Uart_StopBit   StopBit_1
/***********************************Number of data bit**************************************************************************************************************/
typedef enum{
	DataBit_5,
	DataBit_6,
	DataBit_7,
	DataBit_8,
	DataBit_9
}Uart_DataBit_en;

#define   Uart_DataBit   DataBit_8 
/**********************************Enable for transmitter & reciever************************************************************************************************/
typedef enum{
	Transmitter,
	Reciever,
	TR
}Uart_Enable_en;

#define  Uart_Enable   Transmitter

/**********************************************************************************************************************************************************************/

