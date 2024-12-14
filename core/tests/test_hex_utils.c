/* gcc test_hex_utils.c ../src/hex_utils.c -lcunit -o test_hex_utils */
#include "../include/hex_utils.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>

void test_byte_to_hex() {
  unsigned char base_10_byte_data[6] = {0, 1, 16, 128, 252, 255};
  char *base_16_byte_data = "0x00 0x01 0x10 0x80 0xFC 0xFF";
  char *result = byte_to_hex(base_10_byte_data, 6);
  CU_ASSERT_STRING_EQUAL(result, base_16_byte_data);
  free(result);
}

int main() {
  if (CU_initialize_registry() != CUE_SUCCESS) {
    return CU_get_error();
  }

  CU_pSuite suite = CU_add_suite("Hex Utils", NULL, NULL);
  if (!suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (!CU_add_test(suite, "test_byte_to_hex", test_byte_to_hex)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return CU_get_error();
}