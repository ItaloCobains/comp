#ifndef STACK_ERROR_H
#define STACK_ERROR_H

#pragma once

#include "./code.hpp"
#include "./error_type.hpp"
#include <any>
#include <iostream>
#include <stack>
#include <stdint.h>
#include <variant>

class StackErrorLex {
public:
  StackErrorLex();
  ~StackErrorLex();

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