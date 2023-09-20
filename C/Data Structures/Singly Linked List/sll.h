#ifndef _SLL_H
#define _SLL_H

#include  "utility.h"

typedef struct Node {
  uint32_t data;
  struct Node *next;
}Node;

void insert_front(Node **list, uint32_t value);

void insert_end(Node **list, uint32_t value);

void insert_after(Node *list, uint32_t value, uint32_t position);

void delete_front(Node **list);

uint32_t length(Node *list);

void delete_node(Node **list, uint32_t position);

void display(Node *list);

#endif