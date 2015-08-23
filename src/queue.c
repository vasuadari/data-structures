#include "linked_list/doubly_linked_list.h"

void dequeue(DOUBLY_LINKED_LIST* list)
{
  if (dll_is_empty(list))
  {
    printf("Queue is empty\n");
    return;
  }

  DOUBLY_LINKED_LIST_NODE* node;
  node = list->head->next;
  if (node->next == NULL)
  {
    list->tail = node->prev;
    node->prev->next = node->next;
  }
  else
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  list->size--;

  if (dll_is_empty(list))
    dll_empty(list);

  printf("Dequeued value: %d", node->element);

  return;
}

void peek(DOUBLY_LINKED_LIST* list)
{
  if (list->tail == NULL)
    printf("Queue is empty\n");
  else
    printf("Element at first: %d\n", list->tail->next->element);
}

int queue_menu(DOUBLY_LINKED_LIST* list)
{
  int choice, value;
  printf("Menu\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Size of the queue\n5. Back to Main Menu\n6. Exit\nYour Choice:");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter the value to be enqeueued:");
      scanf("%d", &value);
      dll_insert(list, value);
      break;
    case 2:
      dequeue(list);
      break;
    case 3:
      peek(list);
      break;
    case 4:
      printf("Queue size: %d\n", list->size);
      break;
    case 5:
      main_menu();
    default: exit(0);
  }

  queue_menu(list);

  return 1;
}
