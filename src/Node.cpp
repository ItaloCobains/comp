#include "../include/Node.hpp"

Node::Node(std::string type, std::string value) : type(type), value(value) {}

void Node::addChild(Node *child)
{
  children.push_back(child);
}
