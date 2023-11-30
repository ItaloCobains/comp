#include <iostream>

#include "../include/AST.hpp"
#include "../include/gera_hashArquivo.hpp"
#include "../include/gerenciador_arquivo.hpp"
#include "../include/lex.hpp"

void verificaArgs(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    exit(1);
  }
}

int main(int argc, char *argv[])
{
  AST ast;

  // Criar nós
  Node *literalNode = ast.createNode("Literal", "123");
  Node *identifierNode = ast.createNode("Identifier", "x");
  Node *binaryExpressionNode = ast.createNode("BinaryExpression", "+");

  // Adicionar filhos
  binaryExpressionNode->addChild(literalNode);
  binaryExpressionNode->addChild(identifierNode);

  // Imprimir a árvore
  ast.printTree(binaryExpressionNode);

  verificaArgs(argc, argv);

  GerenciadorArquivo::Arquivo arquivo(argv[1]);

  if (!arquivo.abrir())
  {
    std::cout << "Erro ao abrir o arquivo " << argv[1] << std::endl;
    exit(1);
  }

  std::string linhas = arquivo.lerConteudo();

  StackErrorLex stackError;
  Lex lex(stackError, Gera_hashArquivo::gera_hashArquivo(
                          arquivo.caminho_completo.c_str(),
                          arquivo.caminho_completo.length()));

  LexadorReturn retornoLexador = lex.analizar(linhas);

  std::cout << "Tokens: " << std::endl;
  for (auto token : retornoLexador.tokens)
  {
    std::cout << token.type << std::endl;
  }

  std::cout << "Lexemas: " << std::endl;
  for (auto token : retornoLexador.tokens)
  {
    std::cout << token.lexema << std::endl;
  }

  arquivo.fechar();
  return 0;
}