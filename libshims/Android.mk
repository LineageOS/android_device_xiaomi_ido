#
# Copyright (C) 2016 The CyanogenMod Project
#               2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    android/sensor.cpp \
    gui/SensorManager.cpp \
    ui/GraphicBuffer.cpp

LOCAL_C_INCLUDES := gui
LOCAL_SHARED_LIBRARIES := libgui libutils liblog libbinder libandroid libui
LOCAL_MODULE := libshim_camera
LOCAL_MODULE_CLASS := SHARED_LIBRARIES

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	camera/Camera.cpp \
	camera/CameraMetadata.cpp \
	camera/CaptureResult.cpp \
	camera/CameraParameters2.cpp \
	camera/ICamera.cpp \
	camera/ICameraClient.cpp \
	camera/ICameraService.cpp \
	camera/ICameraServiceListener.cpp \
	camera/ICameraServiceProxy.cpp \
	camera/ICameraRecordingProxy.cpp \
	camera/ICameraRecordingProxyListener.cpp \
	camera/camera2/ICameraDeviceUser.cpp \
	camera/camera2/ICameraDeviceCallbacks.cpp \
	camera/camera2/CaptureRequest.cpp \
	camera/camera2/OutputConfiguration.cpp \
	camera/CameraBase.cpp \
	camera/CameraUtils.cpp \
	camera/VendorTagDescriptor.cpp \
	camera/CameraParameters.cpp

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
	liblog \
	libbinder \
	libhardware \
	libui \
	libgui \
	libcamera_metadata

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/camera/include \
	system/media/camera/include \
	system/media/private/camera/include

LOCAL_MODULE:= libshim_ims_camera

include $(BUILD_SHARED_LIBRARY)
