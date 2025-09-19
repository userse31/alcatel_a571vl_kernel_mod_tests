#include"linux/module.h"
#include"linux/kernel.h"
//replace the "" with angular brackets
int init_module(void)
{
	printk(KERN_INFO "YOU WILL BREAK AMERICAN!\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye android kernel...\n");
}
