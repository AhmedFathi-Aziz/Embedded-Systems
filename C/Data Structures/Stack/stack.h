#ifndef _STACK_H
#define _STACK_H

#include  "utility.h"

#define MAX_SIZE 5

typedef struct {
  uint32_t top;
  uint32_t data[MAX_SIZE];
}Stack;

typedef enum StackStatus {
  FULL,
  EMPTY,
  AVAILABLE
}Status;

/*
  @brief Initializes the stack by resetting its top pointer.
  @param object A pointer to the stack structure.
*/
void init(Stack *object);
/*
  @brief attempts to push a given value onto the stack. It checks if the 
         stack is not full before adding the value.
  @param object A pointer to the stack structure.
  @param value  The value to be pushed onto the stack
  @return The function returns SUCCESS if the push operation is successful,
          or FAILURE if the stack is full and the push operation cannot be performed.
*/
FS push(Stack *object, uint32_t value);
/*
  @brief attempts to pop the top value from the stack and stores it in 
         the provided memory location. It checks if the stack is not empty
         before performing the pop operation
  @param object A pointer to the stack structure.
  @param value  A pointer to a uint32_t variable where the popped value will be stored.
  @return The function returns SUCCESS if the pop operation is successful,
          or FAILURE if the stack is empty and the pop operation cannot be performed.
*/
FS pop(Stack *object, uint32_t *value);
/*
  @brief retrieve the top value of the stack without removing it from the stack
         It checks if the stack is not empty before performing the peek operatoin
  @param object A pointer to the stack structure.
  @param value  A pointer to uint32_t variable where the peeked value will be stored.
  @return The function returns SUCCESS if the peek operation is successful,
          or FAILURE if the stack is empty and the peek operation cannot be performed.
*/
FS peek(Stack *object, uint32_t *value);
/*
  @brief retrieves the current size of the stack (the number of elements) and
         stores it in the provided memory location
  @param object A pointer to the stack structure.
  @param size   A pointer to uint32_t variable where the size of the stack will be stored.
*/
void size(Stack *object, uint32_t *size);
/*
  @brief displays the elements of the stack, starting from to top and moving downwards
         It checks if the stack is not empty before performing the display operation
  @param object A pointer to the stack structure.
  @return The function returns SUCCESS if the display operation is successful,
          or FAILURE if the stack is empty there are no elements to display.
*/
FS display(Stack *object);

#endif