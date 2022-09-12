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
#define MAXL 5
#define MAXP 4

typedef struct paletes_st {
    int topo;
    int locais;
} Pilha;

bool estaCheia(Pilha *paletes) {
    if (paletes->topo == MAXL) {
        return true;
    } else {
        return false;
    }
}

void iniciarPaletes(Pilha *paletes) {
    for (int i = 0; i < MAXL; i++)
    {
        paletes[i].topo = NULL;
        paletes[i].locais = 0;
    }
}

int localizarDisponivel(Pilha *paletes) {
    int menorPilha = paletes[0].locais; //Auxiliar para pilha mais baixa
    int localPilha = 0; //Posicao pilha mais baixa

    for (int i = 0; i < MAXL; i++) {
        if (paletes[i].locais <= menorPilha) {
            menorPilha = paletes[i].locais;
            localPilha = i;
        }
    }
    return localPilha;
}

void imprimirPaletes(Pilha *paletes, int local) {
    printf("Local: %d - Quantidade: %d\n", local, paletes[local].locais);
}

void inserirPaletes(Pilha *paletes) {
    if (estaCheia(paletes) == true) {
        printf("\nLocais cheios\n");
        return;
    }
    int local = localizarDisponivel(paletes);
    imprimirPaletes(paletes, local);
    if (paletes[local].locais == MAXP) {
        printf("Local esta com maximo de paletes\n");
        return;
    } else {
        paletes[local].locais = paletes[local].locais + 1;
        paletes[local].topo++;
        printf("Dados atualizados...:\n");
        imprimirPaletes(paletes, local);
    }
}


int localizarCheio(Pilha *paletes) {
    int maiorPilha = paletes[0].locais; //Auxiliar para pilha com maior numero de paletes
    int localPilha = 0; //Posicao pilha com mais paletes
    for (int i = 0; i < MAXL; i++) {
        if (paletes[i].locais > maiorPilha) {
            maiorPilha = paletes[i].locais;
            localPilha = i;
        }
    }
    return localPilha;
}

int removerPaletes(Pilha *paletes) {
    int local = localizarCheio(paletes);
    imprimirPaletes(paletes, local);
    if (paletes[local].locais == 0) {
        printf("Local ja esta vazio\n");
    } else {
        paletes[local].locais--;
        printf("Dados atualizados...:\n");
        imprimirPaletes(paletes, local);
        return paletes[local].locais;
    }
}

int tamanho(Pilha *paletes) {
    return paletes->topo;
}

int main() {
    Pilha locais[MAXL];
    iniciarPaletes(locais);

    while (1)
    {
        printf("(a) Adicionar novo palete\n(b) Remover palete\n(c) Sair\n");
        char option;
        scanf("%s", &option);
        switch (option)
        {
        case 'a':
            inserirPaletes(locais);
            break;
        case 'b':
            removerPaletes(locais);
            break;
        case 'c':
            return 0;
            break;

        default:
            printf("Opcao invalida.\nDigite novamente...");
            break;
        }
    }
}