/*
 * ADC_5529.c
 *
 *  Created on: 2018年7月15日
 *      Author: Muller Lee (X.C.Lee)
 */
#include <msp430f5529.h>

void ADC_All_Init(void){
	int i=0;
	  REFCTL0 &= ~REFMSTR;                      // Reset REFMSTR to hand over control to
	                                            // ADC12_A ref control registers
	  ADC12CTL0 = ADC12ON+ADC12SHT02+ADC12REFON+ADC12REF2_5V;
	                                            // Turn on ADC12, Sampling time
	                                            // On Reference Generator and set to
	                                            // 2.5V
	  ADC12CTL1 = ADC12SHP;                     // Use sampling timer
	  ADC12MCTL0 = ADC12SREF_1;                 // Vr+=Vref+ and Vr-=AVss

	  for ( i=0; i<0x30; i++);                  // Delay for reference start-up

	  ADC12CTL0 |= ADC12ENC;                    // Enable conversions
}

void ADC_All_Int(void){
	 ADC12CTL0 = ADC12SHT02 + ADC12ON;         // Sampling time, ADC12 on
	 ADC12CTL1 = ADC12SHP;                     // Use sampling timer
	 ADC12IE = 0x01;                           // Enable interrupt
	 ADC12CTL0 |= ADC12ENC;
}
