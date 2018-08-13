/*
 * Interrupt.c
 *
 *  Created on: 2018/7/13
 *      Author: Muller Lee (X.C.Lee)
 */
//#include"global.h"
#include <msp430f5529.h>
#include"Interrupt.h"
#include "USCI_5529.h"

/*
//uint8_t P2Use_Flag = 1;
//==========WDT================
#pragma vector=WDT_VECTOR
__interrupt void WDT_ISR()
{
	//-----任何情况下均执行按键和滚轮检测任务-----
	P2REN |= BIT3+BIT6;
	__delay_cycles(75);
	P2_IODect();
	P2REN &= ~(BIT3+BIT6);
	Wheel_ADC_Begin();
	//-----demo对应的特殊任务-----

	Change_PWM_Duty();							//---DC-motor----PID改变输出
	LPM3_EXIT;									//执行DC Motor任务时，需要测量电机转速
}

*/
//任务1中断处理函数
//==========P2================
#pragma vector = PORT2_VECTOR
__interrupt void PORT2_ISR(void)
{
	P2_IODect();
	P2IFG=0;  										//退出中断前必须手动清除IO口中断标志
}
void P2_IODect()
{
	unsigned int Push_Key=0;
	//-----排除输出IO的干扰后，锁定唯一被触发的中断标志位-----
	Push_Key=P2IFG&(~P2DIR);
	//-----延时一段时间，避开机械抖动区域-----
	__delay_cycles(10000);							//消抖延时
	//----判断按键状态是否与延时前一致-----
	if((P2IN&Push_Key)==0) 	                	//如果该次按键确实有效
   {
	 //----判断具体哪个IO被按下，调用该IO的事件处理函数-----
	  switch(Push_Key){
//	 case BIT0:	P10_Onclick();		break;
	 case BIT1: 	P21_Onclick();		break;
//	 case BIT2: 	P22_Onclick();		break;
//	 case BIT3: 	P23_Onclick();		break;
//	 case BIT4: 	P24_Onclick();		break;
//	 case BIT5: 	P25_Onclick();		break;
//	 case BIT6: 	P26_Onclick();		break;
//	 case BIT7: 	P27_Onclick();		break;
	 default:									break;		//任何情况下均加上default
	 }
   }
}

void P21_Onclick()
{
	//-----翻转IO电平-----
	P1OUT ^= BIT0;
	}
/*
//HCI
//==========ADC12================
#pragma vector=ADC12_VECTOR
__interrupt void ADC12ISR (void)
{
	  switch(__even_in_range(ADC12IV,34))
	  {
	  case  6: Wheel_ADC();break;             	// Vector  6:  ADC12IFG0
	  default: break;
	  }
}
*/
//==========P1================
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
	P1_IODect();
	P2IFG=0;  										//退出中断前必须手动清除IO口中断标志
}
void P1_IODect()
{
	unsigned int Push_Key=0;
	//-----排除输出IO的干扰后，锁定唯一被触发的中断标志位-----
	Push_Key=P1IFG&(~P1DIR);
	//-----延时一段时间，避开机械抖动区域-----
	__delay_cycles(75);							//消抖延时
	//----判断按键状态是否与延时前一致-----
	if((P1IN&Push_Key)==0) 	                	//如果该次按键确实有效
   {
	 //----判断具体哪个IO被按下，调用该IO的事件处理函数-----
	  switch(Push_Key){
//	 case BIT0:	P10_Onclick();		break;
	 case BIT1: 	P11_Onclick();		break;
//	 case BIT2: 	P12_Onclick();		break;
//	 case BIT3: 	P13_Onclick();		break;
//	 case BIT4: 	P14_Onclick();		break;
//	 case BIT5: 	P15_Onclick();		break;
//	 case BIT6: 	P16_Onclick();		break;
//	 case BIT7: 	P17_Onclick();		break;
	 default:									break;		//任何情况下均加上default
	 }
   }
}

void P11_Onclick()
{
	//-----翻转IO电平-----
	P4OUT ^= BIT7;
	}

//=========TimerA1===============
#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR(void){
	//TA1_Dect();
	TA1_Dect();
	//flag 自动复位，无需手动复位
}
void TA1_Dect(void)
{
  P8OUT ^= BIT1;                            // Toggle P1.0
  //TA1CCR0 =+50000;                         // Add Offset to CCR0
}

//==========UART0================
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
	P8OUT ^=BIT1;
	USCIA0_SendString("What's happening?");
	UCA0IFG = 0x00;


}
/*
//HCI
//==========ADC12================
#pragma vector=ADC12_VECTOR
__interrupt void ADC12ISR (void)
{
	  switch(__even_in_range(ADC12IV,34))
	  {
	  case  6: Wheel_ADC();break;             	// Vector  6:  ADC12IFG0
	  default: break;
	  }
}


//任务1中断处理函数
// Timer1_A3 Interrupt Vector (TAIV) handler
#pragma vector=TIMER1_A1_VECTOR
__interrupt void TIMER1_A1_ISR(void)
{
	  switch(__even_in_range(TA1IV,14))
	  {
	    case 14: 								 // overflow
	    ui16TA1_Overflow_Cnt++;   break;      // 计算溢出次数
	    break;
	    default: break;
	  }
}*/

