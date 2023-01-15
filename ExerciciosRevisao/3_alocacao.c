/**
 * @file 3_alocacao.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br)
 * @brief 3 [Aloca¸c˜ao Dinˆamica] Fa¸ca um programa que leia um valor N e crie dinamicamente um vetor com essa
 * quantidade de elementos. Em seguida, passe esse vetor para um procedimento que vai preencher os
 * elementos desse vetor com n´umeros aleat´orios de 0 at´e N. Depois, no programa principal, imprima os
 * valores do vetor preenchido. Al´em disso, antes de finalizar o programa, lembre-se de liberar a ´area de mem´oria alocada
 * @version 0.1
 * @date 2022-08-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

void preencher(int *vetor, int size_v) {
    for (int i = 0; i < size_v; i++)
    {
        vetor[i] = rand() % size_v;
    }
}

int main(int argc, char *argv[]) {
    int *vetor = (int*) malloc(atoi(argv[1]) * sizeof(int));
    preencher(vetor, atoi(argv[1]));
    for (int i = 0; i < atoi(argv[1]); i++)
    {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }

    return 0;
}