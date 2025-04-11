#include <stdio.h>
#include "Lista.h"

int main() {
    // Criando lista com capacidade 10, Não ordenada, COM repetição
    
    tLista *lista = lst_criarListaVazia(10, 0, 1); 

    printf("Inserindo elementos na lista (não ordenada, com repetição):\n");
    lst_incluirElemento(lista, 5);
    lst_incluirElemento(lista, 3);
    lst_incluirElemento(lista, 7);
    lst_incluirElemento(lista, 5);  // repetido
    lst_incluirElemento(lista, 1);
    lst_exibe(lista); // Deve mostrar: 5, 3, 7, 5, 1,

    printf("\nRemovendo todos os elementos com valor 5...\n");
    lst_excluirElemento(lista, 5);
    lst_exibe(lista); // Deve mostrar: 3, 7, 1,
        
    lst_free(lista);
    
    printf("\nCriando nova lista ordenada, SEM repetição...\n");
    tLista *listaOrd = lst_criarListaVazia(10, 1, 0);
    if (!listaOrd) {
        printf("Erro ao criar lista ordenada.\n");
        return 1;
    }

    lst_incluirElemento(listaOrd, 10);
    lst_incluirElemento(listaOrd, 4);
    lst_incluirElemento(listaOrd, 8);
    lst_incluirElemento(listaOrd, 6);
    lst_incluirElemento(listaOrd, 8); // deve ser ignorado

    lst_exibe(listaOrd); // Deve mostrar: 4, 6, 8, 10,

    printf("\nRemovendo elemento 6...\n");
    lst_excluirElemento(listaOrd, 6);
    lst_exibe(listaOrd);
    
    return 0;
}
