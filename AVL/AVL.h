#ifndef SAIGRADLE_AVL_H
#define SAIGRADLE_AVL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>      // necessaria para transformar em lowercase
#include <locale.h>


typedef struct lista{
    int num;
    struct lista *prox;
} lista;

typedef struct arv{
    struct arv *esq;
    struct arv *dir;
    lista *ids;
    char string[20];
} arv;



arv* Inicializa(void);
arv* InsereArvore (arv* a, char dados[], int id);
arv* RecebeTweet(char *tweet, arv *arvo);
lista* InsereId(lista *lista1, int id);
lista* IDS(int id);
void RecebePesquisa(char *palavra, arv *arvo, FILE *arq);
#endif //SAIGRADLE_AVL_H
