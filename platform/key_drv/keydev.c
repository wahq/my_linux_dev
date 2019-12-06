#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include "devinfo.h"


extern struct bus_type keybus;


struct key_dev_desc devinfo = {
	.name  = "key1",
	.irqno = 9999,
	.addr  = 0x30008000,
};

void key_dev_release(struct device *dev)
{
	printk("--------------------%s------------------\n",__FUNCTION__);
	return;
}


struct device key_dev = {
	.bus_id	 = "key_drv",
	.bus     = &keybus,
	.release = key_dev_release,
	.platform_data = &devinfo,
};


static int __init key_dev_init(void)
{
	int ret;

	printk("--------------------%s------------------\n",__FUNCTION__);
	ret = device_register(&key_dev);
	if(ret < 0){
		printk("device register is error\n");
		return ret;
	}
	return 0;
}


static void __exit key_dev_exit(void)
{
	printk("--------------------%s------------------\n",__FUNCTION__);
	device_unregister(&key_dev);
	return;
}





module_init(key_dev_init);
module_exit(key_dev_exit);
MODULE_LICENSE("GPL");



