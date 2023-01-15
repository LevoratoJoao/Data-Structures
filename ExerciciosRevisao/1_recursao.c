/**
 * @file recursao.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br)
 * @brief 1 [Recursao] Escreva e programe uma funcao recursiva para calcular o valor de um numero inteiro de base
 * x elevada a um expoente inteiro y, sendo os valores de x>0 e y>0 fornecidos pelo usuario.
 *
 * @version 0.1
 * @date 2022-08-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

int recursao(int x, int y) {
    if (y == 0) return 1;
    else return x * recursao(x, y - 1);
}

int main(int argc, char *argv[]) {
    int resultado = recursao(atoi(argv[1]), atoi(argv[2]));
    printf("Result: %d\n", resultado);
    return 0;
}

