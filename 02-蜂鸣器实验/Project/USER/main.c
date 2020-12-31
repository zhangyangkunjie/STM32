#include "sys.h"
#include "delay.h"
#include "usart.h"
/************************************************
蜂鸣器属于压电式传感器需要1-5kHz 的脉冲
************************************************/
/***注意：本工程和教程中的新建工程3.3小节对应***/
#include "LED.h"
#include "BEEP.h"
int main(void)
{
	HAL_Init();//初始化HAL库
	Stm32_Clock_Init(RCC_PLL_MUL9);//设置时钟72M
	delay_init(72);//初始化延时函数
	LED_Init();//初始化LED
	BEEP_Init();//初始化BEEP
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_5);
		delay_us(100);
	}
}
