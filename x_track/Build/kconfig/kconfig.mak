ifeq ($(SDK_KCONFIG),)
SDK_KCONFIG = 1

# Check Parameter
ifeq ($(SDK_ROOT),)
    $(error please specify sdk root path)
endif

##########################################################################################
#	Kconfig Common Configure
##########################################################################################
KCONFIG_CONFIG   ?= $(SDK_ROOT)/.config
ifeq ($(KCONFIG_CONFIG), $(wildcard $(KCONFIG_CONFIG)))
include $(KCONFIG_CONFIG)
endif
KCONFIG_CFLAGS   :=

##########################################################################################
#	GN Extra Configure
##########################################################################################
GN_EXTRA_CFLAGS  :=
GN_EXTRA_LDFLAGS :=

#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Architecture Type
#++++++++++++++++++++++++++++++++++++++++++++++++++++
ifeq ($(CONFIG_ARM_ARCH), y)
KCONFIG_CFLAGS += -D__ARM__
else ifeq ($(CONFIG_LINUX_X86), y)
KCONFIG_CFLAGS += -D__LINUX_X86__
else ifeq ($(CONFIG_LINUX_X86_64), y)
KCONFIG_CFLAGS += -D__LINUX_X86_64__
else ifeq ($(CONFIG_WINDOWS_X86), y)
KCONFIG_CFLAGS += -D__WIN_X86__
else ifeq ($(CONFIG_WINDOWS_X86_64), y)
KCONFIG_CFLAGS += -D__WIN_X86_64__
endif

#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Chip types && Models
#++++++++++++++++++++++++++++++++++++++++++++++++++++

ifeq ($(CONFIG_HISILICON), y)
ifeq ($(CONFIG_HI3556V100), y)
CFG_CHIP_TYPE    := hi3556av100
KCONFIG_CFLAGS   += -D__LINUX__ -DHI3556V100 -D__HI3556V100__
CFG_COMPILE_ARGS := target_cpu="arm" arm_arch="armv7-a" arm_tune="cortex-a7" 
CFG_COMPILE_ARGS += arm_fpu="neon-vfpv4" arm_float_abi="softfp"
CFG_COMPILE_ARGS += chip_type="hi3556av100"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DHI3556V100", "-D__HI3556V100__",
else ifeq ($(CONFIG_HI3559V200), y)
CFG_CHIP_TYPE    := hi3559v200
KCONFIG_CFLAGS   += -D__LINUX__ -DHI3559V200 -D__HI3559V200__
CFG_COMPILE_ARGS := target_cpu="arm" arm_arch="armv7-a" arm_tune="cortex-a7"
CFG_COMPILE_ARGS += arm_fpu="neon-vfpv4" arm_float_abi="softfp"
CFG_COMPILE_ARGS += chip_type="hi3559v200"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DHI3559V200", "-D__HI3559V200__",
else ifeq ($(CONFIG_HI3516EV200), y)
CFG_CHIP_TYPE    := hi3516ev200
KCONFIG_CFLAGS   += -D__LINUX__ -DHI3516EV200 -D__HI3516EV200__
CFG_COMPILE_ARGS := target_cpu="arm" arm_arch="armv7-a" arm_tune="cortex-a7"
CFG_COMPILE_ARGS += arm_fpu="neon-vfpv4" arm_float_abi="softfp"
CFG_COMPILE_ARGS += chip_type="hi3516ev200"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DHI3516EV200", "-D__HI3516EV200__",
endif
endif

ifeq ($(CONFIG_SIGMASTAR), y)
ifeq ($(CONFIG_SSC325), y)
CFG_CHIP_TYPE    := ssc325
KCONFIG_CFLAGS   += -D__LINUX__ -DSSC325 -D__SSC325__
CFG_COMPILE_ARGS := target_cpu="arm" arm_arch="armv7-a" arm_tune="cortex-a7"
CFG_COMPILE_ARGS += chip_type="ssc325"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DSSC325", "-D__SSC325__",
else ifeq ($(CONFIG_SSC335), y)
CFG_CHIP_TYPE    := ssc335
KCONFIG_CFLAGS   += -D__LINUX__ -DSSC335 -D__SSC335__
CFG_COMPILE_ARGS := target_cpu="arm" arm_arch="armv7-a" arm_tune="cortex-a7"
CFG_COMPILE_ARGS += chip_type="ssc335"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DSSC335", "-D__SSC335__",
endif
endif

ifeq ($(CONFIG_ROCKCHIP), y)
ifeq ($(CONFIG_RV1109), y)
CFG_CHIP_TYPE    := rv1109
KCONFIG_CFLAGS   += -D__LINUX__ -DRV1109 -D__RV1109__
CFG_COMPILE_ARGS := target_cpu="arm" arm_arch="armv7-a" arm_tune="cortex-a7"
CFG_COMPILE_ARGS += chip_type="rv1109"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DRV1109", "-D__RV1109__",
endif
endif

