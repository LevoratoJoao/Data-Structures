/**
 * @file 3_PaletesPalete.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br) / Arthur Henrique de Oliveira Petroli (arthurpetroli@alunos.utfpr.edu.br)
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
#include <ctype.h>
#define MAXL 5 // Max de lugares
#define MAXP 4 // Max de paletes

typedef struct paletes_st {
    int topo; // Indica quantidade de paletes
    int local; // Local dos paletes
} Pilha;

/**
 * @brief Funcao para verificar se a pilha esta cheia
 *
 * @param locais
 * @return true
 * @return false
 */
bool estaCheia(Pilha *locais) {
    if (locais->topo == MAXL) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Funcao para verificar se a pilha esta vazia
 *
 * @param locais
 * @return true
 * @return false
 */
bool estaVazia(Pilha *locais) {
    if (locais->topo == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Funcao para iniciar a pilha zerando seu topo e o vetor de locais
 *
 * @param locais
 */
void iniciarPaletes(Pilha *locais) {
    locais->local = 0;
    locais->topo = 0;
}

/**
 * @brief Funcao para imprimir local e a quantidade de paletes
 *
 * @param locais
 */
void imprimirPaletes(Pilha *locais) {
    printf("Local: %d - Quantidade: %d\n", locais->local, locais->topo);
}

/**
 * @brief Funcao para insercao de um palete no topo do local com menor numero de paletes
 *
 * @param locais
 */
void inserirPaletes(Pilha *locais) {
    if (estaCheia(locais) == true) { // Verifica se esta cheio o local
        printf("\nLocal cheio\n");
        return;
    } else {
        printf("\nDados atuais do local...:\n");
        imprimirPaletes(locais);
        locais->topo++;
        printf("\nDados atualizados...:\n");
        imprimirPaletes(locais);
    }
}

/**
 * @brief Funcao para remocao de um palete do topo do local com maior numero de paletes
 *
 * @param locais
 * @return int
 */
int removerPaletes(Pilha *locais) {
    if (estaVazia(locais))
    {
        printf("\nLocal vazio\n");
        return locais->topo;
    } else {
        printf("\nDados atuais do local...:\n");
        imprimirPaletes(locais);
        locais->topo--;
        printf("\nDados atualizados...:\n");
        imprimirPaletes(locais);
        return locais->topo;
    }
}

int tamanho(Pilha *locais) {
    return locais->topo;
}

/**
 * @brief Funcao para localizar quais locais estao disponiveis para insercao retornando o local com menor numero de paletes
 *
 * @param locais
 * @return int
 */
int localizarDisponivel(Pilha *locais) {
    int localPilha = 0; //Posicao pilha mais baixa
    for (int i = 0; i < MAXL; i++) {
        if (locais[i].topo < locais[localPilha].topo) {
            localPilha = i;
        }
    }
    return localPilha;
}

/**
 * @brief Funcao para localizar quais locais estao cheios para remocao retornando o local com maior numero de paletes
 *
 * @param locais
 * @return int
 */
int localizarCheio(Pilha *locais) {
    int localPilha = 0; //Posicao pilha com mais paletes
    for (int i = 0; i < MAXL; i++) {
        if (locais[i].topo > locais[localPilha].topo) {
            localPilha = i;
        }
    }
    return localPilha;
}

int main() {
    Pilha locais[MAXL]; // Vetor de locais com pilha de paletes
    for (int i = 0; i < MAXL; i++) {
        iniciarPaletes(&locais[i]);
    }

    while (1) { // loop menu
        printf("\n(a) Adicionar novo palete\n(b) Remover palete\n(c) Sair\n");
        char option;
        scanf("%s", &option);
        option = tolower(option); // Passa opcao para minusculo
        switch (option)
        {
        case 'a':
            int disponivel = localizarDisponivel(locais);
            locais[disponivel].local = disponivel + 1;
            inserirPaletes(&locais[disponivel]);
            break;
        case 'b':
            int cheio = localizarCheio(locais);
            removerPaletes(&locais[cheio]);
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