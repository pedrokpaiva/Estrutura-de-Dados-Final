//
// Created by pedro on 09/05/2021.
//
#include "AVL.h"
int comp = 0, rot = 0, nodos = 0, comp2 = 0;

arv* Inicializa(void){
    arv* a = (arv*) malloc(sizeof(arv)+10);
    a->esq = NULL;
    a->dir = NULL;
    a->FB = 0;
    return a;
}

arv* InsereArvore (arv* a, char dados[], int* ok, int id){
    int temp;
    if(a==NULL) {
        a=Inicializa();
        strcpy(a->string, dados);
        a->ids= InicializaID(id);
        *ok=1;
        nodos++;
        return a;
    }
    else{
        comp++;
        temp = strcmp(dados, a->string);
        if(temp == 0){
            *ok=0;
            a->ids = InsereId(a->ids, id);
            return a;
        }
        else if(temp<0){
            a->esq = InsereArvore(a->esq, dados, ok, id);
            if (*ok){
                switch (a->FB){
                    case -1:
                        a->FB = 0;
                        *ok = 0;
                        break;
                    case 0:
                        a->FB = 1;
                        break;
                    case 1:
                        a = Caso1(a, ok);
                        break;
                }
            }
        }
        else if(temp>0){
            a->dir = InsereArvore(a->dir, dados, ok, id);
            if (*ok){
                switch (a->FB){
                    case 1:
                        a->FB = 0;
                        *ok = 0;
                        break;
                    case 0:
                        a->FB = -1;
                        break;
                    case -1:
                        a = Caso2(a, ok);
                        break;
                }
            }
        }
    }
    return a;
}

lista* InsereId(lista *ids, int id){
    lista *temp;

    if(id == ids->num){
        return ids;
    }

    else{
        temp = (lista*) malloc(sizeof(lista)+10);
        temp->num = id;
        temp->prox = ids;
        return temp;
    }
}

arv* Caso1(arv* a, int *ok){
    arv* z;
    z = a->esq;
    if (z->FB == 1){
        a = rotacao_direita(a);
        rot++;
    }
    else{
        a = rotacao_dupla_direita(a);
        rot = rot + 2;
    }
    a->FB = 0;
    *ok = 0;
    return a;
}

arv* Caso2(arv* a, int *ok){
    arv* z;
    z = a->dir;
    if (z->FB == -1)
    {
        a = rotacao_esquerda(a);
        rot++;
    }
    else
    {
        a = rotacao_dupla_esquerda(a);
        rot = rot + 2;
    }
    a->FB = 0;
    *ok = 0;
    return a;
}

arv* rotacao_direita(arv* p){
    arv* u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;
    return p;
}

arv* rotacao_esquerda(arv* p){
    arv* z;
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
    if (v->FB == 1)
        p->FB = -1;
    else
        p->FB = 0;
    if (v->FB == -1)
        u->FB = 1;
    else
        u->FB = 0;
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
    if (y->FB == -1)
        p->FB = 1;
    else
        p->FB = 0;
    if (y->FB == 1)
        z->FB = -1;
    else
        z->FB = 0;
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
    temp = strtok(NULL, delimiter);
    // faz o resto dos ciclos até o fim da string
    while(temp != NULL){
        arvo = InsereArvore(arvo, temp, &ok, id);
        temp = strtok(NULL,delimiter);
    }
    return arvo;
}

lista* InicializaID(int num){
    lista *lista1 = malloc(sizeof(lista)+10);
    lista1->num= num;
    lista1->prox= NULL;
    return lista1;
}

void RecebePesquisa(char *palavra, arv *arvo, FILE *arq){
    arv *ptarv;
    int x;
    lista *ptlista;
    ptarv = arvo;

    while(ptarv!=NULL){
        comp2++;
        x = strcmp(palavra, ptarv->string);

        if(x<0){
            ptarv = ptarv->esq;
        }
        else if(x>0){
            ptarv = ptarv->dir;
        }
        else{
            // Imprime a palavra com seus ids
            fprintf(arq,"consulta: %s Palavra encontrada nos tweets:\n", palavra);
            for(ptlista = ptarv->ids; ptlista!=NULL; ptlista = ptlista->prox){
                fprintf(arq, "%i, ", ptlista->num);
            }
            fprintf(arq, "\n\n\n");
            return;
        }
    }
    // Palavra não encontrada;
    comp2++;
    fprintf(arq,"consulta: %s Palavra não encontrada\n", palavra);
}

void printStats(FILE *arq, arv* a){
    int altura;
    altura = Altura(a);
    fprintf(arq, "\n********** Estatisticas da Indexação ***********\n");
    fprintf(arq, "Nodos = %i\nComparações = %i\nRotações = %i\nAltura da árvore = %i", nodos, comp, rot, altura);
    fprintf(arq, "\n\n********** Estatisticas das Consultas ***********\n");
    fprintf(arq, "Comparações = %i", comp2);
}

int Altura(arv *a){
    int Alt_Esq, Alt_Dir;
    if (a == NULL) // se a árvore for nula retorna 0
        return 0;
    else // se não retorna a altura da maior sub-árvore
    {
        Alt_Esq = Altura(a->esq);
        Alt_Dir = Altura(a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}