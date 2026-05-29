#include <stdio.h>
#include "lista_linear.h"

int main() {
    // 1. Criar a lista
    printf("--- Criando a lista ---\n");
    Lista minha_lista = lista_criar();
    
    if (lista_esta_vazia(minha_lista)) {
        printf("Lista criada com sucesso e esta vazia!\n\n");
    }

    // 2. Testar Inserções
    printf("--- Testando Inserções ---\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    lista_exibir(minha_lista); // Esperado: [ 10 20 30 40 ]
    printf("\n");

    // 3. Testar Busca
    printf("--- Testando Buscas ---\n");
    int valores_busca[] = {20, 50};
    for (int i = 0; i < 2; i++) {
        int idx = lista_buscar(minha_lista, valores_busca[i]);
        if (idx != -1) {
            printf("Valor %d encontrado no indice: %d\n", valores_busca[i], idx);
        } else {
            printf("Valor %d nao encontrado na lista.\n", valores_busca[i]);
        }
    }
    printf("\n");

    // 4. Testar Remoções
    printf("--- Testando Remocoes ---\n");
    
    printf("Removendo o 10 (primeiro elemento):\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista); // Esperado: [ 20 30 40 ]

    printf("Removendo o 40 (ultimo elemento):\n");
    lista_remover(minha_lista, 40);
    lista_exibir(minha_lista); // Esperado: [ 20 30 ]

    printf("Removendo o 30 (meio/ultimo atual):\n");
    lista_remover(minha_lista, 30);
    lista_exibir(minha_lista); // Esperado: [ 20 ]
    
    printf("\n");

    // 5. Destruir a lista
    printf("--- Destruindo a lista e encerrando ---\n");
    lista_destruir(minha_lista);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}