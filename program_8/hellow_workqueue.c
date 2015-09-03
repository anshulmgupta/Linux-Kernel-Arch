#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/gfp.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("STUDENT");
MODULE_DESCRIPTION("My first work queue");

/*
#define INIT_WORK(_work,_func)  \
	do{                     \
		(_work)->data = (atomic_long_t)WORK_DATA_INIT(); \
		INIT_LIST_HEAD(&(_work)->entry); \
		PREPARE_WORK((_work),(_func)); \
	}while(0)
*/

static struct workqueue_struct *my_WORKQ;

typedef struct{
	struct work_struct my_work;
	int x;
} my_work_t;

my_work_t *work,*work2;

static void my_WORKQ_function(struct work_struct *work){
	my_work_t *my_work = (my_work_t*)work;
	printk("from workqueue my_work.x %d\n", my_work->x);
	kfree((void*)work);
	kfree((void*)work2);
	
	return;
}

int my_init_module(void){
	int ret;
	my_WORKQ = create_workqueue("my_WORKQ");
	if(my_WORKQ){
		work=(my_work_t*)kmalloc(sizeof(my_work_t),GFP_KERNEL);
		if (work){
			INIT_WORK((struct work_struct*)work,my_WORKQ_function);
			work->x = 1;
			ret = queue_work(my_WORKQ,(struct work_struct*)work);
		}
		work2=(my_work_t*)kmalloc(sizeof(my_work_t),GFP_KERNEL);
	       if(work2){
			INIT_WORK((struct work_struct*)work2,my_WORKQ_function);
                        work->x = 2;
                        ret = queue_work(my_WORKQ,(struct work_struct*)work2);
		}
	}
	work_pending(work);
	work_pending(work2);
	return 0;
}

void my_exit_module(void){
	flush_workqueue(my_WORKQ);
	destroy_workqueue(my_WORKQ);
	return;
}

module_init(my_init_module);
module_exit(my_exit_module);
