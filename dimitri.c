//Arbitrary memory read address demo thing. Shows us in dmesg that we have the ability to read arbitrary parts of real memory on the Alcatel A571VL
//
//Unlike loading kernel modules, getting access to dmesg doesn't require running "lordroot" for access to a broken root shell.
//-> dmesg

//Because of SELinux, you can't load the kernel module from the "/sdcard" symbolic link, you must use the actual path to virtual sdcard:
//-> insmod /data/media/0/dimitri.ko

#include"linux/module.h"
#include"linux/kernel.h"

//System RAM past the kernel section.
//#define TEST_ADDR 0x8da00000
//#define READ_LEN 16*16

//Bootrom on ARM platforms (crashes phone)
//#define TEST_ADDR 0xffff0000
//#define READ_LEN 16*16

//"tsens_eeprom_physical" Crashes phone ;(
//#define TEST_ADDR 0x0005c000
//#define READ_LEN 64

//Kernel data
//#define TEST_ADDR 0x81132000
//#define READ_LEN 16*128

//Kernel code
//#define TEST_ADDR 0x80000000
//#define READ_LEN 16*128

//qdsp6_base
#define TEST_ADDR 0x04080000
#define READ_LEN 16

int init_module(void)
{
	void *ptr=0;
	unsigned char *read_ptr=0;
	int i;
	printk(KERN_INFO "Dimitri: <silence in no voicelines>\n");
	ptr=phys_to_virt(TEST_ADDR);
	if(ptr==NULL){
		printk("Dimitri: Could not access $%p\n",(void*)TEST_ADDR);
		return 0;
	}else{
		printk("Dimitri: Success!\n");
	}
	printk("Dimitri: Original address: $%p\n",(void*)TEST_ADDR);
	printk("Dimitri: phys_to_virt address: $%p\n",(void*)ptr);
	read_ptr=ptr;
	for(i=0;i<READ_LEN;i+=16){
		printk("Dimitri: $%p: %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n",(void*)ptr+i, read_ptr[i],read_ptr[i+1],read_ptr[i+2],read_ptr[i+3],read_ptr[i+4],read_ptr[i+5],read_ptr[i+6],read_ptr[i+7],read_ptr[i+8],read_ptr[i+9],read_ptr[i+10],read_ptr[i+11],read_ptr[i+12],read_ptr[i+13],read_ptr[i+14],read_ptr[i+15]);
	}
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Dimitri: Removing...\n");
}
