/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 14/11/2024
	
	Listas Dinâmicas:

	Lista de Exercícios XIII (Listas Encadeadas):
	
	QUESTÃO 06:
Desenvolver uma função que, dada uma lista L1, crie uma nova lista L2, cópia de L1.
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
TLista copiarLista (TLista L1);

int  inserir (TLista *L, int numero);
void exibir  (TLista  L);

//main
void main ()
{
	//declaração de variáveis
	TLista lista1 = NULL, lista2;

	//inserindo elementos em lista1
	inserir (&lista1, 1);
	inserir (&lista1, 2);
	inserir (&lista1, 3);
	inserir (&lista1, 4);
	inserir (&lista1, 5);

	//chamando a função
	lista2 = copiarLista (lista1);

	//exibindo as listas
	exibir (lista1);
	exibir (lista2);
}

//implementação das funções
TLista copiarLista (TLista L1)
{
TLista L2 = NULL, aux1 = L1, aux2, novo;

//percorrendo todos os elementos de L1 para inseri-los em L2
while (aux1)
{
	//alocando memória para o novo nó
	novo = malloc (sizeof (TNo));

	novo->valor = aux1->valor;

	if (!L2) //se a lista L2 estiver vazia
	{
		L2 = novo;
	}
	else
	{
		aux2->prox = novo;
	}

	aux2 = novo;

	//indo para o próximo elemento da lista L1
	aux1 = aux1->prox;
}

//finalizando a nova lista
aux2->prox = NULL;

return L2;	
}

int  inserir (TLista *L, int numero)
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

		//passo 3: fazer o campo ‘prox’ do novo nó apontar para o “até então 1º nó”
		aux->prox = *L;

		//passo 4: atualizar L, de forma que aponte para o novo nó
		*L = aux;

		return 1;
	}
}

void exibir  (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	if (!L) //ou:  if (L == NULL)
	{
		printf ("\nLista vazia!\n");
	}
	else
	{
		printf ("\nElementos da lista: ");
	
		while (aux != NULL)
		{
			//printf ("%d ", (*aux).valor);
			printf ("%d ", aux->valor);
			
			//aux = (*aux).prox;
			aux = aux->prox;
		}
	}
}


