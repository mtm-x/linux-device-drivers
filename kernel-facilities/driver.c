/*
 * Copyright @ 2025 thamaraimanalan.tech. All Rights Reserved.
 * Author; Thamaraimanalan M <mahasel.1969@gmail.com>
 *
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>


static int __init mod_init(void) {
        printk(KERN_INFO "Hellooo!!");
        return 0;
}

static void __exit mod_exit(void) {
        printk(KERN_INFO "Byeeeeee!!");

}

module_init(mod_init);
module_exit(mod_exit);

MODULE_AUTHOR("Thamarai <mahasel.1969@gmail.com>");
MODULE_LICENSE("GPL");