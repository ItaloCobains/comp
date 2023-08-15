#ifndef ERROR_H
#define ERROR_H

#include <stdint.h>
#include "./code.hpp"

struct ErrorStruct
{
  CODE_ERR code;
  const char *message;
  int64_t line;
  int64_t column;
};

typedef struct ErrorStruct Error;

#endif // ERROR_H