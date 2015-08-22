include Makefile.inc

SRC_DIR		:= src
BUILD_DIR	:= build

all: checkdirs recursive

checkdirs: build

build:
	$(ECHO) creating $(BUILD_DIR) directory
	mkdir $(BUILD_DIR)

recursive:
	$(ECHO) started building *.c files in $(SRC_DIR)/
	cd src/linked_list; $(MAKE) $(MFLAGS)

clean:
	$(ECHO) cleaning up $(BUILD_DIR) directory
	$(RM) -rf $(BUILD_DIR)
