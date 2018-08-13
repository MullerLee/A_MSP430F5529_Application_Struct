/*
 * @filename:	UART_5529.c
 * @author:		Muller Lee (X.C.Lee)
 * @date:		2018/7/13
 */

#include "USCI_5529.h"
#include <msp430f5529.h>

/*********************************************************
*名称：USCIA0_Init
*功能：串口初始化
*入口参数：无
*出口参数：无
*说明：设置为P3.3和P3.4为串口通信端口 3.3-UCA0TXD 3.4-UCA0RXD
**********************************************************/
void USCIA0_Init(void)
{
	P3SEL |= BIT3+BIT4;                       // P3.3,4 = USCI_A0 TXD/RXD
	UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
	UCA0CTL1 |= UCSSEL_2;                     // SMCLK
	UCA0BR0 = 9;                              // 1MHz 115200 (see User's Guide)
	UCA0BR1 = 0;                              // 1MHz 115200
	UCA0MCTL |= UCBRS_1 + UCBRF_0;            // Modulation UCBRSx=1, UCBRFx=0
	UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
	//UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt
}


//串口0发送字符函数
void USCIA0_SendChar(unsigned char c)
{
    UCA0TXBUF=c;
    while(!(UCA0IFG & UCTXIFG));   // USCI_A0 TX buffer ready?
    UCA0IFG &= ~UCTXIFG;
}


//串口0接收字符函数
unsigned char USCIA0_ReceiveChar(void)
{
	unsigned char data = 0;

//阻塞式返回值
 /*   while(!(UCA0IFG & UCRXIFG));   // USCI_A0 TX buffer ready?
    UCA0IFG &= ~UCRXIFG;
    data = UCA0RXBUF;
    return data;
*/


//非阻塞式返回值
    if(UCA0IFG & UCRXIFG)
  {
UCA0IFG &= ~UCRXIFG;
data = UCA0RXBUF;
}
return data;

}


//串口0发送字符串函数
void USCIA0_SendString(unsigned char *str)
{
    while(*str != '\0')
    {
        USCIA0_SendChar(*str);
        str++;
    }
}



/*********************************************************
*名称：USCIA0_Init
*功能：串口初始化
*入口参数：无
*出口参数：无
*说明：设置为P4.4和P4.5为串口通信端口 4.4-UCA1TXD 4.5-UCA1RXD
**********************************************************/
//串口1初始化函数
void USCIA1_Init(void)
{
  P4SEL |= BIT4+BIT5;                       // P3.3,4 = USCI_A0 TXD/RXD
  UCA1CTL1 |= UCSWRST;                      // **Put state machine in reset**
  UCA1CTL1 |= UCSSEL__ACLK;                     // ACLK
  UCA1BR0 = 34;           // 4MHz 115200
  UCA1BR1 = 0;            // 4MHz 115200
  UCA1MCTL |= UCBRS_6 + UCBRF_0;            // Modulation UCBRSx=1, UCBRFx=0
  UCA1CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  //IE2 |= UCA0RXIE + UCA0TXIE;  // Enable USCI_A0 TX/RX interrupt
  //IE2 |= UCA0RXIE;             // Enable USCI_A0 RX interrupt
  //__bis_SR_register(GIE);      // Enter LPM3 w/ interrupts enabled
}


//串口1发送字符函数
void USCIA1_SendChar(unsigned char c)
{
    UCA1TXBUF=c;
    while(!(UCA1IFG & UCTXIFG));   // USCI_A0 TX buffer ready?
    UCA1IFG &= ~UCTXIFG;
}


//串口1接收字符函数
unsigned char USCIA1_ReceiveChar(void)
{
	unsigned char data = 0;

//阻塞式返回值
    while(!(UCA1IFG & UCRXIFG));   // USCI_A0 TX buffer ready?
    UCA1IFG &= ~UCRXIFG;
    data = UCA1RXBUF;
    return data;


/*
//非阻塞式返回值
    if(UCA1IFG & UCRXIFG)
  {
UCA1IFG &= ~UCRXIFG;
data = UCA1RXBUF;
}
return data;
*/
}


//串口1发送字符串函数
void USCIA1_SendString(unsigned char *str)
{
    while(*str != '\0')
    {
        USCIA1_SendChar(*str);
        str++;
    }
}




/*


void UART0_Init(void)
{
    P3SEL = 0x30;                             // 配置P3.4和P3.5脚为串口的输入输出口
    UCA0CTL1 |= UCSWRST;                      // 复位串口
    UCA0CTL1 |= UCSSEL_1;                     // 选择串口时钟为ACLK(32768HZ)
    UCA0BR0 = 0x03;                           // 设置串口波特率为9600
    UCA0BR1 = 0x00;
    UCA0MCTL = UCBRS_3+UCBRF_0;
    UCA0CTL1 &= ~UCSWRST;                     // 打开串口
    UCA0IE |= UCRXIE;                         // 打开串口接收中断
}
*/

