/*
  Tokens.hpp - Tokens for the language
  Created by ItaloCobains on 15/08/2023.
*/

#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <iostream>
#include <map>

struct TokenStruct
{
  Tokens type;
  std::string value;
  int64_t line;
  int64_t column;
  u_int64_t hashArquivo;
};

typedef struct TokenStruct Token;

enum Tokens
{
  TOK_EOF = -1,          // end of file
  TOK_ADD = -2,          // +
  TOK_SUB = -3,          // -
  TOK_MUL = -4,          // *
  TOK_DIV = -5,          // /
  TOK_NUM = -6,          // number
  TOK_STR = -7,          // string
  TOK_ID = -8,           // identifier
  TOK_EQUAL = -9,        // =
  TOK_SEMICOLON = -10,   // ;
  TOK_LPAREN = -11,      // (
  TOK_RPAREN = -12,      // )
  TOK_LBRACE = -13,      // {
  TOK_RBRACE = -14,      // }
  TOK_COMMA = -15,       // ,
  TOK_COLON = -16,       // :
  TOK_DOT = -17,         // .
  TOK_LBRACKET = -18,    // [
  TOK_RBRACKET = -19,    // ]
  TOK_LT = -20,          // <
  TOK_GT = -21,          // >
  TOK_LE = -22,          // <=
  TOK_GE = -23,          // >=
  TOK_EQUAL = -24,       // =
  TOK_EQUAL_EQUAL = -25, // ==
  TOK_NE = -25,          // !=
  TOK_AND = -26,         // &&
  TOK_OR = -27,          // ||
  TOK_NOT = -28,         // !

};

#endif // TOKENS_H