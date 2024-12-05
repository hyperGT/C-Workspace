/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 21/11/2024
	
	Filas Dinâmicas (encadeadas)
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
int  enfilar (TLista *F, TLista *U, int numero);
int  desenfilar (TLista *F, TLista *U, int *numero);
int  primeiro (TLista F, int *numero);

int menu ();

//main
void main ()
{
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

//implementação das funções
int  enfilar (TLista *F, TLista *U, int numero)
{
	//declaração de variáveis
	TLista aux;

	//alocar memória para o novo nó
	aux = malloc (sizeof(TNo));		//malloc: memory allocation
	
	//verificando se a memória solicitada foi alocada
	if (!aux)    //ou:   if (aux == NULL)
	{
		return 0;
	}
	else
	{
		//armazenar o valor no novo nó
		aux->valor = numero;

//fazendo o campo ‘prox’ do novo nó apontar para NULL
aux->prox = NULL;

//verificando se há elementos na fila
if (*F)
{
	//fazendo o “antigo último nó” apontar para o novo
(*U)->prox = aux;
}
else
{
	//fazer ‘F’ apontar para o novo nó
	*F = aux;
}

//atualizando ‘U’, de forma que aponte para o novo nó
*U = aux;

		return 1;
	}	
}

int  desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;

	//verificando se a fila está vazia
	if (!(*F))
	{
		return 0;
	}
	else
	{
		//armazenando em ‘aux’ o endereço do nó que contém o primeiro elemento da fila
		aux = *F;

		//armazenando em ‘numero’ o valor que está no primeiro elemento da fila
		*numero = (*F)->valor;

		//atualizando o valor de F
		*F = (*F)->prox;   //ou *F = aux->prox;

		//se a fila tornou-se vazia
		if (!(*F))
		{
			*U = NULL;
}

		//liberando a memória do nó que continha o primeiro elemento da fila
		free (aux);

		return 1;
	}
}

int primeiro (TLista F, int *numero)
{
	//verificando se a fila está vazia
	if (!F)
	{
		return 0;
	}
	else
	{
		//armazenando em ‘numero’ o primeiro element da fila
		*numero = F->valor;

		return 1;
	}

}

int menu ()
{
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
