#include <stdio.h>
#include <stdbool.h>

int main() {
    int vetor[100];
    int alvo, i;
    bool encontrado = false;

    // Preenchendo o vetor com valores de 0 a 99 para teste
    for (i = 0; i < 100; i++) {
        vetor[i] = i; 
    }

    printf("Digite o valor que deseja buscar (0 a 99): ");
    scanf("%d", &alvo);

    // Busca Sequencial
    for (i = 0; i < 100; i++) {
        if (vetor[i] == alvo) {
            printf("Valor %d encontrado na posicao %d do vetor.\n", alvo, i);
            encontrado = true;
            break; // Otimização: para a busca assim que encontra o valor
        }
    }

    if (!encontrado) {
        printf("Valor %d nao encontrado no vetor.\n", alvo);
    }

    return 0;
}