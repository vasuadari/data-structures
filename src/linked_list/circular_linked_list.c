#include "../../include/main.h"

void cll_empty(CIRCULAR_LINKED_LIST* list)
{
  list->head = list->tail = NULL;
}

int cll_is_empty(CIRCULAR_LINKED_LIST* list)
{
  return list->head == list->tail;
}

// Insert

void cll_add(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* newNode)
{
  list->head = malloc(sizeof(CIRCULAR_LINKED_LIST_NODE));
  list->head->next = list->tail = newNode;
  newNode->next = list->head;
  list->size = 0;

  return;
}

void cll_append(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* newNode)
{
  list->tail->next = newNode;
  list->tail = list->tail->next;
  list->tail->next = list->head;

  return;
}

void cll_insert(CIRCULAR_LINKED_LIST* list, int element)
{
  CIRCULAR_LINKED_LIST_NODE* newNode;
  newNode = malloc(sizeof(CIRCULAR_LINKED_LIST_NODE));
  newNode->element = element;
  newNode->next = NULL;

  if (cll_is_empty(list))
    cll_add(list, newNode);
  else
    cll_append(list, newNode);

  list->size++;

  return;
}

// Delete

CIRCULAR_LINKED_LIST_NODE* cll_find_node(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* prev, int element)
{
  CIRCULAR_LINKED_LIST_NODE* next = prev->next;

  if (next == list->head || next->element == element)
    return prev;
  else
    return cll_find_node(list, next, element);
}

void cll_delete(CIRCULAR_LINKED_LIST* list, int element)
{
  if (cll_is_empty(list)) {
    printf("List is empty\n");
    return;
  }

  CIRCULAR_LINKED_LIST_NODE *prev, *next;
  prev = cll_find_node(list, list->head, element);
  next = prev->next;

  if (next == list->head && prev->element != element)
    printf("Element not found\n");
  else
  {
    prev->next = next->next;
    list->size--;

    if (prev->next == list->head)
      list->tail = prev;

    if (cll_is_empty(list))
      cll_empty(list);
  }

  return;
}

// Display

void cll_display_element(CIRCULAR_LINKED_LIST* list, CIRCULAR_LINKED_LIST_NODE* cursor)
{
  printf("%d", cursor->element);

  if (cursor->next != list->head)
  {
    printf("->");
    cll_display_element(list, cursor->next);
  }

  return;
}

void cll_display(CIRCULAR_LINKED_LIST* list)
{
  if (cll_is_empty(list))
  {
    printf("List is empty\n");
    return;
  }

  CIRCULAR_LINKED_LIST_NODE* cursor;
  cursor = list->head;
  printf("Circular Linked List:\n");

  if (cursor->next != NULL)
    cll_display_element(list, cursor->next);

  printf("\n");
  return;
}

CIRCULAR_LINKED_LIST* circular_linked_list()
{
  CIRCULAR_LINKED_LIST* new_list;
  new_list = malloc(sizeof(CIRCULAR_LINKED_LIST));
  cll_empty(new_list);

  return new_list;
}

// Menu

int cll_menu(CIRCULAR_LINKED_LIST* list)
{
  int choice, value;

  printf("Menu\n1. Insert\n2. Delete\n3. Display all the elements\n4. Size of the list\n5. Back to Main Menu\n6. Exit\nYour Choice:");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter the value to insert:");
      scanf("%d", &value);
      cll_insert(list, value);
      cll_display(list);
      break;

    case 2:
      cll_display(list);
      printf("Enter the value to be deleted:");
      scanf("%d", &value);
      cll_delete(list, value);
      cll_display(list);
      break;

    case 3:
      cll_display(list);
      break;

    case 4:
      cll_display(list);
      printf("No. of elements in the list: %d\n", list->size);
      break;

    case 5:
      main_menu();
      break;

    default: exit(0);
  }
  cll_menu(list);

  return 0;
}
