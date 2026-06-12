#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no {
    int valor;
    struct no* proximo;
} no_t;

struct fila {
    no_t* inicio;
    no_t* fim;
};

Fila* fila_criar(void) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

void fila_enfileirar(Fila* f, int valor) {
    if (f == NULL) return;
    
    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return;
    
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
}

int fila_desenfileirar(Fila* f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    
    no_t* temp = f->inicio;
    int valor = temp->valor;
    f->inicio = f->inicio->proximo;
    
    if (fila_esta_vazia(f)) {
        f->fim = NULL;
    }
    
    free(temp);
    return valor;
}

int fila_inicio(Fila* f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->inicio->valor;
}

void fila_exibir(Fila* f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    
    printf("Fila: ");
    no_t* atual = f->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int fila_esta_vazia(Fila* f) {
    if (f == NULL) return 1;
    return f->inicio == NULL;
}

void fila_destruir(Fila* f) {
    if (f == NULL) return;
    
    while (!fila_esta_vazia(f)) {
        fila_desenfileirar(f);
    }
    free(f);
}