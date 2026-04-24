#include <stdio.h>
#include "conta.h"

int main() {
    // 1. Criar a conta
    Conta minha_conta = conta_criar(1234, 500.00);
    printf("Conta criada com saldo inicial de: R$ %.2f\n", conta_ver_saldo(minha_conta));

    // 2. Realizar depósito
    conta_depositar(minha_conta, 250.50);
    printf("Após depósito de R$ 250.50: R$ %.2f\n", conta_ver_saldo(minha_conta));

    // 3. Realizar saque com sucesso
    if (conta_sacar(minha_conta, 100.00)) {
        printf("Saque de R$ 100.00 realizado!\n");
    }

    // 4. Tentar saque sem saldo
    if (!conta_sacar(minha_conta, 2000.00)) {
        printf("Falha ao sacar R$ 2000.00: Saldo insuficiente.\n");
    }

    // 5. Exibir saldo final e limpar memória
    printf("Saldo final: R$ %.2f\n", conta_ver_saldo(minha_conta));
    
    conta_destruir(minha_conta);
    return 0;
}