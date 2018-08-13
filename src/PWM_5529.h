/*
 * PWM_5529.h
 *
 *  Created on: 2018年7月13日
 *      Author: Muller Lee (X.C.Lee)
 */

#ifndef SRC_PWM_5529_H_
#define SRC_PWM_5529_H_

//---------------------- Flexible Adjust Function -----------------------
void P1_4_ChangeDuty(int num);
void P1_5_ChangeDuty(int num);
void P2_4_ChangeDuty(int num);
void P2_5_ChangeDuty(int num);
void Channel1_Change(int period, int num1, int num2);
void Channel2_Change(int period, int num1, int num2);
//---------------------- the config of timerA0 pwm ----------------------
void TimerA0_1_PWM_Init(int num, int period); //P1.2
void TimerA0_2_PWM_Init(int num, int period); //P1.3
void TimerA0_3_PWM_Init(int num, int period); //P1.4
void TimerA0_4_PWM_Init(int num, int period); //P1.5


//---------------------- the config of timerA1 pwm ----------------------
void TimerA1_1_PWM_Init(int num, int period); //P2.0
#define TimerA1_1_SetPWM(num) (TA1CCR1=(num))
void TimerA1_2_PWM_Init(int num, int period); //P2.1
#define TimerA1_2_SetPWM(num) (TA1CCR2=(num))


//---------------------- the config of timerA2 pwm ----------------------
void TimerA2_1_PWM_Init(int num, int period); //P2.4
#define TimerA2_1_SetPWM(num) (TA2CCR1=(num))
void TimerA2_2_PWM_Init(int num, int period); //P2.5
#define TimerA2_2_SetPWM(num) (TA2CCR2=(num))


//---------------------- the config of timerB0 pwm ----------------------
void TimerB0_1_PWM_Init(int num, int period); //P5.7
void TimerB0_2_PWM_Init(int num, int period); //P7.4
void TimerB0_3_PWM_Init(int num, int period); //P7.5
void TimerB0_4_PWM_Init(int num, int period); //P7.6
void TimerB0_5_PWM_Init(int num, int period); //P3.5
void TimerB0_6_PWM_Init(int num, int period); //P3.6




#endif /* SRC_PWM_5529_H_ */
