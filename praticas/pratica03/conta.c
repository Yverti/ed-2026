#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

// Definição real da struct, escondida do main.c
struct conta_t {
    int numero;
    float saldo;
};

Conta conta_criar(int numero, float saldo_inicial) {
    Conta c = (Conta) malloc(sizeof(struct conta_t));
    if (c != NULL) {
        c->numero = numero;
        c->saldo = saldo_inicial;
    }
    return c;
}

void conta_depositar(Conta c, float valor) {
    if (c != NULL && valor > 0) {
        c->saldo += valor;
    }
}

int conta_sacar(Conta c, float valor) {
    if (c != NULL && valor > 0 && c->saldo >= valor) {
        c->saldo -= valor;
        return 1; // Sucesso
    }
    return 0; // Falha (saldo insuficiente ou valor inválido)
}

float conta_ver_saldo(Conta c) {
    if (c != NULL) return c->saldo;
    return 0.0;
}

void conta_destruir(Conta c) {
    if (c != NULL) {
        free(c);
    }
}