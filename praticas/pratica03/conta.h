#ifndef CONTA_H
#define CONTA_H

// Tipo abstrato de dados (ponteiro opaco)
typedef struct conta_t* Conta;

// Protótipos das funções
Conta conta_criar(int numero, float saldo_inicial);
void  conta_depositar(Conta c, float valor);
int   conta_sacar(Conta c, float valor); // Retorna 1 se sucesso, 0 se falha
float conta_ver_saldo(Conta c);
void  conta_destruir(Conta c);

#endif