#include "../include/lex.hpp"

Lex::Lex()
{
}

Lex::~Lex()
{
}

void Lex::analizar(std::string &code)
{
  this->line = 1;
  this->column = 1;
  this->current = 0;
  this->start = 0;

  std::string::iterator it = code.begin();

  while (it != code.end())
  {
    std::cout << *it << std::endl;
    it++;
  }
}