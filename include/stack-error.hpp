#ifndef STACK_ERROR_H
#define STACK_ERROR_H

#pragma once

#include <stdint.h>
#include <stack>
#include <iostream>
#include <any>
#include <variant>
#include "./error_type.hpp"
#include "./code.hpp"

class StackError
{
public:
  StackError();
  ~StackError();

  void push(std::variant<ErrorLexico, std::nullptr_t> error);
  std::variant<ErrorLexico, std::nullptr_t> pop();
  std::variant<ErrorLexico, std::nullptr_t> top();
  bool empty();
  void report();
  void clear();

private:
  std::stack<std::variant<ErrorLexico, std::nullptr_t>> stack;
};

#endif // STACK_ERROR_H