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

void emOrdem(No* raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esq);
        printf("- %d -", raiz->valor);
        emOrdem(raiz->dir);
    }
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

int buscar(struct No* raiz, int valor)
{
    if ( raiz == NULL)
    {
        return 0;
    }

    if ( raiz->valor == valor)
    {
        return 1;
    }

    if (valor < raiz-> valor)
    {
        return buscar(raiz->esq, valor);
    } 
    else
    {
        return buscar(raiz->dir, valor);
    }
}

int main(void)
{
    No* raiz = NULL;

    raiz = inserirNo(raiz, 50);
    raiz = inserirNo(raiz, 30);
    raiz = inserirNo(raiz, 70);
    raiz = inserirNo(raiz, 20);

    int valor = 20;

    if(buscar(raiz, valor))
    {
        printf("Valor encontrado");
    } else {
        printf("Valor não encontrado");
    }

    emOrdem(raiz);    

    return 0;
}