#include <iostream>
#include "../include/file-read.hpp"
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
    verificaArgs(argc, argv);

    FileReader reader(argv[1]);
    StackError stackError;
    Lex lex(stackError);

    std::string conteudoArquivo = reader.readWholeFileToString();

    LexadorReturn retornoLexador = lex.analizar(conteudoArquivo);

    return 0;
}