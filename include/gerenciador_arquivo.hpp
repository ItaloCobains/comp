#ifndef GERENCIADOR_ARQUIVO_HPP
#define GERENCIADOR_ARQUIVO_HPP

#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace GerenciadorArquivo
{
  class Arquivo
  {
  public:
    Arquivo(const std::string &nome_arquivo);
    bool abrir();
    void fechar();
    std::string lerConteudo();

  private:
    std::string nome_arquivo_;
    std::ifstream arquivo_;
    bool arquivo_aberto_;
  };
}

#endif // GERENCIADOR_ARQUIVO_HPP