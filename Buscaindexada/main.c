#include <stdio.h>

#define TAM 9
#define TAM_INDICE 3

struct Indice
{
    int chave;
    int posicao;
};

int buscaSequencialIndexada(int vetor[], struct Indice indice[], int valor )
{
    int inicio = 0;
    int fim = TAM - 1;

    for (int i = 0; i < TAM_INDICE; i++)
    {
        if (valor < indice[i].chave){
            fim = indice[i].posicao - 1;
            break;
        }

        inicio = indice[i].posicao;
    }

    for (int i = inicio; i <= fim; i++)
    {
        if (vetor[i] == valor)
        {
            return i;
        }
    }

    return -1;
     
}

int main(void)
{
    int vetor[TAM] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    struct Indice indice[TAM_INDICE] = 
    {
        {10, 0},
        {40, 3},
        {70, 6},
    };
    
    int valor;
    printf("Digite o valor a buscar: ");
    scanf("%d", &valor);

    int resultado = buscaSequencialIndexada(vetor, indice, valor);

    if (resultado != -1)
    {
        printf("valor encontrado na posicao %d\n", resultado);
    }else {
        printf("Valor nao encontrado");
    }
    return 0;
}