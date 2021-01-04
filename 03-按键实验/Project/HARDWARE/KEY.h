#ifndef __KEY_H
#define __KEY_H
#include "sys.h"
#define K0 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) //K0=PA0
#define K1 HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_2)//K1=PE2
#define K2 HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3) //K2=PE3
#define K3 HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4) //K3=PE4
#define K0_VALUE 1
#define K1_VALUE 2
#define K2_VALUE 3
#define K3_VALUE 4
void KEY_Init(void);
u8 KEY_Scan(u8 mode);
#endif
