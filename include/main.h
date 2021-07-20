#include <stdio.h>
#include <stdlib.h>
#include "linked_list/singly_linked_list.h"
#include "linked_list/doubly_linked_list.h"
#include "linked_list/circular_linked_list.h"
#include "tree/binary_search_tree.h"

int main_menu();

int sll_menu();

int dll_menu(struct doubly_linked_list* list);

int cll_menu(struct circular_linked_list* list);

int queue_menu(struct doubly_linked_list* list);

int stack_menu(struct singly_linked_list* list);

int bst_menu(struct binary_search_tree* tree);
