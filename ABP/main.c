#include "ABP.h"

// esses argumentos da main são usados para receber os inputs além da função
// na linha de comando;
int main(int argc, char *argv[]) {
    arv *arvo;
    arvo = Inicializa();
    char leitura[300];
    FILE *tweets;
    FILE *searchs;
    FILE *output;

    setlocale(LC_ALL, "pt_BR_utf8");

    //strcpy(argv[1],"base_completa.csv");
    //strcpy(argv[2],"consulta_100.txt");
    //strcpy(argv[3],"saida_comp.txt");

    // testa se o numero de parametros esperado esão corretos
    if (argc!=4)
    {
        printf ("Número incorreto de parámetros.\n Para chamar o programa digite: %s <arq_entrada> <arq_consulta> <arq_saida>\n");
        return 1;
    }

    // testa a abertura/criação de cada arquivo
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


    // Enquanto há linhas no arquivo a ser lido, as encaminha para a inserção na árvore
    while(fgets(leitura, 300, tweets)){
        arvo = RecebeTweet(leitura, arvo);
    }

    // Enquanto há linhas palavras para serem consultadas as encaminha para a pesquisa
    while(fgets(leitura, 300, searchs)){
        leitura[strlen(leitura) - 1] = '\0';
        RecebePesquisa(leitura, arvo, output);
    }


    // Imprime os status das as operações
    printStats(output, arvo);


    // Fecha os arquivos
    fclose(tweets);
    fclose(searchs);
    fclose(output);

    return 0;
}
