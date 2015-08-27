#include <linux/init.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANSHUL MOHAN GUPTA");
MODULE_DESCRIPTION("Passing params to loaded module");

int pass_params=0;

module_param(pass_params, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(pass_params, "Params to pass");

int sysint_init(void){

	printk("\n\n Hello World, Module Hellow pass_params Loaded! The parameter passed is %d \n\n\n", pass_params);

	return 0;

}

void sysint_exit(void){

	printk("\n\n Bye, bye, Module Unloaded \n\n");
}

module_init(sysint_init);
module_exit(sysint_exit);
