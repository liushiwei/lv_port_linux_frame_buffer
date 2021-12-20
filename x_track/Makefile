#
#     Makefile for X-TRACK
#
# Copyright (c) 2021 AlgoIdeas
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

INSTALL_DIR ?= Out

.PHONY: default
default: all

##########################################################################################
#	help config
##########################################################################################
.PHONY: help
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GREEN="\e[32;1m"
NORMAL="\e[39m"
RED="\e[31m"
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
help:
	@echo -e ${GREEN}
	@#cat script/Readme|less
	@echo -e ${NORMAL}

##########################################################################################
#	menuconfig config
##########################################################################################
.PHONY: menuconfig
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++++++++++++++++++
KCONFIG_PATH= Build/kconfig/mconf
KCONFIG_EXE = Build/kconfig/mconf/mconf
KCONFIG_CFG = Build/kconfig/kconfig
#++++++++++++++++++++++++++++++++++++++++++++++++++++
prepare_kconfig:
	@if [ ! -f $(KCONFIG_EXE) ];then cd $(KCONFIG_PATH);make;cd -;fi

menuconfig: prepare_kconfig
	@-chmod -Rf 777 $(KCONFIG_EXE)
	$(if $(wildcard $(KCONFIG_EXE)), \
		@$(KCONFIG_EXE) $(KCONFIG_CFG), \
	)

##########################################################################################
#	compile config
##########################################################################################
export SDK_ROOT  := $(shell pwd)
include $(SDK_ROOT)/Build/kconfig/base.mak

.PHONY: all install clean distclean

# modules
MODULES := USER Simulator
.PHONY: $(MODULES)

COMPILE_ARGS ?= $(CFG_COMPILE_ARGS)

#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Target Compile
#++++++++++++++++++++++++++++++++++++++++++++++++++++
all:
	@$(call BUILD_GN, ${COMPILE_ARGS}, default)

$(MODULES):
	@$(call BUILD_GN, ${COMPILE_ARGS}, $@)

install: all
	@echo "Install ..."

clean:
	@if [ -d "${INSTALL_DIR}" ]; then \
		pushd ${INSTALL_DIR} > /dev/null;$(NINJA) -t clean;popd > /dev/null; \
	else \
		echo "No need clean ${INSTALL_DIR}!"; \
	fi

distclean:
	@rm -rf ${INSTALL_DIR}/

