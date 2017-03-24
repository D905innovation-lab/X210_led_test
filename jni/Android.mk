LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := LED_LIB
LOCAL_SRC_FILES := led_jni.c led_hal/Led.c
LOCAL_C_INCLUDES:= led_hal

include $(BUILD_SHARED_LIBRARY)
