/*
    Implementação do algoritmo base do Selection Sort

    Compilação do algoritmo base : gcc selectionSort.c -o selectionSort
    Compilação com a flag de otimização -O2: gcc -o selectionSort -O2 selectionSort.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort (int vet[],int tam);
void exibevetor(int vet[], int tam);

void selectionSort (int vet[],int tam){
   int i, j, menor, aux;
   for(i = 0; i < (tam-1); i++) {
      menor = i;  // o menor é o primeiro número não ordenado ainda 
   for(j = (i+1); j < tam; j++){
     if(vet[j] < vet[menor]) // busca pelo menor elemento atraves do indice  
      menor = j;  // salva o novo indice como menor 
   }
   /* troca e coloca o menor elemento para frente */
     if(vet[i] != vet[menor]){
       aux = vet[i];
       vet[i] = vet[menor];
       vet[menor] = aux;
     }
  }
}

void exibevetor(int vet[], int tam){
    int i;
    for (i = 0; i < tam; ++i){
        printf("%d ", vet[i]);
    }
    printf("\n");
}


int main () {
    int *vet, i, tam;
    clock_t t, end;
    double cpu_time_used;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&tam);
    
    vet = (int *)malloc(sizeof(int)*tam);
    if(vet == NULL){
        exit(1);
    }
    
    for(i = 0; i < tam; ++i){
        vet[i] = rand() %100; //preenche vetor com valores aleatorios
    }

    exibevetor(vet,tam);
    t = clock();
    selectionSort(vet,tam);
    t = clock()-t;
    exibevetor(vet,tam);
    cpu_time_used = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTempo de execução: %f\n", cpu_time_used);
    free(vet);
}