/*
Questão 05:
Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.
*/

// bibliotecas
#include <stdio.h>


// funções
int gerarArquivoB (char *nomeArq, char *novoArq);
int busca(float valor, float vet[], int tam);
void ordenaVetorDecrescente (float vet[], int tam);
void exibir(float vet[], int tam);

void main(){
	
	int r;
	r = gerarArquivoB("arqA.txt", "arqB.txt");
	
	//exibindo o resultado
	if (r == 1)
	{
		printf ("\n\nArquivo gerado com sucesso!");
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos!");
	}
}

int gerarArquivoB (char *nomeArq, char *novoArq){
	
	FILE *arqA, *arqB;
	int tam = 0, i;
	float valor, vetDescrescente[tam];
	
	arqA = fopen(nomeArq, "r"); // abrindo para leitura
	arqB = fopen(novoArq, "w"); // abrindo para escrita
	
	if(!arqA || !arqB){ // arq == NULL
	
		// fechando os arquivos
		if(arqA) fclose(arqA);
		if(arqB) fclose(arqB);
		
		return -1; // retornando erro
	}else{		
		
		// colocando todos os valores presentes no arquivo A dentro de um vetor
		while(fscanf(arqA, "%f", &valor) != EOF){
			
			// verificando se o valor a ser adicionado já está presente no vetor			
			if(busca(valor, vetDescrescente, tam) != 1){
				vetDescrescente[tam] = valor;
				tam++;
			}
		}
		
		// exibindo o vetor antes de ordenar
		exibir(vetDescrescente, tam);
		
		// ordenando os valores dentro do vetor
		ordenaVetorDecrescente(vetDescrescente, tam);
		
		// reescrevendo os valores no arquivo B
		for(i = 0; i < tam; i++){
			// escreve cada valor do vetor em uma nova linha
			fprintf(arqB, "%.0f\n", vetDescrescente[i]); 
		}
		
		fclose(arqA);
		fclose(arqB);		
	}
	exibir(vetDescrescente, tam);
	return 1;
}

void ordenaVetorDecrescente (float vet[], int tam){
	
	int i, j;
	float aux;
	
	for(i=0; i<tam; i++){
		for(j=0; j < tam - 1 - i; j++){
			// comparando os valores para verificar se estão obedecendo a ordem
			if(vet[j] < vet[j+1]){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
	}
	
	
}

int busca(float valor, float vet[], int tam){
	
	int i;
	
	for(i=0;i<tam;i++){
		if(valor == vet[i]){
			return 1; // valor já existe no vetor
		}
	}
	
	return 0; // valor não encontrado
}

void exibir(float vet[], int tam){
	int i;
	
	for(i=0;i<tam;i++){
		printf("%.0f ", vet[i]);
	}
	printf("\n\n");
}
