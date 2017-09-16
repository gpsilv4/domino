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
#include "projetolp1primparte.h"  //Biblioteca para headers

/** \brief Fun��o main_projectolp1primparte */
int main_projetolp1primparte(int argc, char * argv[]){
    /** char pecas[LINSTRING][COLSTRING] - Array de strings para pecas */
    char pecas[LINSTRING][COLSTRING];
    /** char baralho[LINSTRING][COLSTRING] - Array de strings de pe�as baralhadas, dependendo das m�os que o jogador pedir (4 m�os de 7 pe�as no m�ximo)  */
    char baralho[LINSTRING][COLSTRING];
    /** char sobrou[LINSTRING][COLSTRING] - Array de strings de pecas baralhadas, onde ficam as pe�as n�o utilizadas na m�o do jogador */
    char sobrou[LINSTRING][COLSTRING];
    /** char arrayfinalcompleto[3000][150] - Array de strings de todas as sequencias possiveis das m�os do jogador   */
    char arrayfinalcompleto[3000][150];
    /** int opc=0 - Op��o escolhida no menu inicial */
    int opc=0;
    /** int num=0 - N�mero de baralhos que o jogador escolhe (m�ximo 4) */
    int num=0;
    /** int npecasremover=0 - N�mero de pe�as que o utilizador pretende remover da sua m�o */
    int npecasremover=0;
    /** int pecastotal=0 - N�mero de pe�as total que o jogador tem na m�o, consoante o n�mero de m�os escolhidas. Ex: 2 m�o x 7 pe�as =  14 pe�as total */
    int pecastotal=0;
    /** int npecas=0 - N�mero de pe�as que o utilizador pretende adicionar � sua m�o */
    int npecas=0;
    /** int y=0 - Tamanho do array de strings de todas as sequencias possiveis das m�os do jogador (arraycompleto) */
    int y=0;
    /** criarpecas(pecas) - Criar todas pe�as do jogo*/
    criarpecas(pecas);
    /** bool sair = false - Manter ciclo do menu enquanto for false, quando for true sai  */
    bool sair = false;
    /** char escolha - Usado para quando � escrito "S" ou "s" fecha programa, caso contr�rio continua */
    char escolha;

    INICIARPECA b = {0,0,0,0,NULL,NULL,NULL,NULL};

    create_array_pecas(&b,2);


    //Menu com ciclo. O utilizador escolhe a op��o que pretende e atrav�s do switch retorna para a fun��o pretendida
    do{
    printf("**************** JOGO DO DOMINO ****************\n\n");
    printf("Escolha uma opcao\n");
    printf("1 ----> Listar Pecas Sring\n");
    printf("2 ----> Criar Mao\n");
    printf("3 ----> Remover Pecas\n");
    printf("4 ----> Adicionar Pecas\n");
    printf("5 ----> Listar baralho/mao string to int\n");
    printf("6 ----> Criar e ordenar sequencias\n");
    printf("7 ----> Procurar padrao\n");
    printf("8 ----> Criar sequencias com sequencia inicial\n");
    printf("9 ----> Criar sequencias com maos alternadas\n");
    printf("10 ----> Listar baralho/mao int to string\n");
    printf("11 ----> Guardar baralho/sequencias em ficheiro txt\n");
    printf("12 ----> Guardar sequencias em ficheiro bin\n");
    printf("13 ----> Ler de um ficheiro txt\n");
    printf("14 ----> Ler de um ficheiro binario\n");

    printf("Opcao: ");
    scanf("%d", &opc);

    switch(opc)
            {
            case 1:
                imprimirpecas(pecas);
                break;
            case 2:
                printf("Insira o numero de m�os a jogar:\n");
                scanf("%d",&num);
                baralhos(&b,pecas,baralho,sobrou,num);
                break;
            case 3:
                printf("Quantas pecas pretende remover:\n");
                scanf("%d",&npecasremover);
                pecastotal=num*7;
                rempeca(&b,pecastotal,npecasremover);
                break;
            case 4:
                printf("Quantas pecas pretende adicionar:\n");
                scanf("%d",&npecas);
                pecastotal=num*7;
                addpeca(&b,pecastotal,npecas);
                break;
            case 5:
                pecastotal=num*7;
                convert_mao_string_to_int(&b,pecastotal);
                break;
            case 6:
                y=ordenarseq(&b,num);
                break;
            case 7:
                procurar_padrao(arrayfinalcompleto,y);
                break;
            case 8:
                seq_inicial(baralho);
                break;
            case 9:
                retirar_mao_jogadores(baralho,num);
                break;
            case 10:
                pecastotal=num*7;
                convert_mao_int_to_string(&b,pecastotal);
                break;
            case 11:
                save_txt_jogo(b,"./wbarseq.txt");
                break;
            case 12:
                save_bin(b,"./binwseq.bin");
                break;
            case 13:
                load_txt_jogo(&b,"./rbar.txt");
                break;
            case 14:
                load_bin(&b,"binrbar.bin");
                break;

            default:
            printf("Escolha invalida!\n\n");
            }
            printf("Pretende sair? S --->sim \n");
            scanf("%s",&escolha);
            if(escolha=='S'||escolha=='s'){
                sair=true;
            }else{
                sair=false;
            }
    }while(sair==false);
    return 0;
}

/** \brief Criar pe�as string */
void criarpecas(char pecas[][COLSTRING]){
    /**
        \details S�o criadas todas as pe�as possiveis que um jogo tem e s�o copiadas atrav�s do strcpy para dentro do array pecas
        \param pecas[][COLSTRING] Array do tipo char guarda as pe�as totais do jogo.
    */
    strcpy(pecas[0],"0|0");
    strcpy(pecas[1],"0|1");
    strcpy(pecas[2],"0|2");
    strcpy(pecas[3],"0|3");
    strcpy(pecas[4],"0|4");
    strcpy(pecas[5],"0|5");
    strcpy(pecas[6],"0|6");
    strcpy(pecas[7],"1|1");
    strcpy(pecas[8],"1|2");
    strcpy(pecas[9],"1|3");
    strcpy(pecas[10],"1|4");
    strcpy(pecas[11],"1|5");
    strcpy(pecas[12],"1|6");
    strcpy(pecas[13],"2|2");
    strcpy(pecas[14],"2|3");
    strcpy(pecas[15],"2|4");
    strcpy(pecas[16],"2|5");
    strcpy(pecas[17],"2|6");
    strcpy(pecas[18],"3|3");
    strcpy(pecas[19],"3|4");
    strcpy(pecas[20],"3|5");
    strcpy(pecas[21],"3|6");
    strcpy(pecas[22],"4|4");
    strcpy(pecas[23],"4|5");
    strcpy(pecas[24],"4|6");
    strcpy(pecas[25],"5|5");
    strcpy(pecas[26],"5|6");
    strcpy(pecas[27],"6|6");

/** O que est� comentado - Pe�as teste para usar no ponto R7, visto que pecas aleatorias de 2 ou mais m�os, ele n�o tem mem�ria para gerar as sequencias  */
/*
    strcpy(pecas[0],"2|5");
    strcpy(pecas[1],"3|3");
    strcpy(pecas[2],"2|2");
    strcpy(pecas[3],"1|1");
    strcpy(pecas[4],"4|4");
    strcpy(pecas[5],"5|5");
    strcpy(pecas[6],"6|6");
    strcpy(pecas[7],"1|2");
    strcpy(pecas[8],"6|3");
    strcpy(pecas[9],"1|4");
    strcpy(pecas[10],"1|5");
    strcpy(pecas[11],"0|6");
    strcpy(pecas[12],"2|1");
    strcpy(pecas[13],"0|3");
*/

}
/** \brief Imprime as pecas em string */
void imprimirpecas(char pecas[][COLSTRING]){
    /**
        \details Imprime o array das 28 pecas em string
        \param pecas[][COLSTRING] Array do tipo char onde recebe as pe�as totais do jogo.
    */
    int i = 0;
    for(i=0;i<28;i++){
        printf("%s\n",pecas[i]);
    }
}


/** \brief Imprimir pecas em inteiros */
void imprimirpecasint(char pecas[][COLSTRING], int pecasint[][COL]){
    /**
     \details Imprime o array das 28 pecas em inteiros, guarda apenas os dois valores inteiros e ignora a barra. Ex: 1 3
     \param pecas[][COLSTRING] Array do tipo char onde recebe as pe�as totais do jogo.
     \param pecasint[][COL] Array do tipo int onde guarda as pe�as totais do jogo.
    */
    int i=0;
    for(i=0;i<28;i++){
        pecasint[i][0]=atoi(pecas[i]);
        pecasint[i][1]=atoi(&pecas[i][2]);
        printf("%d|%d \n", pecasint[i][0],pecasint[i][1]);
    }
}

