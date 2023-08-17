#include "../include/gerenciador_arquivo.hpp"

namespace GerenciadorArquivo
{
  Arquivo::Arquivo(const std::string &nome_arquivo) : nome_arquivo_(nome_arquivo), arquivo_aberto_(false) {}

  bool Arquivo::abrir()
  {
    arquivo_.open(nome_arquivo_);
    if (arquivo_.is_open())
    {
      arquivo_aberto_ = true;
      return true;
    }
    return false;
  }

  void Arquivo::fechar()
  {
    if (arquivo_aberto_)
    {
      arquivo_.close();
      arquivo_aberto_ = false;
    }
  }

  std::string Arquivo::lerConteudo()
  {
    std::string conteudo;
    if (arquivo_aberto_)
    {
      std::string linha;
      while (std::getline(arquivo_, linha))
      {
        conteudo += linha + '\n';
      }
    }
    return conteudo;
  }
}