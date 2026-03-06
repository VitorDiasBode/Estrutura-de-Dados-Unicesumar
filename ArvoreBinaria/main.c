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
        raiz = criarNo(valor);
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


int main(void)
{
    No* raiz = NULL;
    char opcao;
    int valor;

    do
    {
        printf("Valor:");
        scanf("%d", &valor);

        raiz = inserirNo(raiz, valor);

        printf("ORDEM DA ARVORE\n");
        emOrdem(raiz);
        printf("\n");

        printf("Quer adicionar um novo no? (s/n)");
        scanf("%c", &opcao);

    } while (opcao == 's');
    

    return 0;
}