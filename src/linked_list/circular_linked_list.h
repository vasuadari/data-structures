#include "../../include/main.h"

typedef struct circular_linked_list_node CIRCULAR_LINKED_LIST_NODE;
typedef struct circular_linked_list CIRCULAR_LINKED_LIST;

struct circular_linked_list_node
{
  int element;
  struct circular_linked_list_node *prev, *next;
};

struct circular_linked_list
{
  int size;
  CIRCULAR_LINKED_LIST_NODE *head, *tail;
};

void cll_empty(CIRCULAR_LINKED_LIST* list);

int cll_is_empty(CIRCULAR_LINKED_LIST* list);

void cll_add(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* newNode);

void cll_append(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* newNode);

void cll_insert(CIRCULAR_LINKED_LIST* list, int element);

CIRCULAR_LINKED_LIST_NODE* cll_find_node(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* prev, int element);

void cll_delete(CIRCULAR_LINKED_LIST* list, int element);

void cll_display_element(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* cursor);

void cll_display(CIRCULAR_LINKED_LIST* list);

CIRCULAR_LINKED_LIST* cll_circular_linked_list();
