//
// Created by Lucas on 06/05/2021.
//

#ifndef SAIGRADLE_ABP_H
#define SAIGRADLE_ABP_H
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
void imprimeIDs(lista *ids, FILE *arq);
#endif //SAIGRADLE_ABP_H
