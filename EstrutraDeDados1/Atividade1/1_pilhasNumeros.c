/**
 * @file 1_pilhasNumeros.c
 * @author João Vitor Levonumerosto de Souza (joaosouza.2021@Numeros.utfpr.edu.br)
 * @brief Implemente um prognumerosma com duas Pilhas Est ́aticas, uma que ter ́a apenas n ́umeros pares,
 * e a outnumeros apenas com n ́umeros  ́ımpares. O prognumerosma dever ́a ler um arquivo de entnumerosda contendo 10
 * n ́umeros, e empilha-los corretamente. Ao final, imprima cada pilha em um arquivo de sa ́ıda pr ́oprio.
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAME "entradaEX01.txt"

#define N 10

typedef struct numPar {
    int nPares;
} Pares;

typedef struct numImpar {
    int nImpares;
} Impares;

typedef struct pilhaPares {
    int topo;
    Pares numeros[N];
} PilhaPar;

typedef struct pilhaImpares {
    int topo;
    Impares numeros[N];
} PilhaImpar;

bool estaCheiaPar(PilhaPar *pilha) {
    if (pilha->topo == N) {
        return true;
    } else {
        return false;
    }
}

bool estaCheiaImpar(PilhaImpar *pilha) {
    if (pilha->topo == N) {
        return true;
    } else {
        return false;
    }
}

void iniciarPilha(PilhaPar *pPar, PilhaImpar *pImpar) {
    pPar->topo = 0;
    pImpar->topo = 0;
}

void inserir(PilhaPar *pPar, PilhaImpar *pImpar, int n) {
    if (n % 2 == 0) {
        if (estaCheiaPar(pPar) == true) {
            printf("\nStack is full\n");
            return;
        }
        pPar->numeros[pPar->topo].nPares = n;
        pPar->topo++;
    } else {
        if (estaCheiaImpar(pImpar) == true) {
            printf("\nStack is full\n");
            return;
        }
        pImpar->numeros[pImpar->topo].nImpares = n;
        pImpar->topo++;
    }
}

void imprimirPilha(PilhaPar pPar, PilhaImpar pImpar) {
    printf("Stack of even numbers: ");
    for (int i = 0; i < pPar.topo; i++) {
        printf("%d ", pPar.numeros[i].nPares);
    }
    printf("\nStack of odd numbers: ");
    for (int i = 0; i < pImpar.topo; i++) {
        printf("%d ", pImpar.numeros[i].nImpares);
    }
}

int removerPilhaPar(PilhaPar *pilha) {
    return pilha->topo--;
}

int removerPilhaImpar(PilhaImpar *pilha) {
    return pilha->topo--;
}

int tamanhoPar(PilhaPar *pilha) {
    return pilha->topo;
}

int tamanhoImpar(PilhaImpar *pilha) {
    return pilha->topo;
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

int rd_file(FILE *file, PilhaPar *pPar, PilhaImpar *pImpar) {
    int c;
    int n = 0;
    //(c = fgetc(file)) != EOF
    while (1) {
        fscanf(file, "%d", &c);
        inserir(pPar, pImpar, c);
        if (feof(file)) {
            break;
        }
    }
    if (pPar->topo != 0 && pImpar != 0) {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    PilhaPar pilhaPar;
    PilhaImpar pilhaImpar;
    iniciarPilha(&pilhaPar, &pilhaImpar);

    FILE *entrada = op_file(NAME);
    printf("Reading file...\n");
    if(rd_file(entrada, &pilhaPar, &pilhaImpar) == 0) {
        printf("File read successfully!\n");
    }

    int tamI = tamanhoImpar(&pilhaImpar);
    int tamP = tamanhoPar(&pilhaPar);
    printf("Size of the odd stack: %d\n", tamI);
    printf("Size of the even stack: %d\n", tamP);
    imprimirPilha(pilhaPar, pilhaImpar);

    removerPilhaPar(&pilhaPar);
    removerPilhaImpar(&pilhaImpar);

    imprimirPilha(pilhaPar, pilhaImpar);
    tamI = tamanhoImpar(&pilhaImpar);
    tamP = tamanhoPar(&pilhaPar);
    printf("\nSize of the odd stack: %d\n", tamI);
    printf("Size of the even stack: %d\n", tamP);

    return 0;
}