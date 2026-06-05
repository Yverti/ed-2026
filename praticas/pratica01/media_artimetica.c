#include <stdio.h>
#include <math.h>

// Função que contém a lógica do programa
float calcular_media(int n, float numeros[]) {
    if (n <= 0 || n > 100) {
        return 0.0f; // Retorna 0 caso a quantidade seja inválida
    }

    float soma = 0.0f;
    for (int i = 0; i < n; i++) {
        soma += numeros[i];
    }
    return soma / n;
}

// Função de comparação
int comparar_float(float valor_obtido, float valor_esperado) {
    return fabsf(valor_obtido - valor_esperado) < 0.01f;
}

int main() {
    float media;
    
    // Caso 1: 3 números normais
    float teste1[] = {10.0f, 8.0f, 6.0f};
    media = calcular_media(3, teste1);
    printf("n = 3, notas: 10, 8, 6 | media = %.1f => %i\n", media, comparar_float(media, 8.0f));

    // Caso 2: 4 números com decimais
    float teste2[] = {7.5f, 7.5f, 8.0f, 9.0f};
    media = calcular_media(4, teste2);
    printf("n = 4, notas: 7.5, 7.5, 8, 9 | media = %.1f => %i\n", media, comparar_float(media, 8.0f));

    // Caso 3: Erro (n = 0)
    float teste3[] = {};
    media = calcular_media(0, teste3);
    printf("n = 0 | media = %.1f => %i\n", media, comparar_float(media, 0.0f));

    // Caso 4: Erro (n > 100)
    float teste4[101] = {0}; // Cria um vetor com 101 posições
    media = calcular_media(101, teste4);
    printf("n = 101 | media = %.1f => %i\n", media, comparar_float(media, 0.0f));

    return 0;
}