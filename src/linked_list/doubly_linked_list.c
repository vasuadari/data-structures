#include "doubly_linked_list.h"

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
  list->head = malloc(sizeof(struct list));
  newNode->prev = list->head;
  list->tail = newNode;
  list->head->next = list->tail;
  list->size = 0;

  return;
}

void append(struct list* list, struct node* newNode)
{
  newNode->prev = list->tail;
  list->tail->next = newNode;
  list->tail = newNode;

  return;
}

void insert(struct list* list, int element)
{
  struct node* newNode;
  newNode = malloc(sizeof(struct node));
  newNode->element = element;
  newNode->prev = newNode->next = NULL;

  if (is_empty(list))
    add(list, newNode);
  else
    append(list, newNode);

  list->size++;

  return;
}

// Delete

struct node* find_node(struct node* prev, int element)
{
  if (prev->element != element && prev->next != NULL)
    return find_node(prev->next, element);
  else
    return prev;
}

void delete(struct list* list, int element)
{
  if (is_empty(list))
  {
    printf("List is empty");
    return;
  }

  struct node* node;
  node = malloc(sizeof(struct node));
  node = find_node(list->head, element);

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

  if (is_empty(list))
    empty(list);

  return;
}

// Display

void display_element(struct node* cursor)
{
  printf("%d", cursor->element);

  if (cursor->next != NULL)
  {
    printf("->");
    display_element(cursor->next);
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

  printf("Doubly linked list\n");

  display_element(list->head->next);

  printf("\n");
  return;
}

struct list* doubly_linked_list()
{
  struct list* new_list;
  new_list = malloc(sizeof(struct node*));
  empty(new_list);

  return new_list;
}

// Menu

int menu(struct list* list)
{
  int choice, value;

  printf("Menu\n1. Insert\n2. Delete\n3. Display all the elements\n4. Size of the list\n5. Exit\nYour Choice:");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter the value to insert:");
      scanf("%d", &value);
      insert(list, value);
      display(list);
      break;

    case 2:
      display(list);
      printf("Enter the value to be deleted:");
      scanf("%d", &value);
      delete(list, value);
      display(list);
      break;

    case 3:
      display(list);
      break;

   case 4:
      display(list);
      printf("No. of elements in the list: %d\n", list->size);
      break;

    default: exit(0);
  }
  menu(list);

  return 0;
}

int main() {
  return menu(doubly_linked_list());
}
