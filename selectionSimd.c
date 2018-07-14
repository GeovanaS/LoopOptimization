/*
    Versão otimizada do algoritmo base do Selection Sort utilizando 
    a diretiva do OpenMP #pragma omp for simd 

    Compilação: gcc -o selectionSimd -fopenmp selectionSimd.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


void selectionSort (int vet[],int tam);
void exibevetor(int vet[], int tam);


void selectionSort (int vet[],int tam){
   int i,j,aux,menor;
   #pragma omp for simd  //instrui o compilador a distribuir as iterações do laço com o time de threads, operando em paralelo utilizando instruções SIMD 
   for(i = 0; i < (tam-1); ++i) { 
      menor = i;
   for(j = (i+1); j < tam; ++j){
     if(vet[j] < vet[menor]) // busca pelo menor elemento atraves do indice  
          menor= j; // salva o novo indice como menor 
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
        vet[i] = rand() %100; //preenche vetor com valores pseudo-aleatorios
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