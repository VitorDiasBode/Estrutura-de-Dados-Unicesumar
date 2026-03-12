#include <stdio.h>

void bubbleSort(int vetor[], int tamanho){
    int i, j, temp;

    for(i = 0; i < tamanho - 1; i++){
        for(j=0; j < tamanho - i - 1; j++){
            if(vetor[j] > vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main(void){
    int vetor[] = {5, 1, 4, 2, 8};

    bubbleSort(vetor, 5);

    printf("Vetor Ordenado\n");

    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}