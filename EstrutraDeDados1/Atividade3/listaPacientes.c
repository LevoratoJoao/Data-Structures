/**
 * @file listaPacientes.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br)
 * @brief Um casal de m ́edicos decidiu organizar seus pacientes em listas. Atualmente, os dados dos paciente est ̃ao
 * todos juntos em um  ́unico arquivo e sem qualquer organiza ̧c ̃ao alfab ́etica ou de gˆenero. A ginecologista
 * quer listar suas pacientes em ordem alfab ́etica, de A-Z, por nome. J ́a o andrologista precisa que seus
 * pacientes estejam ordenados em ordem alfab ́etica, mas na sequˆencia de Z-A. O(A) ginecologista  ́e o m ́edico
 * respons ́avel por cuidar da sa ́ude da mulher e o(a) andrologista lida com a sa ́ude dos homens. Fa ̧ca um
 * programa que implemente o funcionamento de um sistema para a cl ́ınica, utilizando listas duplamente
 * encadeadas, e organize as informa ̧c ̃oes dos pacientes que est ̃ao dispostas no arquivo pacientes.txt da
 * seguinte forma:
 *
 * < nome, sexo, nascimento, ultima consulta>
 *
 * O programa tamb ́em dever ́a oferecer tres op̧coes:
 *
 * 1.) adicionar um novo paciente que n ̃ao est ́a contido na base de dados antiga,
 *
 * 2.) realizar a pesquisa por nome, devolvendo a idade e, tambem, ha quantos dias foi a  ́ultima consulta
 * deste paciente (considere os anos com 365 dias, ou seja, NAO precisa adicionar um dia nos anos bissextos);
 *
 * 3.) encerrar a sua execucao, gerando os dois arquivos de saıda, sendo um para cada especialista.
 *
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;


typedef struct pacientes_st{
    char nome[100];
    char sexo;
    Data nascimento;
    Data ultimaConsulta;
} Pacientes;

///////////////////////////////////////////////////////////////////
// FUNCOES LISTA
typedef struct obj {
    Pacientes pacientes;
    struct obj* proximo;
} NoLista;

typedef struct listaEncadeada {
    NoLista *inicio;
    int numElemento;
} Lista;

void inicializarLista(Lista *list) {
    list->inicio = NULL;
    list->numElemento = 0;
}

int estaVazia(Lista *list) {
    if (list->numElemento == 0) {
        return 0;
    } else {
        return 1;
    }
}

int tamanhoLista(Lista *list) {
    return list->numElemento;
}

// void inserirElemento(Lista *list, Pacientes pacientes) {
//     NoLista *novo;
//     novo = (NoLista*) malloc(sizeof(NoLista));
//     novo->pacientes = pacientes;
//     novo->proximo = NULL;
//     if(estaVazia(list) == 0) {
//         list->inicio = novo;
//     } else if(pacientes < list->inicio->pacientes) { // strcmp ??????
//         novo->proximo = list->inicio;
//         list->inicio = novo;
//     } else {
//         NoLista *aux = list->inicio;
//         while (aux->proximo != NULL && aux->proximo->pacientes < pacientes) {
//             aux = aux->proximo;
//         }
//         novo->proximo = aux->proximo;
//         aux->proximo = novo;
//     }
//     list->numElemento++;
// }

void imprimirLista(Lista *list) {
    NoLista *aux = list->inicio;
    int pos = 0;
    printf("Inicio da lista:\n");
    while (aux != NULL) {
        printf("\nPos %d --> %d\n", ++pos, aux->pacientes);
        aux = aux->proximo;
    }
    printf("\nFim da lista\n");
}

void destroiLista(Lista *list) {
    NoLista *aux = list->inicio;
    while (list->inicio != NULL) {
        list->inicio = list->inicio->proximo;
        free(aux);
        aux = list->inicio;
    }
}

#define NAME "pacientes.txt"

FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        return EXIT_FAILURE;
    }
    return file;
}

FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        return EXIT_FAILURE;
    }
    return file;
}

void rd_file(FILE *file, Lista *lista) {
    Pacientes n; //Objeto auxiliar
    char aux[100]; //Variavel de leitura auxiliar
    if (fgets(aux, 100, file) == NULL) { // acaba o loop ao final do arquivo
        return;
    } else {
        sscanf(aux, "< %d; %[^;]; %[^;]; %d >\n", &n.nome, &n.sexo, &n.nascimento.dia, &n.nascimento.mes, &n.nascimento.ano, &n.nascimento.dia, &n.nascimento.mes, &n.nascimento.ano); //Formatacao dos dados armazenados na variavel auxiliar, eles sao armazenados em uma variavel auxiliar do tipo do objeto que é usada para inserir na fila
        inserirElemento(lista, n);
    }
}

/**
 * @brief Save file - funcao para salvar as informacoes da variavel no arquivo
 *
 * @param file
 * @param pilha
 * @return FILE
 */
FILE sv_file(FILE *file, Lista *lista) {
    for (NoLista *i = lista->inicio; i != NULL; i = i->proximo) {
        fprintf(file, "< %s, %c, %d/%d/%d, %d/%d/%d >\n", i->pacientes.nome , i->pacientes.sexo, i->pacientes.nascimento.dia, i->pacientes.nascimento.mes, i->pacientes.nascimento.ano, i->pacientes.ultimaConsulta.dia, i->pacientes.ultimaConsulta.mes, i->pacientes.ultimaConsulta.ano);
    }
}

int main(int argc, char *argv[]) {
    //Variaveis de arquivos
    FILE *entrada = op_file(NAME);
    FILE *saidaUm = cr_file("ginecologita.txt");
    FILE *saidaDois = cr_file("andrologista.txt");
    //Variaveis de lista
    Lista pacientesMasculino;
    Lista pacientesFeminino;
    rd_file(entrada, &pacientesMasculino);

    fclose(entrada);
    fclose(saidaUm);
    fclose(saidaDois);
    return EXIT_SUCCESS;
}