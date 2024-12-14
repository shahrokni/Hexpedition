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

int main() {
  if (CU_initialize_registry() != CUE_SUCCESS) {
    return CU_get_error();
  }

  CU_pSuite suite = CU_add_suite("Stack Tests", NULL, NULL);
  if (!suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (!CU_add_test(suite, "test_stack_create", test_stack_create)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return CU_get_error();
}