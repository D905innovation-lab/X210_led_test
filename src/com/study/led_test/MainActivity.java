package com.study.led_test;

import com.api.led.LED_SDK;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {

	Button bn_on;
	Button bn_off;
	LED_SDK LED;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bn_on = (Button) findViewById(R.id.bn_open);
        bn_off = (Button) findViewById(R.id.bn_close);
        LED = new LED_SDK();
        
        bn_on.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				LED.led_open(1);
				LED.led_on(1);
				LED.led_close(1);
			}
		});
        
        bn_off.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				LED.led_open(1);
				LED.led_off(1);
				LED.led_close(1);
			}
		});
    }
}
