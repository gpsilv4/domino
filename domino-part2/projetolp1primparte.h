/*
    \mainpage Linguagens Programa��o I
    \author Rui Moreira
    \author Daniel Mendes 26385
    \author Gon�alo Silva 26329
    \version 1.0
    \date 2016

R1. Permitir ao utilizador armazenar e gerir um ou mais conjuntos de pe�as de domin�, i.e., inserir e/ou remover as pe�as iniciais dum jogo de m�o usado no
jogo; as pe�as tamb�m podem ser geradas de forma aleat�ria; em nenhum dos casos podem haver pe�as repetidas nos v�rios conjuntos de pe�as m�o envolvidos;
        (IMPLEMENTADO)
R2. Dada uma representa��o de pe�as ou sequ�ncias de pe�as recorrendo a tipos inteiros, permitir gerar as mesmas pe�as ou sequ�ncia usando caracteres/strings,
e vice-versa;
        (IMPLEMENTADO)
R3. Dadas v�rias sequ�ncias de encaixe com tamanhos vari�veis (geradas por um algoritmo ou aleatoriamente) pretende-se permitir ordenar essas pesquisas por
ordem de tamanho (comprimento da sequ�ncia de encaixe);
        (IMPLEMENTADO) (FUNCIONA SE ESCOLHER UM BARALHO/MAO, CASO CONTRARIO ELE N�O TEM ESPA�O PARA MOSTRAR AS SEQUENCIAS)
R4. Dadas v�rias sequ�ncias de encaixe com tamanhos vari�veis (geradas por um algoritmo ou aleatoriamente) pretende-se encontrar padr�es de encaixe nessas
sequ�ncias, ou seja, encontrar as posi��es de sub-sequ�ncias pr�-definidas de encaixe;
        (IMPLEMENTADO)
R5. Dada um sequ�ncia de encaixe com v�rias pe�as, permitir substituir um padr�o de encaixe por outro padr�o (os padr�es podem ter tamanhos diferentes); dever�
ser poss�vel tamb�m substituir todas as ocorr�ncias de um padr�o por outro padr�o, numa dada sequ�ncia;
        (IMPLEMENTADO)
R6. A partir de um conjunto de pe�as do jogador e de uma sequ�ncia de encaixe de pe�as inicial j� colocada na mesa de jogo (esta sequ�ncia pode ser vazia),
pretende-se determinar a sequ�ncia de encaixe final que utiliza todas as pe�as dispon�veis; poder�o existir uma ou mais sequ�ncias de encaixe com todas as
pe�as; se n�o for poss�vel encaixar todas as pe�as deve determinar-se a maior sequ�ncia de encaixe poss�vel;
        (IMPLEMENTADO)
R7. Dados dois ou mais conjuntos de pe�as ou jogos de m�o e de uma sequ�ncia de encaixe de pe�as inicial colocada na mesa de jogo (esta sequ�ncia pode ser
vazia), pretende-se determinar se � poss�vel encaixar todas as pe�as desses conjuntos de m�o (retiradas � vez de cada m�o do jogador) de forma a
conseguir-se uma sequ�ncia v�lida; se n�o for poss�vel encaixar todas as pe�as ent�o deve determinar-se a maior sequ�ncia de encaixe poss�vel;
        (IMPLEMENTADO) (FUNCIONA SE ESCOLHER M�O MANUAL, CASO CONTRARIO ELE N�O TEM ESPA�O PARA MOSTRAR AS SEQUENCIAS)
R8. Permitir a manipula��o das estruturas de dados atrav�s da entrada e sa�da de dados via ficheiros de texto;
        (IMPLEMENTADO)
R9. Permitir a manipula��o das estruturas de dados atrav�s da entrada e sa�da de dados via ficheiros bin�rios;
        (IMPLEMENTADO)
R10. Permitir a manipula��o das estruturas de dados e das funcionalidades da aplica��o atrav�s de uma estrutura de intera��o baseada em texto (menus);
        (IMPLEMENTADO)
*/
#include <stdio.h>          //Biblioteca de entrada e saida
#include <stdlib.h>         //Biblioteca de fun��es padr�o
#include <string.h>         //Biblioteca para usar string
#include <stdbool.h>        //Biblioteca para usar booleana
#include <time.h>           //Biblioteca usada para o rand(),srand()
#define COLSTRING 4         //Tamanho das colunas do array de strings
#define COL 2               //Tamanho das colunas do array de inteiros
#define LINSTRING 28        //Tamanho das linhas do array de strings
typedef struct sequencia
{
    char * seqstring;
}SEQUENCIA;
typedef struct pecaint
{
    int dir;
    int esq;
    struct pecaint * pnextint;
}PECAINT;
typedef struct sobrou
{
    char * sobroustr;
    struct sobrou * proximo;
}SOBROU;
typedef struct peca
{
    char * pecastr;
    struct peca * pnext;
}PECA;
typedef struct iniciarpeca
{
    int nbar; //baralho
    int nsob; //sobrou
    int npecasint; //pecas int
    int nseq;
    PECA * pfirst;
    SOBROU * psobrou;
    PECAINT * pfirstint;
    SEQUENCIA * pfirstseq;

}INICIARPECA;

//Assinatura das fun��es
int main_projetolp1primparte(int argc, char * argv[]);
void criarpecas(char pecas[][COLSTRING]);
void imprimirpecas(char pecas[][COLSTRING]);
void baralhos(INICIARPECA * b,char pecas[][COLSTRING],char baralho[][COLSTRING],char sobrou[][COLSTRING],int);
void rempeca(INICIARPECA * b,int pecastotal,int npecasremover);
void addpeca(INICIARPECA * b,int pecastotal,int npecas);
void imprimirpecasint(char pecas[][COLSTRING],int pecasint[][COL]);
int ordenarseq(INICIARPECA * b,int num);
void procurar_padrao(char arrayfinalcompleto[][150],int);
void seq_inicial(char baralho[][COLSTRING]);
void retirar_mao_jogadores(char baralho[][COLSTRING],int);
char * create_dyn_string(char str[]);
void inserir_peca_baralho(INICIARPECA * b, char pecas[COLSTRING]);
void inserir_sobrou_baralho(INICIARPECA * b, char pecas[COLSTRING]);
PECA *  find_peca_baralho(INICIARPECA * b, char novapeca[]);
void inserir_pecaint_baralho(INICIARPECA * b, int dir, int esq);
void convert_mao_string_to_int(INICIARPECA * b, int pecastotal);
void convert_mao_int_to_string(INICIARPECA * b, int pecastotal);
void create_array_pecas(INICIARPECA * b, unsigned int n);
void inserir_seq_iniciarpeca(INICIARPECA * b, char seq[]);
void save_txt_jogo(INICIARPECA b, char fname[]);
void save_bin(INICIARPECA b, char fnome[]);
void load_txt_jogo(INICIARPECA *b, char fname[]);
void load_bin(INICIARPECA *b, char fname[]);

