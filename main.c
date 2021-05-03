#include "Arvores.h"

// esses argumentos da main são usados para receber os inputs além da função
// na linha de comando;
int main(int argc, char **agrv) {

    // variáveis básicas da main
    int i;
    arv *arvo;
    arvo = Inicializa();


    // "função" para receber a linha e quebrar ela em stirngs
    char leitura[100] = "0;para eu ir";     // linha exemplo
    char *temp;     // vai receber o valor dos cortes da strtok
    char delimiter[] = " ,.!:\n;";  // caracteres delimitadores para o corte;

    // faz o 1o corte, separado para podermos pegar o indice do tweet já q não é string
    temp = strtok(leitura, delimiter);

    // usar atoi para transformar a string em número

    // faz o resto dos ciclos até o fim da string
    while(temp != NULL){
        puts(temp);
        temp = strtok(NULL,delimiter);
    }



    // minifunção que transforma tudo em lowercase

    char s[20] = "Banana";

    for(i = 0; s[i]; i++){
        s[i] = tolower(s[i]);
    }


    // faz a inserção na arvore de forma correta só falta adicionar os
    // movimentos caracteristicos (ajustes) da árvore desejada, pensei em AVL
    arvo = InsereArvore(arvo, s);
    strcpy(s,"Pera");

    arvo = InsereArvore(arvo, s);

    // testa a correta inserção dos nós
    puts(arvo->string);
    puts(arvo->dir->string);


    return 0;
}
