

ifeq ($(KERNELRELEASE),)

KERNEL_DIR = /home/zh/share/linux/linux-2.6.22.6
CUR_DIR	= $(shell pwd)

all:
	make -C $(KERNEL_DIR) M=$(CUR_DIR) modules

clean:
	make -C $(KERNEL_DIR) M=$(CUR_DIR) clean
	rm Module.symvers


else

obj-m += keybus.o
obj-m += keydev.o
obj-m += keydrv.o


endif

