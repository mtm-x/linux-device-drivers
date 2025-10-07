#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>


MODULE_AUTHOR("THAMARAI");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Lotus /proc loadable driver module");

static struct proc_dir_entry *custom_proc_node;

static ssize_t	lotus_read(struct file* fileptr, char  *user_space_buf, size_t count, loff_t* offset){
    printk("lotus_read");
    return 0;
}


struct proc_ops custom_proc_ops = {
    .proc_read = lotus_read

};


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