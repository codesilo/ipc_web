################################################################################
################################################################################
##
## Makefile -- makefile for ADI test application
##
## (C) Copyright 2012-2014 by Goke Microelectronics Co.,Ltd
##
## Version: $Id: Makefile 1980 2014-10-21 10:12:26Z houwentao $
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
##
################################################################################
################################################################################

  TOPDIR = ../..
  SUBDIR = subsystem/web

include $(TOPDIR)/env/make/Makefile.config
ECHO := echo
################################################################################
# source files
################################################################################

#SOURCES += src/main.c
#SOURCES += src/shell.c
#SOURCES += src/parser.c
#SOURCES += src/video.c
#SOURCES += src/isp.c

################################################################################
# define define user cc flags
################################################################################

#CCFLAGS_USER += -O3 -DDEBUG
#CCFLAGS_USER += -I $(TOPDIR)/legacy/build/include
#CCFLAGS_USER += -I $(TOPDIR)/adi/include
#CCFLAGS_USER += -I $(TOPDIR)/env/temp/headers

################################################################################
# define define user ld flags
################################################################################

#LDFLAGS_USER += -lrt 
#LDFLAGS_USER += -L $(TOPDIR)/legacy/prebuild/imgproc
#LDFLAGS_USER += -limg_algo_a5s -limg_dsp_a5s

################################################################################
# define library used
################################################################################

#LIBRARIES = adi

################################################################################
# define target name
################################################################################

PROGRAM = boa-0.94.13/src/boa

################################################################################
# define local file to be installed
################################################################################
LOCAL_FILE += boa-0.94.13/boa.conf

BOA_LOG_FILES := $(ROOTFS_TOP)/var/log/boa/access_log $(ROOTFS_TOP)/var/log/boa/error_log

################################################################################
# define local file install location
# if this was commented out, the target will be installed into the default 
# location:
#   $(ROOTFS_TOP)/usr/local/bin/
################################################################################

INSTALL_LOCAL_FILE_DIR = $(ROOTFS_TOP)/etc/boa/boa.conf

################################################################################
# define target install location
# if this was commented out, the target will be installed into the default 
# location:
#   $(ROOTFS_TOP)/usr/local/bin/
################################################################################

# INSTALL_BIN_DIR = 

################################################################################
# define user targets
################################################################################

default: install

#include $(TOPDIR)/env/make/Makefile.rules

clean: clean-objects clean-all

#build:  build-objects build-program

install-configname:
	@echo  "### --> [$(INSTALL_LOCAL_FILE_DIR)]"
	@mkdir -p $(ROOTFS_TOP)/etc/boa
	@mkdir -p $(ROOTFS_TOP)/var/log/boa
	touch $(BOA_LOG_FILES)
	chmod 777  $(BOA_LOG_FILES)
	@cp -a $(LOCAL_FILE) $(INSTALL_LOCAL_FILE_DIR)
	@cp -a /etc/mime.types $(ROOTFS_TOP)/etc/

install-program:
	@$(NEWLINE)
	@$(ECHO) "### --> [$(ROOTFS_TOP)/webSvr/`basename $(PROGRAM)`]"
	@mkdir -p  $(ROOTFS_TOP)/webSvr
	@cp -a  $(PROGRAM) $(ROOTFS_TOP)/webSvr/
	@mkdir -p $(ROOTFS_TOP)/webSvr/www/

	@find cgi-bin/ -name '*.cgi' |xargs tar czf /tmp/cgi-bin.tgz && tar -zxf /tmp/cgi-bin.tgz -C $(ROOTFS_TOP)/webSvr/www/
	@find css/ -name '*.css' |xargs tar czf /tmp/css.tgz && tar -zxf /tmp/css.tgz -C $(ROOTFS_TOP)/webSvr/www/
	@find js/ -name '*.js' |xargs tar czf /tmp/js.tgz && tar -zxf /tmp/js.tgz -C $(ROOTFS_TOP)/webSvr/www/
	@find html/ -name '*.html' |xargs tar czf /tmp/html.tgz && tar -zxf /tmp/html.tgz -C $(ROOTFS_TOP)/webSvr/www/
	@find activeX/ -name '*.cab' |xargs tar czf /tmp/activeX.tgz && tar -zxf /tmp/activeX.tgz -C $(ROOTFS_TOP)/webSvr/www/

install: build install-configname install-program 
#install-debug-program install-file

headers:

all: clean build install



#-include $(TOPDIR)/env/make/Makfile.dep

