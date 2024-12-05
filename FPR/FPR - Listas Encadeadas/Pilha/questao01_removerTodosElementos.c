/*
Pilhas - Funções básicas
LIFO: Último a entrar é o primeiro a sair

Questão 01:
Desenvolver uma função que remova todos os elementos de uma pilha P do tipo TLista e retorne a
quantidade de elementos que existiam em P.
Nota: as regras de manipulação de uma pilha clássica devem ser respeitadas.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	
	int valor;
	struct No* prox;
	
}TNo;

typedef TNo* TLista;

// protótipos das funções
int empilhar(TLista *P, int numero);
int desempilhar(TLista *P, int *numero);
int topo (TLista P, int *numero);
int removerTodosPilha(TLista *P);

int menu();

void main(){
	
	TLista P = NULL;
	int num, op, qnt;
	
	do
	{
		system ("CLS");		//limpar tela

		//exibindo o meu ao usuário
		op = menu ();

		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (empilhar (&P, num) == 1)   //ou apenas: if (empilhar (&P, num))
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2: //chamando a função
			        if (desempilhar (&P, &num) == 1)
			        {
			        	printf ("\n\tElemento %d removido da pilha!", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!");
					}
					break;

			//Topo
			case 3: if (topo (P, &num) == 1)
			        {
			        	printf ("\n\tTopo da pilha: %d", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!");
					}
					break;

			//Saída
			case 4: 
				
				qnt = removerTodosPilha(&P);
				
				if(qnt != 0){
					printf("\n\nElementos removidos: %d\n", qnt);
				}else{
					printf("\n\nNenhum elemento removido\n");
				}
				
			    break;
			    
			case 5:
				printf("Programa encerrado");
				break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		printf("\n");
		system ("PAUSE");
	}
	while (op != 5); //5 = SAIR
	
}

int removerTodosPilha(TLista *P){
	
	TLista aux;
	int cont = 0;
	
	// verifica se a pilha está vazia
	if(!(*P)){
		return 0;
	}else{
		
		
		while(*P != NULL){
			
			// 'aux' recebe o endereço do nó do topo
			aux = *P;
			
			*P = (*P)->prox;
			
			printf("Removendo elemento: %d\n", aux->valor);
			
			free (aux);
			
			cont++;			
		}
		
		return cont;
	}
	
}

int empilhar (TLista *P, int numero){
	
	TLista aux;
	
	// aloca memória para um novo nó
	aux = malloc(sizeof(TNo));
	
	// verifica se a memória foi alocada
	if(!aux){
		return 0;
	}else{
		
		// guarda o valor no nó
		aux->valor = numero;
		
		// aponta o novo nó pro antigo topo
		aux->prox = *P;
		
		// o novo nó agora é referenciado como o novo nó no topo
		*P = aux;
				
		return 1;
	}
}

int desempilhar (TLista *P, int *numero){
	
	TLista aux;
	
	// verificando se a pilha está vazia
	if(!(*P)){
		return 0;
	}else{		
		
		// 'aux' recebe o ponteiro pro nó a ser excluido(o valor que está no topo)
		aux = *P;
		
		// o valor a ser excluido é armazenado
		*numero = (*P)->valor;
		
		// o valor logo abaixo do topo é referenciado como novo topo
		*P = (*P)->prox;
		
		// liberando a memória do topo
		free (aux);
	}
	
}

int topo (TLista P, int *numero){
	
	if(!P){
		return 0;
	}else{
		*numero = P->valor;
		return 1; 
	}
}

int menu (){
	
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Limpar pilha\n");
	printf ("(5) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
