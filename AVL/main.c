#include "AVL.h"
#include "AVL.c"
// esses argumentos da main são usados para receber os inputs além da função
// na linha de comando;

//int argc, char **argv
int main() {
    arv *arvo;
    arvo = Inicializa();
    char leitura[300];
    FILE *tweets;
    FILE *searchs;
    FILE *output;

    tweets = fopen("base_100.txt", "r");
    searchs = fopen("consulta_100.txt", "r");
    output = fopen("saida_100.txt", "w");
    
    setlocale(LC_ALL, "pt_BR_utf8");
    // No fim irá ser descomentado, tá comentado agora só pra dar pra rodar sem ter q ser pela linha de comando e dai
    // conseguir usar o debuger melhor :)

//    if (argc!=4)  //testa se o numero de parametros esperado est� correto (deve ser 3): nome do programa (argv[0]), nome do arq de entrada(argv[1]), nome do arq de saida(argv[2])
//    {
//        printf ("Número incorreto de parámetros.\n Para chamar o programa digite: %s <arq_entrada> <arq_consulta> <arq_saida>\n",argv[0]);
//        return 1;
//    }
//
//    if ((tweets=fopen(argv[1],"r"))==NULL)   // testa se consegue abrir o arquivo de entrada
//    {
//        printf("erro ao abrir arquivo %s \n",argv[1]);
//        return 1;
//    }
//    if ((searchs=fopen(argv[2],"r"))==NULL)   // testa se consegue abrir o arquivo de consulta
//    {
//        printf("erro ao abrir arquivo %s \n",argv[1]);
//        return 1;
//    }
//
//    if ((output = fopen(argv[3],"s"))==NULL)   // testa se consegue criar o arquivo de saída
//    {
//        printf("erro ao criar arquivo %s \n",argv[2]);
//        return 1;
//    }



    while(fgets(leitura, 300, tweets)){
    printf("here");
        arvo = RecebeTweet(leitura, arvo);

    }

    while(fgets(leitura, 300, searchs)){
        RecebePesquisa(leitura, arvo, output);
    }

    // fazer uma consulta que retoma o número de comparações já contado na ABP.c e adicionar a contagem de comparação
    // para a consulta também


    fclose(tweets);
    fclose(searchs);
    fclose(output);

    return 0;
}
