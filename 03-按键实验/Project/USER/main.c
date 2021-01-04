#include "sys.h"
#include "delay.h"
#include "usart.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板实验0-1
 Template工程模板-新建工程章节使用-HAL库版本
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
#include "LED.h"
#include "KEY.h"

/***注意：本工程和教程中的新建工程3.3小节对应***/

int main(void)
{ 
		u8 key;
    HAL_Init();                    	 			//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//设置时钟,72M
		delay_init(72);   //初始化延时函数
	  LED_Init();
	  KEY_Init();
	while(1)
	{
		key=KEY_Scan(0);
		switch(key)
		{
			case K0_VALUE:
			  LED0=!LED0;
			break;
			case K1_VALUE:
			  LED1=!LED1;
			break;
			case K2_VALUE:
				LED2=!LED2;
			break;
			case K3_VALUE:
				LED3=!LED3;
			break;
		}
		delay_ms(10);
	}
}
