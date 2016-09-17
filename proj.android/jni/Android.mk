LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../..)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

 
# ����Ŀ¼����Ŀ¼�ĺ���
define walk
	$(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef


# ����ClassesĿ¼
ALLFILES = $(call walk, $(LOCAL_PATH)/../../Classes)

 
FILE_LIST := hellocpp/main.cpp 
# �������ļ�����ȡ������.cpp�ļ�
FILE_LIST += $(filter %.cpp, $(ALLFILES))

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)


rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard, $d/,$2))

MY_FILES_PATH := $(LOCAL_PATH)/../../Classes
MY_ALL_DIRS := $(dir $(foreach src_path,$(MY_FILES_PATH),$(call rwildcard, $(src_path),*/) ) )
MY_ALL_DIRS := $(call uniq,$(MY_ALL_DIRS))
LOCAL_C_INCLUDES := $(MY_ALL_DIRS) 


# LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

 
# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

 

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END