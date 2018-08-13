/*
 * @filename:	main.c
 * @author:		Muller Lee (X.C.Lee)
 * @date:		2018/7/13
 */

//======================================================
#include "global.h"

//Function Prototype
void init(void);
void  init_interrupt(void);


/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    //unsigned char data='0';
	init();
	init_interrupt();
	//int time=5000;
	//int dute1=0;
	//int dute2=0;
	//_enable_interrupts();
	while(1){
		/***************ADC���Զ���********************/
		//ADC12CTL0 |= ADC12SC;                   // Start conversion
		/**************TIMERA���Զ���****************/
		/*
		if(TA1R>25000)
			P1OUT=0x01;
		else
			P1OUT=0x00;
		*/
		/**************PWM���Զ���*******************/
		//Channel1_Change(time,dute1,dute2);
		//Channel2_Change(time,dute1,dute2);
		//dute1++;
		//dute2++;
		//if(dute1>4000)dute1=0;
		//if(dute2>4000)dute2=0;
		//Delay(5);
		/*******************����********************/
		/*************UART���Զ���*******************/
		/*
        // USCIA0_SendChar('A\n');
        // USCIA0_SendString("Xingchen\n");
        data = USCIA0_ReceiveChar();
        if(data == 'a')
        {
        	P8OUT ^= BIT1;
        }
        Delay(10);*/
		/*******************����********************/
	}
}



/*
 * function definition
 */
/*
 * init_all
 */
void init(void)
{
	GPIO_init();
	//P8DIR |= 0x01;
	//P8OUT &= BIT1;
	//UART_init();
	PWM_init();
	LED_init();
	//CMP_init();
	//Timer_Init(50000);
}
/*
 * init_interrupt
 */
void init_interrupt(void){
	//Key_Int_Init();
	Timer_Int_Init();
	UART0_Int_Init();
}
