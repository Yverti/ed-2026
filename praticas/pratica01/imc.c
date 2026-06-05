#include <stdio.h>
#include <math.h>

float calcular_imc(float altura, float peso) {
    if (altura <= 0.0f || peso <= 0.0f) {
        return 0.0f;
    }
    return peso / (altura * altura);
}

int comparar_imc(float valor_obtido, float valor_esperado) {
    return fabsf(valor_obtido - valor_esperado) < 0.1;
}

int main() {
    float a, p, imc;

    a = 0.0f; p = 50.0f; imc = calcular_imc(a, p);
    printf("altura = %.1f, peso = %.1f, imc = %.1f => %i\n", a, p, imc, comparar_imc(imc, 0.0f));

    a = 1.75f; p = 0.0f; imc = calcular_imc(a, p);
    printf("altura = %.1f, peso = %.1f, imc = %.1f => %i\n", a, p, imc, comparar_imc(imc, 0.0f));

    a = 1.75f; p = 50.0f; imc = calcular_imc(a, p);
    printf("altura = %.1f, peso = %.1f, imc = %.1f => %i\n", a, p, imc, comparar_imc(imc, 16.3f));

    a = 1.75f; p = 65.0f; imc = calcular_imc(a, p);
    printf("altura = %.1f, peso = %.1f, imc = %.1f => %i\n", a, p, imc, comparar_imc(imc, 21.2f));

    a = 1.75f; p = 85.0f; imc = calcular_imc(a, p);
    printf("altura = %.1f, peso = %.1f, imc = %.1f => %i\n", a, p, imc, comparar_imc(imc, 27.8f));

    a = 1.75f; p = 95.0f; imc = calcular_imc(a, p);
    printf("altura = %.1f, peso = %.1f, imc = %.1f => %i\n", a, p, imc, comparar_imc(imc, 31.0f));

    return 0;
}