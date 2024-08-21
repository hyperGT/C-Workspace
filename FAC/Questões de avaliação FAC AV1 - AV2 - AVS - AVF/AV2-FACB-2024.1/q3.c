/*
* Verificando se o vetor em questão se classifica como um tipo de organização de dados Heap
* 80 50 30 25 10 28 16
*
* Partindo do 'i', para achar os dois filhos do elemento pai localizado no 'i'
* faz-se respectivamente 2 * i + 1 e 2 * i + 2
* nota: retorna 0 caso não seja, e caso seja, retornar o número 1 
*/

# include <stdio.h>

// funções
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
	
	// percorrendo o vetor até o penultimo nó pai
	for(i=0; i<=(cap-2)/2; i++){
		
		// verifica se o filho esquerdo é maior que o pai
		if(2 * i + 1 < cap && vet[i] < vet[2 * i + 1]){
			printf("Elemento %d e menor que o filho esquerdo %d\n", vet[i], vet[2 * i + 1]);
			return 0;
		}
		
		// verifica se o filho direito é maior que o pai
		if(2 * i + 2 < cap && vet[i] < vet[2 * i + 2]){
			printf("Elemento %d e menor que o filho direito %d\n", vet[i], vet[2 * i + 2]);
			return 0;
		}
	}
	return 1; // o vetor atual é classificado como um Heap
}
