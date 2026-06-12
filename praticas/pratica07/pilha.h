#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

/* Tipo opaco para a Pilha */
typedef struct pilha_t Pilha;

/* Protótipos das funções */

/* Cria e inicializa uma nova pilha vazia */
Pilha* pilha_criar();

/* Insere um novo elemento no topo da pilha */
void pilha_empilhar(Pilha* p, int valor);

/* Remove e retorna o elemento do topo da pilha */
int pilha_desempilhar(Pilha* p);

/* Retorna o valor do elemento no topo sem removê-lo */
int pilha_topo(Pilha* p);

/* Verifica se a pilha está vazia */
bool pilha_esta_vazia(Pilha* p);

/* Exibe todos os elementos da pilha (do topo para a base) */
void pilha_exibir(Pilha* p);

/* Libera toda a memória alocada para a pilha e seus nós */
void pilha_destruir(Pilha* p);

#endif /* PILHA_H */