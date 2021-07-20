#include "../../include/main.h"

int bst_is_empty(struct binary_search_tree* tree)
{
  return tree->height == 0;
}

void bst_display(struct binary_search_tree* tree)
{
  if (bst_is_empty(tree))
  {
    printf("Tree is empty\n");
    return;
  }
}

struct binary_search_tree* binary_search_tree()
{
  struct binary_search_tree* new_tree;

  new_tree = malloc(sizeof(struct binary_search_tree_node));

  return new_tree;
}

// Menu


int bst_menu(struct binary_search_tree* tree)
{
  int choice, value;

  printf("Menu\n1. Display all the elements\nYour Choice: ");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      bst_display(tree);
      break;
    default: exit(0);
  }

  bst_menu(tree);

  return 0;
}
