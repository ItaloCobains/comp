#ifndef LEX_H
#define LEX_H

#pragma once

#include <string>
#include <any>
#include <stdint.h>
#include <vector>
#include <iostream>
#include "../include/error_type.hpp"
#include "../include/tokens.hpp"

struct LexadorTypeReturn
{
  std::vector<Token> tokens;
  std::vector<ErrorLexico> errors;
  u_int64_t hashArquivo;
};

typedef struct LexadorTypeReturn LexadorReturn;

class Lex
{
public:
  Lex();
  ~Lex();
  LexadorReturn analizar(std::string &code);

private:
  int64_t current;
  int64_t start;
  int64_t line;
  int64_t column;
  std::vector<ErrorLexico> errors;
  std::string code;
  std::vector<Token> tokens;
  u_int64_t hashArquivo;

  bool isDigit(char c);
  bool isAlpha(char c);
  u_int64_t nextToken();
  void addToken(Tokens type, std::string lexema, std::any literal);
  void scanToken(std::string::iterator &it);
  void addError(CODE_ERR type, std::string message);
};

#endif // LEX_H