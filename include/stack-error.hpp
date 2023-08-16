#ifndef STACK_ERROR_H
#define STACK_ERROR_H

#pragma once

#include <stdint.h>
#include <stack>
#include <iostream>
#include <any>
#include "./error_type.hpp"
#include "./code.hpp"

class StackError
{
public:
  StackError();
  ~StackError();

  int i = 0;
};

#endif // STACK_ERROR_H