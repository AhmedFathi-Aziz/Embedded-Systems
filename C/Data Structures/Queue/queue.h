#ifndef _QUEUE_H
#define _QUEUE_H

#include "utility.h"

typedef struct {
  void **data;
  uint32_t max_size;
  uint32_t length;
  sint32_t front;
  sint32_t rear;
}Queue;

Queue *init(uint32_t max_size);

FS enqueue(Queue *object, void *value);

void *dequeue(Queue *object);

void *front(Queue *object);

void *rear(Queue *object);

uint32_t queue_size(Queue *object);

void *destroy(Queue *object);

#endif