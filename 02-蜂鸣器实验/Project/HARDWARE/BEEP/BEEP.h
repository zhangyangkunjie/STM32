#ifndef __BEEP_H
#define __BEEP_H
#include "sys.h"
//LED端口定义
#define BEEP PBout(5)//蜂鸣器控制IO
void BEEP_Init(void);//初始化
#endif

