#include <linux/init.h>
#include <linux/module.h>

static int __init first_dev_init(void)
{
	printk("the driver is init\n");

	return 0;
}


static void __exit first_dev_exit(void)
{
	printk("the driver is exit\n");

	return;
}


module_init(first_dev_init);
module_exit(first_dev_exit);
MODULE_LICENSE("GPL");
