# alcatel_a571vl_kernel_mod_tests
Some kernel modules for demonstrating the next link in the exploit chain.

# Compiling
COMPILING THIS PHONE'S KERNEL WAS AN ABSOLUTE BI-

Anyway, you need the kernel source code, cross compiler, and the "Module.symvers" ripped from the phone's precompiled kernel.

-The Kernel: git clone https://github.com/N939sc-dev/android_kernel_zte_msm8916.git
-The cross compiler: https://bitbucket.org/matthewdalex/arm-linux-androideabi-4.9/src/master/

Copy the supplied "stock_config.txt" to the root of the kernel source directory. Run "make ARCH=arm SUBARCH=arm CROSS_COMPILE=<cross compiler prefix>" it'll rerun the config process. Just hold "enter" down, we don't mind all too much if the compiled kernel is correct or not. Just "let it do it's thing".

You'll need to apply DIFF patches to get the kernel to compile. Got it? Okay! Good! Now replace the "Module.symvers" generated from the compilation process with the one I supplied here. (Whole complicated thing involving compilers. TL;DR: The one spit out from the compiler has function addresses that are completely different from what the phone is expecting, and will crash the phone.)

Inside the Makefile for these kernel modules, set "export CROSS_COMPILE" to be correct on your machine.

----

This next section relies on a source codeless mystery binary that was uploaded by god-knows-who that performs the privilege escalation exploit. If this binary does not work in your case _god help you._

Push "lordroot" to the phone: "adb push ./lordroot /data/local/tmp"
Enter the adb shell: "adb shell"->"cd /local/data/tmp"->"chmod 555 ./lordroot"->"./lordroot"

Unless the binary is already on the phone, then just cd to the directory and run the program. Idk why it doesn't work when the shell working directory is not "/data/local/tmp" because NO SOURCE CODE! You also HAVE to do this all in the adb shell thing.

"lordroot" has the tendency to not fully working and crashing the phone. If either of the cases happen, just try running it again.

Push the compiled modules to the phone: "adb push <module.ko> /sdcard"

Have a non-root instance of "adb shell" open in another terminal tab so you can see the dmesg logs. (Dmesg won't work when """"rooted"""" because of selinux. You can access /proc/kmsg though!)

Insert the module by running "insmod /data/media/0/<module.ko>" in that rooted instance of "adb shell". (You can't access via "/sdcard". Again: selinux shenanigans)

You should see printk messages from the loaded kernel module!