/** \brief Criar baralhos/m�os aleat�rios */
void baralhos(INICIARPECA * b,char pecas[][COLSTRING],char baralho[][COLSTRING],char sobrou[][COLSTRING],int num){
    /**
        \details Cria um array de pe�as baralhadas (baralho), sendo esta a m�o do jogador. E guarda noutro array (sobrou) as pe�as n�o utilizadas na m�o.
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param pecas[][COLSTRING] Array do tipo char onde recebe as pe�as totais do jogo.
        \param baralho[][COLSTRING] Array do tipo char, onde ir�o ser guardadas as pe�as baralhadas da m�o do jogador
        \param sobrou[][COLSTRING] Array do tipo char, onde ir�o ser guardadas as pe�as que sobraram, ou seja, que n�o foram usadas na m�o do jogador
        \param num Valor do tipo int, utilizado para definir o numero de m�os a ser usado pelo jogador
    */
    /** srand((unsigned)time(NULL)) - Fun��o srand(),respons�vel por alimentar o rand() e gerar n�meros aleat�rios*/
    srand((unsigned)time(NULL));
    /** int pecastotal=0 - N�mero de pe�as total que o jogador tem na m�o */
    int pecastotal=0;
    /** int i=0 - Variav�l usada nos ciclos */
    int i=0;
    /** int aleatorio - Variav�l que guarda n�mero gerado aleat�rio*/
    int aleatorio;
    /** int array[28] - Array com as posicoes de 0 a 27 das pecas das m�os */
    int array[28];
    /** int temp - Variav�l tempor�ria para guardas conteudo de array[i] */
    int temp;

    PECA * pauxbar = NULL;
    SOBROU * pauxsob = NULL;

    // N�mero de pe�as total que o jogador tem na m�o, numero de m�os (1,2,3 ou 4) multiplicado pelas pecas possiveis de cada m�o (7)
    pecastotal = num * 7;
    //Caso o numero de m�os escollhidas seja igual ou inferior a 4, entra neste if
    if(num<=4){
            // Cria array posicoes das pecas totais
            for(i=0;i<28;i++){
                array[i] = i;
            }
            // Baralha essas 28 pecas e guarda em array, de forma aleat�ria
            for(i=0;i<28;i++){
                temp=array[i];
                aleatorio = rand() % 28;
                array[i]=array[aleatorio];
                array[aleatorio]=temp;
            }
            // Guarda num array baralho[] as pe�as aleat�rias at� ao numero de pecas total definida pelo jogador e imprime
            printf("MAO:\n");
            for(i=0;i<pecastotal;i++){
                //strcpy(baralho[i],pecas[array[i]]);
                //printf("%s\n",baralho[i]);
                inserir_peca_baralho(b,pecas[array[i]]);
            }

                //imprime mao do baralho
                pauxbar=b->pfirst;

                while(pauxbar!=NULL)
                {
                    printf("%s\n",pauxbar->pecastr);
                     pauxbar=pauxbar->pnext;
                }
            // Guarda num array sobrou[] as pe�as aleat�rias desde o numero de pecas total definida pelo jogador at� as 27 possiveis e imprime
            printf("SOBROU:\n");
            for(i=pecastotal;i<28;i++){
                //strcpy(sobrou[i],pecas[array[i]]);
                //printf("%s\n",sobrou[i]);

                inserir_sobrou_baralho(b,pecas[array[i]]);

            }

            //imprime sobras do baralho
            pauxsob=b->psobrou;

                while(pauxsob!=NULL)
                {
                    printf("%s\n",pauxsob->sobroustr);
                     pauxsob=pauxsob->proximo;
                }

    }else if(num>4){
        printf("Nao pode escolher mais que 4 baralhos!\n");
    }
}
/** \brief Converter pe�as string para int */
void convert_mao_string_to_int(INICIARPECA * b, int pecastotal)
    /**
        \details Converte pe�as strings para inteiro
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param pecastotal Valor do tipo int, utilizado para definir as pe�as totais usadas pelo jogador
    */
{
    PECA * paux = NULL;
    PECAINT * pauxbar = NULL;
    char aux1[4];
    char aux2[4];

    paux = b->pfirst;

    while(paux!=NULL)
    {
        strcpy(aux1,paux->pecastr);
        strcpy(aux2,paux->pecastr);
        aux1[1]='\0';
        aux2[0]=aux2[2];
        aux2[1]='\0';

        inserir_pecaint_baralho(b,atoi(aux1),atoi(aux2));

        paux = paux->pnext;
    }

    pauxbar = b->pfirstint;

    //imprime baralho todo
    while(pauxbar!=NULL)
    {
        printf("%d|%d\n",pauxbar->dir,pauxbar->esq);
        pauxbar=pauxbar->pnextint;
    }
}

/** \brief Converter pe�as int para string */
void convert_mao_int_to_string(INICIARPECA * b, int pecastotal)
{
    /**
        \details Converte pe�as inteiro para strings
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param pecastotal Valor do tipo int, utilizado para definir as pe�as totais usadas pelo jogador
    */

    PECA * paux = NULL;
    PECA * pauxbar = NULL;
    PECAINT * pauxint = NULL;
    char str[4];
    int aux1 = 0 ,aux2 = 0,i = 0;
    int tamanhobar=b->nbar;

    paux = b->pfirst;
    //percorro o baralho inicial e meto tudo vazio
    while(paux!=NULL)
    {
            paux->pecastr=NULL;
            b->nbar--;
            paux = paux->pnext;
    }


    //percorro a lista das pecas int e transformo e coloco de volta no baralho original (b->pfirst)
    pauxint = b->pfirstint;
    for(i=0;i<tamanhobar;i++)
    {
        aux1=pauxint->dir;
        aux2=pauxint->esq;
        str[0]=aux1+'0';
        str[1]='|';
        str[2]=aux2+'0';

        inserir_peca_baralho(b,str);

        pauxint = pauxint->pnextint;
    }

    pauxbar = b->pfirst;

    //imprime baralho todo
    while(pauxbar!=NULL)
    {
        printf("%s\n",pauxbar->pecastr);
        pauxbar=pauxbar->pnext;
    }
}
/** \brief Remover pe�as de uma ou mais m�os */
void rempeca(INICIARPECA * b,int pecastotal,int npecasremover){
    /**
        \details Remove pe�as de uma ou mais m�os, sendo que as pe�as removidas s�o substituidas por X|X, e � pedido ao utilizador para inserir tantas pe�as quantas removeu. Sendo tudo verificado para n�o remover pe�as que n�o existam e que n�o sejam adicionas pe�as repetidas.
        \param INICIARPECA * b , estrutura do tipo INICIARPECAr
        \param pecastotal Valor do tipo int, utilizado para definir as pe�as totais usadas pelo jogador
        \param npecasremover Valor do tipo int, utilizado para definir o numero de pe�as a ser removido pelo jogador
    */
    /** char pecaremover[4] - Usado para guardar a pe�a inserida pelo jogador, para depois remover */
    char pecaremover[4];
    /** int j=0 - Variav�l usada nas fun��es seguintes */
    int j=0;
    /** int h=0 - Variav�l usada nas fun��es seguintes */
    int h=0;
    /** char newpeca[4] - Usado para guardar a pe�a a ser inserida pelo jogador, para depois adicionar */
    char newpeca[4];
    /** char invertnewpeca[4] - Usado para guardar a pe�a invertida da newpeca inserida */
    char invertnewpecarem[4]={};

    PECA * pauxbar = NULL;

    //Caso o numero de pe�as a remover seja maior que as pe�as totais, entra neste if
    if(npecasremover>pecastotal){
        printf("Numero de pecas a remover e superior ao baralho!\n");
    // Caso o numero de pe�as a remover seja menor que as pe�as totais, entra neste if
    }else if(npecasremover<pecastotal){
        // Insere peca a remover
        for(j=0;j<npecasremover;j++){
            printf("Insira a peca a remover:");
            scanf("%s",pecaremover);

            PECA * pauxfind = NULL;
            PECA * paux = NULL;
            PECA * pant = NULL;

            pauxfind = find_peca_baralho(b,pecaremover);

            if(pauxfind != NULL){
                paux = b->pfirst;
                //percorre todas as pe�as
                while(paux!=NULL && strcmp(paux->pecastr,pecaremover)!=0){
                        pant=paux;
                        paux=paux->pnext;
                }
                //remover na cabe�a
                if(paux==b->pfirst)
                {
                    b->pfirst=paux->pnext;
                    b->nbar--;
                }else if(paux->pnext==NULL)
                {
                    //remover na cauda
                    pant->pnext=NULL;
                    b->nbar--;
                }else{
                    //se for no meio
                    pant->pnext=paux->pnext;
                    b->nbar--;
                }

            }else{
               printf("Essa peca nao existe, insira outra:\n");
                  j--;
            }
        }

        //Imprime m�o j� com as pe�as removidas
        pauxbar = b->pfirst;
        while(pauxbar!=NULL)
        {
            printf("%s\n",pauxbar->pecastr);
            pauxbar=pauxbar->pnext;
        }

        //Foram removidas pe�as logo insiro novas para completar m�o
        for(j=0;j<npecasremover;j++){
            printf("Insira uma nova peca:");
            scanf("%s",newpeca);

            // Inverter pe�a inserida
            int d=strlen(newpeca)-1;
            for(h=0;h<(strlen(newpeca));h++){
                invertnewpecarem[d]=newpeca[h];
                d--;
            }
            // Verifica se a peca da m�o(baralho[]) � igual a novapeca, ou � invertida
            PECA * pauxfindrem = NULL;
            PECA * pauxfindinvrem = NULL;

            pauxfindrem = find_peca_baralho(b,newpeca);

            pauxfindinvrem = find_peca_baralho(b,invertnewpecarem);

            if(pauxfindrem != NULL || pauxfindinvrem != NULL){
                        printf("A peca ja existe!\n");
                        j--;

            }else{
                        pauxbar = b->pfirst;

                        //Caso contrario ele insere a nova pe�a na ultima posi��o da m�o (baralho[]) e imprime

                        inserir_peca_baralho(b,newpeca);

                        //imprime baralho todo
                        while(pauxbar!=NULL)
                        {
                            printf("%s\n",pauxbar->pecastr);
                            pauxbar=pauxbar->pnext;
                        }
            }
        }
    }
}

