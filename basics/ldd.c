#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("THAMARAI");
MODULE_DESCRIPTION("FIRST loadable kernel module");

static int lotus_init(void){

    printk("HELLLL \n");
    return 0;
}

static void lotus_exit(void){

    printk("FUCKKK");
}

module_init(lotus_init);
module_exit(lotus_exit);