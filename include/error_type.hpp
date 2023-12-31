#ifndef ERROR_H
#define ERROR_H

#pragma once

#include "./code.hpp"
#include <stdint.h>
#include <string>

struct ErrorLexicoStruct {
  CODE_ERR code;
  std::string message;
  int64_t line;
  int64_t column;
};

typedef struct ErrorLexicoStruct ErrorLexico;

#endif // ERROR_H