//
// Created by Lucas on 03/05/2021.
//

#include "Arvores.h"

arv* Inicializa(void){
    return NULL;
}

arv* InsereArvore (arv* a, char dados[]){
    int comp;

    if(a==NULL) {
        a = (arv*) malloc(sizeof(arv));
        strcpy(a->string,dados);
        a->esq = NULL;
        a->dir = NULL;
    }

    else{

        comp = strcmp(dados, a->string);

        if(comp<0){
            a->esq = InsereArvore(a->esq, dados);
        }
        if(comp>0){
            a->dir = InsereArvore(a->dir, dados);
        }
    }

    return a;
}

