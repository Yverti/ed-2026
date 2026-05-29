#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

#include <stdbool.h>

// Definição do tipo Lista (Ponteiro opaco para ocultar a estrutura interna)
typedef struct lista_t* Lista;

// Protótipos das funções do TDA
Lista lista_criar();
bool lista_inserir(Lista l, int valor); // Insere no final por padrão
bool lista_remover(Lista l, int valor); // Remove a primeira ocorrência do valor
int lista_buscar(Lista l, int valor);   // Retorna o índice ou -1 se não encontrar
void lista_exibir(Lista l);
bool lista_esta_vazia(Lista l);
void lista_destruir(Lista l);

#endif // LISTA_LINEAR_H