/*
 * Copyright @ 2025 thamaraimanalan.tech. All Rights Reserved.
 * Author; Thamaraimanalan M <mahasel.1969@gmail.com>
 *
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static char *mystr = "hello";
static int myint = 1;



module_param(myint, int, S_IRUGO);
module_param(mystr, charp, S_IRUGO);

/*
 * MODULE_PARM_DESC gives description about the params when modinfo is used
 */

MODULE_PARM_DESC(myint,"this is my int variable");
MODULE_PARM_DESC(mystr,"this is my char pointer variable");

/**
 * print_params - Prints the cli parameter to the kernel buffer
 * returns myint
 */


static int print_params(void) {
        pr_info("mystring is a string: %s\n", mystr);
        return myint;

}

static int __init mod_init(void) {
        printk(KERN_INFO "Hellooo!!");
        print_params();
        return 0;
}

static void __exit mod_exit(void) {
        printk(KERN_INFO "Byeeeeee!!");

}

module_init(mod_init);
module_exit(mod_exit);

MODULE_AUTHOR("Thamarai <mahasel.1969@gmail.com>");
MODULE_LICENSE("GPL");