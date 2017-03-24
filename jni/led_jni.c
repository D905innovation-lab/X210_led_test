/*
 * led_jni.c
 *
 *  Created on: 2017年3月23日
 *      Author: panmk
 */
#include "jni.h"
#include <stdio.h>

#define CLASS_NAME "com/api/led/LED_SDK"
#define METHODS_NUM (sizeof(methods)/sizeof(methods[0]))

/*
 * Class:     com_api_led_LED_SDK
 * Method:    led_open
 * Signature: (I)I
 */
JNIEXPORT jint  c_led_open(JNIEnv *env, jobject obj, jint led_num){
	return led_Open(led_num);

}

/*
 * Class:     com_api_led_LED_SDK
 * Method:    led_close
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL c_led_close(JNIEnv *env, jobject obj, jint led_num){
	return led_Close(led_num);
}

/*
 * Class:     com_api_led_LED_SDK
 * Method:    led_off
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL c_led_off(JNIEnv *env, jobject obj, jint led_num){
	return led_Off(led_num);
}

/*
 * Class:     com_api_led_LED_SDK
 * Method:    led_blink
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL c_led_blink(JNIEnv *env, jobject obj, jint led_num,jint ms){
	return blink(led_num,ms);
}

/*
 * Class:     com_api_led_LED_SDK
 * Method:    led_on
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL c_led_on (JNIEnv *env, jobject obj , jint led_num){
	return led_On(led_num);
}


static const JNINativeMethod methods[] ={
	{"led_open", "(I)I", (void *)c_led_open},
	{"led_close", "(I)I", (void *)c_led_close},
	{"led_off", "(I)I", (void *)c_led_off},
	{"led_blink", "(II)I", (void *)c_led_blink},
	{"led_on", "(I)I", (void *)c_led_on},
//	{"hello","()Ljava/lang/String;", (void *)c_hello}
};

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved){
	JNIEnv *env;
	jclass cls;

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}

	cls = (*env)->FindClass(env, CLASS_NAME);
	if (cls == NULL) {
		return JNI_ERR;
	}

	if ((*env)->RegisterNatives(env, cls, methods, METHODS_NUM) < 0)
		return JNI_ERR;

	return JNI_VERSION_1_4;
}

