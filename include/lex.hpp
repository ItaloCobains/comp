#ifndef LEX_H
#define LEX_H

#pragma once

#include <string>
#include <stdint.h>
#include <vector>
#include "../include/error_type.hpp"

class Lex
{
  Lex();
  ~Lex();

public:
  void analizar(std::string &code);

private:
  int64_t current;
  int64_t line;
  int64_t column;
  std::vector<Error> errors;
};

#endif // LEX_H