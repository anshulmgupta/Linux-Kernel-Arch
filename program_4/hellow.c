#include <linux/init.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/in.h>
#include <linux/errqueue.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANSHUL MOHAN GUPTA");
MODULE_DESCRIPTION("Printing Process Info");

int sysint_init(void){
	
	printk("\n\n Hello World, Module Loaded! \n\n\n");
	
	struct task_struct * cur_task;
	cur_task = get_current();

	printk(KERN_ALERT "\n\n STARTING WITH PROCESS : %s[%d] \n\n", cur_task->comm, cur_task->pid);

	for_each_process(cur_task){
		printk(KERN_ALERT " %s[%d]", cur_task->comm, cur_task->pid);
	}
	return 0;

}

void sysint_exit(void){
	printk("\n\n Bye, Bye, Module Unloaded \n\n");
}

module_init(sysint_init);
module_exit(sysint_exit);
