/*
Fila - Funções básicas
FIFO - First In First Out | Primeiro a entrar é o primeiro a sair
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	
	int valor;
	struct No* prox;
	
}TNo;

typedef TNo* TLista;

// protótipos
int enfilar(TLista *F, TLista *U, int numero);
int desenfilar(TLista *F, TLista *U, int *numero);
int primeiro(TLista F, int *numero);

int menu();

void main(){
	
	//declaração de variáveis
	TLista F = NULL, U = NULL;  //representando a fila inicialmente vazia
	int num, op;

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
			        if (enfilar (&F, &U, num) == 1)   //ou apenas: if (enfilar (&F, &U, num))
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
			        if (desenfilar (&F, &U, &num) == 1)
			        {
			        	printf ("\n\tElemento %d removido da fila!", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!");
					}
					break;

			//Primeiro
			case 3: if (primeiro (F, &num) == 1)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!");
					}
					break;

			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4); //4 = SAIR
}

int enfilar(TLista *F, TLista *U, int numero){
	
	TLista aux;
	
	aux = malloc(sizeof(TNo));
	
	if(!aux){
		return 0;		
	}else{
		
		// atribuindo os valores ao novo nó
		aux->valor = numero;
		aux->prox = NULL;
		
		if(*F){	// verifica se há elementos na fila
			
			// faz o último nó apontar pro novo
			(*U)->prox = aux;
			
		}else{	// se a lista estiver vazia
			
			// atualiza o endereço do começo da lista
			*F = aux;
		}
		
		// atualizando o endereço do final da lista
		*U = aux;
		
		return 1;
	}
}

int desenfilar(TLista *F, TLista *U, int *numero){
	
	TLista aux;
	
	if(!(*F)){
		return 0;
	}else{
		
		// armazenando o nó do começo da lista em 'aux'
		aux = *F;
		
		// armazenando o valor que será excluido
		*numero = (*F)->valor;
		
		// atualizando o valor de 'F' (nó que referencia o começo da lista)
		*F = aux->prox;
		
		// caso a fila fique vazia após a remoção
		if(!(*F)){
			
			// faz o nó 'U' receber NULL 
			*U = NULL;
		}
		
		// libera memória e exclui o elemento do começo da fila
		free (aux);
		
		return 1;
	}
}

int primeiro(TLista F, int *numero){
	
	if(!F){
		return 0; // lista está vazia
	}else{
		
		*numero = F->valor;
		
		return 1; 
	}
}


int menu(){
	
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
