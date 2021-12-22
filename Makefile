#
# Makefile
#
CTOOL := riscv64-unknown-linux-gnu-
CCL := /media/george/android/tina-d1-open/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702
CC := ${CCL}/bin/${CTOOL}gcc
CCP := ${CCL}/bin/${CTOOL}g++
#CC ?= gcc
LVGL_DIR_NAME ?= lvgl
LVGL_DIR ?= ${shell pwd}
CFLAGS ?= -O3 -g0 -I$(LVGL_DIR)/ -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wall -Wextra -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits -Wshift-negative-value -Wstack-usage=2048 -Wno-unused-value -Wno-unused-parameter -Wno-missing-field-initializers -Wuninitialized -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wno-discarded-qualifiers -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare
LDFLAGS ?= -lm -lstdc++
BIN = demo

X_TRACK_DIR_NAME ?= x_track
D1S_DIR_NAME ?= d1s

#Collect the files to compile
MAINSRC = ./main.cpp

include $(LVGL_DIR)/lvgl/lvgl.mk
include $(LVGL_DIR)/lv_drivers/lv_drivers.mk
include $(LVGL_DIR)/lv_demos/lv_demo.mk
include $(LVGL_DIR)/x_track/x_track.mk
include $(LVGL_DIR)/d1s/d1s.mk
OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))
CCPOBJS = $(CCPSRCS:.cpp=$(OBJEXT))

MAINOBJ = $(MAINSRC:.cpp=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(CCPSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS) $(CCPOBJS)

## MAINOBJ -> OBJFILES

all: default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@ $(INC_PATH)
	@echo "CC $<"


%.o : %.cpp
	$(CCP) $(CCPFLAGS) $< -c -o $@ $(INC_PATH) $(LIB_PATH) $(CCPLDFLAGS)
	@echo "CCP $<"

default: $(AOBJS) $(COBJS) $(CCPOBJS) $(MAINOBJ)
	$(CCP) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS)  $(CCPOBJS) $(LDFLAGS)

clean: 
	rm -f $(BIN) $(AOBJS) $(COBJS)  $(CCPOBJS) $(MAINOBJ)

