/*
 * Button.h
 *
 * Created: 4/5/2023 4:19:28 AM
 *  Author: Mohamed Sayed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO_Interface.h"

/***************************Button Configuration********************************/
#define  Button1   PINC0
#define  Button2   PIND1
#define  Button3   PIND2
/*******************************************************************************/
typedef enum{
	Pressed,
	NotPressed	
}Button_Status;

Button_Status Button_Check(u8 Button);



#endif /* BUTTON_H_ */