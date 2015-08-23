#include "doubly_linked_list.h"

void dll_empty(DOUBLY_LINKED_LIST* list)
{
  list->head = list->tail = NULL;
}

int dll_is_empty(DOUBLY_LINKED_LIST* list)
{
  return list->head == list->tail;
}

// Insert

void dll_add(DOUBLY_LINKED_LIST* list, DOUBLY_LINKED_LIST_NODE* newNode)
{
  list->head = malloc(sizeof(DOUBLY_LINKED_LIST));
  newNode->prev = list->head;
  list->tail = newNode;
  list->head->next = list->tail;
  list->size = 0;

  return;
}

void dll_append(DOUBLY_LINKED_LIST* list, DOUBLY_LINKED_LIST_NODE* newNode)
{
  newNode->prev = list->tail;
  list->tail->next = newNode;
  list->tail = newNode;

  return;
}

void dll_insert(DOUBLY_LINKED_LIST* list, int element)
{
  DOUBLY_LINKED_LIST_NODE* newNode;
  newNode = malloc(sizeof(DOUBLY_LINKED_LIST_NODE));
  newNode->element = element;
  newNode->prev = newNode->next = NULL;

  if (dll_is_empty(list))
    dll_add(list, newNode);
  else
    dll_append(list, newNode);

  list->size++;

  return;
}

// Delete

DOUBLY_LINKED_LIST_NODE* dll_find_node(DOUBLY_LINKED_LIST_NODE* prev, int element)
{
  if (prev->element != element && prev->next != NULL)
    return dll_find_node(prev->next, element);
  else
    return prev;
}

void dll_delete(DOUBLY_LINKED_LIST* list, int element)
{
  if (dll_is_empty(list))
  {
    printf("List is empty");
    return;
  }

  DOUBLY_LINKED_LIST_NODE* node;
  node = malloc(sizeof(DOUBLY_LINKED_LIST_NODE));
  node = dll_find_node(list->head, element);

  if (node->next == NULL)
  {
    if (node->element != element)
    {
      printf("Element not found\n");
      return;
    }
    else
    {
      list->tail = node->prev;
      node->prev->next = node->next;
    }
  }
  else
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  list->size--;

  if (dll_is_empty(list))
    dll_empty(list);

  return;
}

// Display

void dll_display_element(DOUBLY_LINKED_LIST_NODE* cursor)
{
  printf("%d", cursor->element);

  if (cursor->next != NULL)
  {
    printf("->");
    dll_display_element(cursor->next);
  }

  return;
}

void dll_display(DOUBLY_LINKED_LIST* list)
{
  if (dll_is_empty(list))
  {
    printf("List is empty\n");
    return;
  }

  printf("Doubly linked list\n");

  dll_display_element(list->head->next);

  printf("\n");
  return;
}

DOUBLY_LINKED_LIST* doubly_linked_list()
{
  DOUBLY_LINKED_LIST* new_list;
  new_list = malloc(sizeof(DOUBLY_LINKED_LIST*));
  dll_empty(new_list);

  return new_list;
}

// Menu

int dll_menu(DOUBLY_LINKED_LIST* list)
{
  int choice, value;

  printf("Menu\n1. Insert\n2. Delete\n3. Display all the elements\n4. Size of the list\n5. Back to Main Menu\n6. Exit\nYour Choice:");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter the value to insert:");
      scanf("%d", &value);
      dll_insert(list, value);
      dll_display(list);
      break;

    case 2:
      dll_display(list);
      printf("Enter the value to be deleted:");
      scanf("%d", &value);
      dll_delete(list, value);
      dll_display(list);
      break;

    case 3:
      dll_display(list);
      break;

    case 4:
      dll_display(list);
      printf("No. of elements in the list: %d\n", list->size);
      break;

    case 5:
      main_menu();
      break;

    default: exit(0);
  }
  dll_menu(list);

  return 0;
}