ifeq ($(CONFIG_ANYKA), y)
ifeq ($(CONFIG_AK3918EV331), y)
CFG_CHIP_TYPE    := ak3918ev331
KCONFIG_CFLAGS   += -D__LINUX__ -DAK3918EV331 -D__AK3918EV331__
CFG_COMPILE_ARGS := target_cpu="arm" arm_arch="armv7-a" arm_tune="cortex-a7"
CFG_COMPILE_ARGS += arm_fpu="neon-vfpv4" arm_float_abi="softfp"
CFG_COMPILE_ARGS += chip_type="ak3918ev331"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DAK3918EV331", "-D__AK3918EV331__",
endif
endif

ifeq ($(CONFIG_ALLWINNER), y)
ifeq ($(CONFIG_R329), y)
CFG_CHIP_TYPE    := r329
KCONFIG_CFLAGS   += -D__LINUX__ -DR329 -D__R329__
CFG_COMPILE_ARGS := target_cpu="arm" arm_version="8"
CFG_COMPILE_ARGS += chip_type="r329"
GN_EXTRA_CFLAGS  := "-D__LINUX__", "-D__ARM__", "-DR329", "-D__R329__",
endif
endif

#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Cross ToolChain
#++++++++++++++++++++++++++++++++++++++++++++++++++++
ifeq ($(CONFIG_CROSS_COMPILE_HISIV600), y)
export CROSS_COMPILE := arm-hisiv600-linux-
CFG_CROSS_COMPILE := arm-hisiv600-linux-
LIBC_TYPE        := glibc
else ifeq ($(CONFIG_CROSS_COMPILE_HIMIX100), y)
export CROSS_COMPILE := arm-himix100-linux-
CFG_CROSS_COMPILE := arm-himix100-linux-
LIBC_TYPE        := uclibc
else ifeq ($(CONFIG_CROSS_COMPILE_ARCH64_HIMIX100), y)
export CROSS_COMPILE := aarch64-himix100-linux-
CFG_CROSS_COMPILE := aarch64-himix100-linux-
LIBC_TYPE        := glibc
LINUX_ARCH64     := y
else ifeq ($(CONFIG_CROSS_COMPILE_UCLIBC_HARD_FLOAT), y)
export CROSS_COMPILE := arm-buildroot-linux-uclibcgnueabihf-
CFG_CROSS_COMPILE := arm-buildroot-linux-uclibcgnueabihf-
LIBC_TYPE        := uclibc
else ifeq ($(CONFIG_CROSS_COMPILE_RV_UCLIBC_HARD_FLOAT), y)
export CROSS_COMPILE := arm-linux-gnueabihf-
CFG_CROSS_COMPILE := arm-linux-gnueabihf-
LIBC_TYPE        := uclibc
else ifeq ($(CONFIG_CROSS_COMPILE_ANYKA_UCLIBC_HARD_FLOAT), y)
export CROSS_COMPILE := arm-anykav500-linux-uclibcgnueabi-
CFG_CROSS_COMPILE := arm-anykav500-linux-uclibcgnueabi-
LIBC_TYPE        := uclibc
else ifeq ($(CONFIG_CROSS_COMPILE_AARCH64_OPENWRT), y)
export CROSS_COMPILE := aarch64-openwrt-linux-
CFG_CROSS_COMPILE := aarch64-openwrt-linux-
LIBC_TYPE        := uclibc
else ifeq ($(CONFIG_CROSS_COMPILE_GNU), y)
export CROSS_COMPILE := 
LIBC_TYPE        := glibc
ifeq ($(CONFIG_LINUX_X86_64), y)
export CROSS_COMPILE := 
LINUX_ARCH64     := y
endif
endif

# GN ToolChain
ifneq ($(CROSS_COMPILE),)
CFG_COMPILE_ARGS += build_compiler="$(CROSS_COMPILE)"
CFG_COMPILE_ARGS += gcc_cc="$(CROSS_COMPILE)gcc"
CFG_COMPILE_ARGS += gcc_cxx="$(CROSS_COMPILE)g++"
CFG_COMPILE_ARGS += readelf="$(CROSS_COMPILE)readelf"
CFG_COMPILE_ARGS += ar="$(CROSS_COMPILE)ar"
CFG_COMPILE_ARGS += nm="$(CROSS_COMPILE)nm"
CFG_COMPILE_ARGS += ld="$(CROSS_COMPILE)ld"
endif

##########################################################################################
#	Build Configure
##########################################################################################
#CoreDump
ifeq ($(CONFIG_COREDUMP_ON), y)
GN_EXTRA_CFLAGS += "-DCOREDUMP_ON",
KCONFIG_CFLAGS += -DCOREDUMP_ON
endif

