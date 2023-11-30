#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node
{
public:
  std::string type;
  std::vector<Node *> children;
  std::string value;

  Node(std::string type, std::string value);

  void addChild(Node *child);
};

#endif // NODE_HPP