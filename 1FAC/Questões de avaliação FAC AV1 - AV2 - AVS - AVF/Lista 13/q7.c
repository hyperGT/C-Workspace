/*
Quest�o 07:
Considere que um vetor de inteiros armazene o
n�mero 0 em algumas de suas posi��es
objetivando �separar subconjuntos de valores�,
como no exemplo a seguir:

1         2   3    4         5
5 7 3 0 5 9 0 1 0 3 4 8 0 1 2 3 4 5 6 7 8 9 10 11

Desenvolver uma fun��o que, dados um vetor
como definido anteriormente e um n�mero
inteiro n, retorne um vetor contendo o n-�simo
subconjunto do vetor.
Nota 1: caso exista o n-�simo subconjunto, a fun��o
retornar�, al�m do subconjunto, o valor 1; caso
contr�rio, retornar� 0
*/

#include <stdio.h>
#define CAP 12

// prototipos das fun��es
int retornaSubConjunto (int vet[], int vetSubConj[], int *qntVSC, int n, int cap);

void exibir (int vet[], int qnt);

int main(){
	int n, 
	vetor[CAP] = {5, 7, 3, 0, 5, 9, 0, 1, 0, 3, 4, 8},
	subVetor[CAP],
	qntSV;
	
	// exibindo vetor original
	printf("Vetor: ");
	exibir(vetor, CAP);
	
	printf("Insira o subconjunto a ser buscado[1 a 4]: ");
	scanf("%d", &n);
	
	int result = retornaSubConjunto (vetor, subVetor, &qntSV, n, CAP);
	
	// exibindo o resultado
	if(result > 0)
	{		
		// exibindo o n-�simo subconjunto
		printf("\nSubconjunto: ");
		exibir(subVetor, qntSV);
	} 
	else
	{
		printf("\nSubconjunto inexistente");
	}
}

int 
retornaSubConjunto (int vet[], int vetSubConj[], int *qntVSC, int n, int cap)
{
	// declara��o de vari�veis
	int i, j=0, contConj=1;
	
	// primeiro loop para ir percorrendo o vetor atr�s do subconjunto requisitado
	for(i=0; i<cap; i++)
	{		
	
		if(vet[i]==0)
		{
			
			contConj++;
				
		}else
		{
			if(contConj==n){
				
				// varrendo o vetor nas posi��es seguintes e guardando at� identificar o 0 (a� finaliza)			
				while(vet[i]!=0)
				{
					vetSubConj[j] = vet[i];
					i++;
					j++;
				}
				
				*qntVSC = j; 
				return 1; 				
			}			
		}
		
	}
	return 0; // o subconjunto buscado n�o existe
}

void exibir (int vet[], int qnt)
{
	int i;
	
	for(i=0; i<qnt; i++)	
	{
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
