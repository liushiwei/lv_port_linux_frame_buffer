ifeq ($(SDK_BASECFG),)
SDK_BASECFG = 1

CreateDir = $(shell [ -d $1 ] || mkdir -p $1 || echo ":mkdir '$1' fail")

##########################################################################################
# Check Parameter
##########################################################################################
ifeq ($(SDK_ROOT),)
$(error please specify sdk root path)
endif

##########################################################################################
#	Common Function Define
##########################################################################################

# Current Directory Name(exclude prefix)
CUR_DIR_NAME = $(shell pwd |sed 's/^\(.*\)[/]//' )

# Current Parent Directory Name(exclude prefix)
CUR_PARENT_DIR_NAME = $(shell cd ./..;pwd|sed 's/^\(.*\)[/]//')

# Make Result Check
MAKE_EXT_FLAG := || exit "$$?"

# GN Build Tools
GN := gn
NINJA := ninja

define BUILD_GN
    mkdir -p ${INSTALL_DIR}; \
    $(GN) gen ${INSTALL_DIR} --args='$(1)' --export-compile-commands; \
    cd ${INSTALL_DIR}; \
    $(NINJA) $(2);
endef

# Shallow Git clones (--depth) do not have the N tag:
# use 'git-YYYY-MM-DD-hhhhhhh'.
# test "$COMMIT_REVISION" || COMMIT_REVISION=$(shell cd "$1" && shell git log -1 --pretty=format:"git-%cd-%h" --date=short 2> /dev/null)

# COMMIT_VERSION = $(shell git show HEAD | head -1 | grep commit | sed 's/commit\ //')

##########################################################################################
#	Common Definition
##########################################################################################
# Reference Product Define
SDK_ROOT := $(shell cd $(SDK_ROOT); pwd)
SDK_THIRDPARTY_ROOT := $(SDK_ROOT)/Thirdparty
SDK_KCONFIG_ROOT    := $(SDK_ROOT)/Build/kconfig
SDK_TOOLS_ROOT      := $(SDK_ROOT)/Tools

include $(SDK_KCONFIG_ROOT)/cfg.mak
include $(SDK_KCONFIG_ROOT)/kconfig.mak

# Toolchains
CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)g++
CCDEP := $(CROSS_COMPILE)gcc
CXXDEP := $(CROSS_COMPILE)g++
STRIP := $(CROSS_COMPILE)strip
AR := $(CROSS_COMPILE)ar

# App Out Definition
SDK_OUT_ROOT := $(SDK_ROOT)/Out

SDK_OUT_OBJ_ROOT   := $(SDK_OUT_ROOT)/Obj/Thirdparty/$(CUR_DIR_NAME)
SDK_OUT_LIB_ROOT   := $(SDK_OUT_ROOT)/lib
SDK_OUT_TOOLS_ROOT := $(SDK_OUT_ROOT)/Tools
SDK_OUT_TOOLS_OBJ  := $(SDK_OUT_TOOLS_ROOT)/Obj/$(CUR_DIR_NAME)
SDK_OUT_TOOLS_BIN  := $(SDK_OUT_TOOLS_ROOT)/bin

endif # ifndef $(SDK_BASECFG)
