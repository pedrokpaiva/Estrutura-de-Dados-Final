//
// Created by pedro on 09/05/2021.
//

#ifndef CONSULTAAVL_AVL_H
#define CONSULTAAVL_AVL_H
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
    int FB;
    lista *ids;
    char string[30];
} arv;



arv* Inicializa(void);
arv* InsereArvore (arv* a, char dados[], int* ok, int id);
arv* Caso1(arv* a, int *ok);
arv* Caso2(arv* a, int *ok);
arv* rotacao_direita(arv* p);
arv* rotacao_esquerda(arv* p);
arv* rotacao_dupla_direita(arv* p);
arv* rotacao_dupla_esquerda(arv* p);
arv* RecebeTweet(char *tweet, arv *arvo);
lista* InicializaID(int num);
lista* InsereId(lista *ids, int id);
void RecebePesquisa(char *palavra, arv *arvo, FILE *arq);
void printStats(FILE *arq, arv* a);
int Altura(arv *a);

#endif //CONSULTAAVL_AVL_H
