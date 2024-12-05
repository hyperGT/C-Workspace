/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 21/11/2024
	
	Pilhas Dinâmicas (encadeadas)
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declaração de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
int  empilhar (TLista *P, int numero);
int  desempilhar (TLista *P, int *numero);
int  topo (TLista P, int *numero);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista P = NULL;  //representando a pilha inicialmente vazia
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
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4); //4 = SAIR
}

//implementação das funções
int  empilhar (TLista *P, int numero)
{
	//declaração de variáveis
	TLista aux;

	//passo 1: alocar memória para o novo nó
	aux = malloc (sizeof(TNo));		//malloc: memory allocation
	
	//verificando se a memória solicitada foi alocada
	if (!aux)    //ou:   if (aux == NULL)
	{
		return 0;
	}
	else
	{
		//passo 2: armazenar o valor no novo nó
		aux->valor = numero;

		//passo 3: fazer o campo ‘prox’ do novo nó apontar para o antigo topo
		aux->prox = *P;
	
		//passo 4: atualizar P, de forma que aponte para o novo nó
		*P = aux;
	
		return 1;
	}	
}

int  desempilhar (TLista *P, int *numero)
{
	//declaração de variáveis
	TLista aux;

	//verificando se a pilha está vazia
	if (!(*P))
	{
		return 0;
	}
	else
	{
		//armazenando em ‘aux’ o endereço do nó que contém o topo da pilha
		aux = *P;

		//armazenando em ‘numero’ o valor que está no topo da pilha
		*numero = (*P)->valor;

		//atualizando o valor de P
		*P = (*P)->prox;   //ou *P = aux->prox;

		//liberando a memória do nó que continha o topo da pilha
		free (aux);

		return 1;
	}
}

int topo (TLista P, int *numero)
{
	//verificando se a pilha está vazia
	if (!P)
	{
		return 0;
	}
	else
	{
		//armazenando em ‘numero’ o valor que está no topo da pilha
		*numero = P->valor;

		return 1;
	}

}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
