#ifndef LEX_H
#define LEX_H

#pragma once

#include <string>
#include <stdint.h>
#include <vector>
#include <iostream>
#include "../include/error_type.hpp"
#include "../include/tokens.hpp"

class Lex
{
public:
  Lex();
  ~Lex();
  void analizar(std::string &code);
  void scanToken(std::string::iterator &it);
  void addToken(Tokens type, std::string lexema);
  bool match(char c);
  u_int64_t nextToken();
  void printErrors();
  void addError(Error type, std::string lexema);

private:
  int64_t current;
  int64_t start;
  int64_t line;
  int64_t column;
  std::vector<Error> errors;
  std::string code;
  std::vector<Token> tokens;
  u_int64_t hashArquivo;
};

#endif // LEX_H