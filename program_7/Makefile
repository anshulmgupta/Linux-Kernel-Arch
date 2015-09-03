KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
LDD := /lib/modules/$(shell uname -r)/kernel/drivers/ldd/

OBJ := hellow_tasklet

obj-m := $(OBJ).o

all: load clean

run: load unload

runall: loadall unload

runcleanall: loadall unload

compile:
	echo "Now in compile"
	@$(MAKE) -C $(KDIR) M=$(PWD) modules
	sudo mkdir -p $(LDD); sudo cp $(OBJ).ko $(LDD); sudo depmod -a

#
# Called as follows make params_pass=5000 load
#

load: compile
	echo "Now in load"
	sudo insmod ./$(OBJ).ko pass_params=$(params_pass)

loadall: compile
	echo "Now in loadall"
	sudo modprobe $(OBJ)

unload:
	echo "Now in unload"
	sudo rmmod $(OBJ)

clean: unload
	echo "Now in clean"
	@rm -rf $(OBJ).o $(OBJ).ko $(OBJ).*.* .$(OBJ).* .tmp_versions* Module* module*
