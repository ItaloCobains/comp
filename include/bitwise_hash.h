#ifndef BITWISE_HASH_H
#define BITWISE_HASH_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

  void calculate_bitwise_hash(const char *input_string, size_t input_length, unsigned long long int *hash_value);

#ifdef __cplusplus
}
#endif

#endif // BITWISE_HASH_H
