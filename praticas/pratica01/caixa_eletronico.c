#include <stdio.h>

// Estrutura para guardar a quantidade de cada nota
typedef struct {
    int n200, n100, n50, n20, n10, n5, n2;
} Notas;

// Função que contém a lógica do Algoritmo Guloso
Notas calcular_saque(int valor) {
    Notas n = {0, 0, 0, 0, 0, 0, 0}; // Inicializa todas as notas com zero

    // Se o valor for inválido, retorna tudo zero imediatamente
    if (valor <= 0 || valor > 1000) {
        return n; 
    }

    n.n200 = valor / 200; valor %= 200;
    n.n100 = valor / 100; valor %= 100;
    n.n50 = valor / 50;   valor %= 50;
    n.n20 = valor / 20;   valor %= 20;
    n.n10 = valor / 10;   valor %= 10;
    n.n5 = valor / 5;     valor %= 5;
    n.n2 = valor / 2;     valor %= 2;

    return n;
}

// Função para comparar se as notas obtidas batem com as esperadas
int comparar_notas(Notas obtido, Notas esperado) {
    if (obtido.n200 == esperado.n200 && obtido.n100 == esperado.n100 &&
        obtido.n50 == esperado.n50 && obtido.n20 == esperado.n20 &&
        obtido.n10 == esperado.n10 && obtido.n5 == esperado.n5 &&
        obtido.n2 == esperado.n2) {
        return 1; // Verdadeiro (Teste passou)
    }
    return 0; // Falso (Teste falhou)
}

int main() {
    Notas res, esp;
    int saque;

    // Teste 1: Saque de 387 (1 nota de cada)
    saque = 387; 
    res = calcular_saque(saque); 
    esp = (Notas){1, 1, 1, 1, 1, 1, 1};
    printf("saque = %d, notas = [%d, %d, %d, %d, %d, %d, %d] => %i\n", 
           saque, res.n200, res.n100, res.n50, res.n20, res.n10, res.n5, res.n2, comparar_notas(res, esp));

    // Teste 2: Saque de 500 (2 notas de 200, 1 de 100)
    saque = 500; 
    res = calcular_saque(saque); 
    esp = (Notas){2, 1, 0, 0, 0, 0, 0};
    printf("saque = %d, notas = [%d, %d, %d, %d, %d, %d, %d] => %i\n", 
           saque, res.n200, res.n100, res.n50, res.n20, res.n10, res.n5, res.n2, comparar_notas(res, esp));

    // Teste 3: Saque de 1000 (5 notas de 200)
    saque = 1000; 
    res = calcular_saque(saque); 
    esp = (Notas){5, 0, 0, 0, 0, 0, 0};
    printf("saque = %d, notas = [%d, %d, %d, %d, %d, %d, %d] => %i\n", 
           saque, res.n200, res.n100, res.n50, res.n20, res.n10, res.n5, res.n2, comparar_notas(res, esp));

    // Teste 4: Erro - Saque de 1005 (Acima do limite)
    saque = 1005; 
    res = calcular_saque(saque); 
    esp = (Notas){0, 0, 0, 0, 0, 0, 0};
    printf("saque = %d, notas = [%d, %d, %d, %d, %d, %d, %d] => %i\n", 
           saque, res.n200, res.n100, res.n50, res.n20, res.n10, res.n5, res.n2, comparar_notas(res, esp));

    // Teste 5: Erro - Saque negativo
    saque = -50; 
    res = calcular_saque(saque); 
    esp = (Notas){0, 0, 0, 0, 0, 0, 0};
    printf("saque = %d, notas = [%d, %d, %d, %d, %d, %d, %d] => %i\n", 
           saque, res.n200, res.n100, res.n50, res.n20, res.n10, res.n5, res.n2, comparar_notas(res, esp));

    return 0;
}