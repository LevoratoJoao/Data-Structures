/**
 * @file 3_PaletesPalete.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br) // Arthur Petroli
 * @brief Um supermercado precisa implementar um programa para auxiliar a administracao de seu
 * estoque, onde diversos paletes s ̃ao empilhados. O equipamento permite empilhar no maximo 4 paletes
 * em 5 locais. Elabore um programa em C implementando uma Pilha Estatica, com o seguinte menu de programa:
 * (a) Adicionar novo palete;
 * (b) Remover palete;
 * (c) Sair.
 * Observacoes:
 * • Novos paletes devem ser colocados no local com a pilha mais baixa disponıvel;
 * • Ao se remover um palete, retirar do local com a pilha mais alta disponıvel;
 * • Em cada operacao (empilhar ou desempilhar) mostrar de qual local (Pilha) esta manipulando.
 *
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct paletes_st {
    int topo;
    int locais[5];
} Pilha;

bool estaCheia(Pilha *paletes) {
    if (paletes->topo == MAX - 1) {
        return true;
    } else {
        return false;
    }
}

void iniciarPaletes(Pilha *locais) {
    locais->topo = NULL;
}

int localizarDisponivel(Pilha *locais) {
    int menorPilha = locais->topo; //Auxiliar para pilha mais baixa
    int localPilha = 0; //Posicao pilha mais baixa
    for (int i = 0; i < MAX; i++) {
        if (locais->topo <= menorPilha) {
            menorPilha = locais[i].topo;
            localPilha = i;
        }
    }
    return localPilha;
}

void inserirPaletes(Pilha *paletes) {
    if (estaCheia(paletes) == true) {
        printf("\nLocais cheios\n");
        return;
    }
    int local = localizarDisponivel(paletes);
    imprimirPaletes(paletes, &local);
    paletes[local].topo++;
    printf("Dados atualizados...:\n");
    imprimirPaletes(paletes, &local);
}

void imprimirPaletes(Pilha *paletes, int *local) {
    printf("Local: %d - Quantidade: %d\n", local++, paletes[*local].topo);
}

int localizarCheio(Pilha *paletes) {
    int maiorPilha = paletes[0].locais; //Auxiliar para pilha com maior numero de paletes
    int localPilha; //Posicao pilha com mais paletes
    for (int i = 0; i < MAX; i++) {
        if (paletes->locais[i] > maiorPilha) {
            maiorPilha = paletes[i].locais[i];
            localPilha = maiorPilha;
        }
    }
    return localPilha;
}

int removerPaletes(Pilha *paletes) {
    int local = localizarCheio(paletes);
    imprimirPaletes(paletes, &local);
    return paletes[local].topo--;
    printf("Dados atualizados...:\n");
    imprimirPaletes(paletes, &local);
}

int tamanho(Pilha *Paletes) {
    return Paletes->topo;
}

int main() {
    Pilha locais;
    iniciarPaletes(&locais);

    while (1)
    {
        printf("(a) Adicionar novo palete\n(b) Remover palete\n(c) Sair\n");
        char option;
        scanf("%s", &option);
        switch (option)
        {
        case 'a':
            inserirPaletes(&locais);
            break;
        case 'b':
            removerPaletes(&locais);
            break;
        case 'c':
            return 0;
            break;

        default:
            printf("Opcao invalida.\nDigite novamente...");
            break;
        }
    }
    return 0;
}