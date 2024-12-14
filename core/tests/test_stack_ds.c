/* gcc test_stack_ds.c ../src/stack_ds.c -lcunit -o test_stack */

#include "../include/stack_ds.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void test_stack_create() {
  StackDS *stack = stack_create(sizeof(int), 10);
  CU_ASSERT_PTR_NOT_NULL(stack);
  CU_ASSERT_EQUAL(stack->capacity, 10);
  CU_ASSERT_EQUAL(stack->element_size, sizeof(int));
  CU_ASSERT_TRUE(stack_is_empty(stack));
  stack_destroy(stack);
}

void test_stack_push_with_char() {
  StackDS *stack = stack_create(sizeof(char), 1);
  char chr = 'a';
  CU_ASSERT_TRUE(stack_push(stack, &chr));
  CU_ASSERT_TRUE(!stack_is_empty(stack));
  CU_ASSERT_EQUAL(stack->pointer, 0);
  CU_ASSERT_TRUE(stack_is_full(stack));
  stack_destroy(stack);
}

void test_stack_pop_with_int() {
  StackDS *stack = stack_create(sizeof(char), 1);
  char chr = 'a';
  char *popped_element = malloc(sizeof(char));
  stack_push(stack, &chr);
  CU_ASSERT_TRUE(stack_pop(stack, popped_element));
  CU_ASSERT_EQUAL(*popped_element, 'a');
  CU_ASSERT_TRUE(stack_is_empty(stack));
  CU_ASSERT_TRUE(!stack_is_full(stack));
  CU_ASSERT_EQUAL(stack->pointer, -1);
  stack_destroy(stack);
}

int main() {
  if (CU_initialize_registry() != CUE_SUCCESS) {
    return CU_get_error();
  }

  CU_pSuite suite = CU_add_suite("Stack Tests", NULL, NULL);
  if (!suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pTest tests[3];
  tests[0] = CU_add_test(suite, "test_stack_create", test_stack_create);
  tests[1] = CU_add_test(suite, "test_stack_push_with_char",
                         test_stack_push_with_char);
  tests[2] =
      CU_add_test(suite, "test_stack_pop_with_int", test_stack_pop_with_int);

  for (int i = 0; i < 4; i += 1) {
    if (!tests[i]) {
      CU_cleanup_registry();
      return CU_get_error();
    }
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return CU_get_error();
}