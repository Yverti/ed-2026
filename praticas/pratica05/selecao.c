#include "selecao.h"

// Implementação da Busca Linear
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Função auxiliar para trocar elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partição de Lomuto para o QuickSelect
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

// Implementação do QuickSelect
int quick_select(int arr[], int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
        int index = partition(arr, left, right);

        if (index - left == k - 1)
            return arr[index];

        if (index - left > k - 1)
            return quick_select(arr, left, index - 1, k);

        return quick_select(arr, index + 1, right, k - index + left - 1);
    }
    return -1;
}