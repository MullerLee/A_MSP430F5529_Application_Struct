/*
 * @filename:	TimerA1.c
 * @author:		Muller Lee (X.C.Lee)
 * @date:		2018/7/13
 */

#include <msp430f5529.h>
#include "TimerA1.h"

void TimerA1_0_init(int period){
	TA1CCR0 = period;
	TA1CTL = TASSEL_2 + MC_1 + TACLR;         	// SMCLK, up-mode, clear TAR
}
void TimerA1_0_int_init(void){
	TA1CCTL0 = CCIE; 							// CCR0 interrupt enabled
}
