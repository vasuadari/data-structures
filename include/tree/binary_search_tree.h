#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct binary_search_tree_node
{
  int element;
  struct SINGLY_LINKED_LIST_NODE* left;
  struct SINGLY_LINKED_LIST_NODE* right;
};

struct binary_search_tree
{
  int height;
  struct binary_search_tree_node* root;
};

int bst_is_empty(struct binary_search_tree* tree);

void bst_display(struct binary_search_tree* tree);

struct binary_search_tree* binary_search_tree();

#endif
