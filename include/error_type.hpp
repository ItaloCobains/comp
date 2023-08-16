#ifndef ERROR_H
#define ERROR_H

#include <stdint.h>
#include "./code.hpp"

struct ErrorLexicoStruct
{
  CODE_ERR code;
  const char *message;
  int64_t line;
  int64_t column;
};

typedef struct ErrorLexicoStruct ErrorLexico;

#endif // ERROR_H