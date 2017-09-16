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
#include "projetolp1primparte.h"  //Biblioteca para headers

/** \brief Função main_projectolp1primparte */
int main_projetolp1primparte(int argc, char * argv[]){
    /** char pecas[LINSTRING][COLSTRING] - Array de strings para pecas */
    char pecas[LINSTRING][COLSTRING];
    /** int pecasint[LINSTRING][COL] - Array de inteiros para pecas */
    int pecasint[LINSTRING][COL];
    /** char baralho[LINSTRING][COLSTRING] - Array de strings de peças baralhadas, dependendo das mãos que o jogador pedir (4 mãos de 7 peças no máximo)  */
    char baralho[LINSTRING][COLSTRING];
    /** char sobrou[LINSTRING][COLSTRING] - Array de strings de pecas baralhadas, onde ficam as peças não utilizadas na mão do jogador */
    char sobrou[LINSTRING][COLSTRING];
    /** char arrayfinalcompleto[3000][150] - Array de strings de todas as sequencias possiveis das mãos do jogador   */
    char arrayfinalcompleto[3000][150];
    /** int opc=0 - Opção escolhida no menu inicial */
    int opc=0;
    /** int num=0 - Número de baralhos que o jogador escolhe (máximo 4) */
    int num=0;
    /** int npecasremover=0 - Número de peças que o utilizador pretende remover da sua mão */
    int npecasremover=0;
    /** int pecastotal=0 - Número de peças total que o jogador tem na mão, consoante o número de mãos escolhidas. Ex: 2 mão x 7 peças =  14 peças total */
    int pecastotal=0;
    /** int npecas=0 - Número de peças que o utilizador pretende adicionar á sua mão */
    int npecas=0;
    /** int y=0 - Tamanho do array de strings de todas as sequencias possiveis das mãos do jogador (arraycompleto) */
    int y=0;
    /** criarpecas(pecas) - Criar todas peças do jogo*/
    criarpecas(pecas);
    /** bool sair = false - Manter ciclo do menu enquanto for false, quando for true sai  */
    bool sair = false;
    /** char escolha - Usado para quando é escrito "S" ou "s" fecha programa, caso contrário continua */
    char escolha;
    //Menu com ciclo. O utilizador escolhe a opção que pretende e através do switch retorna para a função pretendida
    do{
    printf("**************** JOGO DO DOMINO ****************\n\n");
    printf("Escolha uma opcao\n");
    printf("1 ----> Listar Pecas Sring\n");
    printf("2 ----> Criar Mao\n");
    printf("3 ----> Remover Pecas\n");
    printf("4 ----> Adicionar Pecas\n");
    printf("5 ----> Listar Pecas Int\n");
    printf("6 ----> Criar e ordenar sequencias\n");
    printf("7 ----> Procurar padrao\n");
    printf("8 ----> Criar sequencias com sequencia inicial\n");
    printf("9 ----> Criar sequencias com maos alternadas\n");

    printf("Opcao: ");
    scanf("%d", &opc);

    switch(opc)
            {
            case 1:
                imprimirpecas(pecas);
                break;
            case 2:
                printf("Insira o numero de mãos a jogar:\n");
                scanf("%d",&num);
                baralhos(pecas,baralho,sobrou,num);
                break;
            case 3:
                printf("Quantas pecas pretende remover:\n");
                scanf("%d",&npecasremover);
                pecastotal=num*7;
                rempeca(pecas,baralho,pecastotal,npecasremover);
                break;
            case 4:
                printf("Quantas pecas pretende adicionar:\n");
                scanf("%d",&npecas);
                pecastotal=num*7;
                addpeca(pecas,baralho,sobrou,pecastotal,npecas);
                break;
            case 5:
                imprimirpecasint(pecas,pecasint);
                break;
            case 6:
                y=ordenarseq(pecas,baralho,arrayfinalcompleto,num);
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

/** \brief Criar peças string */
void criarpecas(char pecas[][COLSTRING]){
    /**
        \details São criadas todas as peças possiveis que um jogo tem e são copiadas através do strcpy para dentro do array pecas
        \param pecas[][COLSTRING] Array do tipo char guarda as peças totais do jogo.
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

/** O que está comentado - Peças teste para usar no ponto R7, visto que pecas aleatorias de 2 ou mais mãos, ele não tem memória para gerar as sequencias  */
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
        \param pecas[][COLSTRING] Array do tipo char onde recebe as peças totais do jogo.
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
     \param pecas[][COLSTRING] Array do tipo char onde recebe as peças totais do jogo.
     \param pecasint[][COL] Array do tipo int onde guarda as peças totais do jogo.
    */
    int i=0;
    for(i=0;i<28;i++){
        pecasint[i][0]=atoi(pecas[i]);
        pecasint[i][1]=atoi(&pecas[i][2]);
        printf("%d|%d \n", pecasint[i][0],pecasint[i][1]);
    }
}

/** \brief Criar baralhos/mãos aleatórios */
void baralhos(char pecas[][COLSTRING],char baralho[][COLSTRING],char sobrou[][COLSTRING],int num){
    /**
        \details Cria um array de peças baralhadas (baralho), sendo esta a mão do jogador. E guarda noutro array (sobrou) as peças não utilizadas na mão.
        \param pecas[][COLSTRING] Array do tipo char onde recebe as peças totais do jogo.
        \param baralho[][COLSTRING] Array do tipo char, onde irão ser guardadas as peças baralhadas da mão do jogador
        \param sobrou[][COLSTRING] Array do tipo char, onde irão ser guardadas as peças que sobraram, ou seja, que não foram usadas na mão do jogador
        \param num Valor do tipo int, utilizado para definir o numero de mãos a ser usado pelo jogador
    */
    /** srand((unsigned)time(NULL)) - Função srand(),responsável por alimentar o rand() e gerar números aleatórios*/
    srand((unsigned)time(NULL));
    /** int pecastotal=0 - Número de peças total que o jogador tem na mão */
    int pecastotal=0;
    /** int i=0 - Variavél usada nos ciclos */
    int i=0;
    /** int aleatorio - Variavél que guarda número gerado aleatório*/
    int aleatorio;
    /** int array[28] - Array com as posicoes de 0 a 27 das pecas das mãos */
    int array[28];
    /** int temp - Variavél temporária para guardas conteudo de array[i] */
    int temp;
    // Número de peças total que o jogador tem na mão, numero de mãos (1,2,3 ou 4) multiplicado pelas pecas possiveis de cada mão (7)
    pecastotal = num * 7;
    //Caso o numero de mãos escollhidas seja igual ou inferior a 4, entra neste if
    if(num<=4){
            // Cria array posicoes das pecas totais
            for(i=0;i<28;i++){
                array[i] = i;
            }
            // Baralha essas 28 pecas e guarda em array, de forma aleatória
            for(i=0;i<28;i++){
                temp=array[i];
                aleatorio = rand() % 28;
                array[i]=array[aleatorio];
                array[aleatorio]=temp;
            }
            // Guarda num array baralho[] as peças aleatórias até ao numero de pecas total definida pelo jogador e imprime
            printf("MAO:\n");
            for(i=0;i<pecastotal;i++){
                strcpy(baralho[i],pecas[array[i]]);
                printf("%s\n",baralho[i]);
            }
            // Guarda num array sobrou[] as peças aleatórias desde o numero de pecas total definida pelo jogador até as 27 possiveis e imprime
            printf("SOBROU:\n");
            for(i=pecastotal;i<28;i++){
                strcpy(sobrou[i],pecas[array[i]]);
                printf("%s\n",sobrou[i]);
            }
    }else if(num>4){
        printf("Nao pode escolher mais que 4 baralhos!\n");
    }
}
/** \brief Remover peças de uma ou mais mãos */
void rempeca(char pecas[][COLSTRING],char baralho[][COLSTRING],int pecastotal,int npecasremover){
    /**
        \details Remove peças de uma ou mais mãos, sendo que as peças removidas são substituidas por X|X, e é pedido ao utilizador para inserir tantas peças quantas removeu. Sendo tudo verificado para não remover peças que não existam e que não sejam adicionas peças repetidas.
        \param pecas[][COLSTRING] Array do tipo char onde recebe as peças totais do jogo.
        \param baralho[][COLSTRING] Array do tipo char, onde recebe as peças baralhadas da mão do jogador
        \param pecastotal Valor do tipo int, utilizado para definir as peças totais usadas pelo jogador
        \param npecasremover Valor do tipo int, utilizado para definir o numero de peças a ser removido pelo jogador
    */
    /** char pecaremover[4] - Usado para guardar a peça inserida pelo jogador, para depois remover */
    char pecaremover[4];
    /** int i=0 - Variavél usada nas funções seguintes */
    int i=0;
    /** int j=0 - Variavél usada nas funções seguintes */
    int j=0;
    /** int k=0 - Variavél usada nas funções seguintes */
    int k=0;
    /** int y=0 - Variavél usada nas funções seguintes */
    int y=0;
    /** int h=0 - Variavél usada nas funções seguintes */
    int h=0;
    /** int aux[npecasremover] - Usado para guardar as posições onde as peças foram removidas para depois usar para adicionar as peças novas nessa posição */
    int aux[npecasremover];
    /** char newpeca[4] - Usado para guardar a peça a ser inserida pelo jogador, para depois adicionar */
    char newpeca[4];
    /** char invertnewpeca[4] - Usado para guardar a peça invertida da newpeca inserida */
    char invertnewpeca[4];
    //Caso o numero de peças a remover seja maior que as peças totais, entra neste if
    if(npecasremover>pecastotal){
        printf("Numero de pecas a remover e superior ao baralho!\n");
    // Caso o numero de peças a remover seja menor que as peças totais, entra neste if
    }else if(npecasremover<pecastotal){
        int count=0;
        // Insere peca a remover
        for(j=0;j<npecasremover;j++){
            printf("Insira a peca a remover:");
            scanf("%s",pecaremover);
            // Verifica se a peça do baralho/mão é igual á peça a remover, se for substitui por X|X
            for(i=0;i<pecastotal;i++){
                if(strcmp(baralho[i],pecaremover)==0){
                    strcpy(baralho[i],"X|X");
                    aux[k]=i;
                    k++;
                    count++;
                }
            }
            // Caso a peça do baralho/mão não seja igual á peça a remover, count mantém a zero, e entra neste if
            if(count==0){
                printf("Essa peca nao existe, insira outra:\n");
                    j--;
            }
            count=0;
        }
        //Imprime mão já com as peças removidas (com pecas X|X)
        for(i=0;i<pecastotal;i++){
                printf("%s\n",baralho[i]);
        }
        //No lugar onde foram removidas as peças, insere novas peças
        for(j=0;j<npecasremover;j++){
            printf("Insira uma nova peca:");
            scanf("%s",newpeca);

            // Inverter peça inserida
            int d=strlen(newpeca)-1;
            for(h=0;h<(strlen(newpeca));h++){
                invertnewpeca[d]=newpeca[h];
                d--;
            }
            // Verifica se as peças da mão são iguais ás novas peças inseridas e ao seu inverso
            for(i=0;i<pecastotal;i++){
                if((strcmp(baralho[i],newpeca)==0)||(strcmp(baralho[i],invertnewpeca)==0)){
                        count++;
                }
            }
            // Caso sejam as peças verificadas iguais, entra neste if
            if(count>0){
                printf("Essa peca existe!\n");
                j--;
                count=0;
            }else{
                // Caso as peças verificadas não sejam iguais, ele copia a nova peça inserida para a posição do baralho/mão onde foi removida
                strcpy(baralho[aux[y]],newpeca);
                y++;
            }
        }
        // Imprime as peças da mão do jogador
        for(i=0;i<pecastotal;i++){
                printf("%s\n",baralho[i]);
        }
    }
}

/** \brief Adicionar peças numa mão/mãos */
void addpeca(char pecas[][COLSTRING],char baralho[][COLSTRING],char sobrou[][COLSTRING],int pecastotal,int npecas){
    /**
        \details Adicionar peças na mão, sendo que as peças inseridas sao adicionadas á mão inicial e completada com peças aleatorias para preencher as mãos. Ex: o jogador tem uma mão de 7 peças, quer adicionar mais duas, ou seja adiciona essas duas, e sao adicionadas automaticamente 5 peças aleatorias, para completar duas mãos (14 peças)
        \param pecas[][COLSTRING] Array do tipo char onde recebe as peças totais do jogo.
        \param baralho[][COLSTRING] Array do tipo char, onde recebe as peças baralhadas da mão do jogador
        \param sobrou[][COLSTRING] Array do tipo char, onde irão ser guardadas as peças que sobraram, ou seja, que não foram usadas na mão do jogador
        \param pecastotal Valor do tipo int, utilizado para definir as peças totais usadas pelo jogador
        \param npecas Valor do tipo int, utilizado para definir o numero de peças a ser adicionado pelo jogador
    */
    /** int aleatorio=0 - Variavél onde é guardada o numero de peças total mais as peças adicionadas pelo jogador. Posteriormente, este valor é subtraido conforme as mãos usadas */
    int aleatorio=0;
    /** int i=0 - Variavél usada nas funções seguintes */
    int i=0;
    /** int j=0 - Variavél usada nas funções seguintes */
    int j=0;
    /** int k=0 - Variavél usada nas funções seguintes */
    int k=0;
    /** char novapeca[4] - Usado para guardar a peça a ser inserida pelo jogador, para depois adicionar */
    char novapeca[4];
    /** char invertnewpeca[4] - Usado para guardar a peça invertida da novapeca inserida */
    char invertnewpeca[4];


    aleatorio=pecastotal+npecas;
    // Verificar se a soma da numero de pecas total com as peças que quer adicionar está no primeiro baralho, entre 0 e 6. Se sim, subtrai o valor aleatorio por 6 e guarda em aleatório o numero de peças que vao ser lançadas aleatóriamente. E assim sucessivamente para os outros.
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
    for(j=pecastotal;j<=(pecastotal+aleatorio);j++){

        strcpy(baralho[j],sobrou[j]);
    }
    // Imprime a mão/baralho mais as peças aleatorias
    for(i=0;i<j;i++){
        printf("%s\n",baralho[i]);
    }
    // Inserir peca (novapeca)
    int x=0,fim=0,h=0,cont=0;
    for(k=0;k<npecas;k++){
            printf("Insira a peca");
            scanf("%s",novapeca);

            // Inverter novapeca
            int d=strlen(novapeca)-1;
            for(h=0;h<(strlen(novapeca));h++){
                invertnewpeca[d]=novapeca[h];
                d--;
            }
            // Verifica se a peca da mão(baralho[]) é igual a novapeca, ou á invertida
            for(i=0;i<=(pecastotal+aleatorio+x);i++){
                 if((strcmp(baralho[i],novapeca)==0)||(strcmp(baralho[i],invertnewpeca)==0)){
                        cont++;
                 }
            }
            // Caso a peça exista, aumenta o cont, e entra no if
            if(cont>0){
                        printf("Essa peca ja existe!\n");
                        k--;
                        cont=0;
            }else{
                //Caso contrario ele insere a nova peça na ultima posição da mão (baralho[]) e imprime
                        cont=0;
                        x++;
                        fim=pecastotal+aleatorio+x;
                        strcpy(baralho[fim],novapeca);

                        for(i=0;i<=fim;i++){
                            printf("%s\n",baralho[i]);
                        }
            }
    }
}

/** \brief Sequencias e ordenar sequencia por ordem decrescente */
int ordenarseq(char pecas[][COLSTRING],char baralho[][COLSTRING],char arrayfinalcompleto[][150],int num){
    /**
        \details Numa primeira parte, ele faz quatro verificações para juntar duas peças. Numa outra parte ele verifica se é possivel adicionar sequencias de mais de tres peças e vai juntando no arrayfinalcompleto até o tamanho do arrayfinalcompleto (p) termine.Tudo isto com verificações a ver se há repetidas, ou invertidas.
        \param pecas[][COLSTRING] Array do tipo char onde recebe as peças totais do jogo.
        \param baralho[][COLSTRING] Array do tipo char, onde recebe as peças baralhadas da mão do jogador
        \param arrayfinalcompleto[][150] Array do tipo char, onde são guardadas as sequencias totais da mão do jogador
        \param num Valor do tipo int, utilizado para definir o numero de mãos a ser usado pelo jogador
        \return y, tamanho do array total das sequencias (arrayfinalcompleto)
    */
int i=0,j=0,h=0,z=0,count=0,p=0;
int x=0,k=0,y=0;
char aux[3000][150];
/** char seqduaspecas[3000][150] - Usado para guardar sequencias de duas peças */
char seqduaspecas[3000][150];
/** char arrayfinal[3000][150] - Usado para guardar sequencias de duas peças */
char arrayfinal[3000][150];
char tempd[150][150];
/** char invertnewpeca[150] - Usado para guardar um peça inversa */
char invertnewpeca[150];
/** char invertnewpecaaux[150] - Usado para guardar um peça inversa */
char invertnewpecaaux[150];
/** char invert[150] - Usado para guardar um peça inversa */
char invert[150];
/** char inversopeca[150] - Usado para guardar um peça inversa */
char inversopeca[150];
/** char invertfinal[500] - Usado para guardar um peça inversa */
char invertfinal[500];

num=num*7;
//Juntar 2 pecas
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(baralho[i][2]==baralho[j+1][0]){
                //concatena
                strcpy(aux[count], baralho[i]);
                strcat(aux[count],"-");
                strcat(aux[count], baralho[j+1]);
                count++;
            }
            if(baralho[i][2]==baralho[j+1][2]){
                // Inverter peca
                int d=strlen(baralho[j+1])-1;
                for(h=0;h<(strlen(baralho[j+1]));h++){
                    invertnewpeca[d]=baralho[j+1][h];
                    d--;
                }
                // concatena
                strcpy(aux[count], baralho[i]);
                strcat(aux[count],"-");
                strcat(aux[count], invertnewpeca);
                count++;
            }
            if(baralho[i][0]==baralho[j+1][2]){
                // concatena
                strcpy(aux[count], baralho[j+1]);
                strcat(aux[count],"-");
                strcat(aux[count], baralho[i]);
                count++;
            }
            if(baralho[i][0]==baralho[j+1][0]){
                // Inverter peca
                int d=strlen(baralho[j+1])-1;
                for(h=0;h<(strlen(baralho[j+1]));h++){
                    invertnewpeca[d]=baralho[j+1][h];
                    d--;
                }
                // concatena
                strcpy(aux[count], invertnewpeca);
                strcat(aux[count],"-");
                strcat(aux[count], baralho[i]);
                count++;
            }
        }
    }
    //Verificar se ha sequencias iguais e o inversos tambem
    for(x=0;x<count;x++){
                // Inverter peca
                int w=strlen(aux[x])-1;
                for(k=0;k<(strlen(aux[x]));k++){
                    invertnewpecaaux[w]=aux[x][k];
                    w--;
                }
    // Verifica se é igual e se for substitui por X|X
            for(i=x+1;i<count;i++){
                if((strcmp(aux[i],invertnewpecaaux)==0)||(strcmp(aux[i],aux[x])==0)||((aux[i][0]==aux[i][6])&&(aux[i][2]==aux[i][4]))){
                    strcpy(aux[i],"X|X");
                }
            }
    }
    // Copia do aux que contem x|x e guarda num array final(seqduaspecas) e guarda num array final (arrayfinal) as sequencias de duas pecas
     for(z=0;z<count;z++){
            if(strcmp(aux[z],"X|X")==0){
            }else{
                strcpy(seqduaspecas[p],aux[z]);
                strcpy(arrayfinal[p],aux[z]);
                p++;
            }
    }

// Juntar 3 ou mais pecas
    for(i=0;i<p;i++){
        int tamlin=strlen(arrayfinal[i])-1;
        for(j=0;j<num;j++){

            //Primeira verificação
            if(arrayfinal[i][tamlin]==baralho[j][0]){
                int igual=0;
                //inverte peca apenas para verificar
                int w=strlen(baralho[j])-1;
                for(k=0;k<(strlen(baralho[j]));k++){
                    inversopeca[w]=baralho[j][k];
                    w--;
                }
                //strtok da peca arrayfinal
                char partidos[100][100];
                char *palavra=NULL;
                char umaseqpeca[100];

                strcpy(umaseqpeca,arrayfinal[i]);
                palavra = strtok (umaseqpeca,"-");
                int s=0;
                while (palavra != NULL)
                {
                    strcpy(partidos[s++],palavra);
                    palavra = strtok (NULL, "-");
                }

                //verifica se o arraypartidos ou o inverdo é igual a peca
                for (x=0;x<s;x++){
                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],inversopeca)==0){
                                igual++;
                        }
                }
                if(igual==0){
                            //concatena para arrayfinal
                            strcpy(arrayfinal[p], arrayfinal[i]);
                            strcat(arrayfinal[p],"-");
                            strcat(arrayfinal[p], baralho[j]);
                            p++;
                }
            }
            //Segunda verificação
            if(arrayfinal[i][tamlin]==baralho[j][2]){
                int igual=0;
                //inverte peca
                int w=strlen(baralho[j])-1;

                for(k=0;k<(strlen(baralho[j]));k++){
                    invert[w]=baralho[j][k];
                    w--;
                }
                //strtok da peca arrayfinal
                char partidos[100][100];
                char *palavra=NULL;
                char umaseqpeca[100];

                strcpy(umaseqpeca,arrayfinal[i]);
                palavra = strtok (umaseqpeca,"-");
                int s=0;
                while (palavra != NULL)
                {
                    strcpy(partidos[s++],palavra);
                    palavra = strtok (NULL, "-");
                }

                //verifica se o arraypartidos ou o inverso é igual a peça
                for (x=0;x<s;x++){
                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],invert)==0){
                                igual++;
                        }
                }
                if(igual==0){
                    //concatena
                    strcpy(arrayfinal[p], arrayfinal[i]);
                    strcat(arrayfinal[p],"-");
                    strcat(arrayfinal[p], invert);
                    p++;
                }
            }

            //Terceira verificação
            if(arrayfinal[i][0]==baralho[j][0]){
                int igual=0;

                //inverte peca
                int w=strlen(baralho[j])-1;
                for(k=0;k<(strlen(baralho[j]));k++){
                    invert[w]=baralho[j][k];
                    w--;
                }

                //strtok da peca arrayfinal
                char partidos[100][100];
                char *palavra=NULL;
                char umaseqpeca[100];
                strcpy(umaseqpeca,arrayfinal[i]);
                palavra = strtok (umaseqpeca,"-");
                int s=0;
                while (palavra != NULL)
                {
                    strcpy(partidos[s++],palavra);
                    palavra = strtok (NULL, "-");
                }

                //verifica se o arraypartidos ou o inverso é igual a peça
                for (x=0;x<s;x++){
                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],invert)==0){
                                igual++;
                        }
                }
                if(igual==0){
                    //concatena
                    strcpy(arrayfinal[p], invert);
                    strcat(arrayfinal[p],"-");
                    strcat(arrayfinal[p], arrayfinal[i]);
                    p++;
                }
            }
            //Quarta verificação
            if(arrayfinal[i][0]==baralho[j][2]){
                int igual=0;

                //inverte peca
                int w=strlen(baralho[j])-1;
                for(k=0;k<(strlen(baralho[j]));k++){
                    invert[w]=baralho[j][k];
                    w--;
                }
                //strtok da peca arrayfinal
                char partidos[100][100];
                char *palavra=NULL;
                char umaseqpeca[100];

                strcpy(umaseqpeca,arrayfinal[i]);
                palavra = strtok (umaseqpeca,"-");
                int s=0;
                while (palavra != NULL)
                {
                    strcpy(partidos[s++],palavra);
                    palavra = strtok (NULL, "-");
                }

                //verifica se o arraypartidos ou o inverso é igual a peça
                for (x=0;x<s;x++){
                        if(strcmp(partidos[x],baralho[j])==0||strcmp(partidos[x],invert)==0){
                                igual++;
                        }
                }
                if(igual==0){
                    //concatena
                    strcpy(arrayfinal[p], baralho[j]);
                    strcat(arrayfinal[p],"-");
                    strcat(arrayfinal[p], arrayfinal[i]);
                    p++;
                }
            }
        }
    }
    //verificar se ha sequencias iguais e inversos tambem
    for(x=0;x<p;x++){
                // Inverter peca
                int w=strlen(arrayfinal[x])-1;
                for(k=0;k<(strlen(arrayfinal[x]));k++){
                    invertfinal[w]=arrayfinal[x][k];
                    w--;
                }

            // Verifica se e igual e se for substitui por X|X
            for(i=x+1;i<p;i++){
                if((strcmp(arrayfinal[i],invertfinal)==0)||(strcmp(arrayfinal[i],arrayfinal[x])==0)){
                    strcpy(arrayfinal[i],"X|X");
                }
            }
    }
    // Copia do aux que contem x|x e guarda num array final(arrayfinalcompleto) as sequencias de tres ou mais pecas */
     for(z=0;z<p;z++){
            if(strcmp(arrayfinal[z],"X|X")==0){
            }else{
                strcpy(arrayfinalcompleto[y],arrayfinal[z]);
                y++;
            }
    }

        // Ordenar de forma decrescente
        for( i=0; i<y; i++ ){
                  for( j=(i+1); j<y; j++ ){
                       if((strlen(arrayfinalcompleto[i]))<(strlen(arrayfinalcompleto[j]))){
                           strcpy(tempd[0],arrayfinalcompleto[i]);
                           strcpy(arrayfinalcompleto[i],arrayfinalcompleto[j]);
                           strcpy(arrayfinalcompleto[j],tempd[0]);
                       }
                  }
        }

        for(k=0;k<y;k++){
              printf("%s\n",arrayfinalcompleto[k]);
        }
    return y;
}
/** \brief Funçao procurar e substituir padrão */
void procurar_padrao(char arrayfinalcompleto[][150],int y){
    /**
        \details Nesta função é recebido uma sequencia aleatoria do arrayfinalcompleto, o utilizador insere uma sequencia a procurar,é verificada para ver se está inserida corretamente e se nao existe peças repetidas na mão do jogador. Depois é perguntado se pretende substituir esse padrao. Caso pretende ele faz verificaçoes dessa peça para ver se existe esse padrao de forma normal ou invertida e se for possivel troca o padrão.
        \param arrayfinalcompleto[][150] Array do tipo char, onde é recebido as sequencias totais da mão do jogador
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

                //Verifica se a invertida é igual a string original (partidosstr1)
                for(x=0;x<u;x++){
                    if((strcmp(partidosstr1[x],partidosstr2inv[g])==0)){
                        count++;
                        g++;
                      if(count==g && count==l){
                        //pos- é o valor da peca final menos o tam da sub -1, para retornar a primeira posicao onde encontrou
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
                //Verifica se a string original partida (partidosstr1) é igual a substring inserida partida (partidosstr2)
                for(x=0;x<u;x++){
                    if(strcmp(partidosstr1[x],partidosstr2[g])==0){
                        count++;
                        g++;
                      if(count==g && count==l){
                        //pos- é o valor da peca final menos o tam da sub -1, para retornar a primeira posicao onde encontrou
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
                //Substituir Padrão
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

                        //Strtok da peça adicionada (addseqpeca)
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

                        //Verifica se essa seq adicionada é possivel inserir
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
                                    //verifica se a peça adicionada existe na string original , ou se a peça adicionada invertida existe na string original
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
                                    //verifica se o padrao encontrado está no meio, á frente ou atrás.
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
        \details O utilizador escolhe uma sequencia inicial, e é realizado uma verificação para ver se é possivel encaixar essa sequencia com as peças da mão/baralho
        \param baralho[][COLSTRING] Array do tipo char, onde recebe as peças baralhadas da mão do jogador
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

                            //Primeira verificação
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

                                //verifica se o partidos ou o inverso é igual a peça
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
                            //Segunda verificação
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

                                //verifica se o partidos ou o inverso é igual a peça
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
                            //Terceira verificação
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

                                //verifica se o partidos ou o inverso é igual a peca
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
                            //Quarta verificação
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

/** \brief Cria as sequencias possiveis apartir de uma sequencia inicial com 2 ou mais mãos*/
void retirar_mao_jogadores(char baralho[][COLSTRING],int num){
    /**
        \details A partir de uma sequencia inicial inserida pelo utilizador, ele vai guardando num array mixpecas de forma alternada as mãos pedidas pelo jogador, e vai inserido do array mixpecas de forma alternada na sequencia inicial e guardado no arrayfinalmixpecascompleto.
        \param baralho[][COLSTRING] Array do tipo char, onde recebe as peças baralhadas da mão do jogador
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
                            //Primeira verificação
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
                            //Segunda verificação
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
                            //Terceira verificação
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
                                //verifica se o partidos ou o inverso é igual a peca
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
                            //Quarta verificação
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
                                //verifica se o partidos ou o inverso é igual a peca
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

