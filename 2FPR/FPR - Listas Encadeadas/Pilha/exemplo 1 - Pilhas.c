/*
Pilhas - Fun��es b�sicas
LIFO: �ltimo a entrar � o primeiro a sair
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	
	int valor;
	struct No* prox;
	
}TNo;

typedef TNo* TLista;

// prot�tipos das fun��es
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *numero);
int menu();

void main(){
	
	TLista P = NULL;
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
			        if (empilhar (&P, num) == 1)   //ou apenas: if (empilhar (&P, num))
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

			//Sa�da
			case 4: printf ("\n\nPrograma finalizado!");
			    break;
			
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		printf("\n");
		system ("PAUSE");
	}
	while (op != 4); //4 = SAIR
}

int empilhar (TLista *P, int numero){
	
	TLista aux;
	
	// passo 1: alocar mem�rio pro novo n�
	aux = malloc(sizeof(TNo));
	
	if(!aux) return 0;
	
	//passo 2: armazenar o valor no novo n�
	aux->valor = numero;
	
	//passo 3: fazer o campo �prox� do novo n� apontar para o antigo topo	
	aux->prox = *P;
	
	//passo 4: atualizar P, de forma que aponte para o novo n�
	*P = aux;
	
	return 1;
}

int desempilhar (TLista *P, int *numero){
	
	TLista aux;
	
	if(!(*P)) return 0;
	
	// armazenando em 'aux' o endere�o do n� que cont�m o topo da pilha
	aux = *P;
	
	// armazena em 'numero' o valor que est� no topo da pilha
	*numero = (*P)->valor;
	
	// atualizando o valor de P
	//*P = (*P)->prox;   //ou *P = aux->prox;
	*P = aux->prox;
	
	// liberando a mem�ria do n� que continha o topo da pilha
	free(aux);
	
	return 1;
	
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
	
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
