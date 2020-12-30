#include "sys.h"
#include "delay.h"
#include "usart.h"
/************************************************
 ALIENTEK ս��STM32F103������ʵ��0-1
 Template����ģ��-�½������½�ʹ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


/***ע�⣺�����̺ͽ̳��е��½�����3.3С�ڶ�Ӧ***/
#include "LED.h"

int main(void)
{
	HAL_Init();//��ʼ��HAL��
	Stm32_Clock_Init(RCC_PLL_MUL9);//����ʱ��72M
	delay_init(72);//��ʼ����ʱ����
	LED_Init();//��ʼ��LED
	while(1)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);//LED0 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);//LED1-2 ��
	  delay_ms(500);//��ʱ500ms
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);//LED1 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);//LED0.2.3.4.5.6.7 ��
		delay_ms(500);//��ʱ500ms
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);//LED2 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);//LED0.1.3.4.5.6.7 ��
		delay_ms(500);//��ʱ500ms
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);//LED3 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);//LED0.1.2.4.5.6.7 ��
		delay_ms(500);//��ʱ500ms
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);//LED4 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);//LED0.1.2.3.5.6.7 ��
		delay_ms(500);//��ʱ500ms
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);//LED5 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);//LED0.1.2.3.4.6.7 ��
		delay_ms(500);//��ʱ500ms
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_RESET);//LED6 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7,GPIO_PIN_SET);//LED0.1.2.3.4.5.7 ��
	  delay_ms(500);//��ʱ500ms
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);//LED7 ��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,GPIO_PIN_SET);//LED0.1.2.3.4.5.6 ��
		delay_ms(500);//��ʱ500ms
	}
}
