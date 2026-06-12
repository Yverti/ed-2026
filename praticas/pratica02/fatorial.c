#include <stdio.h>

// Função iterativa
unsigned long long fatorial_iterativo(int n) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função recursiva
unsigned long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: O numero deve ser positivo.\n");
        return 1;
    }

    printf("Fatorial Iterativo de %d: %llu\n", numero, fatorial_iterativo(numero));
    printf("Fatorial Recursivo de %d: %llu\n", numero, fatorial_recursivo(numero));

    return 0;
}