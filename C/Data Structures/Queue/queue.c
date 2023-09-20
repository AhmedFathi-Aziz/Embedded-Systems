#include "queue.h"

static uint8_t empty(Queue *object) {
  assert(object != NULL);
  return object->length == 0;
}
static uint8_t full(Queue *object) {
  assert(object != NULL);
  return object->length == object->max_size;
}

Queue *init(uint32_t max_size) {
  assert(max_size > 0);
  Queue *queue = NULL;
  queue = malloc(sizeof(Queue));
  assert(queue != NULL);
  queue->data = calloc(max_size, sizeof(void *));
  assert(queue->data != NULL);
  queue->max_size = max_size;
  queue->length = 0;
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

FS enqueue(Queue *object, void *value) {
  FS out = FAILURE;
  assert(object != NULL);
  assert(value != NULL);
  if (!full(object)) {
    if (empty(object))
      object->front = 0;
    ++object->rear;
    if (object->rear == object->max_size)
      object->rear = 0;
    object->data[object->rear] = value;
    ++object->length;
  }
  return out;
}

void *dequeue(Queue *object) {
  assert(object != NULL);
  void *out = NULL;
  if (!empty(object)) {
    out = object->data[object->front];
    ++object->front;
    if (object->front == object->max_size)
      object->front = 0;
    --object->length;
    if (empty(object)) {
      object->front = -1;
      object->rear = -1;
    }
  }
  return out;
}

void *front(Queue *object) {
  assert(object != NULL);
  void *out = NULL;
  if (!empty(object)) {
    out = object->data[object->front];
  }
  return out;
}

void *rear(Queue *object) {
  assert(object != NULL);
  void *out = NULL;
  if (!empty(object)) {
    out = object->data[object->rear];
  }
  return out;
}

uint32_t queue_size(Queue *object) {
  assert(object != NULL);
  return object->length;
}

void *destroy(Queue *object) {
  assert(object != NULL);
  free(object->data);
  free(object);
  return NULL;
}