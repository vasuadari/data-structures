#include "../../include/main.h"

struct node
{
  int element;
  struct node *prev, *next;
};

struct list
{
  int size;
  struct node *head, *tail;
};

void empty(struct list* list);

int is_empty(struct list* list);

void add(struct list* list, struct node* newNode);

void append(struct list* list, struct node* newNode);

void insert(struct list* list, int element);

struct node* find_node(struct node* prev, int element);

void delete(struct list* list, int element);

void display_element(struct node* cursor);

void display(struct list* list);
