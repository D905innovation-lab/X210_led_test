/*
 * Led.h
 *
 *  Created on: 2017年3月23日
 *      Author: Administrator
 */

#ifndef LED_H_
#define LED_H_

int led_On(int led_num);
int led_Off(int led_num);
int led_Open(int led_num);
int led_Close(int led_num);
int blink(int led_num,int s);


#endif /* LED_H_ */
