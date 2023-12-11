#ifndef PARSER_HPP
#define PARSER_HPP

#include "./tokens.hpp"
#include <vector>

class Parser {
public:
  Parser();
  ~Parser();
  void parse(std::vector<Token> &tokens);

private:
  std::vector<Token> tokens;
};

#endif // PARSER_HPP
