#include "KEY.h"
#include "delay.h"
//按键初始化函数
//PA0(K0)-K_UP PE2(K1)-K_LEFT PE3(K2)-K_DOWN PE4(K3)-K_RIGHT
void KEY_Init(void)
{
//管脚时钟初始化
	GPIO_InitTypeDef GPIO_initure;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	GPIO_initure.Pin=GPIO_PIN_0;  //PA0
	GPIO_initure.Mode=GPIO_MODE_INPUT;//输入模式
	GPIO_initure.Pull=GPIO_PULLDOWN;//下拉模式
	GPIO_initure.Speed=GPIO_SPEED_FREQ_HIGH;//高速
	HAL_GPIO_Init(GPIOA,&GPIO_initure);
	
	GPIO_initure.Pin=GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;  //PE2 PE3 PE4
	GPIO_initure.Mode=GPIO_MODE_INPUT;//输入模式
	GPIO_initure.Pull=GPIO_PULLUP;//上拉模式
	GPIO_initure.Speed=GPIO_SPEED_FREQ_HIGH;//高速
	HAL_GPIO_Init(GPIOE,&GPIO_initure);
}

//按键处理函数
//返回按键值
//mode 0 不支持连续按下 1支持连续按下
//return: 按下的按键值 
//此函数有响应优先级 K0>K1>k2>K3
u8 KEY_Scan(u8 mode)
{
	static u8 key_state=1;//按键松开标志
	if(mode==1)
		key_state=1;//支持连续按下
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
	return 0;// 无按键按下
}
