#include "KEY.h"
#include "delay.h"
//������ʼ������
//PA0(K0)-K_UP PE2(K1)-K_LEFT PE3(K2)-K_DOWN PE4(K3)-K_RIGHT
void KEY_Init(void)
{
//�ܽ�ʱ�ӳ�ʼ��
	GPIO_InitTypeDef GPIO_initure;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	GPIO_initure.Pin=GPIO_PIN_0;  //PA0
	GPIO_initure.Mode=GPIO_MODE_INPUT;//����ģʽ
	GPIO_initure.Pull=GPIO_PULLDOWN;//����ģʽ
	GPIO_initure.Speed=GPIO_SPEED_FREQ_HIGH;//����
	HAL_GPIO_Init(GPIOA,&GPIO_initure);
	
	GPIO_initure.Pin=GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;  //PE2 PE3 PE4
	GPIO_initure.Mode=GPIO_MODE_INPUT;//����ģʽ
	GPIO_initure.Pull=GPIO_PULLUP;//����ģʽ
	GPIO_initure.Speed=GPIO_SPEED_FREQ_HIGH;//����
	HAL_GPIO_Init(GPIOE,&GPIO_initure);
}

//����������
//���ذ���ֵ
//mode 0 ��֧���������� 1֧����������
//return: ���µİ���ֵ 
//�˺�������Ӧ���ȼ� K0>K1>k2>K3
u8 KEY_Scan(u8 mode)
{
	static u8 key_state=1;//�����ɿ���־
	if(mode==1)
		key_state=1;//֧����������
	if(key_state&&(K0==1||K1==0||K2==0||K3==0))
	{
	delay_ms(10);
		key_state=0;
		if(K0==1) return K0_VALUE;
		if(K1==0) return K1_VALUE;
		if(K2==0) return K2_VALUE;
		if(K3==0) return K3_VALUE;
	}
	else if(K0==0&&K1==1&&K2==1&&K3==1)
		key_state=1;
	return 0;// �ް�������
}
