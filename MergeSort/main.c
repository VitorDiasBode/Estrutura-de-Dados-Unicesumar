#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = malloc(n1 * sizeof(int));
    int *direita = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++){
        esquerda[i] = vetor[inicio + i];
    }

    for (j = 0; j < n2; j++) {
        direita[j] = vetor[meio + 1 + j];
    }


    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2){
        if (esquerda[i] <= direita[j]){
            vetor[k] = esquerda[i];
            i++;
        }else {
            vetor[k] = direita[j];
            j++;
        }

        k++;
    }

    while ( i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while ( j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
    
}

void mergeSort(int vetor[], int inicio, int fim){
    if (inicio < fim ){
        int meio = inicio + (fim - inicio)/2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

void imprimirVetor(int vetor[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(void){

    int vetor[] = {38, 27, 43, 3, 9, 10};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    imprimirVetor(vetor, n);

    mergeSort(vetor, 0, n-1);
    
    imprimirVetor(vetor, n);

    return 0;
}