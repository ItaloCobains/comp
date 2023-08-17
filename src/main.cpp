#include <iostream>
#include "../include/gerenciador_arquivo.hpp"
#include "../include/lex.hpp"
#include "../include/bitwise_hash.h"
#include <cstring>
#include <fstream>

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

  verificaArgs(argc, argv);

  GerenciadorArquivo::Arquivo arquivo(argv[1]);

  if (!arquivo.abrir())
  {
    std::cout << "Erro ao abrir o arquivo " << argv[1] << std::endl;
    exit(1);
  }

  std::string linhas = arquivo.lerConteudo();

  arquivo.fechar();

  StackErrorLex stackError;
  Lex lex(stackError);

  LexadorReturn retornoLexador = lex.analizar(linhas);

  return 0;
}