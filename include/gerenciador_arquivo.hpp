#ifndef GERENCIADOR_ARQUIVO_HPP
#define GERENCIADOR_ARQUIVO_HPP

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <string>

namespace GerenciadorArquivo {
class Arquivo {
public:
  Arquivo(const std::string &nome_arquivo);
  bool abrir();
  void fechar();
  std::string lerConteudo();
  std::string caminho_completo;

private:
  std::string nome_arquivo_;
  std::ifstream arquivo_;
  bool arquivo_aberto_;
};
} // namespace GerenciadorArquivo

#endif // GERENCIADOR_ARQUIVO_HPP