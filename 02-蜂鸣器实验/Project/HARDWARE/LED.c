/*
LED������Ƴ���
���ߣ���һ��
���ڣ�20201229
ע�ͣ�LED0-LED7 ��8��LED �ֱ��Ӧ�ܽ�PC0-PC7
���ܣ�LED ��ˮ��
*/
#include "LED.h"
//#include "sys.h"
//#include "delay.h"
//#include "usart.h"
//��ʼ��PC0-7Ϊ�������ʹ��ʱ��
//LED ��ʼ��
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;//��ʼ���˿ڽṹ��
  __HAL_RCC_GPIOC_CLK_ENABLE();//����GPIOC�˿�ʱ��
	//��ʼ���ܽ�0-7
	GPIO_Initure.Pin=GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;//�������
	GPIO_Initure.Pull=GPIO_PULLUP;//�������
	GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH; //����
	HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_RESET);
}
