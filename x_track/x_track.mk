include $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Application/application.mk
include $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/USER/user.mk
#include $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/vendor.mk
include $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Application/application.mk

INC_PATH += -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/USER \
		-I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/USER/App \
        -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/USER/App/Utils/ArduinoJson/src \
		-I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/USER/App/Utils/MapConv \
		-I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Libraries \
		-I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Libraries/ButtonEvent \
		-I $(LVGL_DIR) 
		
CFLAGS +=			-DLV_FS_POSIX_PATH=\"/mnt/SDCARD\" \
                    -DLV_HOR_RES=320 \
                    -DLV_VER_RES=240 \
                    -DDISP_HOR_RES=320 \
                    -DDISP_VER_RES=240 \
					-D_GNU_SOURCE \
        			-pthread \
        			-DLINUX \
        			-DUSE_WIN32DRV=0 \
        			-DUSE_FBDEV=1 \
        			-DBOARD_BODYCAM_REFB \
					-std=c99 \
        			-O2

CCPFLAGS +=			-std=gnu++11 \
					-DDISP_HOR_RES=320 \
                    -DDISP_VER_RES=240 \
					-D_GNU_SOURCE \
        			-pthread \
        			-DLINUX \
        			-DUSE_WIN32DRV=0 \
        			-DUSE_FBDEV=1 \
        			-DBOARD_BODYCAM_REFB \
					-DLV_FS_POSIX_PATH=\"/mnt/SDCARD\" \
        			-O2
					
CCPLDFLAGS +=  -lstdc++

# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Simulator/LVGL.Simulator 
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/prebuilt_libs/middleware/linux/include \
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/common/devmng/include \
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/common/utils/include \
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/common/utils/hilog/include \
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/common/usb/include \
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/common/system/include \
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/common/storagemng/include \
		# -I $(LVGL_DIR)/$(X_TRACK_DIR_NAME)/Vendor/hisilicon/hi3559v200/prebuilt_libs/amp/a7_linux/mpp/include 
