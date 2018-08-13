/*
 * CMP_5529.c
 *
 *  Created on: 2018年7月13日
 *      Author: Muller Lee (X.C.Lee)
 */
#include <msp430f5529.h>
#include "CMP_5529.h"


void CB0_Init(void){
	  CBCTL0 |= CBIPEN + CBIPSEL_0; // Enable V+, input channel CB0
	  CBCTL1 |= CBPWRMD_1;          // normal power mode
	  CBCTL2 |= CBRSEL;             // VREF is applied to -terminal
	  CBCTL2 |= CBRS_3+CBREFL_2;    // R-ladder off; Bandgap voltage amplifier ON and generates 2.0V reference
	  CBCTL3 |= BIT0;               // Input Buffer Disable @P6.0/CB0
	  //CBCTL1 |= CBON;               // Turn On ComparatorB
	 // __delay_cycles(75);
}

void CB1_Init(void){
	  CBCTL0 |= CBIPEN + CBIPSEL_1; // Enable V+, input channel CB1
	  CBCTL1 |= CBPWRMD_1;          // normal power mode
	  CBCTL2 |= CBRSEL;             // VREF is applied to -terminal
	  CBCTL2 |= CBRS_3+CBREFL_2;    // R-ladder off; Bandgap voltage amplifier ON and generates 2.0V reference
	  CBCTL3 |= BIT1;               // Input Buffer Disable @P6.1/CB1
	  //CBCTL1 |= CBON;               // Turn On ComparatorB
	  //__delay_cycles(75);
}

void CB2_Init(void){
	  CBCTL0 |= CBIPEN + CBIPSEL_2; // Enable V+, input channel CB2
	  CBCTL1 |= CBPWRMD_1;          // normal power mode
	  CBCTL2 |= CBRSEL;             // VREF is applied to -terminal
	  CBCTL2 |= CBRS_3+CBREFL_2;    // R-ladder off; Bandgap voltage amplifier ON and generates 2.0V reference
	  CBCTL3 |= BIT2;               // Input Buffer Disable @P6.2/CB2
	  //CBCTL1 |= CBON;               // Turn On ComparatorB
	  //__delay_cycles(75);
}

void CB3_Init(void)
{
	  CBCTL0 |= CBIPEN + CBIPSEL_3; // Enable V+, input channel CB3
	  CBCTL1 |= CBPWRMD_1;          // normal power mode
	  CBCTL2 |= CBRSEL;             // VREF is applied to -terminal
	  CBCTL2 |= CBRS_3+CBREFL_2;    // R-ladder off; Bandgap voltage amplifier ON and generates 2.0V reference
	  CBCTL3 |= BIT3;               // Input Buffer Disable @P6.3/CB3
	  //CBCTL1 |= CBON;               // Turn On ComparatorB
	  //__delay_cycles(75);
}
