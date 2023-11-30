#ifndef AST_HPP
#define AST_HPP

#include "./Node.hpp"

class AST
{
public:
  Node *createNode(std::string type, std::string value);

  void printTree(Node *node, int level = 0);
};

#endif // AST_HPP
