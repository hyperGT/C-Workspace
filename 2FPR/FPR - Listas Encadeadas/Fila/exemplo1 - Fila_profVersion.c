/*
	FAETERJ-Rio
	Fundamentos de Programa��o - FPR - Turma: Manh�
	Data: 21/11/2024
	
	Filas Din�micas (encadeadas)
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declara��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//prot�tipos das fun��es
int  enfilar (TLista *F, TLista *U, int numero);
int  desenfilar (TLista *F, TLista *U, int *numero);
int  primeiro (TLista F, int *numero);

int menu ();

//main
void main ()
{
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

//implementa��o das fun��es
int  enfilar (TLista *F, TLista *U, int numero)
{
	//declara��o de vari�veis
	TLista aux;

	//alocar mem�ria para o novo n�
	aux = malloc (sizeof(TNo));		//malloc: memory allocation
	
	//verificando se a mem�ria solicitada foi alocada
	if (!aux)    //ou:   if (aux == NULL)
	{
		return 0;
	}
	else
	{
		//armazenar o valor no novo n�
		aux->valor = numero;

//fazendo o campo �prox� do novo n� apontar para NULL
aux->prox = NULL;

//verificando se h� elementos na fila
if (*F)
{
	//fazendo o �antigo �ltimo n� apontar para o novo
(*U)->prox = aux;
}
else
{
	//fazer �F� apontar para o novo n�
	*F = aux;
}

//atualizando �U�, de forma que aponte para o novo n�
*U = aux;

		return 1;
	}	
}

int  desenfilar (TLista *F, TLista *U, int *numero)
{
	//declara��o de vari�veis
	TLista aux;

	//verificando se a fila est� vazia
	if (!(*F))
	{
		return 0;
	}
	else
	{
		//armazenando em �aux� o endere�o do n� que cont�m o primeiro elemento da fila
		aux = *F;

		//armazenando em �numero� o valor que est� no primeiro elemento da fila
		*numero = (*F)->valor;

		//atualizando o valor de F
		*F = (*F)->prox;   //ou *F = aux->prox;

		//se a fila tornou-se vazia
		if (!(*F))
		{
			*U = NULL;
}

		//liberando a mem�ria do n� que continha o primeiro elemento da fila
		free (aux);

		return 1;
	}
}

int primeiro (TLista F, int *numero)
{
	//verificando se a fila est� vazia
	if (!F)
	{
		return 0;
	}
	else
	{
		//armazenando em �numero� o primeiro element da fila
		*numero = F->valor;

		return 1;
	}

}

int menu ()
{
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
