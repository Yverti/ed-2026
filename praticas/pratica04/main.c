#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"

void preencher_vetor(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Números de 0 a 999
    }
}

int main() {
    int n = 100;
    int original[n], teste[n];
    clock_t start, end;
    double tempo;

    srand(time(NULL));
    preencher_vetor(original, n);

    // --- BUBBLE SORT ---
    memcpy(teste, original, sizeof(original));
    start = clock();
    bubble_sort(teste, n);
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f segundos\n", tempo);

    // --- SELECTION SORT ---
    memcpy(teste, original, sizeof(original));
    start = clock();
    selection_sort(teste, n);
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f segundos\n", tempo);

    // --- QUICK SORT ---
    memcpy(teste, original, sizeof(original));
    start = clock();
    quick_sort(teste, 0, n - 1);
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f segundos\n", tempo);

    return 0;
}