/** \brief Inserir pecas no baralho (lista ligada) */
void inserir_peca_baralho(INICIARPECA * b, char pecas[COLSTRING])
{
    /**
        \details Remove pe�as de uma ou mais m�os, sendo que as pe�as removidas s�o substituidas por X|X, e � pedido ao utilizador para inserir tantas pe�as quantas removeu. Sendo tudo verificado para n�o remover pe�as que n�o existam e que n�o sejam adicionas pe�as repetidas.
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param char pecas[COLSTRING] peca nova a inserir
    */
    PECA *pnew = (PECA*)malloc(sizeof(PECA));
    PECA *paux = NULL;

    pnew->pecastr = create_dyn_string(pecas);
    pnew->pnext=NULL;

    paux=b->pfirst;

    if(b->pfirst==NULL)
    {

        b->pfirst=pnew;
        b->nbar++;
    }
    else
    {
        //insere na cauda

        while(paux->pnext!=NULL)
        {

            paux=paux->pnext;

        }

        paux->pnext=pnew;
        b->nbar++;
    }

}

/** \brief Inserir pecas que sobraram do baralho (lista ligada) */
void inserir_sobrou_baralho(INICIARPECA * b, char pecas[COLSTRING])
{
    /**
        \details Remove pe�as de uma ou mais m�os, sendo que as pe�as removidas s�o substituidas por X|X, e � pedido ao utilizador para inserir tantas pe�as quantas removeu. Sendo tudo verificado para n�o remover pe�as que n�o existam e que n�o sejam adicionas pe�as repetidas.
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param char pecas[COLSTRING] peca nova a inserir
    */
    SOBROU *pnew = (SOBROU*)malloc(sizeof(SOBROU));
    SOBROU *paux = NULL;

    pnew->sobroustr = create_dyn_string(pecas);
    pnew->proximo=NULL;

    paux=b->psobrou;

    if(b->psobrou==NULL)
    {

        b->psobrou=pnew;
        b->nsob++;
    }
    else
    {
        //insere na cauda

        while(paux->proximo!=NULL)
        {
            paux=paux->proximo;
        }

        paux->proximo=pnew;
        b->nsob++;

        return;
    }
}

/** \brief Inserir pecas do tipo int no baralho (lista ligada) */
void inserir_pecaint_baralho(INICIARPECA * b, int dir, int esq)
{
    /**
        \details Remove pe�as de uma ou mais m�os, sendo que as pe�as removidas s�o substituidas por X|X, e � pedido ao utilizador para inserir tantas pe�as quantas removeu. Sendo tudo verificado para n�o remover pe�as que n�o existam e que n�o sejam adicionas pe�as repetidas.
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param int dir , valor do tipo inteiro, da parte direita da pe�a
        \param int esq , valor do tipo inteiro, da parte esquerda da pe�a
    */
    PECAINT *pnew = (PECAINT*)malloc(sizeof(PECAINT));
    PECAINT *paux = NULL;

    pnew->dir = dir;
    pnew->esq = esq;
    pnew->pnextint=NULL;

    paux=b->pfirstint;

    if(b->pfirstint==NULL)
    {

        b->pfirstint=pnew;
        b->npecasint++;

    }
    else
    {
        //insere na cauda
        while(paux->pnextint!=NULL)
        {
            paux=paux->pnextint;
        }

        paux->pnextint=pnew;
        b->npecasint++;
    }
}

/** \brief Criar um array dinamico para strings */
char * create_dyn_string(char str[])
{
    /**
        \details Criar um array dinamico para strings
        \param char str[], recebe uma string
    */
    char *paux=NULL;
    int slen = strlen(str)+1;

    paux=(char*)malloc(sizeof(char)*slen);

    strcpy(paux,str);

    return paux;
}

/** \brief Adicionar pe�as numa m�o/m�os */
void addpeca(INICIARPECA * b,int pecastotal,int npecas){
    /**
        \details Adicionar pe�as na m�o, sendo que as pe�as inseridas sao adicionadas � m�o inicial e completada com pe�as aleatorias para preencher as m�os. Ex: o jogador tem uma m�o de 7 pe�as, quer adicionar mais duas, ou seja adiciona essas duas, e sao adicionadas automaticamente 5 pe�as aleatorias, para completar duas m�os (14 pe�as)
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param pecastotal Valor do tipo int, utilizado para definir as pe�as totais usadas pelo jogador
        \param npecas Valor do tipo int, utilizado para definir o numero de pe�as a ser adicionado pelo jogador
    */
    /** int aleatorio=0 - Variav�l onde � guardada o numero de pe�as total mais as pe�as adicionadas pelo jogador. Posteriormente, este valor � subtraido conforme as m�os usadas */
    int aleatorio=0;
    /** int j=0 - Variav�l usada nas fun��es seguintes */
    int j=0;
    /** int k=0 - Variav�l usada nas fun��es seguintes */
    int k=0;
    /** char novapeca[4] - Usado para guardar a pe�a a ser inserida pelo jogador, para depois adicionar */
    char novapeca[4];
    /** char invertnewpeca[4] - Usado para guardar a pe�a invertida da novapeca inserida */
    char invertnewpeca[4]={};

    SOBROU * pauxsob = NULL;
    PECA * pauxbar = NULL;

    aleatorio=pecastotal+npecas;
    // Verificar se a soma da numero de pecas total com as pe�as que quer adicionar est� no primeiro baralho, entre 0 e 6. Se sim, subtrai o valor aleatorio por 6 e guarda em aleat�rio o numero de pe�as que vao ser lan�adas aleat�riamente. E assim sucessivamente para os outros.
    if(aleatorio>0 && aleatorio<6){
        aleatorio=6-aleatorio;
    }else if(aleatorio>6 && aleatorio<13){
            aleatorio=13-aleatorio;
    }else if(aleatorio>13 && aleatorio<20){
        aleatorio=20-aleatorio;
    }else if(aleatorio>20 && aleatorio<27){
        aleatorio=27-aleatorio;
    }
    // Por exemplo, caso o utilizador adiciona 5 pecas, entao 5+7 (7 do baralho original) =12 logo 2 pecas sao aleatorias e as outras 5 manual

    pauxsob = b->psobrou;
    //inserir as pecas do sobrou para o baralho
    for(j=pecastotal;j<=(pecastotal+aleatorio);j++){
        inserir_peca_baralho(b,pauxsob->sobroustr);
        pauxsob=pauxsob->proximo;
    }
    // Imprime a m�o/baralho mais as pe�as aleatorias
    pauxbar = b->pfirst;
    while(pauxbar!=NULL)
    {
        printf("%s\n",pauxbar->pecastr);
        pauxbar=pauxbar->pnext;
    }


    // Inserir peca (novapeca)
    int h=0;

    for(k=0;k<npecas;k++){
            printf("Insira a peca");
            scanf("%s",novapeca);

            // Inverter novapeca
            int d=strlen(novapeca)-1;
            for(h=0;h<(strlen(novapeca));h++){
                invertnewpeca[d]=novapeca[h];
                d--;
            }
            // Verifica se a peca da m�o(baralho[]) � igual a novapeca, ou � invertida
            PECA * pauxfind = NULL;
            PECA * pauxfindinv = NULL;

            pauxfind = find_peca_baralho(b,novapeca);

            pauxfindinv = find_peca_baralho(b,invertnewpeca);

            if(pauxfind != NULL || pauxfindinv != NULL){
                        printf("A peca ja existe!\n");
                        k--;

            }else{
                        pauxbar = b->pfirst;

                        //Caso contrario ele insere a nova pe�a na ultima posi��o da m�o (baralho[]) e imprime

                        inserir_peca_baralho(b,novapeca);

                        //imprime baralho todo
                        while(pauxbar!=NULL)
                        {
                            printf("%s\n",pauxbar->pecastr);
                            pauxbar=pauxbar->pnext;
                        }
            }
    }
}

