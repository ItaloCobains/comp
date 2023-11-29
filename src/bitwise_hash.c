#include "../include/bitwise_hash.h"

void calculate_bitwise_hash(const char *input_string, size_t input_length,
                            unsigned long long int *hash_value) {
  unsigned long long int hash = 0;

  for (size_t i = 0; i < input_length; ++i) {
    hash = (hash * 65537) + input_string[i];
  }

  *hash_value = hash;
}