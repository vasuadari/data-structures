include Makefile.inc

SRC_DIR		:= src
BIN_DIR		:= bin

all: checkdirs recursive

checkdirs: $(BIN_DIR)

$(BIN_DIR):
	$(ECHO) creating $(BIN_DIR) directory
	mkdir $(BIN_DIR)

recursive:
	$(ECHO) started building *.c files in $(SRC_DIR)/
	cd src; $(MAKE) $(MFLAGS)

clean:
	$(ECHO) cleaning up $(BIN_DIR) directory
	$(RM) -rf $(BIN_DIR)
