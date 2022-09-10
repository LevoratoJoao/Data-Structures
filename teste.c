/**
 * @file exe001.c
 * @author dimitri maia (dimitrimaia@alunos.utfpr.edu.br)
 * @brief Implemente um programa com duas Pilhas Estaticas, uma que ter ́a apenas n ́umeros pares,
          e a outra apenas com n ́umeros  ́ımpares. O programa dever ́a ler um arquivo de entrada contendo 10
          n ́umeros, e empilha-los corretamente. Ao final, imprima cada pilha em um arquivo de sa ́ıda proprio.
 * @version 0.1
 * @date 09-09-2022
 * 
 * @copyright Copyright (c) 2022
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define N 10

typedef struct{
    int vetor[N];
    int topo;
    int quantidade_elem;
}PilhaEstatica;

void IniciaPilha(PilhaEstatica *pilha){
    pilha->topo = 0;
    pilha->quantidade_elem = 0;
}//inicia pilha

bool pilhaCheia(PilhaEstatica *pilha){
    if(pilha == N){
        return true; //retorna 1
    }else{
        return false; //retorn 0 
    }
}//função que retorna valor booleano

bool pilhaVazia(PilhaEstatica *pilha){
    if(pilha == 0 || pilha == NULL){
        return true; //retorna 1
    }else{
        return false; //retorn 0 
    }
}//função que retorna valor booleano

void empilhaNum(PilhaEstatica *pilha, int num){
    if(pilhaCheia(pilha) == 1){
        printf("Pilha cheia\n");
    }//if
    //entrada de elemento na pilha
    pilha->vetor[pilha->topo] = num;
    pilha->topo++;
    pilha->quantidade_elem++;
}//empilha numero

int desempilhaNum(PilhaEstatica *pilha){
    if (pilhaVazia == 1){
        printf("pilha vazia\n");
    }//if
    pilha->topo--;
    pilha->quantidade_elem--;
}

int main(){
//#######################################################
    int numeros;
    int aux;
    PilhaEstatica pilhaPar;
    IniciaPilha(&pilhaPar);
    PilhaEstatica pilhaImpar;
    IniciaPilha(&pilhaImpar);
//#######################################################S
    //Inicialização de arquivos de entrada e saida
    FILE* arq_num = fopen("numeros.txt", "r");
    if (arq_num == NULL) exit(1);
    FILE* arq_saida_par = fopen("numeros.txt", "w");
    if (arq_saida_par == NULL) exit(1);
    FILE* arq_saida_impar = fopen("numeros.txt", "w");
    if (arq_saida_impar == NULL) exit(1);
//#######################################################
    //ler os numeros do arquivo .txt
    for (int i = 0; i < N; i++){
        //verificação de numeros(Impar || Par)
        printf("test");
        fscanf(arq_num, "%d", &numeros);
        printf("test");
        printf("numero da posição[%d]: %d\n", i + 1, numeros);
        //empilhas os numeros em cada pilha
        if(numeros % 2 == 0){
            empilhaNum(&pilhaPar, numeros);
        }//par
        else{
            empilhaNum(&pilhaImpar, numeros);
        }//impar
    }//for
//#######################################################
    for (int i = N; i > 0; i--){
        fprintf(arq_saida_par, "%d\n", pilhaPar.vetor[i]);
        fprintf(arq_saida_impar, "%d\n", pilhaImpar.vetor[i]);
    }//desempilha os valores da pilha e salva no arquivo
//#######################################################
    //fecha todos os arquivos
    fclose(arq_num);
    fclose(arq_saida_par);
    fclose(arq_saida_impar);
    return 0;
}//main