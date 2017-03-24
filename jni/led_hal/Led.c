/*
 * Led.c
 *
 *  Created on: 2017年3月23日
 *      Author: Administrator
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

///sys/devices/platform/x210-led
#define LED_1PATH "sys/devices/platform/x210-led/led1"
#define LED_2PATH "sys/devices/platform/x210-led/led2"
#define LED_3PATH "sys/devices/platform/x210-led/led3"
#define LED_4PATH "sys/devices/platform/x210-led/led4"

#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4

int fd_led1 = -1;
int fd_led2 = -1;
int fd_led3 = -1;
int fd_led4 = -1;

/**
	 * 打开设备
	 *
	 * @author panmk
	 * @param led_Open  @打开设备后必须用clos销毁
	 * @parameter (int)led_num
	 * @return 	-1 	打开失败
	 * 			若成功返回值为打开对应设备文件的标识符
	 *
	 */
int led_Open(int led_num)
{
	switch(led_num)
	{
		case LED_1:
			fd_led1 = open(LED_1PATH,O_RDWR);
			return fd_led1;
			break;
		case LED_2:
			fd_led2 = open(LED_2PATH,O_RDWR);
			return fd_led2;
			break;
		case LED_3:
			fd_led3 = open(LED_3PATH,O_RDWR);
			return fd_led3;
			break;
		case LED_4:
			fd_led4 = open(LED_4PATH,O_RDWR);
			return fd_led4;
			break;
		default:
			break;
	}
	return -1;
}

int blink(int led_num,int s)
{
	int ret = -1;
	ret = led_On(led_num);
	sleep(s);
	ret = led_Off(led_num);
	return ret;
}

int led_On(int led_num)
{
	char *On = "1";
	switch(led_num)
	{
		case LED_1:
			return write(fd_led1,On,strlen(On));
			break;
		case LED_2:
			return write(fd_led2,On,strlen(On));
			break;
		case LED_3:
			return write(fd_led3,On,strlen(On));
			break;
		case LED_4:
			return write(fd_led4,On,strlen(On));
			break;
		default:
			break;
	}
	return -1;
}


int led_Off(int led_num)
{
	char *Off = "0";
	switch(led_num)
	{
		case LED_1:
			return write(fd_led1,Off,strlen(Off));
			break;
		case LED_2:
			return write(fd_led2,Off,strlen(Off));
			break;
		case LED_3:
			return write(fd_led3,Off,strlen(Off));
			break;
		case LED_4:
			return write(fd_led4,Off,strlen(Off));
			break;
		default:
			break;
	}
	return -1;
}


/**
	 * 关闭设备
	 *
	 * @author panmk
	 * @param led_Close
	 * @parameter (int)led_num
	 * @return 	-1 	关闭失败
	 * 			0       关闭成功
	 *
	 */
int led_Close(int fd)
{
	switch(fd)
	{
		case LED_1:
			return close(fd_led1);
			break;
		case LED_2:
			return close(fd_led2);
			break;
		case LED_3:
			return close(fd_led3);
			break;
		case LED_4:
			return close(fd_led4);
			break;
		default:
			break;
	}
	return -1;
}
