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
  printf("%d\n", cursor->next == NULL);
  while(cursor->next != NULL)
  {
    printf("%d", cursor->next->element);
    printf("->");
    cursor = cursor->next;
  }
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

struct list* delete(struct list *list, int element)
{
  if(is_empty(list)) {
    printf("List is empty\n");
    return list;
  }

  struct node *current, *prev;
  prev = list->head;
  current = list->head->next;

  while(current->element != element)
  {
    prev = current;
    if(current == list->tail)
    {
      printf("Cannot find the element in the list\n");
      return list;
    }
    current = current->next;
  }
  
  if(prev == list->head && current->next == NULL)
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

int main()
{
  int choice, value;
  struct list *newList;

  newList = malloc(sizeof(struct list));
  newList->head = newList->tail = NULL;
  
  do
  {
    printf("Menu\n1. Insert\n2. Delete\n3. Display list\n4. Exit\n");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        printf("Enter the number:");
        scanf("%d", &value);
        newList = insert(newList, value);
        display(newList);
        break;
 
      case 2:
        printf("Enter the element to be deleted:");
	scanf("%d", &value);
	newList = delete(newList, value);
	display(newList);
	break;
     
      case 3:
        display(newList);
	break;
      
      default: exit(0);
    }
  } while(1);
  
  return 0;
}
