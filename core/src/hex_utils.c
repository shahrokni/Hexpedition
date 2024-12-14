#include "../include/hex_utils.h"
#include <stdlib.h>

char *byte_to_hex(const unsigned char *data, int length) {
  const int base = 16;
  const char map_base_16[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  const int hex_code_len = 5;
  char *hex_str = malloc((sizeof(char) * (length * hex_code_len)));

  if (hex_str == NULL) {
    return "";
  }

  for (int i = 0; i < length; i += 1) {
    /* initiate the hexadecimal stack */
    hex_str[i * hex_code_len] = '0';
    hex_str[i * hex_code_len + 1] = 'x';
    hex_str[i * hex_code_len + 2] = map_base_16[(int)(data[i] / base)];
    hex_str[i * hex_code_len + 3] = map_base_16[(data[i] % base)];
    hex_str[i * hex_code_len + 4] = (i != length - 1) ? ' ' : '\0';
  }

  return hex_str;
}
