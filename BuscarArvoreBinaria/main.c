#include <stdio.h>
#include <stdlib.h>

typedef struct  No
{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* criarNo(int valor)
{
    No* novo = (No*) malloc( sizeof(No) );

    novo->esq = NULL;
    novo->dir = NULL;
    novo->valor = valor;
    
    return novo;
}

No* inserirNo(No* raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }

    if (valor < raiz->valor )
    {
        raiz->esq = inserirNo(raiz->esq, valor);
    }
    else if (valor > raiz->valor )
    {
        raiz->dir = inserirNo(raiz->dir, valor);
    } 
    else
    {
        printf("Valor ja existe na arvore\n");
    }

    return raiz;
}

void emOrdem(struct  No* raiz){
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf(" %d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void preOrdem(struct No* raiz)
{
     if (raiz != NULL) {
        printf(" %d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    } 
};

void posOrdem(struct No* raiz){
    if (raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf(" %d ", raiz->valor);
    }

}

int main(void)
{
    No* raiz = criarNo(50);

    raiz->esq = criarNo(30);
    raiz->dir = criarNo(70);
    
    raiz->esq->esq = criarNo(20);
    raiz->esq->dir = criarNo(40);
    
    raiz->dir->esq = criarNo(60);
    raiz->dir->dir = criarNo(80);

    int valor = 20;

    printf("\nEM ORDEM:");
    emOrdem(raiz);    
    printf("");

    printf("\nPRE ORDEM:");
    preOrdem(raiz);    
    printf("");

    printf("\nPOS ORDEM:");
    posOrdem(raiz);    
    printf("");

    return 0;
}