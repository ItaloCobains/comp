#include "../include/gerenciador_arquivo.hpp"

namespace GerenciadorArquivo {
Arquivo::Arquivo(const std::string &nome_arquivo)
    : nome_arquivo_(nome_arquivo), arquivo_aberto_(false) {
  char resolvedPath[PATH_MAX];

  if (realpath(nome_arquivo.c_str(), resolvedPath) == NULL) {
    std::cerr << "Erro ao obter caminho absoluto do arquivo: " << nome_arquivo
              << std::endl;
    std::exit(EXIT_FAILURE);
  }

  caminho_completo = std::string(resolvedPath);
}

bool Arquivo::abrir() {
  arquivo_.open(nome_arquivo_);
  if (arquivo_.is_open()) {
    arquivo_aberto_ = true;
    return true;
  }
  return false;
}

void Arquivo::fechar() {
  if (arquivo_aberto_) {
    arquivo_.close();
    arquivo_aberto_ = false;
  }
}

std::string Arquivo::lerConteudo() {
  std::string conteudo;
  if (arquivo_aberto_) {
    std::string linha;
    while (std::getline(arquivo_, linha)) {
      conteudo += linha + '\n';
    }
  }
  return conteudo;
}
} // namespace GerenciadorArquivo