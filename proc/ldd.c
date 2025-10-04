#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>


MODULE_AUTHOR("THAMARAI");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Lotus /proc loadable driver module");

static struct proc_dir_entry *custom_proc_node;

static struct proc_ops custom_proc_ops = {};


static int lotus_module_init(void){

    printk("Init - entry");

    /*const struct proc_ops *proc_ops cannot be NULL or else it will give some scary looking dmesg */

    /*
    
    struct proc_dir_entry *proc_create(const char *name, 
                                       umode_t mode,
                                       struct proc_dir_entry *parent, 
                                       const struct proc_ops *proc_ops);
                                       
                                                                                    */
    custom_proc_node = proc_create("lotus_driver", 
                                       0, 
                                       NULL, 
                                       &custom_proc_ops
                                    
                                   );

    printk("Init - exit");
    return 0;
}

static void lotus_module_exit(void){

    printk("exit - entry");

    proc_remove(custom_proc_node);

    printk("exit - exit");
}

module_init(lotus_module_init);
module_exit(lotus_module_exit);