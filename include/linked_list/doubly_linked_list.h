#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct doubly_linked_list_node DOUBLY_LINKED_LIST_NODE;
typedef struct doubly_linked_list DOUBLY_LINKED_LIST;

struct doubly_linked_list_node
{
  int element;
  struct doubly_linked_list_node *prev, *next;
};

struct doubly_linked_list
{
  int size;
  DOUBLY_LINKED_LIST_NODE *head, *tail;
};

void dll_empty(DOUBLY_LINKED_LIST* list);

int dll_is_empty(DOUBLY_LINKED_LIST* list);

void dll_add(DOUBLY_LINKED_LIST* list, DOUBLY_LINKED_LIST_NODE* newNode);

void dll_append(DOUBLY_LINKED_LIST* list, DOUBLY_LINKED_LIST_NODE* newNode);

void dll_insert(DOUBLY_LINKED_LIST* list, int element);

DOUBLY_LINKED_LIST_NODE* dll_find_node(DOUBLY_LINKED_LIST_NODE* prev, int element);

void dll_delete(DOUBLY_LINKED_LIST* list, int element);

void dll_display_element(DOUBLY_LINKED_LIST_NODE* cursor);

void dll_display(DOUBLY_LINKED_LIST* list);

DOUBLY_LINKED_LIST* doubly_linked_list();

#endif
