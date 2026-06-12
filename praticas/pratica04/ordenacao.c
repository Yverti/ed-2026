#include "ordenacao.h"

// Troca dois elementos de lugar
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        trocar(&arr[min_idx], &arr[i]);
    }
}

void quick_sort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = arr[fim];
        int i = (inicio - 1);

        for (int j = inicio; j < fim; j++) {
            if (arr[j] < pivo) {
                i++;
                trocar(&arr[i], &arr[j]);
            }
        }
        trocar(&arr[i + 1], &arr[fim]);
        int particao = i + 1;

        quick_sort(arr, inicio, particao - 1);
        quick_sort(arr, particao + 1, fim);
    }
}