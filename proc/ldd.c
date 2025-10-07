#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>


MODULE_AUTHOR("THAMARAI");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Lotus /proc loadable driver module");

static struct proc_dir_entry *custom_proc_node;

static ssize_t	lotus_read(struct file* fileptr, char  *user_space_buf, size_t count, loff_t* offset){
    printk("lotus_read");

    /* need to print or send to user space beacause this printk is only visible in kernel log buffer 
    
    1. user_space_buf is the one of the buff where we will send the message so that it can be printed in the console
    2. copy_to_user is an api which helps to copy the message to the user buffer
    3. cat excepts number bytes to be printed on the console if that is 0 then EOF no output 
    4. we need to make use of offset which is important as it will be usefull to return 0 to cat so that it can stop.
    
    */

    char message[] = "Ack!\n";
    size_t str_len = strlen(message);

    int result;

    if ( *offset >= str_len) return 0;

    result = copy_to_user(user_space_buf, message, str_len);
    *offset += str_len;
    printk("Count : %ld", count);

    return str_len;
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