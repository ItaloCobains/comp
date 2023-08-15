#ifndef LEX_H
#define LEX_H

#pragma once

#include <string>
#include <stdint.h>
#include <vector>
#include <iostream>
#include "../include/error_type.hpp"

class Lex
{
public:
  Lex();
  ~Lex();
  void analizar(std::string &code);

private:
  int64_t current;
  int64_t start;
  int64_t line;
  int64_t column;
  std::vector<Error> errors;
};

#endif // LEX_H