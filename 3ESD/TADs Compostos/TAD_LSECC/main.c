#include <stdio.h>
#include <stdlib.h>
#include "ListaSECC.h"


void testar_lista_nao_classificada() {
    printf("\n=== TESTE LISTA NÃO CLASSIFICADA COM REPETIÇÃO ===\n");
    tLSE *lista = lse_criar_lista(FALSE, TRUE);
    
    // Teste de inserção
    lse_adicionar_elemento(lista, 5);
    lse_adicionar_elemento(lista, 3);
    lse_adicionar_elemento(lista, 7);
    lse_adicionar_elemento(lista, 5); // Repetido
    lse_adicionar_elemento(lista, 1);
    
    printf("Lista após inserções: ");
    // exibe a lista 
    lse_imprimir(lista);
    
    // Teste de exclusão
    int removidos = lse_excluir_elemento(lista, 5);
    printf("\nRemovidos %d elementos com valor 5\n", removidos);
    
    // Libera memória
    lse_destruir(&lista);
}

void testar_lista_classificada() {
    printf("\n=== TESTE LISTA CLASSIFICADA SEM REPETIÇÃO ===\n");
    tLSE *lista = lse_criar_lista(TRUE, FALSE);
    
    // Teste de inserção ordenada
    lse_adicionar_elemento(lista, 10);
    lse_adicionar_elemento(lista, 4);
    lse_adicionar_elemento(lista, 8);
    lse_adicionar_elemento(lista, 6);
    lse_adicionar_elemento(lista, 8); // Deve ser ignorado
    lse_adicionar_elemento(lista, 2);
    
    printf("Lista ordenada após inserções: ");
    // exibe os elementos da lista após as inserções
	lse_imprimir(lista);
    
    // Teste de exclusão
    int removidos = lse_excluir_elemento(lista, 6);
    printf("\nRemovidos %d elementos com valor 6\n", removidos);
    
    // Libera memória
	lse_destruir(&lista);
}

void testar_lista_vazia() {
    printf("\n=== TESTE LISTA VAZIA ===\n");
    tLSE *lista = lse_criar_lista(FALSE, FALSE);
    
    printf("Lista está vazia? %s\n", lse_lista_vazia(lista) ? "Não" : "Sim");
    
    // Teste exclusão em lista vazia
    int removidos = lse_excluir_elemento(lista, 5);
    printf("Tentativa de remover de lista vazia retornou: %d\n", removidos);
    
    // Libera memória
    lse_destruir(&lista);
}

int main() {
    testar_lista_nao_classificada();
    testar_lista_classificada();
    testar_lista_vazia();
    
    return 0;
}
