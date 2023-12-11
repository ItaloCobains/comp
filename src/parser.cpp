#include "../include/parser.hpp"

Parser::Parser() { this->tokens = std::vector<Token>(); }

Parser::~Parser() { this->tokens.clear(); }

void Parser::parse(std::vector<Token> &tokens) {}
