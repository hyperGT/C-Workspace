#include "LDE.h"

#define TRUE 1
#define FALSE 0

int main() {
    tLDE *lista = lde_criar(FALSE, TRUE);  // Não classificada, com repetição
    
    lde_adicionar(lista, 12);
	lde_adicionar(lista, 10);
	lde_adicionar(lista, 20);
	lde_adicionar(lista, 10);
	lde_adicionar(lista, 140);
	lde_imprimir(lista);
	
	lde_excluir(lista, 20);
	
	lde_imprimir(lista);
	
	lde_excluir(lista, 10);
	
	lde_imprimir(lista);
    lde_destruir(&lista);
    return 0;
}
