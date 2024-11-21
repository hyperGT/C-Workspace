/*

QUESTÃO 05:
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se elas
possuem os mesmos elementos, independente da ordem na qual apareçam.

*/

#include<stdio.h>
#include<stdlib.h>

// structs
typedef struct No{
	
	int valor;	
	struct No *prox;

}TNo;

typedef TNo* Tlista;

// funcoes
int inserir(Tlista *L, int numero);
void exibirListas(Tlista L);
int verificaListas(Tlista L1, Tlista L2);
int comparaListas (Tlista L1, Tlista L2);

void main(){
	
	Tlista lista1 = NULL, lista2 = NULL;
	
	//inserindo elementos em lista1
	inserir (&lista1, 1);
	inserir (&lista1, 2);
	inserir (&lista1, 3);
	//inserir (&lista1, 8);

	//inserindo elementos em lista2
	inserir (&lista2, 3);
	inserir (&lista2, 2);
	inserir (&lista2, 1);
	inserir (&lista2, 3);
	inserir (&lista2, 1);
	inserir (&lista2, 3);
	
	exibirListas(lista1);
	exibirListas(lista2);
	
	if(verificaListas(lista1, lista2) == 1){
		printf("As listas sao iguais");
	}else{
		printf("As listas sao diferentes");
	}
}

int verificaListas(Tlista L1, Tlista L2){
	
	// compara a lista 1 com a lista 2
	if((comparaListas(L1, L2) == 1) && (comparaListas(L2, L1) == 1)){
		return 1;	// as listas possuem os mesmos elementos(independente da ordem)
	}else{		
		return 0;
	}	
}

int comparaListas (Tlista L1, Tlista L2){
	
	Tlista aux1 = L1, aux2;
	int verify;
	
	// percorrendo a lista 
	while(aux1){
		
		aux2 = L2;	// reseta a lista auxiliar
		
		verify = 0;	
		
		while(aux2){
			
			if(aux1->valor == aux2->valor){
				verify = 1;
				break;
			}else{
				aux2 = aux2->prox;
			}
		}
		
		if(verify == 0){
			return 0;
		}
		aux1 = aux1->prox;				
	}
	
	return 1;
}

int inserir(Tlista *L, int numero){
	
	Tlista aux;
	
	aux = malloc(sizeof(TNo));
	
	if(!aux){
		return 0;	
	}else{
		
		aux->valor = numero;
		
		aux->prox = *L;
		
		*L = aux;			
		
		return 1;
	}
}

void exibirListas(Tlista L){
	
	Tlista aux = L;
	
	printf("\n\nLista Encadeada: ");
	if(aux)
	{
		while(aux){
			printf("%d, ", aux->valor);
			aux = aux->prox;
		}
		printf("NULL\n");
	}else{
		printf("Lista Vazia");
	}
}



