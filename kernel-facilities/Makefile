#
# Copyright @ 2025 thamaraimanalan.tech. All Rights Reserved.
# Author; Thamaraimanalan M <mahasel.1969@gmail.com>
#



obj-m := $(SRC).o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build

all: modules

modules clean:
	$(MAKE) -C $(KERNELDIR) M=$(shell pwd) $@