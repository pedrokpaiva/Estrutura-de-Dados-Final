//
// Created by Lucas on 03/05/2021.
//

#ifndef TRABFINAL_ARVORES_H
#define TRABFINAL_ARVORES_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>      // necessaria para transformar em lowercase

typedef struct arv{
    struct arv *esq;
    struct arv *dir;
    char string[20];
} arv;

arv* Inicializa(void);
arv* InsereArvore (arv* a, char dados[]);


#endif //TRABFINAL_ARVORES_H
