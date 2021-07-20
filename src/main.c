#include "../include/main.h"

int main_menu()
{
  int choice;

  printf("Main Menu\n1. Singly linked list\n2. Doubly linked list\n3. Circular linked list\n4. Queue\n5. Stack\n6. Binary Search Tree\nExit\nYour choice:");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      sll_menu(singly_linked_list());
    case 2:
      dll_menu(doubly_linked_list());
    case 3:
      cll_menu(circular_linked_list());
    case 4:
      queue_menu(doubly_linked_list());
    case 5:
      stack_menu(singly_linked_list());
    case 6:
      bst_menu(binary_search_tree());
    default: exit(1);
  }

  main_menu();
  return 1;
}

int main() {
  return main_menu();
}
