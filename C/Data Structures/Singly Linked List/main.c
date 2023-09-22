#include "sll.h"

int main() {
  Node *head = NULL;
  insert_front(&head, 3);
  insert_end(&head, 22);
  insert_after(head, 44, 2);
  display(head);
  return 0;
}