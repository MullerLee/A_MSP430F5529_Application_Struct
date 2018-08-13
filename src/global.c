
/*
 * @filename:	global.c
 * @Author: 	zdl--->first edit in 2014
 * 				Muller Lee
 * @Date:		2018/7/13
 */

#include <msp430f5529.h>
//Core library file
#include "hal_ucs.h"
#include "hal_flash.h"
#include "hal_macros.h"
#include "hal_pmap.h"
#include "hal_tlv.h"
#include "hal_pmm.h"
#include "global.h"

/*
 * ========= LOOP Delay =========
 */
void Delay(int time){
	int i=0;
	int j=0;
	for(i=0;i<10;i++)
		for(j=0;j<time;j++);
}
/*
 * ======== Init_GPIO ==========
 */
uint8_t Port_Num[4]={GPIO_PORT_P2,GPIO_PORT_P3,GPIO_PORT_P4,GPIO_PORT_P8};
void GPIO_init(void)
{
	//int i=0;
	/*for (i=0;i<4;i++)
		privateGPIOGetBaseAddress(Port_Num[i]);*/
	GPIO_setAsInputPin(GPIO_PORT_P2,GPIO_PIN0);
	GPIO_setAsInputPin(GPIO_PORT_P2,GPIO_PIN2);
	GPIO_setAsInputPin(GPIO_PORT_P2,GPIO_PIN3);
	GPIO_setAsInputPin(GPIO_PORT_P2,GPIO_PIN6);
	GPIO_setAsOutputPin(GPIO_PORT_P3,GPIO_PIN7);
	GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN0);
	GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN3);
	GPIO_setAsOutputPin(GPIO_PORT_P8,GPIO_PIN1);
	GPIO_setAsOutputPin(GPIO_PORT_P8,GPIO_PIN2);

	GPIO_setOutputLowOnPin(GPIO_PORT_P8,GPIO_PIN2);

/*
	GPIO_setAsInputPinWithPullUpresistor(GPIO_PORT_P1,GPIO_PIN1);
	GPIO_setAsInputPin(GPIO_PORT_P1,GPIO_PIN1);
	GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN1,GPIO_LOW_TO_HIGH_TRANSITION);
	GPIO_enableInterrupt(GPIO_PORT_P1,GPIO_PIN1);

	GPIO_setAsInputPinWithPullUpresistor(GPIO_PORT_P1,GPIO_PIN1);
	GPIO_setAsInputPin(GPIO_PORT_P1,GPIO_PIN1);
	GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN1,GPIO_HIGH_TO_LOW_TRANSITION);
	GPIO_enableInterrupt(GPIO_PORT_P1,GPIO_PIN1);
*/

}
/*
 * ======== Init_UART =======
 */
void UART_init(void){
	USCIA0_Init();
}
/*
 * ======== Init_PWM ========
 */
void PWM_init(void){
	TimerA0_3_PWM_Init(3,6);//P1.4
	TimerA0_4_PWM_Init(30000,60000);
	TimerA2_1_PWM_Init(30000,60000);
	TimerA2_2_PWM_Init(2,4);
}

/*
 * =========Init_Comparator=============
 */
void CMP_init(void)
{
	P1DIR |= BIT6;                // P1.6 output direction
	P1SEL |= BIT6;                // Select CBOUT function on P1.6/CBOUT
	CB0_Init();
	CB1_Init();
	CB2_Init();
	CB3_Init();
	CBCTL1 |= CBON;
	__delay_cycles(75);
}

/*
 * ======== Init_LED on LP5529 ========
 */
void LED_init(void)
{
	P1DIR |= BIT0;				//设定P1.0和P4.7为输出
	P1OUT &= BIT0;					//设定P1.0初值

	P4DIR |= BIT7;
	P4OUT &= ~BIT7;					//设定P4.7初值
}

void Timer_Init(int period){
	TimerA1_0_init(period);
}

void ADC_Init(void){
	P6SEL |= 0x08;				//6.4
	P6SEL |= 0x10;				//6.5
	P6SEL |= 0x20;				//6.6
	P7SEL |= 0x01;				//7.0
	ADC_All_Init();
}

/****************************************
 *        INTERRUPT
 ****************************************/
/*
 * ========  Key_Interrupt ============
 */
void Key_Int_Init(void)
{
	P1REN |= BIT1;				        //启用P1.1内部上下拉电阻
	P1OUT |= BIT1;			            //将电阻设置为上拉
	//-----配置P1.1中断参数-----
	P1DIR &= ~BIT1;						// P1.1设为输入(可省略)
	P1IES |= BIT1;						// P1.1设为下降沿中断
	//P1IE  |= BIT1 ;						// 允许P1.1中断

	P2REN |= BIT1;				        //启用P2.1内部上下拉电阻
	P2OUT |= BIT1;			            //将电阻设置为上拉
	//-----配置P2.1中断参数-----
	P2DIR &= ~BIT1;						// P2.1设为输入(可省略)
	P2IES |= BIT1;						// P2.1设为下降沿中断

	P1IE  |= BIT1 ;						// 允许P1.1中断
	P2IE  |= BIT1 ;						// 允许P2.1中断
}

/*
 * ======= Timer_Interrupt ================
 */
void Timer_Int_Init(void){
	TimerA1_0_int_init();
	TimerA1_0_init(65535);
}

/*
 * ======= UART0_Interrupt ================
 */
void UART0_Int_Init(void){
	UCA0IE |= UCRXIE;		//Enable RX Interrupt
	//UCA0IE |= UCTXIE;		//Enable TX Interrupt
}

/*
 * =========== ADC_Interrupt
 */
void ADC_Int_Init(void){
	P6SEL |= 0x08;				//6.4
	P6SEL |= 0x10;				//6.5
	P6SEL |= 0x20;				//6.6
	P7SEL |= 0x01;				//7.0
	ADC_All_Int();
}
//===============================================
//Possibly will never be used
//===============================================
/*
 * ======== Init_Ports ========
 */
void Ports_init (void)
{
	//  COG背光控制	0/1 on/off
	P3DIR |= BIT2;
	P3OUT |= BIT2;

	// 功放shutdown
	P4DIR |= BIT3;
	P4OUT &= ~BIT3;

	// 关闭白光LED
	P2DIR |= BIT0;
	P2OUT |= BIT0;
}

/*
 * ======== Init_SYSCLK ========
 */
void SysClk_init(void)
{
	SetVCore(PMMCOREV_3);			// 设置工作在20Mhz的Vcore 1.8V

	P5SEL |= BIT5 + BIT4;			// 将P5.4/P5.5设为XT1晶振输入管脚（上电默认为IO口模式）
	//P5SEL |= BIT2 + BIT3;			// 将P5.2/P5.3设为XT2晶振输入管脚（上电默认为IO口模式）

	LFXT_Start(XT1DRIVE_3);			// 启动外部XT1_L低频时钟源
	//XT2_Start(XT1DRIVE_3);		// 启动外部高频XT2时钟源

	SELECT_FLLREF(SELREF__XT1CLK);	// 选择FLL时钟源
	// Use 32.768kHz XTAL as reference
	Init_FLL_Settle(25000,762);		// 设置倍频系数  20000,610 25000 762

	SELECT_ACLK(SELA__XT1CLK);		// 选择ACLK时钟源
}

