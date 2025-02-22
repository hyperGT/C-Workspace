/*

Verificar se L2 é uma sublista de L1

Exemplo: L1: 1 2 3 4 5
L2: 3 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	
	int valor;
	struct No* prox;	
	
}TNo;

typedef TNo* TLista;

// prototipos das funcoes
int inserir(TLista *L, int numero);
int verificarSubLista(TLista L1, TLista L2);
void exibir(TLista L);

void main(){
	
	TLista L1 = NULL, L2 = NULL;
	
	inserir(&L1, 1);
	inserir(&L1, 2);
	inserir(&L1, 3);
	inserir(&L1, 4);
	inserir(&L1, 5);
	
	
	inserir(&L2, 3);
	inserir(&L2, 4);
	
	exibir(L1);
	exibir(L2);
	
	if(verificarSubLista(L1, L2) == 1){
		printf("L2 e uma sublista de L1");
	}else{
		printf("L2 NAO e uma sublista de L1");
	}
}

int verificarSubLista(TLista L1, TLista L2){
	
	TLista auxL2;
	
	if(!L1 || !L2){
		return 0;
	}else{			
		
		// percorrendo L1
		while(L1){
			
			if(L1->valor == L2->valor){
				
				auxL2 = L2;	// Inicializa a auxiliar
				TLista auxL1 = L1; // salva o estado de L1
				
				// percorrendo L2
				while(auxL2 && auxL1 && auxL2->valor == auxL1->valor){		
				
					auxL2 = auxL2->prox;
					auxL1 = auxL1->prox;
				}
				
				if(!auxL2){	// se chegou ao final de L2, então L2 e uma sublista
					return 1;
				}
			}
			L1 = L1->prox;	// atualizando o nó			
		}
		
		return 0;
	}
	
		
}

int inserir (TLista *L, int numero){
	
	TLista aux;
	
	// alocando memória para o novo nó
	aux = malloc(sizeof(TNo));	
	
	// verificando se a memória foi alocada corretamente 
	if(!aux) {
		
		return 0;
		
	}else{
		
		// guardando o valor em 'aux'
		aux->valor = numero;
		
		// atualizando o ponteiro de aux
		aux->prox = *L;
		
		// atualizando o ponteiro do primeiro Nó da lista
		*L = aux;
		
		return 1;
	}
}



void exibir(TLista L){
	
	TLista aux = L;
	
	printf("Lista: ");
	
	if(aux){
		
		
		while(aux){
			
			printf("%d, ", aux->valor);
			aux = aux->prox;
		}
	
	}
	
	printf(" NULL\n\n");
}
