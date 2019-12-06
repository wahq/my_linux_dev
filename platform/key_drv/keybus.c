#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>


int keybus_match(struct device *dev, struct device_driver *drv)
{
	printk("--------------------%s------------------\n",__FUNCTION__);
	return 0;
}


struct bus_type keybus = {
	.name  = "keybus",
	.match = keybus_match,
};

EXPORT_SYMBOL(keybus);

static int __init keybus_init(void)
{
	int ret;

	printk("--------------------%s------------------\n",__FUNCTION__);
	ret = bus_register(&keybus);
	if(ret != 0){
		printk("bus_regitster is error\n");
		return ret;
	}

	return 0;
}


static void __exit keybus_exit(void)
{
	printk("--------------------%s------------------\n",__FUNCTION__);
	bus_unregister(&keybus);
	return;
}




module_init(keybus_init);
module_exit(keybus_exit);
MODULE_LICENSE("GPL");