#Build Type (release or debug)
ifeq ($(CONFIG_RELEASE), y)
GN_EXTRA_CFLAGS += "-DRELEASE",
CFG_COMPILE_ARGS += is_release=true
KCONFIG_CFLAGS += -DRELEASE
endif

ifeq ($(CONFIG_DEBUG), y)
GN_EXTRA_CFLAGS += "-DDEBUG",
CFG_COMPILE_ARGS += is_release=false
KCONFIG_CFLAGS += -DDEBUG
endif

#Log Level
ifeq ($(CONFIG_LOG_LEVEL_DEBUG), y)
GN_EXTRA_CFLAGS += "-DLOG_LEVEL_DEBUG",
KCONFIG_CFLAGS += -DLOG_LEVEL_DEBUG
endif

#Log File
ifeq ($(CONFIG_LOG_FILE_ON), y)
GN_EXTRA_CFLAGS += "-DLOG_FILE_ON",
KCONFIG_CFLAGS += -DLOG_FILE_ON
endif

#Vendor
ifeq ($(CONFIG_HISILICON), y)
CFG_COMPILE_ARGS  += chip_vendor="hisilicon"
else ifeq ($(CONFIG_ROCKCHIP), y)
CFG_COMPILE_ARGS  += chip_vendor="rockchip"
else ifeq ($(CONFIG_SIGMASTAR), y)
CFG_COMPILE_ARGS  += chip_vendor="sigmastar"
else ifeq ($(CONFIG_ANYKA), y)
CFG_COMPILE_ARGS  += chip_vendor="anyka"
endif

#Sensor
ifeq ($(CONFIG_GALAXYCORE_GC2053), y)
GN_EXTRA_CFLAGS += "-DCFG_SENSOR_TYPE0=GC2053", "-DCFG_LANE_DIVIDE_MODE_0", "-DLANE_DIVIDE_MODE=LANE_DIVIDE_MODE_0"
KCONFIG_CFLAGS    += -DCFG_SENSOR_TYPE0=GC2053
CFG_COMPILE_ARGS  += sensor_type="galaxycore_gc2053"
else ifeq ($(CONFIG_GALAXYCORE_GC2053CAR), y)
GN_EXTRA_CFLAGS += "-DCFG_SENSOR_TYPE0=GC2053CAR", "-DCFG_LANE_DIVIDE_MODE_0", "-DLANE_DIVIDE_MODE=LANE_DIVIDE_MODE_0"
KCONFIG_CFLAGS    += -DCFG_SENSOR_TYPE0=GC2053CAR
CFG_COMPILE_ARGS  += sensor_type="galaxycore_gc2053car"
else ifeq ($(CONFIG_OMNIVISION_OV2735), y)
GN_EXTRA_CFLAGS += "-DCFG_SENSOR_TYPE0=OV2735", "-DCFG_LANE_DIVIDE_MODE_0", "-DLANE_DIVIDE_MODE=LANE_DIVIDE_MODE_0"
KCONFIG_CFLAGS    += -DCFG_SENSOR_TYPE0=OV2735
CFG_COMPILE_ARGS  += sensor_type="omnivision_ov2735"
else ifeq ($(CONFIG_SMART_SC2231), y)
GN_EXTRA_CFLAGS += "-DCFG_SENSOR_TYPE0=SC2231", "-DCFG_LANE_DIVIDE_MODE_0", "-DLANE_DIVIDE_MODE=LANE_DIVIDE_MODE_0"
KCONFIG_CFLAGS    += -DCFG_SENSOR_TYPE0=SC2231
CFG_COMPILE_ARGS  += sensor_type="smart_sc2231"
else ifeq ($(CONFIG_SOI_F37), y)
GN_EXTRA_CFLAGS += "-DCFG_SENSOR_TYPE0=SOIF37", "-DCFG_LANE_DIVIDE_MODE_0", "-DLANE_DIVIDE_MODE=LANE_DIVIDE_MODE_0"
KCONFIG_CFLAGS    += -DCFG_SENSOR_TYPE0=SOIF37
CFG_COMPILE_ARGS  += sensor_type="soi_f37"
else ifeq ($(CONFIG_SONY_IMX307), y)
GN_EXTRA_CFLAGS += "-DCFG_SENSOR_TYPE0=IMX307", "-DCFG_LANE_DIVIDE_MODE_0", "-DLANE_DIVIDE_MODE=LANE_DIVIDE_MODE_0"
KCONFIG_CFLAGS    += -DCFG_SENSOR_TYPE0=IMX307
CFG_COMPILE_ARGS  += sensor_type="sony_imx307"
endif

# GN extra_ldflags and extra_cflags
GN_EXTRA_LDFLAGS := $(GN_EXTRA_CFLAGS)
CFG_COMPILE_ARGS  += extra_ldflags=[$(GN_EXTRA_CFLAGS)]
CFG_COMPILE_ARGS  += extra_cflags=[$(GN_EXTRA_LDFLAGS)]

endif # ifndef $(SDK_KCONFIG)
