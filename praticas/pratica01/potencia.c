#include <stdio.h>

// Função que calcula a potência usando apenas lógica manual (laço de repetição)
float calcular_potencia(float base, int expoente) {
    float resultado = 1.0f;
    
    // Multiplicação sucessiva: atende ao requisito "sem funções prontas"
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    
    return resultado;
}

// Função de comparação simplificada (sem math.h)
// Verifica se a diferença é bem pequena
int comparar_resultado(float obtido, float esperado) {
    float diferenca = obtido - esperado;
    // Se a diferença for negativa, transformamos em positiva (módulo manual)
    if (diferenca < 0) {
        diferenca = -diferenca;
    }
    return diferenca < 0.01f;
}

int main() {
    float b, pot;
    int e;

    b = 2.0f; e = 3; pot = calcular_potencia(b, e);
    printf("base = %.1f, expoente = %d, potencia = %.1f => %i\n", b, e, pot, comparar_resultado(pot, 8.0f));

    b = 5.0f; e = 0; pot = calcular_potencia(b, e);
    printf("base = %.1f, expoente = %d, potencia = %.1f => %i\n", b, e, pot, comparar_resultado(pot, 1.0f));

    b = 2.5f; e = 2; pot = calcular_potencia(b, e);
    printf("base = %.1f, expoente = %d, potencia = %.2f => %i\n", b, e, pot, comparar_resultado(pot, 6.25f));

    return 0;
}