#include "../../include/main.h"

void sll_empty(SINGLY_LINKED_LIST* list)
{
  list->head = list->tail = NULL;
}

int sll_is_empty(SINGLY_LINKED_LIST* list)
{
  return list->head == list->tail;
}

// Insert

void sll_add(SINGLY_LINKED_LIST* list, SINGLY_LINKED_LIST_NODE* newNode)
{
  list->head = malloc(sizeof(SINGLY_LINKED_LIST_NODE));
  list->head->next = list->tail = newNode;
  list->size = 0;

  return;
}

void sll_append(SINGLY_LINKED_LIST* list, SINGLY_LINKED_LIST_NODE* newNode)
{
  list->tail->next = newNode;
  list->tail = list->tail->next;

  return;
}

void sll_insert(SINGLY_LINKED_LIST* list, int element)
{
  SINGLY_LINKED_LIST_NODE* newNode;
  newNode = malloc(sizeof(SINGLY_LINKED_LIST_NODE));
  newNode->element = element;
  newNode->next = NULL;

  if (sll_is_empty(list))
    sll_add(list, newNode);
  else
    sll_append(list, newNode);

  list->size++;

  return;
}

// Delete

SINGLY_LINKED_LIST_NODE* sll_find_node(SINGLY_LINKED_LIST_NODE* prev, int element)
{
  SINGLY_LINKED_LIST_NODE* next = prev->next;

  if (next == NULL || (next != NULL && next->element == element))
    return prev;
  else
    return sll_find_node(next, element);
}

void sll_delete(SINGLY_LINKED_LIST* list, int element)
{
  if (sll_is_empty(list)) {
    printf("List is empty\n");
    return;
  }

  SINGLY_LINKED_LIST_NODE *prev, *next;
  prev = sll_find_node(list->head, element);
  next = prev->next;

  if (next == NULL && prev->element != element)
    printf("Element not found\n");
  else
  {
    prev->next = next->next;
    list->size--;

    if (prev->next == NULL)
      list->tail = prev;

    if (sll_is_empty(list))
      sll_empty(list);
  }

  return;
}

// Display

void sll_display_element(SINGLY_LINKED_LIST_NODE* cursor)
{
  printf("%d", cursor->element);

  if (cursor->next != NULL)
  {
    printf("->");
    sll_display_element(cursor->next);
  }

  return;
}

void sll_display(SINGLY_LINKED_LIST* list)
{
  if (sll_is_empty(list))
  {
    printf("List is empty\n");
    return;
  }

  SINGLY_LINKED_LIST_NODE* cursor;
  cursor = list->head;
  printf("Singly Linked List:\n");

  if (cursor->next != NULL)
    sll_display_element(cursor->next);

  printf("\n");
  return;
}

SINGLY_LINKED_LIST* singly_linked_list()
{
  SINGLY_LINKED_LIST* new_list;

  new_list = malloc(sizeof(SINGLY_LINKED_LIST));
  sll_empty(new_list);

  return new_list;
}

// Menu

int sll_menu(SINGLY_LINKED_LIST* list)
{
  int choice, value;

  printf("Menu\n1. Insert\n2. Delete\n3. Display all the elements\n4. Size of the list\n5. Back to Main Menu\n6. Exit\nYour Choice:");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter the value to insert:");
      scanf("%d", &value);
      sll_insert(list, value);
      sll_display(list);
      break;

    case 2:
      sll_display(list);
      printf("Enter the value to be deleted:");
      scanf("%d", &value);
      sll_delete(list, value);
      sll_display(list);
      break;

    case 3:
      sll_display(list);
      break;

    case 4:
      sll_display(list);
      printf("No. of elements in the list: %d\n", list->size);
      break;

    case 5:
      main_menu();
      break;

    default: exit(0);
  }
  sll_menu(list);

  return 0;
}
