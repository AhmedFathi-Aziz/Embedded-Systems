#include "dll.h"

void insert_front(Node **list, uint32_t value) {
  assert(list != NULL);
  Node *node = malloc(sizeof(Node));
  assert(node != NULL);
  node->data = value;
  node->prev = NULL;

  if (*list == NULL) {
    node->next = NULL;
    *list = node;
  } else {
    node->next = *list;
    (*list)->prev = node;
    *list = node;
  }
}

void insert_end(Node **list, uint32_t value) {
  assert(list != NULL);
  Node *node = malloc(sizeof(Node));
  assert(node != NULL);
  node->data = value;
  if (*list == NULL) {
    node->prev = NULL;
    node->next = NULL;
    *list = node;
  } else {
    Node *current = *list;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
    node->prev = current;
    node->next = NULL;
  }
}

void print(Node *list) {
  while (list != NULL) {
    printf("%d\n", list->data);
    list = list->next;
  }
}

void print_backward(Node *list) {
  Node *current = list;
  while (current->next != NULL) {
    current = current->next;
  }
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->prev;
  }
}

void insert_after_position(Node **list, uint32_t value, uint32_t position) {
  assert(list != NULL);

  uint32_t len = length(*list);
  assert(position <= len);

  if (position == len) {
    insert_end(list, value);
  } else {
    Node *node = malloc(sizeof(Node));
    assert(node != NULL);
    node->data = value;

    Node *current = *list;
    for (; position > 1; position--) {
      current = current->next;
    }
    node->next = current->next;
    node->prev = current;
    current->next->prev = node;
    current->next = node;
  }
}

void insert_before_position(Node **list, uint32_t value, uint32_t position) {
  assert(list != NULL);

  uint32_t len = length(*list);
  assert(position <= len);

  if (position == 1) {
    insert_front(list, value);
  } else {
    Node *current = *list;
    for (; position > 1; position--) {
      current = current->next;
    }
    Node *node = malloc(sizeof(Node));
    assert(node != NULL);
    node->data = value;

    node->next = current;
    node->prev = current->prev;
    current->prev->next = node;
    current->prev = node;
  }
}

uint32_t length(Node *list) {
  uint32_t out = 0;
  while (list != NULL) {
    ++out;
    list = list->next;
  }
  return out;
}

void delete_front(Node **list) {
  assert(list != NULL);
  *list = (*list)->next;
  free((*list)->prev);
  (*list)->prev = NULL;
}

void delete_end(Node **list) {
  assert(list != NULL);
  Node *current = *list;
  while (current->next != NULL) {
    current = current->next;
  }
  current->prev->next = NULL;
  free(current);
  current = NULL;
}

void delete_node_at_position(Node **list, uint32_t position) {
  assert(list != NULL);

  uint32_t len = length(*list);
  assert(position <= len);

  if (position == 1) {
    delete_front(list);
  } else if (position == len) {
    delete_end(list);
  } else {
    Node *current = *list;
    for (; position > 1; position--) {
      current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    current = NULL;
  }
}