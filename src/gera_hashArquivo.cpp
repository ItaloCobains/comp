#include "../include/gera_hashArquivo.hpp"

unsigned long long int Gera_hashArquivo::gera_hashArquivo(const char *input_string, size_t input_length)
{
  unsigned long long int *hash_value = new unsigned long long int;
  calculate_bitwise_hash(input_string, input_length, hash_value);
  unsigned long long int result = *hash_value;
  delete hash_value;
  return result;
}