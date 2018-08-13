/*
 * PWM_5529.c
 *
 *  Created on: 2018年7月13日
 *      Author: Muller Lee (X.C.Lee)
 */

#include <msp430f5529.h>

//--------------USED------------------------------
void TimerA0_3_PWM_Init(int num, int period) //P1.4
{
	P1DIR |= BIT4;
	P1SEL |= BIT4;
	TA0CCR0 = period;
	//TA0CCTL3 = OUTMOD_3;//先低电平后高电平
	TA0CCTL3 = OUTMOD_7;//先高电平后低电平
	TA0CCR3 = num;
	TA0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
	TA0CTL |= TACLR;     //将计时器A0清零
}


void TimerA0_4_PWM_Init(int num, int period) //P1.5
{
	P1DIR |= BIT5;
	P1SEL |= BIT5;
	TA0CCR0 = period;
	//TA0CCTL4 = OUTMOD_3;//先低电平后高电平
	TA0CCTL4 = OUTMOD_7;//先高电平后低电平
	TA0CCR4 = num;
	TA0CTL |= TASSEL_1 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
	TA0CTL |= TACLR;     //将计时器A0清零
}

//period 周期值，num百分比值, timerA2的period要一样
void TimerA2_1_PWM_Init(int num, int period) //P2.4
{
	P2DIR |= BIT4;
	P2SEL |= BIT4;
	TA2CCR0 = period;
	//TA2CCTL1 = OUTMOD_3;//先低电平后高电平
	TA2CCTL1 = OUTMOD_7;//先高电平后低电平
	TA2CCR1 = num;
	TA2CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
	TA2CTL |= TACLR;     //将计时器A0清零
}


void TimerA2_2_PWM_Init(int num, int period) //P2.5
{
	P2DIR |= BIT5;
	P2SEL |= BIT5;
	TA2CCR0 = period;
	//TA2CCTL2 = OUTMOD_3;//先低电平后高电平
	TA2CCTL2 = OUTMOD_7;//先高电平后低电平
	TA2CCR2 = num;
	TA2CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
	TA2CTL |= TACLR;     //将计时器A0清零
}

void P1_4_ChangeDuty(int num)
{
	TA0CCR3 = num;
}
void P1_5_ChangeDuty(int num)
{
	TA0CCR4 = num;
}
void P2_4_ChangeDuty(int num)
{
	TA2CCR1 = num;
}
void P2_5_ChangeDuty(int num)
{
	TA2CCR2 = num;
}

void Channel1_Change(int period, int num1, int num2){
	TA0CCR0 = period;
	TA0CCR3 = num1;
	TA0CCR4 = num2;
}
void Channel2_Change(int period, int num1, int num2){
	TA2CCR0 = period;
	TA2CCR1 = num1;
	TA2CCR2 = num2;
}
//////////////////////////////////////////////////////////////////////
//UNUSED
/////////////////////////////////////////////////////////////////////
//period 周期值，num占空比值, timerA0的period要一样
void TimerA0_1_PWM_Init(int num, int period) //P1.2
{
	P1DIR |= BIT2;
	P1SEL |= BIT2;
	TA0CCR0 = period;
	//TA0CCTL1 = OUTMOD_3;//先低电平后高电平
	TA0CCTL1 = OUTMOD_7;//先高电平后低电平
	TA0CCR1 = num;
	TA0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
	TA0CTL |= TACLR;     //将计时器A0清零
	//TA1CCTL0=CCIE;     //定时器A1的捕获比较器0开启CCIFG位中断
	//TA1CCTL1=CCIE;     //捕获比较器1开启中断
}


void TimerA0_2_PWM_Init(int num, int period) //P1.3
{
P1DIR |= BIT3;
P1SEL |= BIT3;
TA0CCR0 = period;
//TA0CCTL2 = OUTMOD_3;//先低电平后高电平
TA0CCTL2 = OUTMOD_7;//先高电平后低电平
TA0CCR2 = num;
TA0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TA0CTL |= TACLR;     //将计时器A0清零
}



//period 周期值，num百分比值, timerA1的period要一样
void TimerA1_1_PWM_Init(int num, int period) //P2.0
{
P2DIR |= BIT0;
P2SEL |= BIT0;
TA1CCR0 = period;
//TA1CCTL1 = OUTMOD_3;//先低电平后高电平
TA1CCTL1 = OUTMOD_7;//先高电平后低电平
TA1CCR1 = num;
TA1CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TA1CTL |= TACLR;     //将计时器A0清零
}


void TimerA1_2_PWM_Init(int num, int period) //P2.1
{
P2DIR |= BIT1;
P2SEL |= BIT1;
TA1CCR0 = period;
//TA1CCTL2 = OUTMOD_3;//先低电平后高电平
TA1CCTL2 = OUTMOD_7;//先高电平后低电平
TA1CCR2 = num;
TA1CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TA1CTL |= TACLR;     //将计时器A0清零
}



//period 周期值，num百分比值, timerB0的period要一样
void TimerB0_1_PWM_Init(int num, int period) //P5.7
{
P5DIR |= BIT7;
P5SEL |= BIT7;
TB0CCR0 = period;
//TB0CCTL1 = OUTMOD_3;//先低电平后高电平
TB0CCTL1 = OUTMOD_7;//先高电平后低电平
TB0CCR1 = num;
TB0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TB0CTL |= TACLR;     //将计时器A0清零
}


void TimerB0_2_PWM_Init(int num, int period) //P7.4
{
P7DIR |= BIT4;
P7SEL |= BIT4;
TB0CCR0 = period;
//TB0CCTL2 = OUTMOD_3;//先低电平后高电平
TB0CCTL2 = OUTMOD_7;//先高电平后低电平
TB0CCR2 = num;
TB0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TB0CTL |= TACLR;     //将计时器A0清零
}


void TimerB0_3_PWM_Init(int num, int period) //P7.5
{
P7DIR |= BIT5;
P7SEL |= BIT5;
TB0CCR0 = period;
//TB0CCTL3 = OUTMOD_3;//先低电平后高电平
TB0CCTL3 = OUTMOD_7;//先高电平后低电平
TB0CCR3 = num;
TB0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TB0CTL |= TACLR;     //将计时器A0清零
}


void TimerB0_4_PWM_Init(int num, int period) //P7.6
{
P7DIR |= BIT6;
P7SEL |= BIT6;
TB0CCR0 = period;
//TB0CCTL4 = OUTMOD_3;//先低电平后高电平
TB0CCTL4 = OUTMOD_7;//先高电平后低电平
TB0CCR4 = num;
TB0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TB0CTL |= TACLR;     //将计时器A0清零
}


void TimerB0_5_PWM_Init(int num, int period) //P3.5
{
P3DIR |= BIT5;
P3SEL |= BIT5;
TB0CCR0 = period;
//TB0CCTL5 = OUTMOD_3;//先低电平后高电平
TB0CCTL5 = OUTMOD_7;//先高电平后低电平
TB0CCR5 = num;
TB0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TB0CTL |= TACLR;     //将计时器A0清零
}
void TimerB0_6_PWM_Init(int num, int period) //P3.6
{
P3DIR |= BIT6;
P3SEL |= BIT6;
TB0CCR0 = period;
//TB0CCTL6 = OUTMOD_3;//先低电平后高电平
TB0CCTL6 = OUTMOD_7;//先高电平后低电平
TB0CCR6 = num;
TB0CTL |= TASSEL_2 + MC_1;//以SMCLK为时钟源，工作在up模式 SMCLK 1MHz
TB0CTL |= TACLR;     //将计时器A0清零
}

