package com.api.led;

import com.x210.api.DeviceNotFoundException;
import com.x210.api.DeviceNotOpenException;



public class LED_SDK {
	
	public void Led_open(int led_num) throws Exception{
		int ret = -1;
		ret = led_open(led_num);
		if(-1 == ret){
			throw new DeviceNotFoundException();
		}	
	}
	
	public void  Led_close(int led_num) throws Exception{
		int ret = -1;
		ret = led_close(led_num);
		if(-1 == ret){
			throw new DeviceNotFoundException();
		}
	}
	
	public void  Led_on(int led_num) throws Exception{
		int ret = -1;
		ret = led_on(led_num);
		if(-1 == ret){
			throw new DeviceNotOpenException();
		}
	}
	
	public void  Led_off(int led_num) throws Exception{
		int ret = -1;
		ret = led_off(led_num);
		if(-1 == ret){
			throw new DeviceNotOpenException();
		}
	}
	
	public void  Led_blink(int led_num,int ms) throws Exception{
		int ret = -1;
		ret = led_blink(led_num,ms);
		if(-1 == ret){
			throw new DeviceNotOpenException();
		}
	}
	
	private native int led_open(int led_num);
	private native int led_close(int led_num);
	private native int led_on(int led_num);
	private native int led_off(int led_num);
	private native int led_blink(int led_num,int ms);
	static{
		System.loadLibrary("LED_LIB");
	}
}
