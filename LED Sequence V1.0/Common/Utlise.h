
#ifndef UTILS_H_
#define UTILS_H_


#include "Standard_Type.h"


#define Read_Bit(reg,bit)         ((reg>>bit) & 1)
#define Set_Bit(reg,bit)          (reg|=1<<bit)
#define CLR_Bit(reg,bit)          (reg&=~(1<<bit))
#define TOG_BIT(reg,bit)          (reg=reg^(1<<bit))




#endif /* UTILS_H_ */