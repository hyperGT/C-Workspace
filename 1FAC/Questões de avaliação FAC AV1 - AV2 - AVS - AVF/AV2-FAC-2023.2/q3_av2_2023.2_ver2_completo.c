/*
Quest�o da AV2 2023.2 FAC A
Considere que um vetor de inteiros armazene o numero 0 em algumas de suas
posi��es objetivando "separar subconjuntos de valores", como no exemplo a
seguir:

Subconjunto:  1			      2 	  	    3	      4 ....
Vetor:	   	| 5 | 7 | 3 | 0 | 5 | 9 | 0 | 1 | 0 | 3 | 4 | 8
Indice:      0   1   2   3   4   5   6   7   8   9   10  11

Desenvolver uma fun��o que, dados um vetor como definido anteriormente e um
n�mero inteiro n, retorne um vetor contendo o n-�simo subconjunto do vetor.
*/

#include <stdio.h>
#include <stdlib.h> 			// necess�rio p/ as fun��es rand() e srand()
#include <time.h>   			//necess�rio p/ fun��o time()
#define TAM 100

// prototypes

// fun��o que retorna subconjuntos
void retornaSC (int vetor[], int vetRetorno[], int n, int tamanho,
				int *tamVetB);

// fun��o para preencher o vetor com valores aleat�rios
//void preencherAleatorio (int vetor[], int tamanho);

// fun��o para exibir o vetor
void exibir (int vetor[], int tamanho);

int
main ()
{

  int n,						// aqui entra o subconjunto a ser buscado
   
	vetA[TAM] =
	{ 5, 7, 3, 0, 5, 9, 0, 1, 0, 3, 4, 8, 1, 0, 7, 7, 7, 0, 2, 1 },
	// vetA[TAM], // vetor original (conjunto A)
	tamVetB,					// guarda a quantidade de elementos do subconjunto
	vetB[5];					// vetor que cont�m um subconjunto de elementos de A

  //preencherAleatorio (vetA, TAM);	// preencher o vetor A
  exibir (vetA, TAM);			// exibir o conjunto/Vetor A

  // obtendo n
  printf ("Escolha um subconjunto para ver os valores: ");
  scanf ("%d", &n);
  printf ("\n");

  retornaSC (vetA, vetB, n, TAM, &tamVetB);	//preencher um vetor secundario com um subconjunto de elementos de A

  printf ("Quantidade de elementos do sub-conjunto: %d\n\n", tamVetB);	// mostrar o tamanho do subconjunto
  exibir (vetB, tamVetB);		// exibir o subconjunto obtido
}


void
retornaSC (int vetor[], int vetRetorno[], int n, int tamanho, int *tamVetB)
{

  int i, j = 0, subConj = 1;

  // loop variando at� o tamanho do vetor
  for (i = 0; i < tamanho; i++)
	{

	  // verificando se o subconjunto N�O � maior que n
	  if (!(subConj > n))
		{

		  // a cada zero � localizado o subconjunto no qual se encontra o
		  // for atualmente
		  if (vetor[i] == 0)
			{

			  subConj++;
			  
			}

		  // verificando se o subconjunto � o requisitado
		  if (subConj == n)		
			{
			  if (vetor[i] != 0)
				{
				  vetRetorno[j] = vetor[i];
				  j++;
				}
			  else
				{
				  vetor[i + 1];
				}
			}
		}
	  else
		{
		  break;
		}
	  *tamVetB = j;
	}
}

void
preencherAleatorio (int vetor[], int tamanho)
{

  int i;

  srand (time (NULL));

  for (i = 0; i < tamanho; i++)
	{

	  vetor[i] = rand () % 10;

	}
}

void
exibir (int vetor[], int tamanho)
{

  int i;

  if (tamanho <= 0)
	{
	  printf ("Exibindo elementos do Vetor: vazio/nao existe");
	}
  else
	{
	  printf ("Exibindo elementos do Vetor: ");
	  for (i = 0; i < tamanho; i++)
		{
		  printf ("%d ", vetor[i]);
		}
	}
  printf ("\n\n\n");
}


