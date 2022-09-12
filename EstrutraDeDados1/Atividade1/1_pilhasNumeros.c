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
#define PARES "pares.txt"
#define IMPARES "impares.txt"

#define N 5

typedef struct pilha {
    int topo;
    int numeros[N];
} PilhaNumeros;

//////////////////////////////////////////////////////////
// Funcoes para manipulacao da pilha:

bool estaCheia(PilhaNumeros *pilha) {
    if (pilha->topo == N) {
        return true;
    } else {
        return false;
    }
}

void iniciarPilha(PilhaNumeros *pPar, PilhaNumeros *pImpar) {
    pPar->topo = 0;
    pImpar->topo = 0;
}

void inserir(PilhaNumeros *pilha, int n) {
    if (estaCheia(pilha) == true) {
        printf("\nStack is full\n");
        return;
    }
    pilha->numeros[pilha->topo] = n;
    pilha->topo++;
}

void imprimirPilha(PilhaNumeros pilha) {
    for (int i = 0; i < pilha.topo; i++) {
        printf("%d ", pilha.numeros[i]);
    }

}

int removerPilha(PilhaNumeros *pilha) {
    if (pilha == NULL || pilha->topo == 0) {
        return 0;
    }
    return pilha->topo--;
}

int tamanhoPilha(PilhaNumeros *pilha) {
    return pilha->topo;
}

//////////////////////////////////////////////////////////
// Funcoes para manipulacao do arquivo de entrada e saida:

FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        return NULL;
    }
    return file;
}

int rd_file(FILE *file, PilhaNumeros *pPar, PilhaNumeros *pImpar) {
    int c;
    //(c = fgetc(file)) != EOF
    while (1) { // Percorre o arquivo lendo ele
        fscanf(file, "%d", &c);
        if (c % 2 == 0) {
            inserir(pPar, c);
        } else {
            inserir(pImpar, c);
        }
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

FILE sv_file(FILE *file, PilhaNumeros pilha) {
    for (int i = pilha.topo - 1; i >= 0; i--) {
        fprintf(file, "%d\n", pilha.numeros[i]);
    }
}

int main(int argc, char *argv[]) {
    // Inicializando pilha
    PilhaNumeros pilhaPar;
    PilhaNumeros pilhaImpar;
    iniciarPilha(&pilhaPar, &pilhaImpar);

    // Lendo dados do arqivo e armazenando nas pilhas
    FILE *entrada = op_file(NAME);
    printf("Reading file...\n");
    if(rd_file(entrada, &pilhaPar, &pilhaImpar) == 1) {
        printf("File read successfully!\n");
    }
    // Criando arquivos de saida
    FILE *pares = cr_file(PARES);
    FILE *impares = cr_file(IMPARES);

    // Menu com manipulacao da pilha
    while (1) {
        printf("\n\n1 - Show stack of numbers\n2 - Remove numbers from stack\n3 - Show stack size\n4 - Save stack\n5 - Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
        case 1: // Mostra pilha de numeros
            printf("Stack of even numbers: ");
            imprimirPilha(pilhaPar);

            printf("\nStack of odd numbers: ");
            imprimirPilha(pilhaImpar);

            break;
        case 2: // Remove elemento do topo da pilha
            printf("Remove from:\n1 - Odd stack\n2 - Even stack\n");
            scanf("%d", &option);
            if (option == 1) {
                removerPilha(&pilhaImpar);
            } else if (option == 2) {
                removerPilha(&pilhaPar);
            } else {
                printf("Invalidate option\n");
            }

            break;
        case 3: // Tamanho das pilhas
            int tamI = tamanhoPilha(&pilhaImpar);
            int tamP = tamanhoPilha(&pilhaPar);

            printf("Size of the odd stack: %d\n", tamI);
            printf("Size of the even stack: %d\n", tamP);

            break;
        case 4: // Salvar arquivos
            printf("Saving files...\n");

            sv_file(pares, pilhaPar);
            sv_file(impares, pilhaImpar);

            break;
        case 5:
            fclose(entrada);
            fclose(pares);
            fclose(impares);

            return 0;
        default:
            printf("Invalidate option\n");

            break;
        }
    }
    return 0;
}