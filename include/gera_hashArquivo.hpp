#ifndef GERA_HASHARQUIVO_HPP
#define GERA_HASHARQUIVO_HPP

#include "./bitwise_hash.h"

namespace Gera_hashArquivo
{
    unsigned long long int gera_hashArquivo(const char* input_string, size_t input_length);
}

#endif // GERA_HASHARQUIVO_HPP