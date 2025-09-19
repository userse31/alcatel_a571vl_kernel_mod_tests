obj-m += test.o dimitri.o
export ARCH=arm
export SUBARCH=arm
#export CROSS_COMPILE=/opt/arm-linux-androideabi-4.9/bin/arm-linux-androideabi-
export CROSS_COMPILE=/opt/arm-eabi-4.8/bin/arm-eabi-
#export CROSS_COMPILE=arm-linux-gnueabihf-
#export EXTRA_CFLAGS=-fno-pic

all:
	make -C ~/Documents/a571vl/3_10_49/android_kernel_zte_msm8916/ M=$(PWD) modules
clean:
	make -C ~/Documents/a571vl/3_10_49/android_kernel_zte_msm8916/ M=$(PWD) clean
	clean
