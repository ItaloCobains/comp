#include "../include/lex.hpp"

Lex::Lex()
{
}

Lex::~Lex()
{
}

bool Lex::isDigit(char c)
{
  return c >= '0' && c <= '9';
}

bool Lex::isAlpha(char c)
{
  return (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z') ||
         c == '_';
}

void Lex::addToken(Tokens type, std::string lexema, std::any literal)
{
  Token token;
  token.type = type;
  token.column = this->column;
  token.line = this->line;
  token.hashArquivo = this->hashArquivo;
  token.lexema = lexema;
  token.literal = literal;
  this->tokens.push_back(token);
}

u_int64_t Lex::nextToken()
{
  return this->current++;
}

void Lex::scanToken(std::string::iterator &it)
{
  char c = *it;
  switch (c)
  {
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
    if (this->code[this->nextToken()] == '=')
    {
      this->addToken(Tokens::TOK_NE, "!=", "!=");
      return;
    }
    this->addToken(Tokens::TOK_NOT, "!", "!");
    break;
  case '=':
    if (this->code[this->nextToken()] == '=')
    {
      this->addToken(Tokens::TOK_EQUAL_EQUAL, "==", "==");
      return;
    }
    this->addToken(Tokens::TOK_EQUAL, "=", "=");
    break;
  case '<':
    if (this->code[this->nextToken()] == '=')
    {
      this->addToken(Tokens::TOK_LE, "<=", "<=");
      return;
    }
    this->addToken(Tokens::TOK_LT, "<", "<");
    break;
  case '>':
    if (this->code[this->nextToken()] == '=')
    {
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
  // case '"':
  //   this->string();
  //   break;
  default:
    if (this->isDigit(c))
    {
      std::cout << "isDigit()" << std::endl;
      // this->number();
    }
    else if (this->isAlpha(c))
    {
      std::cout << "isAlpha()" << std::endl;
      // this->identifier();
    }
    else
    {
      std::cout << "Error lexico en la linea " << this->line << " y columna " << this->column << std::endl;
    }
    break;
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
    this->column++;
    it++;
  }
  for (auto token : this->tokens)
  {
    std::cout << token.lexema << std::endl;
  }
}