#include <iostream>
#include "../include/file-read.hpp"
#include "../include/lex.hpp"
#include "../include/bitwise_hash.h"
#include <cstring>

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

    const char *input_string = "sua_string_aqui"; // Substitua pela string desejada
    size_t input_length = strlen(input_string);
    unsigned long long int hash_value;

    // calculate_bitwise_hash(input_string, input_length, &hash_value);

    // std::cout << "Valor inteiro do hash: " << hash_value << std::endl;

    return 0;
}