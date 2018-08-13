/*
 * global.h
 *
 *  Created on: 2018_7_13
 *      Author: Muller Lee
 */

#ifndef _GLOBAL_H_
#define _GLOBAL_H_
/*
 * 头文件
 */

//common  file
#include <string.h>
#include <stdint.h>
#include <intrinsics.h>

//driverlib
#include "gpio.h"
//#include "timer_a.h"
//#include "adc12_a.h"
//#include "ref.h"

//userlib
//#include "Template_Driver.h"
#include "Interrupt.h"
//#include "grlib.h"
//#include "HCI.h"
//#include "UserGraphic.h"
#include "USCI_5529.h"
#include "PWM_5529.h"
#include "CMP_5529.h"
#include "TimerA1.h"
#include "ADC_5529.h"

// demo相关
//#include "Demo_OS.h"
//#include "DC_Motor.h"




/*
 * 系统相关宏定义
 */
//system Information
#define SYSACLK		32768				// 当前初始化XT1时钟为32768HZ
#define SYSMCLK		25000000			// 当前初始化FLL时钟为25MHZ
#define SYSSMCLK	25000000
#define MAX_WHEEL_VALUE 2450			//轮盘电位器最大采样值

/*
 * 外部函数/变量声明
 */
//Delay
extern void Delay(int time);
//system initialize
extern void GPIO_init(void);
extern void UART_init(void);
extern void PWM_init(void);
extern void CMP_init(void);
extern void Ports_init(void);
extern void SysClk_init(void);
extern void LED_init(void);
extern void Timer_Init(int period);
extern void ADC_Init(void);

//interrupt initialize
extern void Key_Int_Init(void);
extern void Timer_Int_Init(void);
extern void UART0_Int_Init(void);
extern void ADC_Int_Init(void);

#endif /* GLOBAL_H_ */
