#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define SIZE 100

void fill_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Números entre 0 e 999
    }
}

int main() {
    int data[SIZE];
    int temp_arr[SIZE];
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));
    fill_array(data, SIZE);

    // --- Teste Busca Linear ---
    int target = data[50]; // Vamos buscar o elemento que sabemos que existe
    start = clock();
    int pos = linear_search(data, SIZE, target);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Busca Linear: Elemento %d encontrado na posicao %d\n", target, pos);
    printf("Tempo: %f segundos\n\n", cpu_time_used);

    // --- Teste QuickSelect ---
    // Copiando para não perder o vetor original, pois QuickSelect altera a ordem
    for(int i=0; i<SIZE; i++) temp_arr[i] = data[i];
    
    int k = 10; // Queremos o 10º menor elemento
    start = clock();
    int result = quick_select(temp_arr, 0, SIZE - 1, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("QuickSelect: O %do menor elemento e %d\n", k, result);
    printf("Tempo: %f segundos\n", cpu_time_used);

    return 0;
}