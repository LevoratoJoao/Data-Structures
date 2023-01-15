/**
 * @file 4_structPonteiros.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br)
 * @brief 4 [Structs e Ponteiros] O baralho ´e frequentemente usado em v´arios jogos para entretenimento.
 * Este pode sercodificado por meio de dois tipos abstrato de dados:
 * i) CARTA: que representa uma carta f´ısica do baralho. Possui trˆes atributos: s´ımbolo/valor, o naipe, e uma vari´avel booleana indicando se a carta j´a foi ou n˜ao utilizada/jogada;
 * ii) BARALHO: uma estrutura que representa um conjunto de Cartas.
 *
 * A partir das defini¸c˜oes dos tipos pode-se modelar o objeto Baralho. Para que um baralho seja manipulado
 * adequadamente ele precisa de fun¸c˜oes/procedimentos que mudem seu estado/configura¸c˜ao. Por exemplo, temos que:
 * • criar o baralho;
 * • adicionando as cartas;
 * • consultar a carta do topo;
 * • consultar a carta do fundo;
 * • embaralhar novamente as cartas;
 * • retirar cartas e entregar para os jogadores
 * @version 0.1
 * @date 2022-08-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CARTAS_SZ 52
#define VALOR_SZ 13
#define NAIPES_SZ 4

typedef struct
{
    char valor;
    char naipe;
    bool foiJogada;
} Carta;

typedef struct
{
    Carta array[CARTAS_SZ];
} Baralho;

void criarBaralho(Baralho *baralho) {
    char valores[VALOR_SZ] = { "A234567890QJK" };
    char naipes[NAIPES_SZ] = { "OECP" };

    for (int i = 0; i < CARTAS_SZ; i++) {
        baralho->array[i].valor = valores[i % 13];
        baralho->array[i].naipe = naipes[i % 4];
        baralho->array[i].foiJogada = false;
    }
}

int cartasNaoJogadas(Baralho *baralho) {
    int disponivel = 0;
    for (int i = 0; i < CARTAS_SZ; i++) {
        if (baralho->array[i].foiJogada == false) {
            disponivel++;
        }
    }

    return disponivel;
}

Carta topo(Baralho *baralho) {
    return baralho->array[CARTAS_SZ - 1];
}

int main() {
    Baralho *baralho;
    criarBaralho(baralho);

    printf("Numero de cartas disponiveis no baralho: %d\n", cartasNaoJogadas(baralho));

    return 0;
}


