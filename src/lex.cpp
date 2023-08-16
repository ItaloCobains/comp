#include "../include/lex.hpp"

Lex::Lex()
{
}

Lex::~Lex()
{
}

void Lex::addToken(Tokens type, std::string lexema)
{
  Token token;
  token.type = type;
  token.column = this->column;
  token.line = this->line;
  token.hashArquivo = this->hashArquivo;
  token.value = lexema;
  this->tokens.push_back(token);
}

u_int64_t Lex::nextToken()
{
  return this->current++;
}

bool Lex::match(char c)
{
  return this->code[this->nextToken()] == c ? true : false;
}

void Lex::scanToken(std::string::iterator &it)
{
  char c = *it;
  switch (c)
  {
  case '(':
    this->addToken(Tokens::TOK_LPAREN, "(");
    break;
  case ')':
    this->addToken(Tokens::TOK_RPAREN, ")");
    break;
  case '{':
    this->addToken(Tokens::TOK_LBRACE, "{");
    break;
  case '}':
    this->addToken(Tokens::TOK_RBRACE, "}");
    break;
  case ',':
    this->addToken(Tokens::TOK_COMMA, ",");
    break;
  case '.':
    this->addToken(Tokens::TOK_DOT, ".");
    break;
  case '-':
    this->addToken(Tokens::TOK_SUB, "-");
    break;
  case '+':
    this->addToken(Tokens::TOK_ADD, "+");
    break;
  case ';':
    this->addToken(Tokens::TOK_SEMICOLON, ";");
    break;
  case '*':
    this->addToken(Tokens::TOK_MUL, "*");
    break;
  case '!':
    bool match = this->match('=');
    Tokens tok = match ? Tokens::TOK_NE : Tokens::TOK_NOT;
    std::string lexema = match ? "!=" : "!";
    this->addToken(tok, lexema);
    break;
  case '=':
    bool match = this->match('=');
    Tokens tok = match ? Tokens::TOK_EQUAL_EQUAL : Tokens::TOK_EQUAL;
    std::string lexema = match ? "==" : "=";
    this->addToken(tok, lexema);
    break;
    // case '<':

    //   this->addToken(this->match('=') ? Tokens::LESS_EQUAL : Tokens::LESS);
    //   break;
    // case '>':
    //   this->addToken(this->match('=') ? Tokens::GREATER_EQUAL : Tokens::GREATER);
    //   break;
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
    // case ' ':
    // case '\r':
    // case '\t':
    //   break;
    // case '\n':
    //   this->line++;
    //   this->column = 1;
    //   break;
    // case '"':
    //   this->string();
    //   break;
    // default:
    //   if (this->isDigit(c))
    //   {
    //     this->number();
    //   }
    //   else if (this->isAlpha(c))
    //   {
    //     this->identifier();
    //   }
    //   else
    //   {
    //     std::cout << "Error lexico en la linea " << this->line << " y columna " << this->column << std::endl;
    //   }
    //   break;
  }
}

void Lex::analizar(std::string &code)
{
  this->line = 1;
  this->column = 1;
  this->current = 0;
  this->start = 0;
  this->hashArquivo = 0;
  this->code = code;

  std::string::iterator it = this->code.begin();

  while (it != this->code.end())
  {
    this->scanToken(it);
    it++;
  }
}