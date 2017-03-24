package com.study.led_test;

import com.api.led.LED_SDK;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	Button bn_on;
	Button bn_off;
	Button bn_blink;
	LED_SDK LED;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bn_on = (Button) findViewById(R.id.bn_open);
        bn_off = (Button) findViewById(R.id.bn_close);
        bn_blink = (Button) findViewById(R.id.bn_blink);
        LED = new LED_SDK();
        
        for(int i=1;i < 5;i++){
			try {
				LED.Led_open(i);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				Toast.makeText(MainActivity.this,"设备打开失败", Toast.LENGTH_LONG).show();
			}
		}
        
        bn_on.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				for(int i=1;i < 5;i++){
					try {
						LED.Led_on(i);
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						Toast.makeText(MainActivity.this,"操作LED失败", Toast.LENGTH_LONG).show();
					}
				}
			}
		});
        
        bn_off.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				for(int i=1;i < 5;i++){
					try {
						LED.Led_off(i);
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						Toast.makeText(MainActivity.this,"操作LED失败", Toast.LENGTH_LONG).show();
					}
				}
			}
		});
        bn_blink.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				new Led_Thread().run();
			}
		});
        
    }
    
    class Led_Thread extends Thread{
    	@Override
    	public void run() {
    		// TODO Auto-generated method stub
    		super.run();
    		for(int i=1;i < 5;i++){
				try {
					LED.Led_blink(i, 300);
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					Toast.makeText(MainActivity.this,"操作LED失败", Toast.LENGTH_LONG).show();
				}
			}
    	}
    }
    
    @Override
    protected void onDestroy() {
    	// TODO Auto-generated method stub
    	super.onDestroy();
    	 for(int i=1;i < 5;i++){
 			try {
 				LED.Led_close(i);
 			} catch (Exception e) {
 				// TODO Auto-generated catch block
 				e.printStackTrace();
 			}
 		}
    }
}
