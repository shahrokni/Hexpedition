#include "../include/stack_ds.h"
#include <stdlib.h>
#include <string.h>

StackDS *stack_create(size_t element_size, int capacity) {
  StackDS *stack = malloc(sizeof(StackDS));
  if (!stack)
    return NULL;

  stack->elements = malloc(element_size * capacity);
  if (!stack->elements) {
    free(stack);
    return NULL;
  }

  stack->pointer = -1;
  stack->capacity = capacity;
  stack->element_size = element_size;
  return stack;
}

int stack_push(StackDS *stack, const void *element) {
  if (stack_is_full(stack))
    return 0;

  stack->pointer += 1;
  void *target = (char *)stack->elements + stack->pointer * stack->element_size;
  memcpy(target, element, stack->element_size);
  return 1;
}

int stack_pop(StackDS *stack, void *element) {
  if (stack_is_empty(stack))
    return 0;

  void *source = (char *)stack->elements + stack->pointer * stack->element_size;
  memcpy(element, source, stack->element_size);
  stack->pointer -= 1;
  return 1;
}

int stack_is_full(const StackDS *stack) {
  return stack->pointer == stack->capacity - 1;
}

int stack_is_empty(const StackDS *stack) { return stack->pointer == -1; }

void stack_destroy(StackDS *stack) {
  if (stack) {
    free(stack->elements);
    free(stack);
  }
}