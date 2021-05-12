#include "AVL.h"
// esses argumentos da main são usados para receber os inputs além da função
// na linha de comando;


int main(int argc, char **argv) {

    arv *arvo;
    arvo = Inicializa();
    char leitura[300];
    FILE *tweets;
    FILE *searchs;
    FILE *output;


    setlocale(LC_ALL, "pt_BR_utf8");



    if (argc!=4)  //testa se o numero de parametros esperado
    {
        printf ("Número incorreto de parámetros.\n Para chamar o programa digite: %s <arq_entrada> <arq_consulta> <arq_saida>\n",argv[0]);
        return 1;
    }

    if ((tweets=fopen(argv[1],"r"))==NULL)   // testa se consegue abrir o arquivo de entrada
    {
        printf("erro ao abrir arquivo %s \n",argv[1]);
        return 1;
    }
    if ((searchs=fopen(argv[2],"r"))==NULL)   // testa se consegue abrir o arquivo de consulta
    {
        printf("erro ao abrir arquivo %s \n",argv[2]);
        return 1;
    }

    if ((output = fopen(argv[3],"w"))==NULL)   // testa se consegue criar o arquivo de saída
    {
        printf("erro ao criar arquivo %s \n",argv[3]);
        return 1;
    }

    while(fgets(leitura, 300, tweets)){
        arvo = RecebeTweet(leitura, arvo);
    }

    while(fgets(leitura, 300, searchs)){
        leitura[strlen(leitura) - 1] = '\0';
        RecebePesquisa(leitura, arvo, output);
    }
    printStats(output, arvo);
    // fazer uma consulta que retoma o número de comparações já contado na ABP.c e adicionar a contagem de comparação
    // para a consulta também


    fclose(tweets);
    fclose(searchs);
    fclose(output);

    return 0;
}