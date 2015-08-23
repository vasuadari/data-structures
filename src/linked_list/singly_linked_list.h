#include "../../include/main.h"

typedef struct singly_linked_list_node SINGLY_LINKED_LIST_NODE;
typedef struct singly_linked_list SINGLY_LINKED_LIST;

struct singly_linked_list_node
{
  int element;
  struct singly_linked_list_node* next;
};

struct singly_linked_list
{
  int size;
  SINGLY_LINKED_LIST_NODE *head, *tail;
};

void sll_empty(SINGLY_LINKED_LIST* list);

int sll_is_empty(SINGLY_LINKED_LIST* list);

void sll_add(SINGLY_LINKED_LIST* list, SINGLY_LINKED_LIST_NODE* newNode);

void sll_append(SINGLY_LINKED_LIST* list, SINGLY_LINKED_LIST_NODE* newNode);

void sll_insert(SINGLY_LINKED_LIST* list, int element);

SINGLY_LINKED_LIST_NODE* sll_find_node(SINGLY_LINKED_LIST_NODE* prev, int element);

void sll_delete(SINGLY_LINKED_LIST* list, int element);

void sll_display_element(SINGLY_LINKED_LIST_NODE* cursor);

void sll_display(SINGLY_LINKED_LIST* list);

SINGLY_LINKED_LIST* singly_linked_list();
