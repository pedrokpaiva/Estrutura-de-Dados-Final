//
// Created by Lucas on 06/05/2021.
//

#include "ABP.h"

int comp = 0;


arv* Inicializa(void){
    return NULL;
}

arv* InsereArvore (arv* a, char dados[], int id){
    int temp;
    comp = comp +1;



    if(a==NULL) {
        a = (arv*) malloc(sizeof(arv));
        strcpy(a->string,dados);
        a->esq = NULL;
        a->dir = NULL;
        a->ids = NULL;
        a->ids = InsereId(a->ids, id);
    }

    else{

        temp = strcmp(dados, a->string);

        if(temp == 0){
            a->ids = InsereId(a->ids,id);
        }


        if(temp<0){
            a->esq = InsereArvore(a->esq, dados, id);
        }
        if(temp>0){
            a->dir = InsereArvore(a->dir, dados, id);
        }
    }

    return a;
}

arv* RecebeTweet(char tweet[], arv *arvo){

    // variáveis básicas
    int i, id;
    char *temp;     // vai receber o valor dos cortes da strtok
    char delimiter[] = " ,.!:\n;";  // caracteres delimitadores para o corte;

    // minifunção que transforma o tweet em lowercase
    for(i = 0; tweet[i]; i++){
        tweet[i] = tolower(tweet[i]);
    }


    // faz o 1o corte, separado para podermos pegar o indice do tweet já q não é para ser string
    temp = strtok(tweet, delimiter);

    // usa atoi para transformar a string em número
    id = atoi(temp);

    // printf("%i", id);

    temp = strtok(NULL, delimiter);

    // faz o resto dos ciclos até o fim da string
    while(temp != NULL){
        arvo = InsereArvore(arvo, temp, id);
        temp = strtok(NULL,delimiter);
    }


    return arvo;

}


lista* InsereId(lista *lista1, int id){
    lista *temp;

    temp = lista1;

    if (temp == NULL){
        temp = (lista*) malloc(sizeof(lista));
        temp->num = id;
        temp->prox = NULL;
        return temp;
    }

    else{
        for(; temp != NULL; temp = temp->prox ){
        }

        temp = (lista*) malloc(sizeof(lista));
        temp->num = id;
        temp->prox = NULL;
        return lista1;
    }
}


lista* IDS(int id){
    lista *temp = (lista*) malloc(sizeof(lista));

    temp->num = id;
    temp->prox = NULL;
    return temp;
}


void RecebePesquisa(char *palavra, arv *arvo, FILE *arq){
    arv *ptarv;
    int temp;
    lista *ptlista;


    ptarv = arvo;

    while(ptarv!=NULL){


        temp = strncmp(palavra, ptarv->string, strlen(palavra)-1);

        if(temp<0){
            ptarv = ptarv->esq;
        }

        if(temp>0){
            ptarv = ptarv->dir;
        }

        if(temp == 0){
            // Imprime a palavra com seus ids
            fprintf(arq," %s %i", palavra, ptarv->ids->num);
            printf("%s  %i \n\n",palavra, ptarv->ids->num);

            for(ptlista = ptarv->ids; ptlista!=NULL; ptlista = ptlista->prox){
                // falta arrumar para mostrar todos os números consultados
                //fprintf(arq, " %i ", ptlista->num);
            }
            fprintf(arq, "\n");
            return;
        }
    }

    // Palavra não encontrada;
    fprintf(arq,"A palavra %s  não foi encontrada na base de tweets \n", palavra);
    puts("Nao encontrada \n");
}