/** \brief Procurar pe�a no baralho */
PECA *  find_peca_baralho(INICIARPECA * b, char novapeca[])
{
    /**
        \details Verificar se a pe�a existe no baralho, caso haja retorna a pe�a, sen�o retorna NULL
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param char novapeca[],  recebe a nova pe�a para verificar se existe no baralho
    */
    PECA *paux = NULL;
    paux = b->pfirst;

    while(paux !=NULL){
        if( strcmp(paux->pecastr,novapeca)==0 ){
            return paux;
        }else{
            paux=paux->pnext;
        }
    }

    return NULL;
}

/** \brief Criar array dinamico para pecas */
void create_array_pecas(INICIARPECA * b, unsigned int n)
{
    /**
        \details Remove pe�as de uma ou mais m�os, sendo que as pe�as removidas s�o substituidas por X|X, e � pedido ao utilizador para inserir tantas pe�as quantas removeu. Sendo tudo verificado para n�o remover pe�as que n�o existam e que n�o sejam adicionas pe�as repetidas.
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param int n, quantidade que vamos alocar
    */
    SEQUENCIA * paux = NULL;
    SEQUENCIA * pnew = NULL;

    int i=0;
    int j=0;

    if(b->pfirstseq==NULL && b->nseq==0)
    {

        pnew=(SEQUENCIA*)malloc(sizeof(SEQUENCIA)*n);
        b->nseq = n;

        for(i=0;i<n;i++)
        {
            (pnew+i)->seqstring = NULL;

        }
        b->pfirstseq=pnew;
    }else{

            b->nseq = n;
            pnew=(SEQUENCIA*)malloc(sizeof(SEQUENCIA)*n);
            paux=b->pfirstseq;


        //copiar para o novo espa�o
        for(i=0;i<(b->nseq - 1);i++)
        {
            (pnew+i)->seqstring = (paux+i)->seqstring;
        }
        for(j=i;j<n;j++)
        {
            (pnew+j)->seqstring = NULL;
        }

        b->pfirstseq=pnew;

    }
}

/** \brief Inserir sequencias no array dinamico */
void inserir_seq_iniciarpeca(INICIARPECA * b, char seq[])
{
    /**
        \details  Inserir sequencias no array dinamico, caso n�o haja mais espa�o para alocar, ele abre mais espa�o recorrendo a outra fun��o
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param char seq[], recebe sequencia a inserir no array dinamico
    */
    SEQUENCIA *paux=NULL;

    paux=b->pfirstseq;

    while(paux!=NULL&&paux->seqstring!=NULL && (paux - (b->pfirstseq)) < b->nseq)
    {
        paux++;
    }

    if((paux - (b->pfirstseq))==b->nseq)
    {
        create_array_pecas(b,b->nseq+1);
        paux = b->pfirstseq + b->nseq-1;
        paux->seqstring = create_dyn_string(seq);


    }else
    {

        paux->seqstring=create_dyn_string(seq);

    }

}

/** \brief Sequencias e ordenar sequencia por ordem decrescente */
int ordenarseq(INICIARPECA * b,int num){
    /**
        \details Numa primeira parte, ele faz quatro verifica��es para juntar duas pe�as. Numa outra parte ele verifica se � possivel adicionar sequencias de mais de tres pe�as e vai juntando no arraydinamico.Tudo isto com verifica��es a ver se h� repetidas, ou invertidas.
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param num Valor do tipo int, utilizado para definir o numero de m�os a ser usado pelo jogador
    */
int i=0,j=0,h=0,z=0;
int x=0,k=0;
char aux[500];
/** char invertnewpeca[150] - Usado para guardar um pe�a inversa */
char invertnewpeca[150];
/** char invertnewpecaaux[150] - Usado para guardar um pe�a inversa */
char invertnewpecaaux[150];
/** char invert[150] - Usado para guardar um pe�a inversa */
char invert[150];
/** char inversopeca[150] - Usado para guardar um pe�a inversa */
char inversopeca[150];
/** char invertfinal[500] - Usado para guardar um pe�a inversa */
char invertfinal[500];

num=num*7;
                //Juntar 2 pecas

                PECA * paux = NULL;
                PECA * paux2 = NULL;
                paux = b->pfirst;

                //percorre lista ligada baralho, uso o paux que � o primeiro e depois o paux2 do segundo para a frente ate NULL
                while(paux!=NULL)
                {
                    paux2 = paux->pnext;
                    while(paux2!=NULL)
                    {
                        if((paux->pecastr)[2]==(paux2->pecastr)[0])
                        {
                            //concatena
                            strcpy(aux, paux->pecastr);
                            strcat(aux,"-");
                            strcat(aux, paux2->pecastr);
                            inserir_seq_iniciarpeca(b,aux);

                        }
                        if((paux->pecastr)[2]==(paux2->pecastr)[2]){
                            // Inverter peca
                            int d=strlen(paux2->pecastr)-1;
                            for(h=0;h<(strlen(paux2->pecastr));h++){
                                invertnewpeca[d]=paux2->pecastr[h];
                                d--;
                            }

                            // concatena
                            strcpy(aux, paux->pecastr);
                            strcat(aux,"-");
                            strcat(aux, invertnewpeca);
                            inserir_seq_iniciarpeca(b,aux);
                        }
                        if((paux->pecastr)[0]==(paux2->pecastr)[2]){
                            // concatena
                            strcpy(aux, paux2->pecastr);
                            strcat(aux,"-");
                            strcat(aux, paux->pecastr);
                            inserir_seq_iniciarpeca(b,aux);
                        }
                        if((paux->pecastr)[0]==(paux2->pecastr)[0]){
                            // Inverter peca
                            int d=strlen(paux2->pecastr)-1;
                            for(h=0;h<(strlen(paux2->pecastr));h++){
                                invertnewpeca[d]=(paux2->pecastr)[h];
                                d--;
                            }

                            // concatena
                            strcpy(aux, invertnewpeca);
                            strcat(aux,"-");
                            strcat(aux, paux->pecastr);
                            inserir_seq_iniciarpeca(b,aux);
                        }
                        paux2 = paux2->pnext;
                    }
                    paux = paux->pnext;
                }


    //Verificar se ha sequencias iguais e o inversos tambem
    for(x=0;x<b->nseq;x++){
                // Inverter peca
                int w=strlen((b->pfirstseq+x)->seqstring)-1;
                for(k=0;k<(strlen((b->pfirstseq+x)->seqstring));k++){
                    invertnewpecaaux[w]=((b->pfirstseq+x)->seqstring)[k];
                    w--;
                }
    // Verifica se � igual e se for substitui por X|X
            for(i=x+1;i<b->nseq;i++){
                if((strcmp(((b->pfirstseq+i)->seqstring),invertnewpecaaux)==0)||(strcmp(((b->pfirstseq+i)->seqstring),((b->pfirstseq+x)->seqstring))==0)||(((((b->pfirstseq+i)->seqstring)[0])==(((b->pfirstseq+i)->seqstring)[6]))&&((((b->pfirstseq+i)->seqstring)[2])==(((b->pfirstseq+i)->seqstring)[4])))){
                    strcpy(((b->pfirstseq+i)->seqstring),"X|X");
                }
            }
    }

    //remover os X|X e passa os debaixo para cima

        for(i=0;i<b->nseq;i++)
        {
            if(strcmp(((b->pfirstseq+i)->seqstring),"X|X")==0)
            {
                for(j=i;j<b->nseq-1;j++)
                {
                    strcpy(((b->pfirstseq+j)->seqstring),((b->pfirstseq +(j+1))->seqstring));
                }
                b->nseq--;
                i=0;
            }

        }


// Juntar 3 ou mais pecas

    for(i=0;i<b->nseq;i++){

            int tamlin=strlen((b->pfirstseq+i)->seqstring)-1;
            paux = b->pfirst;
            while(paux!=NULL)
            {

                //Primeira verifica��o
                if(((b->pfirstseq+i)->seqstring)[tamlin]==(paux->pecastr)[0]){
                    int igual=0;
                    //inverte peca apenas para verificar
                    int w=strlen(paux->pecastr)-1;
                    for(k=0;k<(strlen(paux->pecastr));k++){
                        inversopeca[w]=(paux->pecastr)[k];
                        w--;
                    }
                    //strtok da peca
                    char partidos[100][100];
                    char *palavra=NULL;
                    char umaseqpeca[100];

                    strcpy(umaseqpeca,((b->pfirstseq+i)->seqstring));
                    palavra = strtok (umaseqpeca,"-");
                    int s=0;
                    while (palavra != NULL)
                    {
                        strcpy(partidos[s++],palavra);
                        palavra = strtok (NULL, "-");
                    }

                    //verifica se o arraypartidos ou o inverdo � igual a peca
                    for (x=0;x<s;x++){
                            if(strcmp(partidos[x],(paux->pecastr))==0||strcmp(partidos[x],inversopeca)==0){
                                    igual++;
                            }
                    }
                    if(igual==0){
                                //concatena
                                strcpy(aux,((b->pfirstseq+i)->seqstring));
                                strcat(aux,"-");
                                strcat(aux, (paux->pecastr));
                                inserir_seq_iniciarpeca(b,aux);

                    }
                }
                //Segunda verifica��o
                if(((b->pfirstseq+i)->seqstring)[tamlin]==(paux->pecastr)[2]){
                    int igual=0;
                    //inverte peca
                    int w=strlen(paux->pecastr)-1;

                    for(k=0;k<(strlen(paux->pecastr));k++){
                        invert[w]=(paux->pecastr)[k];
                        w--;
                    }
                    //strtok da peca
                    char partidos[100][100];
                    char *palavra=NULL;
                    char umaseqpeca[100];

                    strcpy(umaseqpeca,((b->pfirstseq+i)->seqstring));
                    palavra = strtok (umaseqpeca,"-");
                    int s=0;
                    while (palavra != NULL)
                    {
                        strcpy(partidos[s++],palavra);
                        palavra = strtok (NULL, "-");
                    }

                    //verifica se o arraypartidos ou o inverso � igual a pe�a
                    for (x=0;x<s;x++){
                            if(strcmp(partidos[x],(paux->pecastr))==0||strcmp(partidos[x],invert)==0){
                                    igual++;
                            }
                    }
                    if(igual==0){
                        //concatena
                        strcpy(aux, ((b->pfirstseq+i)->seqstring));
                        strcat(aux,"-");
                        strcat(aux, invert);
                        inserir_seq_iniciarpeca(b,aux);

                    }
                }

                //Terceira verifica��o
                if(((b->pfirstseq+i)->seqstring)[0]==(paux->pecastr)[0]){
                    int igual=0;

                    //inverte peca
                    int w=strlen(paux->pecastr)-1;
                    for(k=0;k<(strlen(paux->pecastr));k++){
                        invert[w]=(paux->pecastr)[k];
                        w--;
                    }

                    //strtok da peca
                    char partidos[100][100];
                    char *palavra=NULL;
                    char umaseqpeca[100];
                    strcpy(umaseqpeca,((b->pfirstseq+i)->seqstring));
                    palavra = strtok (umaseqpeca,"-");
                    int s=0;
                    while (palavra != NULL)
                    {
                        strcpy(partidos[s++],palavra);
                        palavra = strtok (NULL, "-");
                    }

                    //verifica se o arraypartidos ou o inverso � igual a pe�a
                    for (x=0;x<s;x++){
                            if(strcmp(partidos[x],(paux->pecastr))==0||strcmp(partidos[x],invert)==0){
                                    igual++;
                            }
                    }
                    if(igual==0){
                        //concatena
                        strcpy(aux,invert);
                        strcat(aux,"-");
                        strcat(aux,((b->pfirstseq+i)->seqstring));
                        inserir_seq_iniciarpeca(b,aux);

                    }
                }
                //Quarta verifica��o
                if(((b->pfirstseq+i)->seqstring)[0]==(paux->pecastr)[2]){
                    int igual=0;

                    //inverte peca
                    int w=strlen(paux->pecastr)-1;
                    for(k=0;k<(strlen(paux->pecastr));k++){
                        invert[w]=(paux->pecastr)[k];
                        w--;
                    }
                    //strtok da peca
                    char partidos[100][100];
                    char *palavra=NULL;
                    char umaseqpeca[100];

                    strcpy(umaseqpeca,((b->pfirstseq+i)->seqstring));
                    palavra = strtok (umaseqpeca,"-");
                    int s=0;
                    while (palavra != NULL)
                    {
                        strcpy(partidos[s++],palavra);
                        palavra = strtok (NULL, "-");
                    }

                    //verifica se o arraypartidos ou o inverso � igual a pe�a
                    for (x=0;x<s;x++){
                            if(strcmp(partidos[x],(paux->pecastr))==0||strcmp(partidos[x],invert)==0){
                                    igual++;
                            }
                    }
                    if(igual==0){
                        //concatena
                        strcpy(aux,(paux->pecastr));
                        strcat(aux,"-");
                        strcat(aux,((b->pfirstseq+i)->seqstring));
                        inserir_seq_iniciarpeca(b,aux);

                    }
                }
               paux = paux->pnext;
            }
        }

    //verificar se ha sequencias iguais e inversos tambem

    for(x=0;x<b->nseq;x++){
                // Inverter peca
                int w=strlen((b->pfirstseq+x)->seqstring)-1;
                for(k=0;k<(strlen((b->pfirstseq+x)->seqstring));k++){
                    invertfinal[w]=((b->pfirstseq+x)->seqstring)[k];
                    w--;
                }

            // Verifica se e igual e se for substitui por X|X
            for(i=x+1;i<b->nseq;i++){
                if((strcmp(((b->pfirstseq+i)->seqstring),invertfinal)==0)||(strcmp(((b->pfirstseq+i)->seqstring),((b->pfirstseq+x)->seqstring))==0)){
                    strcpy(((b->pfirstseq+i)->seqstring),"X|X");
                }
            }
    }


    //remover os X|X e passa os debaixo para cima

        for(i=0;i<b->nseq;i++)
        {
            if(strcmp(((b->pfirstseq+i)->seqstring),"X|X")==0)
            {
                for(j=i;j<b->nseq-1;j++)
                {
                    strcpy(((b->pfirstseq+j)->seqstring),((b->pfirstseq +(j+1))->seqstring));
                }
                b->nseq--;
                i=0;
            }

        }

    //imprimir seq sem repeticoes
    SEQUENCIA * pauxarray = NULL;
    pauxarray = b->pfirstseq;

    for(z=0;z<b->nseq;z++)
    {
        printf("%s\n",((pauxarray+z)->seqstring));
    }
    return 0;
}

