//
// Created by Lucas on 06/05/2021.
//

#include "AVL.h"

int comp = 0;


arv* Inicializa(void){
    return NULL;
}

arv* InsereArvore(arv* a, char dados[], int id, int* ok){
    int temp;
    comp = comp + 1;

    if (a == NULL) {
        a = (arv*) malloc(sizeof(arv*));
        strcpy(a->string,dados);
        a->esq = NULL;
        a->dir = NULL;
        a->ids = NULL;
        a->ids = InsereId(a->ids, id);
        a->FB = 0;
        *ok = 1;
    }
    temp = strcmp(dados, a->string);
    if(temp == 0){
        a->ids = InsereId(a->ids,id);
        *ok = 0;
    }
    else if(temp < 0){
        a->esq = InsereArvore(a->esq, dados, id, ok);
        if (*ok){
            switch (a->FB) {
                case -1: a->FB = 0; *ok = 0; break;
                case 0: a->FB = 1; break;
                case 1: a=Caso1(a, ok); break;
            }
        }
    }
    else if(temp > 0){
        a->dir = InsereArvore(a->dir, dados, id, ok);
        if (*ok) {
            switch (a->FB) {
                case 1: a->FB = 0; *ok = 0; break;
                case 0: a->FB = -1; break;
                case -1: a = Caso2(a, ok); break;
            }
        }
    }
    return a;
}

arv* Caso1(arv* a, int *ok){
    arv *z;
    z = a->esq;
    if (z->FB == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);
    a->FB = 0;
    *ok = 0;
    return a;
}

arv* Caso2(arv* a, int *ok){
    arv *z;
    z = a->dir;
    if (z->FB == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);
    a->FB = 0;
    *ok = 0;
    return a;
}

arv* rotacao_direita(arv* p){
    arv *u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;
    return p;
}

arv* rotacao_esquerda(arv* p){
    arv *z;
    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;
    return p;
} 

arv* rotacao_dupla_direita(arv* p){
    arv *u, *v;
    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;
    if (v->FB == 1) p->FB = -1;
    else p->FB = 0;
    if (v->FB == -1) u->FB = 1;
    else u->FB = 0;
    p = v;
    return p;
} 

arv* rotacao_dupla_esquerda(arv* p){
    arv *z, *y;
    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;
    if (y->FB == -1) p->FB = 1;
    else p->FB = 0;
    if (y->FB == 1) z->FB = -1;
    else z->FB = 0;
    p = y;
    return p;
}

arv* RecebeTweet(char tweet[], arv *arvo){

    // variáveis básicas
    int i, id, ok;
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
        arvo = InsereArvore(arvo, temp, id, &ok);
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

void imprimeIDs(lista *ids, FILE *arq){
    lista* ptaux;
    if (ids == NULL)
    fprintf(arq, "lista vazia");
    else
    for (ptaux=ids; ptaux!=NULL; ptaux=ptaux->prox)
        fprintf(arq, "%i", ptaux->num);
}