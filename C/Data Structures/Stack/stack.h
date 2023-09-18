#ifndef _STACK_H
#define _STACK_H

#include  "utility.h"

typedef struct {
  void **data;
  uint32_t max_size;
  sint32_t top;
}Stack;

typedef enum StackStatus {
  FULL,
  EMPTY,
  AVAILABLE
}Status;

/*
  @brief allocates memory for a new stack structure and its data array.
         it sets the top index to -1, indicating an empty stack, and assigns the specified
         maximum size to the stack. the data array is initialized with null pointers
  @param max_size The maximum number of elements the stack can hold
  @return pointer to the newly initialized stack
*/
Stack* init(uint32_t max_size);
/*
  @brief takes a pointer to a stack and deallocates the memory used by both the stack's
         data array and the stack structure itself.
  @param object A pointer to the stack structure.
  @return NULL, indicating that the stack has been successfully destroyed.
*/
Stack* destroy(Stack *object);
/*
  @brief attempts to push a given value onto the stack. It checks if the 
         stack is not full before adding the value.
  @param object A pointer to the stack structure.
  @param value  A pointer to the element to be pushed onto the stack
  @return The function returns SUCCESS if the push operation is successful,
          or FAILURE if the stack is full and the push operation cannot be performed.
*/
FS push(Stack *object, void *value);
/*
  @brief removes and returns to top element from the stack, reducing the stack's size by one.
         the retrieved element is returned, or NULL if the stack is empty
  @param object A pointer to the stack structure.
  @return pointer to the top element that was removed from the stack,
          or NULL if the stack is empty
*/
void *pop(Stack *object);
/*
  @brief retrieve the top element of the stack without removing it from the stack
         it returns a pointer to the top element, or NULL if the stack is empty
  @param object A pointer to the stack structure.
  @return pointer to the top element of the stack, or NULL if the stack is empty
*/
void *peek(Stack *object);
/*
  @brief retrieves the current size of the stack (the number of elements) and
         stores it in the provided memory location
  @param object A pointer to the stack structure.
  @param size   A pointer to uint32_t variable where the size of the stack will be stored.
*/
void stack_size(Stack *object, uint32_t *size);
/*
  @brief displays the elements of the stack, starting from to top and moving downwards
         It checks if the stack is not empty before performing the display operation
  @param object A pointer to the stack structure.
  @return The function returns SUCCESS if the display operation is successful,
          or FAILURE if the stack is empty there are no elements to display.
*/
FS display(Stack *object);

#endif