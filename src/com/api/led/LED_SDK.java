package com.api.led;

public class LED_SDK {
	public native int led_open(int led_num);
	public native int led_close(int led_num);
	public native int led_on(int led_num);
	public native int led_off(int led_num);
	public native int led_blink(int led_num,int ms);
	
	static{
		System.loadLibrary("LED_LIB");
	}
}
