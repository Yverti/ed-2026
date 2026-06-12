#include "selecao.h"

int busca_sequencial(int v[], int n int valor) {
    for(int i = 0; i < n; i++) { // 0(n)
        if (v[i] == valor) {
            return i;
        }
    }
    return -1;
}