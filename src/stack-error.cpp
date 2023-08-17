#include "../include/stack-error.hpp"

StackErrorLex::StackErrorLex()
{
}

StackErrorLex::~StackErrorLex()
{
}

void StackErrorLex::push(std::variant<ErrorLexico, std::nullptr_t> error)
{
  this->stack.push(error);
}

std::variant<ErrorLexico, std::nullptr_t> StackErrorLex::pop()
{
  std::variant<ErrorLexico, std::nullptr_t> error = this->stack.top();
  this->stack.pop();
  return error;
}

std::variant<ErrorLexico, std::nullptr_t> StackErrorLex::top()
{
  return this->stack.top();
}

bool StackErrorLex::empty()
{
  return this->stack.empty();
}

void StackErrorLex::report()
{
  std::cout << "Erros encontrados:" << std::endl;
  while (!this->stack.empty())
  {
    std::variant<ErrorLexico, std::nullptr_t> error = this->stack.top();
    this->stack.pop();
    if (std::holds_alternative<ErrorLexico>(error))
    {
      ErrorLexico errorLexico = std::get<ErrorLexico>(error);
      std::cout << "Erro: " << errorLexico.message << " na linha " << errorLexico.line << " e coluna " << errorLexico.column << std::endl;
    }
  }

  this->clear();
  exit(1);
}

void StackErrorLex::clear()
{
  while (!this->stack.empty())
  {
    this->stack.pop();
  }
}