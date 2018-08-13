/*
 * UART_5529.h
 *
 *  Created on: 2018年7月13日
 *      Author: Muller Lee (X.C.Lee)
 */

#ifndef SRC_USCI_5529_H_
#define SRC_USCI_5529_H_

//prototypes
extern void USCIA0_Init(void);
extern void USCIA0_SendChar(unsigned char c);
extern unsigned char USCIA0_ReceiveChar(void);
extern void USCIA0_SendString(unsigned char *str);


extern void USCIA1_Init(void);
extern void USCIA1_SendChar(unsigned char c);
extern unsigned char USCIA1_ReceiveChar(void);
extern void USCIA1_SendString(unsigned char *str);



#endif /* SRC_USCI_5529_H_ */
