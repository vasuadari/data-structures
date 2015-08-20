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

int is_empty(struct list *list)
{
  return list->head == NULL;
}

struct list* append(struct list *list, struct node *newNode)
{
  list->tail->next = newNode;
  list->tail = list->tail->next;
  return list;
}

void displayElement(struct node* cursor)
{
  printf("%d", cursor->element);
  printf("->");
  if(cursor->next != NULL)
    displayElement(cursor->next);
  return;
}

int list_size(struct node* cursor)
{
  if(cursor->next == NULL)
    return 0;
  else
    return 1 + list_size(cursor->next);
}

void display(struct list *list)
{
  if(is_empty(list))
  {
    printf("List is empty\n");
    return;
  }
  struct node *cursor;
  cursor = list->head;
  printf("Singly Linked List:\n");

  if(cursor->next != NULL)
    displayElement(cursor->next);

  printf("\n");
}

struct list* add(struct list *list, struct node *newNode)
{
  list->head = malloc(sizeof(struct node));
  list->head->next = list->tail = newNode;
  return list;
}

struct list* insert(struct list *list, int element)
{
  struct node *newNode;
  newNode = malloc(sizeof(struct node));
  newNode->element = element;
  newNode->next = NULL;
  if(is_empty(list))
    return add(list, newNode);
  else
    return append(list, newNode);
}

struct node* find_node(struct node* current, int element)
{
  if(current->next == NULL || current->next->element == element)
    return current;
  else
    return find_node(current->next, element);
}

struct list* delete(struct list *list, int element)
{
  if(is_empty(list)) {
    printf("List is empty\n");
    return list;
  }

  struct node *current, *prev;
  prev = find_node(list->head, element);
  current = prev->next;

  if(current->next == NULL && current->element != element)
  {
    printf("Element not found\n");
    return list;
  }
  else if(prev == list->head && current->next == NULL)
  {
    list->tail = list->head = NULL;
  }
  else
  {
    if(current == list->tail)
      list->tail = prev;
    prev->next = current->next;   
  }

  return list;
}

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
      list = insert(list, value);
      display(list);
      break;
 
    case 2:
      printf("Enter the element to be deleted:");
      scanf("%d", &value);
      list = delete(list, value);
      display(list);
      break;
  
    case 3:
      display(list);
      break;

    case 4:
      printf("No of elements in the list: %d\n", list_size(list->head));
      break;

    default: exit(0);
  }
  menu(list);
  return 0;
}

int main()
{
  struct list *newList;

  newList = malloc(sizeof(struct list));
  newList->head = newList->tail = NULL;

  return menu(newList);
}
