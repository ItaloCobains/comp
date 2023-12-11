#ifndef LEX_H
#define LEX_H

#pragma once

#include "./stack-error.hpp"
#include "./tokens.hpp"
#include <any>
#include <stdint.h>
#include <string>
#include <vector>

struct LexadorTypeReturn {
  std::vector<Token> tokens;
  u_int64_t hashArquivo;
};

typedef struct LexadorTypeReturn LexadorReturn;

class Lex {
public:
  Lex(StackErrorLex &stackErrorLex, unsigned long long int hashArquivo = 0);
  ~Lex();
  LexadorReturn analizar(std::string &code);

private:
  int64_t current;
  int64_t start;
  int64_t line;
  int64_t column;
  std::string code;
  std::vector<Token> tokens;
  u_int64_t hashArquivo;
  StackErrorLex &stackErrorLex;

  bool isDigit(char c);
  bool isAlpha(char c);
  u_int64_t nextToken();
  void addToken(Tokens type, std::string lexema, std::any literal);
  void scanToken(char c);
  void addError(CODE_ERR type, std::string message);
  void string();
  bool isAtEnd();
  void avancar();
  void identifier();
  void number();
};

#endif // LEX_H