#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct argv
{
    char livro[33];
    int mes;
    int ano;
} Livro;


int main(int argc, char *argv[]) {
    Livro livros[1];
    int argumentos = argc;
    if (argc == 1) {
        printf("Programa %s sem parametros\n", argv[0]);
    } else
    {
        int i, soma = 0;
        printf("Soma total dos parametros da main: %d\n", argc);
        printf("Parametros do programa %s:\n", argv[1]);
        for (int i = 1; i < argc; i++)
        {
            printf("Parametro %d: %s\n", i, argv[i]);
        }
        strcpy(livros[0].livro, argv[argc - 3]);
        livros[0].mes = atoi(argv[argc - 2]);
        livros[0].ano = atoi(argv[argc - 1]);
        printf("Nome do livro: %s\nMes: %d\nAno: %d\n", livros[0].livro, livros[0].mes, livros[0].ano);
    }
    return 0;
}