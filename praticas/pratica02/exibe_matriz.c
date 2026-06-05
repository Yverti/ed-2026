#include <stdio.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    int matriz[LINHAS][COLUNAS];
    int i, j;
    volatile int soma = 0; // 'volatile' evita que o compilador otimize/remova o laço vazio
    clock_t inicio, fim;
    double tempo_aninhado, tempo_unico;

    // Inicializando a matriz
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            matriz[i][j] = 1; 
        }
    }

    // ---------------------------------------------------------
    // Abordagem 1: Dois laços aninhados
    // ---------------------------------------------------------
    inicio = clock();
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j]; // Simula uma operação de leitura
        }
    }
    fim = clock();
    tempo_aninhado = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    soma = 0; // resetando

    // ---------------------------------------------------------
    // Abordagem 2: Apenas um laço (usando aritmética de ponteiros)
    // ---------------------------------------------------------
    int *ponteiro_matriz = &matriz[0][0];
    int total_elementos = LINHAS * COLUNAS;
    
    inicio = clock();
    for (i = 0; i < total_elementos; i++) {
        soma += ponteiro_matriz[i]; // Acessa os elementos de forma linear
    }
    fim = clock();
    tempo_unico = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    // ---------------------------------------------------------
    // Resultados
    // ---------------------------------------------------------
    printf("Tempo com dois lacos aninhados: %f segundos\n", tempo_aninhado);
    printf("Tempo com apenas um laco:       %f segundos\n", tempo_unico);

    return 0;
}