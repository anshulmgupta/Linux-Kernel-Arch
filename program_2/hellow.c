#include <linux/init.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/in.h>
#include <linux/errqueue.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anshul Gupta");
MODULE_DESCRIPTION("Print Kernel Message");

int sysint_init(void){

        printk("\n\n Hello World, Module Loaded !!!! \n\n\n");

	return 0;

}

void sysint_exit(void){

	printk("\n\n Bye, Bye, Module Unloaded \n\n");
}

module_init(sysint_init);
module_exit(sysint_exit);

