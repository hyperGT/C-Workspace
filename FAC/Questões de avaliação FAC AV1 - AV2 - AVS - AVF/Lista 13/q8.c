/*
Quest�o 08:
Dado um vetor vet, contendo n�meros inteiros,
implementar uma fun��o que crie o vetor
vetNovo apenas com os elementos de vet que,
na ordem que est�o armazenados, fazem com
que vetNovo esteja ordenado crescentemente.
Todos os demais valores que �atrapalharam�
essa ordena��o ser�o armazenados no vetor
vetDescartados
*/

#include <stdio.h>
#define CAP 11

// prototipos das fun��es
void vetorOrdenado (int vet[], int vetNovo[], int *qntNovoVet, int vetDescartados[], int *qntDesc, int cap);

int buscaPos(int vet[], int valor, int pos);

void exibir(int vet[], int qnt);

int main(){
	
	// declara��o de vari�veis	
	int vet[CAP] = {3, 4, 8, 1, 9, 15, 12, 4, 20, 22, 10}, 
	vetNovo[CAP], 
	vetDesc[CAP], 
	qntVet = CAP,
	qntNovo,
	qntDesc;
	
	
	// chamando as fun��es
	vetorOrdenado (vet, vetNovo, &qntNovo, vetDesc, &qntDesc, CAP);
	
	// Exibindo os vetores
    printf("Vetor original: ");
    exibir(vet, CAP);
    printf("Vetor novo: ");
    exibir(vetNovo, qntNovo);
    printf("Vetor descartados: ");
    exibir(vetDesc, qntDesc);
}

void
vetorOrdenado (int vet[], int vetNovo[], int *qntNovoVet, int vetDescartados[], int *qntDesc, int cap)
{
	// declara��o de vari�veis
	int i, contDesc=0, contNv=0, pos;
	
	for(i=0; i<cap; i++){

		pos = buscaPos(vet, vet[i], i);
			
		if(pos>=0){
				
			// adicionando o valor ao vetor descartados
			vetDescartados[contDesc]=vet[i];
			contDesc++;		
			
		}else{
			vetNovo[contNv]=vet[i];
			contNv++;
			i++;
		}
			
	}
	*qntNovoVet = contNv;
	*qntDesc = contDesc;
}

int
buscaPos(int vet[], int valor, int pos)
{
	int i;
	
	for(i=0; i<pos; i++){
		
		// verificar se h� algum valor inferior ao elemento atual
		if(vet[i]>=valor){
			return i;
		}	
	}
	return -1; // nenhum valor inferior ao elemento atual encontrado
}

void exibir(int vet[], int qnt){
	
	// declara��o de vari�veis 	
	int i;
	
	printf("Vetor: ");
	for(i=0; i<qnt; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
