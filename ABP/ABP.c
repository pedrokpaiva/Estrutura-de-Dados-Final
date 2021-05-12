//
// Created by Lucas on 06/05/2021.
//

#include "ABP.h"

int comp = 0;
int pesq = 0;
int nodos = 0;

// Inicializa uma árvore;
arv* Inicializa(void){
    return NULL;
}

// Dado uma árvore, a palavra e o id do tweet insere corretamente a associação na árvore
arv* InsereArvore (arv* a, char dados[], int id){
    int temp;

    // caso a árvore esteja vazia, ela é iniciada
    if(a==NULL) {
        nodos++;
        a = (arv*) malloc(sizeof(arv));
        strcpy(a->string,dados);
        a->esq = NULL;
        a->dir = NULL;
        a->ids = NULL;
        a->ids = InsereId(a->ids, id);
    }

        // caso não seja nula
    else{
        // é comparada a string do nó atual da arvore com a palavra a ser inserida
        temp = strcmp(dados, a->string);
        comp++;

        // caso sejam iguais, a palavra já exista na árvore, é adicionado o id a palavra
        if(temp == 0){
            a->ids = InsereId(a->ids,id);
        }

        // caso na ordem lexicográfica a palavra fique antes da atual, ela é comparada com o nó filho esquerdo
        if(temp<0){
            a->esq = InsereArvore(a->esq, dados, id);
        }

        // aso na ordem lexicográfica a palavra fique após a atual, ela é comparada com o nó filho direito
        if(temp>0){
            a->dir = InsereArvore(a->dir, dados, id);
        }
    }

    // retorna-se a arvore
    return a;
}

// Função que recebe a leitura de um tweet, o quebra em palavras e o insere na árvore com seu id
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

// Dada uma lista de ids, insere um id nela
lista* InsereId(lista *lista1, int id){
    lista *temp;
    temp = lista1;

    // caso não haja ids na lista da palavra, a lista é iniciada com o 1o id
    if (temp == NULL){
        temp = (lista*) malloc(sizeof(lista)+1);
        temp->num = id;
        temp->prox = NULL;
        return temp;
    }

        // caso já haja ids:
    else{
        // testa se o primeiro id, ultimo a ser inserido é igual ao que deve ser inserido
        // evitando repetição do id, caso a palavra se repita 2 vezes numa mesma frase
        if(id == temp->num){
            return lista1;
        }

            // caso não seja igual, é inserido como primeiro da lista
            // é mais eficiente computacionalmente, visto que não há necessidade de percorrer a lista
            // e também é mais fácil a comparação para evitar copias
        else{
            temp = (lista*) malloc(sizeof(lista)+1);
            temp->num = id;
            temp->prox = lista1;
            return temp;
        }
    }
}


// Função que recebe a palavra a ser pesquisada na árvore
void RecebePesquisa(char *palavra, arv *arvo, FILE *arq){
    arv *ptarv;
    int temp;
    lista *ptlista;
    ptarv = arvo;

    // enquanto não se encontra um nó nulo
    while(ptarv!=NULL){
        pesq++;

        // é comparada a palavra com a string do vertice atual
        temp = strcmp(palavra, ptarv->string);

        // caso a palavra seja "menor" é pesquisada na subárvore esquerda
        if(temp<0){
            ptarv = ptarv->esq;
        }

        // caso a palavra seja "maior" é pesquisada na sub árvore direita
        if(temp>0){
            ptarv = ptarv->dir;
        }

        // caso seja igual
        if(temp == 0){
            // Imprime a palavra com seus ids
            fprintf(arq,"consulta: %s Palavra encontrada nos tweets:\n", palavra);

            for(ptlista = ptarv->ids; ptlista!=NULL; ptlista = ptlista->prox){
                fprintf(arq, "%i, ", ptlista->num);
            }
            fprintf(arq, "\n\n\n");
            return;
        }

    }

    // Caso chega ao null, a palavra não foi encontrada;
    fprintf(arq,"A palavra %s  não foi encontrada na base de tweets \n", palavra);
}




// Somente imprime os status da inserção e pesquisa
void printStats(FILE *arq, arv* a){
    int altura;
    altura = Altura(a);
    fprintf(arq, "\n********** Estatisticas da Indexação ***********\n");
    fprintf(arq, "Nodos = %i\nComparações = %i\nAltura da árvore = %i", nodos, comp, altura);
    fprintf(arq, "\n\n********** Estatisticas das Consultas ***********\n");
    fprintf(arq, "Comparações = %i", pesq);
}

// Calcula a altura de uma árvore, função retirada de uma das aulas.
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