/** \brief Guardar num ficheiro de texto */
void save_txt_jogo(INICIARPECA b, char fname[])
{
    /**
        \details Guarda as pe�as utlizadas na m�o, guarda as pe�as que sobraram e guarda as sequencias
        \param INICIARPECA b , estrutura do tipo INICIARPECA
        \param char fname[], recebe o nome do ficheiro
    */

    FILE *fp = NULL;
    PECA * pauxbar = NULL;
    SOBROU * pauxsob = NULL;
    int i=0;

    if ((fp = fopen(fname, "w")) == NULL)
    {

        printf("save_txt_jogo(): Erro abrir ficheiro %s\n",fname);
        return;

    }

    pauxbar= b.pfirst;

    fprintf(fp,"M�o do jogador:\n");
    while(pauxbar!=NULL)
    {
        fprintf(fp,"%s\n",pauxbar->pecastr);
        pauxbar = pauxbar->pnext;
    }

    pauxsob = b.psobrou;
    fprintf(fp,"\nPe�as que sobram:\n");
    while(pauxsob!=NULL)
    {
        fprintf(fp,"%s\n",pauxsob->sobroustr);
        pauxsob = pauxsob->proximo;
    }

    fprintf(fp,"\nSequencias possiveis:\n");
    for(i=0;i<b.nseq;i++)
    {
        fprintf(fp,"%s\n",(b.pfirstseq+i)->seqstring);
    }
    fclose(fp);

}

/** \brief Guardar num ficheiro binario */
void save_bin(INICIARPECA b, char fnome[]){
     /**
        \details Guarda as pe�as utlizadas na m�o e guarda as sequencias
        \param INICIARPECA b , estrutura do tipo INICIARPECA
        \param char fnome[], recebe o nome do ficheiro
    */
    //nplayers tamnome nome\0 cardid carsuit cardpoints
    //2        7  daniel\0      A      E         2
    PECA * paux = NULL;
    FILE * fp = NULL;
    int size = 0, i = 0,sizebar = 0;

    if((fp=fopen(fnome,"wb"))!=NULL)
    {
        //numero de pecas
        fwrite(&b.nbar,sizeof(int),1,fp);

        //gravar baralho
        paux = b.pfirst;

        while(paux!=NULL)
        {
            sizebar=strlen((b.pfirst)->pecastr)+1;
            fwrite(&sizebar,sizeof(int),1,fp);
            fwrite(paux->pecastr,sizeof(char),sizebar,fp);
            paux = paux->pnext;
        }
         //numero de sequencias
        fwrite(&b.nseq,sizeof(int),1,fp);

        //gravar sequencias
        for(i=0;i<b.nseq;i++){
            size=strlen((b.pfirstseq+i)->seqstring)+1;
            fwrite(&size,sizeof(int),1,fp);
            fwrite((b.pfirstseq+i)->seqstring,sizeof(char),size,fp);
        }
        fclose(fp);
    }
}

/** \brief Ler de um ficheiro de texto */
void load_txt_jogo(INICIARPECA *b, char fname[])
{
     /**
        \details Le as pe�as de uma ou mais maos e insere no jogo
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param char fname[], recebe o nome do ficheiro
    */

    FILE *fp=NULL;
    int i=0;
    char peca[50];
    int nfields=0;


    if((fp=fopen(fname,"r"))==NULL)
    {

        printf("... ERRO ...");
        return;

    }


    for(i=0;i<7;i++)
    {

        nfields=fscanf(fp,"%*[\n] %[^,] %*[,]",peca);

        if(nfields>0)
        {
            inserir_peca_baralho(b,peca);

        }

    }


}

