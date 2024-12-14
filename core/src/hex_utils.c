#include "../include/hex_utils.h"
#include <stdlib.h>

char *byte_to_hex(const unsigned char *data, int length) {
  const int base = 16;
  const char map_base_16[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  const int hex_code_len = 5;
  char *hex_str = malloc((sizeof(char) * (length * hex_code_len)) + 1);
  int hex_str_idx = 0;

  if (hex_str == NULL) {
    return NULL;
  }

  for (int i = 0; i < length; i += 1) {
    int digit = data[i];

    return hex_str;
  }
