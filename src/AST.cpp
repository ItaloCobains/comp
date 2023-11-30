#include "../include/AST.hpp"
#include <iostream>

Node *AST::createNode(std::string type, std::string value)
{
  return new Node(type, value);
}

void AST::printTree(Node *node, int level)
{
  std::cout << std::string(level, ' ') << node->type << ": " << node->value << std::endl;
  for (Node *child : node->children)
  {
    printTree(child, level + 1);
  }
}