/** \brief Ler de um ficheiro binario */
void load_bin(INICIARPECA *b, char fname[])
{
     /**
        \details Le as pe�as de uma ou mais maos e insere no jogo
        \param INICIARPECA * b , estrutura do tipo INICIARPECA
        \param char fname[], recebe o nome do ficheiro
    */
    FILE *fp=NULL;

    int j=0;
    int size=0;
    char peca[50]="";
    int n = 0;
    if((fp=fopen(fname,"rb"))!=NULL)
    {

        fread(&(b->nbar),sizeof(int),1,fp);
        n = b->nbar;
        b->nbar = 0;

        //inserir pecas baralho
        for(j=0;j<n;j++)
        {
            fread(&size,sizeof(int),1,fp);
            fread(peca,sizeof(char),size,fp);
            printf("%s\n",peca);
            inserir_peca_baralho(b,peca);
        }
        fclose(fp);
    }
}


/** \brief Fun�ao procurar e substituir padr�o */
void procurar_padrao(char arrayfinalcompleto[][150],int y){
    /**
        \details Nesta fun��o � recebido uma sequencia aleatoria do arrayfinalcompleto, o utilizador insere uma sequencia a procurar,� verificada para ver se est� inserida corretamente e se nao existe pe�as repetidas na m�o do jogador. Depois � perguntado se pretende substituir esse padrao. Caso pretende ele faz verifica�oes dessa pe�a para ver se existe esse padrao de forma normal ou invertida e se for possivel troca o padr�o.
        \param arrayfinalcompleto[][150] Array do tipo char, onde � recebido as sequencias totais da m�o do jogador
        \param y, tamanho do array total das sequencias (arrayfinalcompleto)
    */
    //Guarda todas as posicoes num array para depois baralhar esses i's
    int z=0;
    int auxp[50];
    int ptemp=0;
    int aleatorio=0;
    int b=0,i=0;
    char strproc[100];
    int tamarraycompleto=y;

    for(z=0;z<tamarraycompleto;z++){
        auxp[z]=z;
    }

    //baralho esse numeros do auxp
    for(b=0;b<tamarraycompleto;b++){
        ptemp=auxp[b];
        aleatorio=rand()%(tamarraycompleto-1);
        auxp[b]=auxp[aleatorio];
        auxp[aleatorio]=ptemp;
    }
    //vai buscar uma sequencia do arrayfinalcompleto dependendo do num de sequencias que o utilizador quer
        strcpy(strproc,arrayfinalcompleto[auxp[0]]);
        printf("A sequencia escolhida foi:\n %s \n",strproc);


    char sub[50];
    char str2[100][100];
    //declaracoes partir arrayfinalcompleto
    char partidosstr1[100][100];
    char *s1=NULL;
    char str1apartir[100];
    int u=0;
    //declaracoes partir subtring
    char partidosstr2[100][100];
    char *s2=NULL;
    char str2apartir[100];
    int l=0;
    //declaracoes partir subtring inversa
    char partidosstr2inv[100][100];
    char *s2inv=NULL;
    char str2invapartir[100];
    int inv=0;
    //declaracao inverter subtring
    char invertsub[100];
    //declaracoes comparar a ver se sao iguais
    int x=0,g=0,count=0,r=0,pos=0;;
    int v[100];


    do{

    printf("Insira uma subsequencia para procurar:\n");
    scanf("%s",sub);

                //Strtok do arrayfinalcompleto
                strcpy(str1apartir,strproc);
                s1 = strtok (str1apartir,"-");

                while (s1!= NULL)
                {
                    strcpy(partidosstr1[u++],s1);
                    s1= strtok (NULL, "-");
                }

                //Strtok da substring escolhida
                strcpy(str2[0],sub);
                strcpy(str2apartir,str2[0]);
                s2 = strtok (str2apartir,"-");
                while (s2!= NULL)
                {
                    strcpy(partidosstr2[l++],s2);
                    s2= strtok (NULL, "-");
                }

                // Inverter substring
                    int w=strlen(sub)-1;
                    int k=0;
                    for(k=0;k<(strlen(sub));k++){
                        invertsub[w]=sub[k];
                        w--;
                    }

                //Strtok da substring invertida

                strcpy(str2invapartir,invertsub);
                s2inv = strtok (str2invapartir,"-");
                while (s2inv!= NULL)
                {
                    strcpy(partidosstr2inv[inv++],s2inv);
                    s2inv= strtok (NULL, "-");
                }

                //Verifica se a invertida � igual a string original (partidosstr1)
                for(x=0;x<u;x++){
                    if((strcmp(partidosstr1[x],partidosstr2inv[g])==0)){
                        count++;
                        g++;
                      if(count==g && count==l){
                        //pos- � o valor da peca final menos o tam da sub -1, para retornar a primeira posicao onde encontrou
                        pos=(x-(l-1));
                        v[r]=pos;
                        r++;
                        count=0;
                        g=0;
                        pos=0;
                        strcpy(sub,invertsub);
                      }
                    }else{
                        count=0;
                        g=0;
                        pos=0;
                    }
                }
                //Verifica se a string original partida (partidosstr1) � igual a substring inserida partida (partidosstr2)
                for(x=0;x<u;x++){
                    if(strcmp(partidosstr1[x],partidosstr2[g])==0){
                        count++;
                        g++;
                      if(count==g && count==l){
                        //pos- � o valor da peca final menos o tam da sub -1, para retornar a primeira posicao onde encontrou
                        pos=(x-(l-1));
                        v[r]=pos;
                        r++;
                        count=0;
                        g=0;
                        pos=0;
                      }
                    }else{
                        count=0;
                        g=0;
                        pos=0;
                    }
                }
                if(r==0){
                    printf("Nao foi encontado a subsequencia %s, na sequencia %s!\n ",sub,strproc);
                    u=0;
                    l=0;

                }else{
                    for(i=0;i<r;i++){
                        printf(" Posicao: %d\n",v[i]);
                    }
                }
    }while(r==0);
                //Substituir Padr�o
                int opcao=0,j=0,q=0;
                char aux[100][100];
                char addseqpeca[50];
                printf("Pretende substituir essa sequencia por outra peca/seq:\n sim->1 , nao->0\n");
                scanf("%d",&opcao);
                if(opcao==1){
                    int continua=1;
                    while(continua>0){
                        continua=0;
                        printf("Insira a seq/peca que deseja substituir");
                        scanf("%s",addseqpeca);

                        //Strtok da pe�a adicionada (addseqpeca)
                        char partidasaddseqpeca[100][100];
                        char *s3=NULL;
                        char addseqpecaapartir[100];
                        strcpy(addseqpecaapartir,addseqpeca);
                        s3 = strtok (addseqpecaapartir,"-");
                        int b=0;

                        while (s3!= NULL)
                        {
                            strcpy(partidasaddseqpeca[b++],s3);
                            s3= strtok (NULL, "-");
                        }

                        //Verifica se essa seq adicionada � possivel inserir
                        char invert[4];
                        int cont=0,n=0,m=0;
                        for(n=0;n<u;n++){
                            for(m=0;m<b;m++){
                                    // Inverter addseqpeca
                                    int d=strlen(partidasaddseqpeca[m])-1;
                                    int h=0;
                                    for(h=0;h<(strlen(partidasaddseqpeca[m]));h++){
                                        invert[d]=partidasaddseqpeca[m][h];
                                        d--;
                                    }
                                    //verifica se a pe�a adicionada existe na string original , ou se a pe�a adicionada invertida existe na string original
                                    if((strcmp(partidasaddseqpeca[m],partidosstr1[n])==0)||(strcmp(partidosstr1[n],invert)==0)){
                                        cont++;
                                    }
                            }
                        }
                        if(cont>0){

                                    printf("Essa peca ja existe!\n");
                                    continua++;
                                    cont=0;
                        }else{
                                    //verifica se o padrao encontrado est� no meio, � frente ou atr�s.
                                    if(((sub[0]==addseqpeca[0])&&(sub[strlen(sub)-1]==addseqpeca[strlen(addseqpeca)-1]))||((addseqpeca[0]==sub[0])&&(sub[strlen(sub)-1]==strproc[strlen(strproc)-1])&&(sub[strlen(sub)-3]==strproc[strlen(strproc)-3]))||((addseqpeca[strlen(addseqpeca)-1]==sub[strlen(sub)-1])&&(sub[0]==strproc[0])&&(sub[2]==strproc[2]))){
                                        cont=0;
                                        //Adiciona no aux as primeiras pecas, as novas e depois o resto
                                            for(i=0;i<v[0];i++){
                                                strcpy(aux[q],partidosstr1[i]);
                                                    q++;
                                            }
                                            int c=0;
                                            for(c=0;c<b;c++){
                                                strcat(aux[q],partidasaddseqpeca[c]);
                                                q++;
                                            }
                                            for(j=(v[0]+l);j<u;j++){
                                                    strcat(aux[q],partidosstr1[j]);
                                                    q++;
                                            }
                            }else{
                                printf("Pecas inseridas nao coincidem!\n");
                                continua++;
                            }
                        }
                        for(m=0;m<q;m++){
                            printf("%s",aux[m]);
                            if(m!=(q-1)){
                                printf("-");
                            }
                        }
                        printf("\n");
                }
                }else if(opcao==0){

                }else{
                    printf("opcao errada!");
                }
}
/** \brief Faz sequencias a partir de uma sequencia inicial */
void seq_inicial(char baralho[][COLSTRING]){
    /**
        \details O utilizador escolhe uma sequencia inicial, e � realizado uma verifica��o para ver se � possivel encaixar essa sequencia com as pe�as da m�o/baralho
        \param baralho[][COLSTRING] Array do tipo char, onde recebe as pe�as baralhadas da m�o do jogador
    */
        char seqcomecar[3000];
        char arrayseqinicial[3000][150];
        char arrayseqinicialcompleto[3000][150];
        int i=0,j=0,count=0,x=0,y=0,p=1,z=0,contador=0;
        char inversazero[150];
        char inversoum[150];
        char inversodois[150];
        char inversotres[150];
        char inversoquatro[150];
        char invertfinal[150];

        printf("Insira uma sequencia a comecar:\n");
        scanf("%s",seqcomecar);

        strcpy(arrayseqinicial[0],seqcomecar);

                //Strtok da sequencia inicial
                char partidosseqcomecar[100][100];
                char *s=NULL;
                char seqapartir[100];
                strcpy(seqapartir,seqcomecar);
                s = strtok (seqapartir,"-");
                int k=0;
                while (s!= NULL)
                {
                    strcpy(partidosseqcomecar[k++],s);
                    s= strtok (NULL, "-");
                }
                //Verificar se as pecas da sequencia inicial sao iguais as pecas do baralho
                for(x=0;x<7;x++){
                    for(y=0;y<k;y++){
                            // Inverter pecas baralho
                            int d=strlen(baralho[x])-1;
                            int h=0;
                            for(h=0;h<(strlen(baralho[x]));h++){
                                    inversazero[d]=baralho[x][h];
                                    d--;
                            }
                            //Verifica se as pecas da seq inicial coincidem
                            int tam=strlen(seqcomecar)-1;
                            int i=0;
                            for(i=0;i<tam;i++){
                                if(seqcomecar[i]=='-'){
                                    if(seqcomecar[i-1]!=seqcomecar[i+1]){
                                        contador++;
                                    }
                                }
                            }

                        if((strcmp(baralho[x],partidosseqcomecar[y])==0)||(strcmp(inversazero,partidosseqcomecar[y])==0)){
                            count++;
                        }
                    }
                }
                if(count>0){
                    printf("As pecas da sequencia que inseriu, ja existem no baralho!\n");
                    count=0;
                }else if(contador>0){
                    printf("A sequencia que inseriu esta errada!\n ");
                    contador=0;
                }else{

                    // Juntar pecas
                    for(i=0;i<p;i++){
                        int tamlin=strlen(arrayseqinicial[i])-1;
                        for(j=0;j<7;j++){

                            //Primeira verifica��o
                            if(arrayseqinicial[i][tamlin]==baralho[j][0]){
                                int igual=0;
                                //inverte peca apenas para verificar
                                int w=strlen(baralho[j])-1;
                                for(k=0;k<(strlen(baralho[j]));k++){
                                    inversoum[w]=baralho[j][k];
                                    w--;
                                }
                                //strtok da peca arrayfinal
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayseqinicial[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }

                                //verifica se o partidos ou o inverso � igual a pe�a
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],inversoum)==0){
                                                igual++;
                                        }
                                }
                                if(igual==0){
                                            //concatena para arrayseqinicial
                                            strcpy(arrayseqinicial[p], arrayseqinicial[i]);
                                            strcat(arrayseqinicial[p],"-");
                                            strcat(arrayseqinicial[p], baralho[j]);
                                            p++;
                                }

                            }
                            //Segunda verifica��o
                            if(arrayseqinicial[i][tamlin]==baralho[j][2]){
                                int igual=0;
                                //inverte peca
                                int w=strlen(baralho[j])-1;
                                for(k=0;k<(strlen(baralho[j]));k++){
                                    inversodois[w]=baralho[j][k];
                                    w--;
                                }
                                //strtok da peca arrayseqinicial
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayseqinicial[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }

                                //verifica se o partidos ou o inverso � igual a pe�a
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],inversodois)==0){
                                                igual++;
                                        }
                                }
                                if(igual==0){
                                    //concatena
                                    strcpy(arrayseqinicial[p], arrayseqinicial[i]);
                                    strcat(arrayseqinicial[p],"-");
                                    strcat(arrayseqinicial[p], inversodois);
                                    p++;
                                }
                            }
                            //Terceira verifica��o
                            if(arrayseqinicial[i][0]==baralho[j][0]){
                                int igual=0;

                                //inverte peca
                                int w=strlen(baralho[j])-1;
                                for(k=0;k<(strlen(baralho[j]));k++){
                                    inversotres[w]=baralho[j][k];
                                    w--;
                                }
                                //strtok da peca arrayfinal
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayseqinicial[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }

                                //verifica se o partidos ou o inverso � igual a peca
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],inversotres)==0){
                                                igual++;
                                        }
                                }
                                if(igual==0){
                                    //concatena
                                    strcpy(arrayseqinicial[p], inversotres);
                                    strcat(arrayseqinicial[p],"-");
                                    strcat(arrayseqinicial[p], arrayseqinicial[i]);
                                    p++;
                                }
                            }
                            //Quarta verifica��o
                            if(arrayseqinicial[i][0]==baralho[j][2]){
                                int igual=0;

                                //inverte peca
                                int w=strlen(baralho[j])-1;
                                for(k=0;k<(strlen(baralho[j]));k++){
                                    inversoquatro[w]=baralho[j][k];
                                    w--;
                                }

                                //strtok da peca arrayfinal
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayseqinicial[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }

                                //verifica se o arraypartidos ou o invero e igual a peca
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],inversoquatro)==0){
                                                igual++;
                                        }
                                }

                                if(igual==0){
                                    //concatena
                                    strcpy(arrayseqinicial[p], baralho[j]);
                                    strcat(arrayseqinicial[p],"-");
                                    strcat(arrayseqinicial[p], arrayseqinicial[i]);
                                    p++;
                                }
                            }
                        }
                    }
                //verificar se ha sequencias iguais e o inversos tambem
                    for(x=0;x<p;x++){
                                // Inverter peca
                                int w=strlen(arrayseqinicial[x])-1;

                                for(k=0;k<(strlen(arrayseqinicial[x]));k++){
                                    invertfinal[w]=arrayseqinicial[x][k];
                                    w--;
                                }
                    // Verifica se e igual e se for substitui por X|X
                            for(i=x+1;i<p;i++){
                                if((strcmp(arrayseqinicial[i],invertfinal)==0)||(strcmp(arrayseqinicial[i],arrayseqinicial[x])==0)){
                                    strcpy(arrayseqinicial[i],"X|X");
                                }
                            }
                    }
                    // Copia do aux que contem x|x e guarda num array final(arrayseqinicialcompleto) as sequencias das pecas
                     for(z=0;z<p;z++){
                            if(strcmp(arrayseqinicial[z],"X|X")==0){
                            }else{
                                strcpy(arrayseqinicialcompleto[y],arrayseqinicial[z]);
                                y++;
                            }
                    }
                }
                for(i=0;i<y;i++){
                    printf("%s\n",arrayseqinicialcompleto[i]);
                }
}

