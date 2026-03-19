#include <stdio.h>

void imprimirVetor(int vetor[], int n){
    printf("\nIMPRIMINDO VETOR\n\n");
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    
    printf("\n");
}

void shellSort(int vetor[], int n){
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2){
        
        for (i = gap; i < n; i++){
            
            temp = vetor[i];
            
            for(j=i; j >= gap && vetor[j - gap] > temp; j -= gap){
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
            imprimirVetor(vetor, n);
        } 
    }
}



int main(void){
    int vetor[] = {80, 10, 120, 70, 20, 100};

    int n = sizeof(vetor) / sizeof(vetor[0]);

    imprimirVetor(vetor, n);
    
    shellSort(vetor, n);

}