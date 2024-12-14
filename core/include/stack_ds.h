#include <stdlib.h>

#ifndef STACK_DS
#define STACK_DS

typedef struct {
  void *elements;
  int pointer;
  int capacity;
  size_t element_size;
} StackDS;

StackDS *stack_create(size_t element_size, int capacity);
int stack_push(StackDS *stack, const void *element);
int stack_pop(StackDS *stack, void *element);
int stack_is_full(const StackDS *stack);
int stack_is_empty(const StackDS *stack);
void stack_destroy(StackDS *stack);

#endif