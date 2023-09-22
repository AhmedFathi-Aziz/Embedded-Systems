#ifndef _DLL_H
#define _DLL_H

#include  "utility.h"

typedef struct Node {
  uint32_t data;
  struct Node *next;
  struct Node *prev;
}Node;

void insert_front(Node **list, uint32_t value);

void insert_end(Node **list, uint32_t value);

void print(Node *list);

void print_backward(Node *list);

void insert_after_position(Node **list, uint32_t value, uint32_t position);

void insert_before_position(Node **list, uint32_t value, uint32_t position);

uint32_t length(Node *list);

void delete_front(Node **list);

void delete_end(Node **list);

void delete_node_at_position(Node **list, uint32_t position);

#endif