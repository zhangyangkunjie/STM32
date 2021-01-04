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
#include "LED.h"
#include "KEY.h"

/***ע�⣺�����̺ͽ̳��е��½�����3.3С�ڶ�Ӧ***/

int main(void)
{ 
		u8 key;
    HAL_Init();                    	 			//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//����ʱ��,72M
		delay_init(72);   //��ʼ����ʱ����
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
