#include "sys.h"
#include "delay.h"
#include "usart.h"
/************************************************
����������ѹ��ʽ��������Ҫ1-5kHz ������
************************************************/
/***ע�⣺�����̺ͽ̳��е��½�����3.3С�ڶ�Ӧ***/
#include "LED.h"
#include "BEEP.h"
int main(void)
{
	HAL_Init();//��ʼ��HAL��
	Stm32_Clock_Init(RCC_PLL_MUL9);//����ʱ��72M
	delay_init(72);//��ʼ����ʱ����
	LED_Init();//��ʼ��LED
	BEEP_Init();//��ʼ��BEEP
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_5);
		delay_us(100);
	}
}
