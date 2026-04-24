#ifndef SELECAO_H
#define SELECAO_H

// Busca linear: retorna o índice do elemento ou -1 se não encontrado
int linear_search(int arr[], int n, int target);

// QuickSelect: retorna o k-ésimo menor elemento do vetor
int quick_select(int arr[], int left, int right, int k);

#endif