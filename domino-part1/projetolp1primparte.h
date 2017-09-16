/*
    \mainpage Linguagens Programação I
    \author Rui Moreira
    \author Daniel Mendes 26385
    \author Gonçalo Silva 26329
    \version 1.0
    \date 2016

R1. Permitir ao utilizador armazenar e gerir um ou mais conjuntos de peças de dominó, i.e., inserir e/ou remover as peças iniciais dum jogo de mão usado no
jogo; as peças também podem ser geradas de forma aleatória; em nenhum dos casos podem haver peças repetidas nos vários conjuntos de peças mão envolvidos;
        (IMPLEMENTADO)
R2. Dada uma representação de peças ou sequências de peças recorrendo a tipos inteiros, permitir gerar as mesmas peças ou sequência usando caracteres/strings,
e vice-versa;
        (PARCIALMENTE IMPLEMENTADO)
R3. Dadas várias sequências de encaixe com tamanhos variáveis (geradas por um algoritmo ou aleatoriamente) pretende-se permitir ordenar essas pesquisas por
ordem de tamanho (comprimento da sequência de encaixe);
        (IMPLEMENTADO) (FUNCIONA SE ESCOLHER UM BARALHO/MAO, CASO CONTRARIO ELE NÃO TEM ESPAÇO PARA MOSTRAR AS SEQUENCIAS)
R4. Dadas várias sequências de encaixe com tamanhos variáveis (geradas por um algoritmo ou aleatoriamente) pretende-se encontrar padrões de encaixe nessas
sequências, ou seja, encontrar as posições de sub-sequências pré-definidas de encaixe;
        (IMPLEMENTADO)
R5. Dada um sequência de encaixe com várias peças, permitir substituir um padrão de encaixe por outro padrão (os padrões podem ter tamanhos diferentes); deverá
ser possível também substituir todas as ocorrências de um padrão por outro padrão, numa dada sequência;
        (IMPLEMENTADO)
R6. A partir de um conjunto de peças do jogador e de uma sequência de encaixe de peças inicial já colocada na mesa de jogo (esta sequência pode ser vazia),
pretende-se determinar a sequência de encaixe final que utiliza todas as peças disponíveis; poderão existir uma ou mais sequências de encaixe com todas as
peças; se não for possível encaixar todas as peças deve determinar-se a maior sequência de encaixe possível;
        (IMPLEMENTADO)
R7. Dados dois ou mais conjuntos de peças ou jogos de mão e de uma sequência de encaixe de peças inicial colocada na mesa de jogo (esta sequência pode ser
vazia), pretende-se determinar se é possível encaixar todas as peças desses conjuntos de mão (retiradas à vez de cada mão do jogador) de forma a
conseguir-se uma sequência válida; se não for possível encaixar todas as peças então deve determinar-se a maior sequência de encaixe possível;
        (IMPLEMENTADO) (FUNCIONA SE ESCOLHER MÃO MANUAL, CASO CONTRARIO ELE NÃO TEM ESPAÇO PARA MOSTRAR AS SEQUENCIAS)
R8. Permitir a manipulação das estruturas de dados através da entrada e saída de dados via ficheiros de texto;
        (NAO IMPLEMENTADO) (IRÁ SER IMPLEMENTADO NA SEGUNDA PARTE)
R9. Permitir a manipulação das estruturas de dados através da entrada e saída de dados via ficheiros binários;
        (NAO IMPLEMENTADO) (IRÁ SER IMPLEMENTADO NA SEGUNDA PARTE)
R10. Permitir a manipulação das estruturas de dados e das funcionalidades da aplicação através de uma estrutura de interação baseada em texto (menus);
        (IMPLEMENTADO)
*/
#include <stdio.h>          //Biblioteca de entrada e saida
#include <stdlib.h>         //Biblioteca de funções padrão
#include <string.h>         //Biblioteca para usar string
#include <stdbool.h>        //Biblioteca para usar booleana
#include <time.h>           //Biblioteca usada para o rand(),srand()
#define COLSTRING 4         //Tamanho das colunas do array de strings
#define COL 2               //Tamanho das colunas do array de inteiros
#define LINSTRING 28        //Tamanho das linhas do array de strings
//Assinatura das funções
int main_projetolp1primparte(int argc, char * argv[]);
void criarpecas(char pecas[][COLSTRING]);
void imprimirpecas(char pecas[][COLSTRING]);
void baralhos(char pecas[][COLSTRING],char baralho[][COLSTRING],char sobrou[][COLSTRING],int);
void rempeca(char pecas[][COLSTRING],char baralho[][COLSTRING],int,int);
void addpeca(char pecas[][COLSTRING],char baralho[][COLSTRING],char sobrou[][COLSTRING],int ,int);
void imprimirpecasint(char pecas[][COLSTRING],int pecasint[][COL]);
int ordenarseq(char pecas[][COLSTRING],char baralho[][COLSTRING],char arrayfinalcompleto[][150],int);
void procurar_padrao(char arrayfinalcompleto[][150],int);
void seq_inicial(char baralho[][COLSTRING]);
void retirar_mao_jogadores(char baralho[][COLSTRING],int);

