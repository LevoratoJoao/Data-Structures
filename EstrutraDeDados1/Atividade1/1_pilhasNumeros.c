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

// #define NAME "entradaEX01.txt"
// #define PARES "pares.txt"
// #define IMPARES "impares.txt"

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

int removerPilha(PilhaImpar *pImpar, PilhaPar *pPar) {
    int option;
    printf("Remove from:\n1 - Odd stack\n2 - Even stack\n");
    scanf("%d", &option);
    if (option == 1) {
        if (pImpar == NULL || pImpar->topo == 0) {
            return 0;
        }
        return pImpar->topo--;
    } else {
        if (pPar == NULL || pPar->topo == 0) {
            return 0;
        }
        return pPar->topo--;
    }
}

int tamanhoPar(PilhaPar *pilha) {
    return pilha->topo;
}

int tamanhoImpar(PilhaImpar *pilha) {
    return pilha->topo;
}

FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        return NULL;
    }
    return file;
}

int rd_file(FILE *file, PilhaPar *pPar, PilhaImpar *pImpar) {
    int c;
    int n = 0;
    //(c = fgetc(file)) != EOF
    while (1) { // Percorre o arquivo lendo ele
        fscanf(file, "%d", &c);
        inserir(pPar, pImpar, c);
        if (feof(file)) { // acaba o loop ao final do arquivo
            break;
        }
    }
    if (pPar->topo != 0 && pImpar->topo != 0) {
        return 1; // Retorna 1 se os topos das pilhas forem diferentes de 0 (insercao deu certo)
    }
}

FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        return NULL;
    }
    return file;
}

FILE sv_file(FILE *filePar, FILE *fileImpar, PilhaPar pPar, PilhaImpar pImpar) {
    for (int i = 0; i < pPar.topo; i++) {
        fprintf(filePar, "%d, ", pPar.numeros[i].nPares);
    }
    for (int i = 0; i < pImpar.topo; i++) {
        fprintf(fileImpar, "%d, ", pImpar.numeros[i].nImpares);
    }
}

int main(int argc, char *argv[]) {
    // Inicializando pilha
    PilhaPar pilhaPar;
    PilhaImpar pilhaImpar;
    iniciarPilha(&pilhaPar, &pilhaImpar);

    // Lendo dados do arqivo e armazenando nas pilhas
    FILE *entrada = op_file(argv[1]);
    printf("Reading file...\n");
    if(rd_file(entrada, &pilhaPar, &pilhaImpar) == 1) {
        printf("File read successfully!\n");
    }

    FILE *pares = cr_file(argv[2]);
    FILE *impares = cr_file(argv[3]);

    while (1) {
        printf("\n\n1 - Show stack of numbers\n2 - Remove numbers from stack\n3 - Show stack size\n4 - Save stack\n5 - Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
        case 1:
            imprimirPilha(pilhaPar, pilhaImpar);
            break;
        case 2:
            removerPilha(&pilhaImpar, &pilhaPar);
        case 3:
            int tamI = tamanhoImpar(&pilhaImpar);
            int tamP = tamanhoPar(&pilhaPar);
            printf("Size of the odd stack: %d\n", tamI);
            printf("Size of the even stack: %d\n", tamP);
            break;
        case 4:
            printf("Saving files...\n");
            sv_file(pares, impares, pilhaPar, pilhaImpar);
            break;
        case 5:
            fclose(entrada);
            fclose(pares);
            fclose(impares);

            return 0;
        default:
            printf("Invalidat option\n");
            break;
        }
    }
    return 0;
}