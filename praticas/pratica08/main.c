#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila* f = fila_criar();
    
    printf("=== Teste da Fila FIFO ===\n\n");
    
    printf("Enfileirando valores: 10, 20, 30, 40, 50\n");
    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    fila_enfileirar(f, 40);
    fila_enfileirar(f, 50);
    
    printf("Estado da fila:\n");
    fila_exibir(f);
    
    printf("\nInício da fila: %d\n", fila_inicio(f));
    
    printf("\nDesenfileirando 3 elementos:\n");
    printf("Removido: %d\n", fila_desenfileirar(f));
    printf("Removido: %d\n", fila_desenfileirar(f));
    printf("Removido: %d\n", fila_desenfileirar(f));
    
    printf("Estado da fila após desenfileiramento:\n");
    fila_exibir(f);
    
    printf("\nNovo início da fila: %d\n", fila_inicio(f));
    
    printf("\nDesenfileirando os 2 elementos restantes:\n");
    printf("Removido: %d\n", fila_desenfileirar(f));
    printf("Removido: %d\n", fila_desenfileirar(f));
    
    printf("Estado da fila:\n");
    fila_exibir(f);
    
    fila_destruir(f);
    printf("\nFila destruída com sucesso!\n");
    
    return 0;
}