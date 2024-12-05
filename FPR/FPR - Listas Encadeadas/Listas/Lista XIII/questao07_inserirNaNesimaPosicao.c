/*

QUEST�O 07:
Desenvolver uma fun��o que insira um n�mero inteiro N na i-�sima posi��o de uma lista
encadeada L.
Observa��o: caso a posi��o i informada seja inv�lida, a fun��o dever� retornar o valor 0; caso
contr�rio, o retorno ser� igual a 1.

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
int inserir(Tlista *L, int numero, int pos);
void exibirListas(Tlista L);


void main(){
	
	Tlista lista = NULL;
	int r, p;
	
	/*Populando a lista*/
	inserir(&lista, 1, 1);
	inserir(&lista, 2, 1);
	inserir (&lista, 10, 1);
	inserir (&lista, 20, 1);
	inserir (&lista, 30, 4);
	inserir (&lista, 40, 2);
	inserir (&lista, 50, 3);
	
	exibirListas(lista);		
	
	printf("Qual valor deseja inserir? valor: ");
	scanf("%d", &r);
	
	printf("\nEm qual posicao? Posicao: ");
	scanf("%d", &p);
	
	inserir(&lista, r, p);
	
	exibirListas(lista);		
}

int inserir(Tlista *L, int numero, int pos){
	
	Tlista aux1, aux2, novoNo;
	int cont;
	
	
	if(pos < 0){
		return 0;	// posi��o inv�lida
	}
		
	novoNo = malloc(sizeof(TNo));	// alocando mem�ria para um novo n�
	if(!novoNo){
		return 0;
	}
	
	novoNo->valor = numero;
	
	// verificando se a inser��o ser� feita no come�o da lista
	if(pos == 1){
									
		novoNo->prox = *L;				
		*L = novoNo;								
		
		return 1;
	}			
					
			
	// inicializando as v�riaveis auxiliares			
	aux1 = *L;
	aux2 = aux1->prox;			
			
	// passo 1: chegar at� a n-�sima posi��o da lista
	cont = 2;
	while(cont < pos){
				
		// avan�ando com aux1 e aux2 para seus pr�ximos valores respectivamente
		aux1 = aux2;
				
		// se o aux1 chegou a NULL a posi��o dada � inv�lida
		if(!aux1){
			return 0;
		}
													
		aux2 = aux2->prox;
				
		// atualizando o contador
		cont++;
	}
			
	// passo 2: inserir						
				
	// inserindo o valor no novo n�
	novoNo->valor = numero;
				
	// referenciando novo N� como prox n� de aux1 
	aux1->prox = novoNo;
			
	// aponta aux2 como pr�x item da lista depois do novo n�
	novoNo->prox = aux2;	
			
	return 1;	// deu tudo certo	
}			


void exibirListas(Tlista L){
	
	Tlista tmp = L;
	
	if(tmp){		
		printf("Lista: ");
		while(tmp){
			printf("%d, ", tmp->valor);
			tmp = tmp->prox;
		}
		printf("NULL\n");
	}else{
		printf("Lista Vazia\n\n");		
	}
	
}