/** \brief Cria as sequencias possiveis apartir de uma sequencia inicial com 2 ou mais m�os*/
void retirar_mao_jogadores(char baralho[][COLSTRING],int num){
    /**
        \details A partir de uma sequencia inicial inserida pelo utilizador, ele vai guardando num array mixpecas de forma alternada as m�os pedidas pelo jogador, e vai inserido do array mixpecas de forma alternada na sequencia inicial e guardado no arrayfinalmixpecascompleto.
        \param baralho[][COLSTRING] Array do tipo char, onde recebe as pe�as baralhadas da m�o do jogador
    */
    /**char mixpecas[3000][150] - guarda varios baralhos de forma alternada*/
     char mixpecas[3000][150];

    //Ver quantos baralhos sao, e guardar num array mix as pecas dos jogadores alternadamente
    if(num==2){
        int i=0;
        int j=7;
        int m=0;

        while(i<7 || j<14){
            if(i<7){
                strcpy(mixpecas[m++],baralho[i]);
            }
            if(j<14){
                strcpy(mixpecas[m++],baralho[j]);
            }
            i++;
            j++;
        }
    }
    if(num==3){
        int i=0;
        int j=7;
        int k=14;
        int m=0;

        while(i<7 || j<14 || k<21 ){
            if(i<7){
                strcpy(mixpecas[m++],baralho[i]);
            }
            if(j<14){
                strcpy(mixpecas[m++],baralho[j]);
            }
            if(k<21){
                strcpy(mixpecas[m++],baralho[k]);
            }
            i++;
            j++;
            k++;
        }
    }

    if(num==4){
        int i=0;
        int j=7;
        int k=14;
        int s=21;
        int m=0;

        while(i<7 || j<14 || k<21 || s<28){
            if(i<7){
                strcpy(mixpecas[m++],baralho[i]);
            }
            if(j<14){
                strcpy(mixpecas[m++],baralho[j]);
            }
            if(k<21){
                strcpy(mixpecas[m++],baralho[k]);
            }
            if(s<28){
                strcpy(mixpecas[m++],baralho[s]);
            }
            i++;
            j++;
            k++;
            s++;
        }
    }

    printf("ARRAY MIX:\n");
    int v=0;
    int pecasmix=num*7;
    for(v=0;v<pecasmix;v++){
        printf("%s\n",mixpecas[v]);
    }

    //Comeca com uma sequencia inicial e vai metendo peca a peca do mixpecas
        char seqcomecar[3000];
        char arrayfinalmixpecas[3000][150];
        char arrayfinalmixpecascompleto[3000][150];
        int i=0,j=0,count=0,x=0,y=0,p=1,z=0,contador=0;
        char inversazero[150];
        char inversoum[150];
        char inversodois[150];
        char inversotres[150];
        char inversoquatro[150];
        char invertfinal[150];

        printf("Insira uma sequencia a comecar:\n");
        scanf("%s",seqcomecar);

        strcpy(arrayfinalmixpecas[0],seqcomecar);

                //Strtok da sequencia inicial
                char partidosseqcomecar[100][100];
                char *s=NULL;
                char seqapartir[100];

                strcpy(seqapartir,seqcomecar);
                s = strtok (seqapartir,"-");
                int k=0;

                while (s!= NULL)
                {
                    strcpy(partidosseqcomecar[k++],s);
                    s= strtok (NULL, "-");
                }

                //Verificar se as pecas da sequencia inicial sao iguais as pecas do baralho mix
                for(x=0;x<pecasmix;x++){
                    for(y=0;y<k;y++){
                            // Inverter pecas baralho
                            int d=strlen(mixpecas[x])-1;
                            int h=0;
                            for(h=0;h<(strlen(mixpecas[x]));h++){
                                    inversazero[d]=mixpecas[x][h];
                                    d--;
                            }
                            //Verifica se as pecas da seq inicial coincidem
                            int tam=strlen(seqcomecar)-1;
                            int i=0;
                            for(i=0;i<tam;i++){
                                if(seqcomecar[i]=='-'){
                                    if(seqcomecar[i-1]!=seqcomecar[i+1]){
                                        contador++;
                                    }
                                }
                            }
                        if((strcmp(mixpecas[x],partidosseqcomecar[y])==0)||(strcmp(inversazero,partidosseqcomecar[y])==0)){
                            count++;
                        }
                    }
                }
                if(count>0){
                    printf("As pecas da sequencia que inseriu, ja existem no baralho!\n");
                    count=0;
                }else if(contador>0){
                    printf("A sequencia que inseriu esta errada!\n ");
                    contador=0;
                }else{
                    //Juntar pecas
                    for(i=0;i<p;i++){
                        int tamlin=strlen(arrayfinalmixpecas[i])-1;
                        for(j=0;j<pecasmix;j++){
                            //Primeira verifica��o
                            if(arrayfinalmixpecas[i][tamlin]==mixpecas[j][0]){
                                int igual=0;
                                //inverte peca apenas para verificar
                                int w=strlen(mixpecas[j])-1;
                                for(k=0;k<(strlen(mixpecas[j]));k++){
                                    inversoum[w]=mixpecas[j][k];
                                    w--;
                                }
                                //strtok da peca arrayfinalmixpecas
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayfinalmixpecas[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }

                                //verifica se o arrayfinalmixpecas ou o inverso e igual a peca
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],mixpecas[j])==0||strcmp(partidos[x],inversoum)==0){
                                                igual++;
                                        }
                                }
                                if(igual==0){
                                    //concatena para arrayfinalmixpecas
                                            strcpy(arrayfinalmixpecas[p], arrayfinalmixpecas[i]);
                                            strcat(arrayfinalmixpecas[p],"-");
                                            strcat(arrayfinalmixpecas[p], mixpecas[j]);
                                            p++;
                                }
                            }
                            //Segunda verifica��o
                            if(arrayfinalmixpecas[i][tamlin]==mixpecas[j][2]){
                                int igual=0;
                                //inverte peca
                                int w=strlen(mixpecas[j])-1;
                                for(k=0;k<(strlen(mixpecas[j]));k++){
                                    inversodois[w]=mixpecas[j][k];
                                    w--;
                                }
                                //strtok da peca arrayfinalmixpecas
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayfinalmixpecas[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }
                                //verifica se o partidos ou o inverso e igual a peca
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],mixpecas[j])==0||strcmp(partidos[x],inversodois)==0){
                                                igual++;
                                        }
                                }
                                if(igual==0){
                                    //concatena
                                    strcpy(arrayfinalmixpecas[p], arrayfinalmixpecas[i]);
                                    strcat(arrayfinalmixpecas[p],"-");
                                    strcat(arrayfinalmixpecas[p], inversodois);
                                    p++;
                                }
                            }
                            //Terceira verifica��o
                            if(arrayfinalmixpecas[i][0]==mixpecas[j][0]){
                                int igual=0;
                                //inverte peca
                                int w=strlen(mixpecas[j])-1;
                                for(k=0;k<(strlen(mixpecas[j]));k++){
                                    inversotres[w]=mixpecas[j][k];
                                    w--;
                                }
                                //strtok da peca arrayfinal
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayfinalmixpecas[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }
                                //verifica se o partidos ou o inverso � igual a peca
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],mixpecas[j])==0||strcmp(partidos[x],inversotres)==0){
                                                igual++;
                                        }
                                }
                                if(igual==0){
                                    //concatena
                                    strcpy(arrayfinalmixpecas[p], inversotres);
                                    strcat(arrayfinalmixpecas[p],"-");
                                    strcat(arrayfinalmixpecas[p], arrayfinalmixpecas[i]);
                                    p++;
                                }
                            }
                            //Quarta verifica��o
                            if(arrayfinalmixpecas[i][0]==mixpecas[j][2]){
                                int igual=0;

                                //inverte peca
                                int w=strlen(mixpecas[j])-1;
                                for(k=0;k<(strlen(mixpecas[j]));k++){
                                    inversoquatro[w]=mixpecas[j][k];
                                    w--;
                                }
                                //strtok da peca arrayfinal
                                char partidos[100][100];
                                char *palavra=NULL;
                                char umaseqpeca[100];

                                strcpy(umaseqpeca,arrayfinalmixpecas[i]);
                                palavra = strtok (umaseqpeca,"-");
                                int s=0;
                                while (palavra != NULL)
                                {
                                    strcpy(partidos[s++],palavra);
                                    palavra = strtok (NULL, "-");
                                }
                                //verifica se o partidos ou o inverso � igual a peca
                                for (x=0;x<s;x++){
                                        if(strcmp(partidos[x],mixpecas[j])==0||strcmp(partidos[x],inversoquatro)==0){
                                                igual++;
                                        }
                                }
                                if(igual==0){
                                    //concatena
                                    strcpy(arrayfinalmixpecas[p], mixpecas[j]);
                                    strcat(arrayfinalmixpecas[p],"-");
                                    strcat(arrayfinalmixpecas[p], arrayfinalmixpecas[i]);
                                    p++;
                                }
                            }
                        }
                    }
                //verificar se ha seq iguais e o inversos tambem
                    for(x=0;x<p;x++){
                                // Inverter peca
                                int w=strlen(arrayfinalmixpecas[x])-1;
                                for(k=0;k<(strlen(arrayfinalmixpecas[x]));k++){
                                    invertfinal[w]=arrayfinalmixpecas[x][k];
                                    w--;
                                }

                    // Verifica se e igual e se for substitui por X|X
                            for(i=x+1;i<p;i++){
                                if((strcmp(arrayfinalmixpecas[i],invertfinal)==0)||(strcmp(arrayfinalmixpecas[i],arrayfinalmixpecas[x])==0)){
                                    strcpy(arrayfinalmixpecas[i],"X|X");
                                }
                            }
                    }
                    // Copia do arrayfinalmixpecas que contem x|x e guarda num array final(arrayfinalmixpecascompleto) as sequencias possiveis
                     for(z=0;z<p;z++){
                            if(strcmp(arrayfinalmixpecas[z],"X|X")==0){
                            }else{
                                strcpy(arrayfinalmixpecascompleto[y],arrayfinalmixpecas[z]);
                                y++;
                            }
                    }
                }
                for(i=0;i<y;i++){
                    printf("%s\n",arrayfinalmixpecascompleto[i]);
                }
}

