#include <linux/init.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/in.h>
#include <linux/errqueue.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANSHUL GUPTA");
MODULE_DESCRIPTION("PRINTING HELLO WORLD!!!");

int sysint_init(void){
        printk("\n\n Hello World!!!!, Module Loaded!!! Yayyyy\n\n");
	return 0;
}

void sysint_exit(void){
	printk("\n\n Bye, Bye, Module Unloaded \n\n");
}
