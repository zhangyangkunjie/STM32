/*
LED灯跑马灯程序
作者：张一波
日期：20201229
注释：LED0-LED7 共8个LED 分别对应管脚PC0-PC7
功能：LED 流水灯
*/
#include "LED.h"
//#include "sys.h"
//#include "delay.h"
//#include "usart.h"
//初始化PC0-7为输出，并使能时钟
//LED 初始化
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;//初始化端口结构体
  __HAL_RCC_GPIOC_CLK_ENABLE();//开启GPIOC端口时钟
	//初始化管脚0-7
	GPIO_Initure.Pin=GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;//推挽输出
	GPIO_Initure.Pull=GPIO_PULLUP;//上拉输出
	GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH; //高速
	HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_RESET);
}
