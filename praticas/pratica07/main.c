#include <stdio.h>
#include "pilha.h"

int main() {
    printf("=== Teste de Pilha Dinamica (FILO) ===\n\n");

    // 1. Criar a pilha
    Pilha* minha_pilha = pilha_criar();
    if (minha_pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }
    
    printf("Pilha criada com sucesso.\n");
    pilha_exibir(minha_pilha);
    printf("\n");

    // 2. Empilhar elementos
    printf("Empilhando valores: 10, 20 e 30...\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    
    // 3. Exibir elementos
    pilha_exibir(minha_pilha); // Deve mostrar: 30 20 10
    printf("\n");

    // 4. Consultar o topo
    printf("Elemento no topo: %d\n\n", pilha_topo(minha_pilha)); // Deve ser 30

    // 5. Desempilhar um elemento
    int valor_removido = pilha_desempilhar(minha_pilha);
    printf("Elemento desempilhado: %d\n", valor_removido); // Deve remover 30
    
    // Exibir novamente para conferir a remocao
    pilha_exibir(minha_pilha); // Deve mostrar: 20 10
    printf("\n");

    // 6. Testar desempilhamento completo
    printf("Desempilhando o resto...\n");
    pilha_desempilhar(minha_pilha);
    pilha_desempilhar(minha_pilha);
    
    // Exibir pilha vazia
    pilha_exibir(minha_pilha);
    printf("\n");

    // 7. Destruir a pilha
    pilha_destruir(minha_pilha);
    printf("Pilha destruida com sucesso. Encerrando programa.\n");

    return 0;
}