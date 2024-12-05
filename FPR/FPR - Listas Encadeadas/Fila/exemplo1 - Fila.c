/*
Fila - Fun��es b�sicas
FIFO - First In First Out | Primeiro a entrar � o primeiro a sair
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	
	int valor;
	struct No* prox;
	
}TNo;

typedef TNo* TLista;

// prot�tipos
int enfilar(TLista *F, TLista *U, int numero);
int desenfilar(TLista *F, TLista *U, int *numero);
int primeiro(TLista F, int *numero);

int menu();

void main(){
	
	//declara��o de vari�veis
	TLista F = NULL, U = NULL;  //representando a fila inicialmente vazia
	int num, op;

	do
	{
		system ("CLS");		//limpar tela

		//exibindo o meu ao usu�rio
		op = menu ();

		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (enfilar (&F, &U, num) == 1)   //ou apenas: if (enfilar (&F, &U, num))
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remo��o
			case 2: //chamando a fun��o
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

			//Sa�da
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
		
		// atribuindo os valores ao novo n�
		aux->valor = numero;
		aux->prox = NULL;
		
		if(*F){	// verifica se h� elementos na fila
			
			// faz o �ltimo n� apontar pro novo
			(*U)->prox = aux;
			
		}else{	// se a lista estiver vazia
			
			// atualiza o endere�o do come�o da lista
			*F = aux;
		}
		
		// atualizando o endere�o do final da lista
		*U = aux;
		
		return 1;
	}
}

int desenfilar(TLista *F, TLista *U, int *numero){
	
	TLista aux;
	
	if(!(*F)){
		return 0;
	}else{
		
		// armazenando o n� do come�o da lista em 'aux'
		aux = *F;
		
		// armazenando o valor que ser� excluido
		*numero = (*F)->valor;
		
		// atualizando o valor de 'F' (n� que referencia o come�o da lista)
		*F = aux->prox;
		
		// caso a fila fique vazia ap�s a remo��o
		if(!(*F)){
			
			// faz o n� 'U' receber NULL 
			*U = NULL;
		}
		
		// libera mem�ria e exclui o elemento do come�o da fila
		free (aux);
		
		return 1;
	}
}

int primeiro(TLista F, int *numero){
	
	if(!F){
		return 0; // lista est� vazia
	}else{
		
		*numero = F->valor;
		
		return 1; 
	}
}


int menu(){
	
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
