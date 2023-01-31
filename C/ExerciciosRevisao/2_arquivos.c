/**
 * @file 2_arquivos.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br)
 * @brief 2 [Arquivos] Fa¸ca um programa que receba, por argumento na main, o nome de um arquivo texto. Crie
 * outro arquivo texto de sa´ıda contendo o texto do arquivo de entrada original, por´em substituindo todas
 * as vogais ‘a’ pelo caractere ‘*’ e as demais vogais por ‘+’. Al´em disso, mostre na tela quantas linhas
 * esse arquivo possui. Dentro do programa fa¸ca o controle de erros, isto ´e, insira comandos que mostre se
 * os arquivos foram abertos com sucesso e, caso contr´ario, imprima uma mensagem de erro encerrando o programa.
 * @version 0.1
 * @date 2022-08-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "libs/filelib/filelib.h"

FILE *cr_file(char *name)
{
    FILE *file = fopen(name, "w+");
    if (file == NULL)
    {
        printf("error: fail to create file\n");
        return NULL;
    }
    return file;
}

FILE *op_file(char *name)
{
    FILE *file = fopen(name, "r");
    if (file == NULL)
    {
        printf("error: fail to open file\n");
        return NULL;
    }
    return file;
}

int ln_file(FILE *file)
{
    int ln = 1;
    char c;
    //(c = fgetc(file)) != EOF
    while (1)
    {
        fscanf(file, "%c", &c);
        if (c == '\n') {
            ln++;
        }
        if (feof(file)) {
            break;
        }
    }
    return ln;
}

void alterarArq(FILE *arq, FILE *arqSaida, char *vogais, char c)
{
    while ((c = fgetc(arq)) != EOF)
    {
        c = tolower(c);
        if (c == vogais[0])
        {
            fputc('*', arqSaida);
        } else if (c == vogais[1] || c == vogais[2] || c == vogais[3] || c == vogais[4]) {
            fputc('+', arqSaida);
        } else {
            fputc(c, arqSaida);
        }

        // c = toupper(c);
        // if (c == vogais[0]) {
        //     fputc('*', arqSaida);
        // }
        // for (int i = 1; i < 5; i++)
        // {
        //     if (c == vogais[i])
        //     {
        //         fputc('+', arqSaida);
        //     }
        // }
    }
    fclose(arqSaida);
}

int main(int argc, char *argv[])
{
    char vogais[5] = { "aeiou" };
    char c;
    FILE *arqEntrada = NULL;
    FILE *arqSaida = NULL;
    arqSaida = cr_file(argv[2]);
    arqEntrada = op_file(argv[1]);

    printf("Numero de linhas do arquivo: %d\n", ln_file(arqEntrada));
    fseek(arqEntrada, 0, SEEK_SET);

    alterarArq(arqEntrada, arqSaida, vogais, c);

    fclose(arqEntrada);
    return 0;
}