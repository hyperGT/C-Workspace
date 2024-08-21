/*
* Verificando se o vetor em quest�o se classifica como um tipo de organiza��o de dados Heap
* 80 50 30 25 10 28 16
*
* Partindo do 'i', para achar os dois filhos do elemento pai localizado no 'i'
* faz-se respectivamente 2 * i + 1 e 2 * i + 2
* nota: retorna 0 caso n�o seja, e caso seja, retornar o n�mero 1 
*/

# include <stdio.h>

// fun��es
int verificaHeap(int vet[], int cap);

int main()
{
	int vet[7] = {80, 50, 30, 25, 10, 38, 16}, result;
	
	result = verificaHeap(vet, 7);
	
	printf("Resultado: %d", result);
}

int
verificaHeap(int vet[], int cap)
{
	
	int i;
	
	// percorrendo o vetor at� o penultimo n� pai
	for(i=0; i<=(cap-2)/2; i++){
		
		// verifica se o filho esquerdo � maior que o pai
		if(2 * i + 1 < cap && vet[i] < vet[2 * i + 1]){
			printf("Elemento %d e menor que o filho esquerdo %d\n", vet[i], vet[2 * i + 1]);
			return 0;
		}
		
		// verifica se o filho direito � maior que o pai
		if(2 * i + 2 < cap && vet[i] < vet[2 * i + 2]){
			printf("Elemento %d e menor que o filho direito %d\n", vet[i], vet[2 * i + 2]);
			return 0;
		}
	}
	return 1; // o vetor atual � classificado como um Heap
}
