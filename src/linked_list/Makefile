TARGETS := singly_linked_list.o doubly_linked_list.o circular_linked_list.o

all: checkdirs $(TARGETS) move_to_build

checkdirs: linked_list

linked_list:
	mkdir ../../build/linked_list

move_to_build:
	mv *.o ../../build/linked_list

%.o: %.c
	$(CC) $< -o $@
