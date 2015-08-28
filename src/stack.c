#include "linked_list/singly_linked_list.h"

void push(SINGLY_LINKED_LIST* list, int element)
{
  SINGLY_LINKED_LIST_NODE* node;
  node = malloc(sizeof(SINGLY_LINKED_LIST_NODE));
  node->element = element;
  if (sll_is_empty(list))
  {
    list->head = malloc(sizeof(SINGLY_LINKED_LIST_NODE));
    node->next = NULL;
    list->size = 0;
  }
  else
    node->next = list->head->next;
  list->head->next = node;
  list->size++;
}

void pop(SINGLY_LINKED_LIST* list)
{
  if (sll_is_empty(list))
  {
    printf("Stack is empty\n");
    return;
  }

  SINGLY_LINKED_LIST_NODE* node;
  node = list->head->next;

  if (node != NULL)
  {
    printf("Popped element: %d\n", node->element);
    if (node->next != NULL)
      list->head->next = node->next;
    else
      sll_empty(list);
    list->size--;
  }
}

int stack_menu(SINGLY_LINKED_LIST* list)
{
  int choice, value;
  printf("Menu\n1. Push\n2. Pop\n3. Size of the stack\n4. Display elements in the stack\n5. Back to Main Menu\n6. Exit\nYour Choice:");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter the value to be pushed:");
      scanf("%d", &value);
      push(list, value);
      break;
    case 2:
      pop(list);
      break;
    case 3:
      printf("Stack size: %d\n", list->size);
      break;
    case 4:
      printf("Displaying stack\n");
      sll_display(list);
      break;
    case 5:
      main_menu();
    default: exit(0);
  }

  stack_menu(list);

  return 1;
}
