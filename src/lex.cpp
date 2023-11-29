#include "../include/lex.hpp"
#include "../include/reserved-word.hpp"

Lex::Lex(StackErrorLex &stackError, unsigned long long int hashArquivo)
    : stackErrorLex(stackError), hashArquivo(hashArquivo) {}

Lex::~Lex() {}

void Lex::avancar() { this->current++; }

bool Lex::isDigit(char c) { return c >= '0' && c <= '9'; }

bool Lex::isAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

void Lex::addToken(Tokens type, std::string lexema, std::any literal) {
  Token token;
  token.type = type;
  token.column = this->column;
  token.line = this->line;
  token.hashArquivo = this->hashArquivo;
  token.lexema = lexema;
  token.literal = literal;
  this->tokens.push_back(token);
}

void Lex::addError(CODE_ERR type, std::string message) {
  ErrorLexico error;
  error.code = type;
  error.message = message;
  error.line = this->line;
  error.column = this->column;
  this->stackErrorLex.push(error);
}

bool Lex::isAtEnd() { return this->current >= this->code.length(); }

void Lex::string() {
  while (this->code[this->current] != '"' ||
         this->code[this->current - 1] == '\\' ||
         this->code[this->current] == '\n' || this->isAtEnd()) {

    if (this->isAtEnd()) {
      this->addError(CODE_ERR::ERROR_UNTERMINATED_STRING,
                     "String não terminada.");
      return;
    }
    if (this->code[this->current] == '\n')
      this->line++;
    this->current++;
    this->column++;
  }

  std::string value =
      this->code.substr(this->start + 2, this->current - this->start - 2);
  this->addToken(Tokens::TOK_STR, value, value);
}

u_int64_t Lex::nextToken() { return this->current++; }

void Lex::scanToken(char c) {
  switch (c) {
  case '(':
    this->addToken(Tokens::TOK_LPAREN, "(", "(");
    break;
  case ')':
    this->addToken(Tokens::TOK_RPAREN, ")", ")");
    break;
  case '{':
    this->addToken(Tokens::TOK_LBRACE, "{", "{");
    break;
  case '}':
    this->addToken(Tokens::TOK_RBRACE, "}", "}");
    break;
  case '[':
    this->addToken(Tokens::TOK_LBRACKET, "[", "[");
    break;
  case ']':
    this->addToken(Tokens::TOK_RBRACKET, "]", "]");
    break;
  case ',':
    this->addToken(Tokens::TOK_COMMA, ",", ",");
    break;
  case '.':
    this->addToken(Tokens::TOK_DOT, ".", ".");
    break;
  case '-':
    this->addToken(Tokens::TOK_SUB, "-", "-");
    break;
  case '+':
    this->addToken(Tokens::TOK_ADD, "+", "+");
    break;
  case ';':
    this->addToken(Tokens::TOK_SEMICOLON, ";", ";");
    break;
  case '*':
    this->addToken(Tokens::TOK_MUL, "*", "*");
    break;
  case '!':
    if (this->code[this->nextToken()] == '=') {
      this->addToken(Tokens::TOK_NE, "!=", "!=");
      return;
    }
    this->addToken(Tokens::TOK_NOT, "!", "!");
    break;
  case '=':
    if (this->code[this->nextToken()] == '=') {
      this->addToken(Tokens::TOK_EQUAL_EQUAL, "==", "==");
      return;
    }
    this->addToken(Tokens::TOK_EQUAL, "=", "=");
    break;
  case '<':
    if (this->code[this->nextToken()] == '=') {
      this->addToken(Tokens::TOK_LE, "<=", "<=");
      return;
    }
    this->addToken(Tokens::TOK_LT, "<", "<");
    break;
  case '>':
    if (this->code[this->nextToken()] == '=') {
      this->addToken(Tokens::TOK_GE, ">=", ">=");
      return;
    }
    this->addToken(Tokens::TOK_GT, ">", ">");
    break;
  // case '/':
  //   if (this->match('/'))
  //   {
  //     while (this->peek() != '\n' && !this->isAtEnd())
  //       this->advance();
  //   }
  //   else
  //   {
  //     this->addToken(TokenType::SLASH);
  //   }
  //   break;
  case ' ':
  case '\r':
  case '\t':
    break;
  case '\n':
    this->line++;
    this->column = 1;
    break;
  case '\'':
  case '\"':
    this->avancar();
    this->string();
    break;
  default:
    if (this->isDigit(c)) {
      this->number();
    } else if (this->isAlpha(c)) {
      this->identifier();
    } else {
      this->addError(CODE_ERR::ERROR_UNKNOW_CHAR, "Caractere desconhecido.");
    }
    break;
  }
}

void Lex::number() {
  while (this->isDigit(this->code[this->current]))
    this->current++;
  if (this->code[this->current] == '.' &&
      this->isDigit(this->code[this->current + 1])) {
    this->current++;
    while (this->isDigit(this->code[this->current]))
      this->current++;
  }
  std::string text =
      this->code.substr(this->start, this->current - this->start);
  this->addToken(Tokens::TOK_NUM, text, std::stod(text));
}

void Lex::identifier() {
  while (this->isAlpha(this->code[this->current]) ||
         this->isDigit(this->code[this->current]))
    this->current++;
  std::string text =
      this->code.substr(this->start, this->current - this->start);
  if (RESERVED_WORD.find(text) != RESERVED_WORD.end()) {
    this->addToken(Tokens::TOK_RESERVED_WORD, text, text);
    return;
  }
  this->addToken(Tokens::TOK_IDENTIFIER, text, text);
}

LexadorReturn Lex::analizar(std::string &code) {
  this->line = 1;
  this->column = 1;
  this->current = 0;
  this->start = 0;
  this->code = code;
  this->stackErrorLex.clear();

  while (this->current < this->code.length()) {
    this->scanToken(this->code[this->current]);
    this->column++;
    this->start = this->current;
    this->current++;
  }
  this->addToken(Tokens::TOK_EOF, "", "");

  if (!this->stackErrorLex.empty())
    this->stackErrorLex.report();

  return {this->tokens, this->hashArquivo};
}