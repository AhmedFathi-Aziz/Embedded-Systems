#include "sll.h"

void insert_front(Node **list, uint32_t value) {
  assert(list != NULL);
  Node *node = malloc(sizeof(Node));
  assert(node != NULL);
  node->data = value;
  node->next = *list;
  *list = node;
}

void insert_end(Node **list, uint32_t value) {
  assert(list != NULL);
  Node *node = malloc(sizeof(Node));
  assert(node != NULL);
  node->data = value;
  if (*list == NULL) {
    *list = node;
  } else {
    Node *lastNode = *list;
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }
    lastNode->next = node;
  }
}

void insert_after(Node *list, uint32_t value, uint32_t position) {
  assert(list != NULL);
  assert(position <= length(list));
  Node *current = list;

  for (; position > 1; position--) {
    current = current->next;
  }
  Node *newNode = malloc(sizeof(Node));
  assert(newNode != NULL);
  newNode->data = value;
  newNode->next = current->next;
  current->next = newNode;
}

void delete_node(Node **list, uint32_t position) {
  assert(*list != NULL);
  assert(position <= length(*list));
  if (position == 1) {
    delete_front(list);
  } else {
    Node *current = *list;

    for (; position > 2; position--) {
      current = current->next;
    }
    Node *node = current->next;
    current->next = node->next;
    free(node);
    node = NULL;
  }
}

uint32_t length(Node *list) {
  assert(list != NULL);
  Node *head = list;
  uint32_t out = 0;
  while (head != NULL) {
    ++out;
    head = head->next;
  }
  return out;
}

void display(Node *list) {
  assert(list != NULL);
  Node *head = list;
  while (head != NULL) {
    printf("%d\n", head->data);
    head = head->next;
  }
}

void delete_front(Node **list) {
  if (*list) {
    Node *current = *list;
    *list = current->next;
    free(current);
    current = NULL;
  }
}