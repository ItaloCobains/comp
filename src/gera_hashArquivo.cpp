#include "../include/gera_hashArquivo.hpp"

unsigned long long int Gera_hashArquivo::gera_hashArquivo(const char *input_string, size_t input_length)
{
  unsigned long long int *hash_value;
  calculate_bitwise_hash(input_string, input_length, hash_value);
  return *hash_value;
}