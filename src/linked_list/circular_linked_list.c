#include "circular_linked_list.h"

void empty(struct list* list)
{
  list->head = list->tail = NULL;
}

int is_empty(struct list* list)
{
  return list->head == list->tail;
}

// Insert

void add(struct list* list, struct node* newNode)
{
  list->head = malloc(sizeof(struct node));
  list->head->next = list->tail = newNode;
  newNode->next = list->head;
  list->size = 0;

  return;
}

void append(struct list* list, struct node* newNode)
{
  list->tail->next = newNode;
  list->tail = list->tail->next;
  list->tail->next = list->head;

  return;
}

void insert(struct list* list, int element)
{
  struct node* newNode;
  newNode = malloc(sizeof(struct node));
  newNode->element = element;
  newNode->next = NULL;

  if (is_empty(list))
    add(list, newNode);
  else
    append(list, newNode);

  list->size++;

  return;
}

// Delete

struct node* find_node(struct list* list, struct node* prev, int element)
{
  struct node* next = prev->next;

  if (next == list->head || next->element == element)
    return prev;
  else
    return find_node(list, next, element);
}

void delete(struct list* list, int element)
{
  if (is_empty(list)) {
    printf("List is empty\n");
    return;
  }

  struct node *prev, *next;
  prev = find_node(list, list->head, element);
  next = prev->next;

  if (next == list->head && prev->element != element)
    printf("Element not found\n");
  else
  {
    prev->next = next->next;
    list->size--;

    if (prev->next == list->head)
      list->tail = prev;

    if (is_empty(list))
      empty(list);
  }

  return;
}

// Display

void display_element(struct list* list, struct node* cursor)
{
  printf("%d", cursor->element);

  if (cursor->next != list->head)
  {
    printf("->");
    display_element(list, cursor->next);
  }

  return;
}

void display(struct list* list)
{
  if (is_empty(list))
  {
    printf("List is empty\n");
    return;
  }

  struct node* cursor;
  cursor = list->head;
  printf("Circular Linked List:\n");

  if (cursor->next != NULL)
    display_element(list, cursor->next);

  printf("\n");
  return;
}

struct list* circular_linked_list()
{
  struct list* new_list;
  new_list = malloc(sizeof(struct list));
  empty(new_list);

  return new_list;
}

// Display Menu

int menu(struct list* list)
{
  int choice, value;

  printf("\nMenu\n1. Insert\n2. Delete\n3. Display list\n4. Size of the list\n5. Exit\n");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter the number:");
      scanf("%d", &value);
      insert(list, value);
      display(list);
      break;
 
    case 2:
      display(list);
      printf("Enter the element to be deleted:");
      scanf("%d", &value);
      delete(list, value);
      display(list);
      break;
  
    case 3:
      display(list);
      break;

    case 4:
      display(list);
      printf("No of elements in the list: %d\n", list->size);
      break;

    default: exit(0);
  }
  menu(list);
  return 0;
}


int main()
{
  return menu(circular_linked_list());
}
