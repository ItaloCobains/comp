#include <iostream>
#include <cstring>
#include <fstream>

#include "../include/lex.hpp"
#include "../include/gerenciador_arquivo.hpp"
#include "../include/gera_hashArquivo.hpp"

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

  StackErrorLex stackError;
  Lex lex(stackError, Gera_hashArquivo::gera_hashArquivo(arquivo.caminho_completo.c_str(), arquivo.caminho_completo.length()));

  LexadorReturn retornoLexador = lex.analizar(linhas);

  arquivo.fechar();
  return 0;
}