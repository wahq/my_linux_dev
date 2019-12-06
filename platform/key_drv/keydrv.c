#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include "devinfo.h"

extern struct bus_type keybus;
struct key_dev_desc *pdesc;

int key_drv_probe(struct device *dev)
{
	printk("--------------------%s------------------\n",__FUNCTION__);
	pdesc = (struct key_dev_desc *)dev->platform_data;

	printk("name = %s\n",pdesc->name);
	printk("irqno = %d\n",pdesc->irqno);

	
	return 0;
}


int key_drv_remove(struct device *dev)
{
	printk("--------------------%s------------------\n",__FUNCTION__);
	return 0;
}



struct device_driver key_drv = {
	.name 	= "key_drv",
	.bus  	= &keybus,
	.probe 	= key_drv_probe, 
	.remove = key_drv_remove,
};


static int __init key_drv_init(void)
{
	int ret;

	printk("--------------------%s------------------\n",__FUNCTION__);
	ret = driver_register(&key_drv);
	if(ret < 0)
	{
		printk("driver register is error\n");
		return ret;
	}
	return 0;
}


static void __exit key_drv_exit(void)
{
	printk("--------------------%s------------------\n",__FUNCTION__);
	driver_unregister(&key_drv);
	return;
}




module_init(key_drv_init);
module_exit(key_drv_exit);
MODULE_LICENSE("GPL");




