#include "BEEP.h"
//��ʼ��PB5Ϊ�������ʹ��ʱ��
//LEDIO��ʼ��
void BEEP_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	__HAL_RCC_GPIOB_CLK_ENABLE();//����GPIOBʱ��
	GPIO_Initure.Pin=GPIO_PIN_5;//PB5
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;//�������
	GPIO_Initure.Pull=GPIO_PULLUP;//����
	GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;//����
	HAL_GPIO_Init(GPIOB,&GPIO_Initure);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);//������������������
	
}
