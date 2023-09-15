#include "stack.h"

/*
  @brief Checks whether the given stack is full by comparing its top pointer
         to the maximum sized allowed.
  @param object A pointer to the stack structure.
  @return The function return AVAILABLE if the stack is not full, or FULL
          if the stack is FULL.
*/
static Status full(Stack *object) {
  assert(object != NULL);
  Status out = AVAILABLE;
  if (object->top + 1 == MAX_SIZE)
    out = FULL;
  return out;
}
/*
  @brief Checks whether the given stack is empty by examining its pointer.
  @param object A pointer to the stack structure.
  @return The function return AVAILABLE if the stack is not empty, or EMPTY
          if the stack is empty.
*/
static Status empty(Stack *object) {
  assert(object != NULL);
  Status out = AVAILABLE;
  if (object->top == -1)
    out = EMPTY;
  return out;
}
/*
  @brief Initializes the stack by resetting its top pointer.
  @param object A pointer to the stack structure.
*/
void init(Stack *object) {
  assert(object != NULL);
  object->top = -1;
}
/*
  @brief attempts to push a given value onto the stack. It checks if the 
         stack is not full before adding the value.
  @param object A pointer to the stack structure.
  @param value  The value to be pushed onto the stack
  @return The function returns SUCCESS if the push operation is successful,
          or FAILURE if the stack is full and the push operation cannot be performed.
*/
FS push(Stack *object, uint32_t value) {
  assert(object != NULL);
  FS out = FAILURE;
  if (full(object) == AVAILABLE) {
    object->data[++object->top] = value;
    out = SUCCESS;
  }
  return out;
}
/*
  @brief attempts to pop the top value from the stack and stores it in 
         the provided memory location. It checks if the stack is not empty
         before performing the pop operation
  @param object A pointer to the stack structure.
  @param value  A pointer to a uint32_t variable where the popped value will be stored.
  @return The function returns SUCCESS if the pop operation is successful,
          or FAILURE if the stack is empty and the pop operation cannot be performed.
*/
FS pop(Stack *object, uint32_t *value) {
  assert(object != NULL);
  assert(value != NULL);
  FS out = FAILURE;
  if (empty(object) == AVAILABLE) {
    *value = object->data[object->top];
    --object->top;
    out = SUCCESS;
  }
  return out;
}
/*
  @brief retrieve the top value of the stack without removing it from the stack
         It checks if the stack is not empty before performing the peek operatoin
  @param object A pointer to the stack structure.
  @param value  A pointer to uint32_t variable where the peeked value will be stored.
  @return The function returns SUCCESS if the peek operation is successful,
          or FAILURE if the stack is empty and the peek operation cannot be performed.
*/
FS peek(Stack *object, uint32_t *value) {
  assert(object != NULL);
  assert(value != NULL);
  FS out = FAILURE;
  if (empty(object) == AVAILABLE) {
    *value = object->data[object->top];
    out = SUCCESS;
  }
  return out;
}
/*
  @brief retrieves the current size of the stack (the number of elements) and
         stores it in the provided memory location
  @param object A pointer to the stack structure.
  @param size   A pointer to uint32_t variable where the size of the stack will be stored.
*/
void size(Stack *object, uint32_t *size) {
  assert(object != NULL);
  assert(size != NULL);
  *size = object->top + 1;
}
/*
  @brief displays the elements of the stack, starting from to top and moving downwards
         It checks if the stack is not empty before performing the display operation
  @param object A pointer to the stack structure.
  @return The function returns SUCCESS if the display operation is successful,
          or FAILURE if the stack is empty there are no elements to display.
*/
FS display(Stack *object) {
  assert(object != NULL);
  FS out = FAILURE;
  if (empty(object) == AVAILABLE) {
    sint32_t i = object->top;
    for (; i >= 0; i--) {
      printf("%d\n", object->data[i]);
    }
    out = SUCCESS;
  }
  return out;
}