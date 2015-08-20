#include <stdio.h>
#include <stdlib.h>

struct node
{
  int element;
  struct node *next;
};

struct list
{
  struct node *head, *tail;
};

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

  return;
}

void append(struct list* list, struct node* newNode)
{
  list->tail->next = newNode;
  list->tail = list->tail->next;

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

  return;
}

// Delete

struct node* find_node(struct node* prev, int element)
{
  struct node* next = prev->next;

  if (next == NULL || (next != NULL && next->element == element))
    return prev;
  else
    return find_node(next, element);
}

void delete(struct list* list, int element)
{
  if (is_empty(list)) {
    printf("List is empty\n");
    return;
  }

  struct node *prev, *next;
  prev = find_node(list->head, element);
  next = prev->next;

  if (next == NULL && prev->element != element)
    printf("Element not found\n");
  else
    prev->next = next->next;

    if (prev->next == NULL)
      list->tail = prev;

    if (is_empty(list))
      empty(list);

  return;
}

// Display

void display_element(struct node* cursor)
{
  printf("%d", cursor->element);
  printf("->");

  if (cursor->next != NULL)
    display_element(cursor->next);

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
  printf("Singly Linked List:\n");

  if (cursor->next != NULL)
    display_element(cursor->next);

  printf("\n");
  return;
}

// Determine size of the list

int size(struct node* cursor)
{
  return (cursor != NULL && cursor->next != NULL) ? 1 + size(cursor->next) : 0;
}

// Display Menu

int menu(struct list* list)
{
  int choice, value;

  printf("Menu\n1. Insert\n2. Delete\n3. Display list\n4. Size of the list\n5. Exit\n");
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
      printf("Enter the element to be deleted:");
      scanf("%d", &value);
      delete(list, value);
      display(list);
      break;
  
    case 3:
      display(list);
      break;

    case 4:
      printf("No of elements in the list: %d\n", size(list->head));
      break;

    default: exit(0);
  }
  menu(list);
  return 0;
}


int main()
{
  struct list* newList;

  newList = malloc(sizeof(struct list));
  empty(newList);

  return menu(newList);
}
