#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* Definição do nó da lista encadeada */
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

/* Definição da estrutura da pilha */
struct pilha_t {
    No* topo;
};

/* Cria e inicializa a pilha */
Pilha* pilha_criar() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

/* Insere um elemento no topo (Push) */
void pilha_empilhar(Pilha* p, int valor) {
    if (p == NULL) return;
    
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return;
    }
    
    novo_no->valor = valor;
    novo_no->proximo = p->topo;
    p->topo = novo_no;
}

/* Remove e retorna o elemento do topo (Pop) */
int pilha_desempilhar(Pilha* p) {
    if (pilha_esta_vazia(p)) {
        printf("Erro: A pilha esta vazia.\n");
        return -1; // Valor de erro
    }
    
    No* no_removido = p->topo;
    int valor = no_removido->valor;
    
    p->topo = no_removido->proximo;
    free(no_removido);
    
    return valor;
}

/* Consulta o elemento do topo (Peek) */
int pilha_topo(Pilha* p) {
    if (pilha_esta_vazia(p)) {
        printf("Erro: A pilha esta vazia.\n");
        return -1; // Valor de erro
    }
    return p->topo->valor;
}

/* Verifica se a pilha está vazia */
bool pilha_esta_vazia(Pilha* p) {
    return (p == NULL || p->topo == NULL);
}

/* Exibe os elementos da pilha */
void pilha_exibir(Pilha* p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    
    printf("Pilha (Topo -> Base): ");
    No* atual = p->topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

/* Destrói a pilha e libera a memória */
void pilha_destruir(Pilha* p) {
    if (p == NULL) return;
    
    No* atual = p->topo;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(p);
}