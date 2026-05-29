#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Estrutura interna para o nó da lista duplamente encadeada
typedef struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
} no_t;

// Estrutura interna para o descritor da lista
typedef struct lista_t {
    no_t* primeiro;
    no_t* ultimo;
} lista_t;

// Cria e inicializa a lista
Lista lista_criar() {
    lista_t* l = (lista_t*) malloc(sizeof(lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return (Lista)l;
}

// Verifica se a lista está vazia
bool lista_esta_vazia(Lista l) {
    if (l == NULL) return true;
    lista_t* lista = (lista_t*)l;
    return (lista->primeiro == NULL);
}

// Insere um elemento no final da lista
bool lista_inserir(Lista l, int valor) {
    if (l == NULL) return false;
    lista_t* lista = (lista_t*)l;

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return false;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->ultimo;

    if (lista_esta_vazia(l)) {
        lista->primeiro = novo;
    } else {
        lista->ultimo->proximo = novo;
    }
    
    lista->ultimo = novo;
    return true;
}

// Remove a primeira ocorrência de um elemento na lista
bool lista_remover(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return false;
    lista_t* lista = (lista_t*)l;

    no_t* atual = lista->primeiro;

    // Busca pelo nó que contém o valor
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    // Se não encontrou o valor
    if (atual == NULL) return false;

    // Ajusta os ponteiros dos nós vizinhos
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->primeiro = atual->proximo; // O nó era o primeiro
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        lista->ultimo = atual->anterior; // O nó era o último
    }

    free(atual);
    return true;
}

// Busca por um valor e retorna seu índice (base 0). Retorna -1 se não encontrar.
int lista_buscar(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return -1;
    lista_t* lista = (lista_t*)l;

    no_t* atual = lista->primeiro;
    int indice = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }

    return -1; 
}

// Exibe a lista do início ao fim
void lista_exibir(Lista l) {
    if (l == NULL) return;
    lista_t* lista = (lista_t*)l;

    if (lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }

    no_t* atual = lista->primeiro;
    printf("Lista: [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

// Libera toda a memória alocada pela lista
void lista_destruir(Lista l) {
    if (l == NULL) return;
    lista_t* lista = (lista_t*)l;

    no_t* atual = lista->primeiro;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(lista);
}