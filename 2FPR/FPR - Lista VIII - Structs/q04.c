/*
Questão 04:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.
Observação: o vetor será considerado ordenado se
estiver organizado crescentemente em função da
idade. Porém, no caso de pessoas com a mesma
idade, estas devem estar ordenadas crescentemente
pelo nome.
*/

// importação de bibliotecas
#include <stdio.h>
#include <string.h>

#define QNT 4

// definição de tipos
typedef struct{
	
	char nome[31];
	char genero;
	int idade;
	
} Tpessoa;

/* Declaração de funções */

// funções principais
int verificarOrdem (Tpessoa pessoa[], int quant);

// funções auxiliares
//int verificaIdade(Tpessoa pessoa, int p, int quant);
void preencherDados (Tpessoa pessoa[], int quant);
void exibir (Tpessoa pessoa[], int quant);

void main(){
	
	Tpessoa pessoa[QNT];
	
	preencherDados(pessoa, QNT);
	exibir(pessoa, QNT);
	
	if(verificarOrdem(pessoa, QNT) == 1){
		printf("Estao Ordenados\n");
	}else{
		printf("Nao Estao Ordenados\n");
	}
	
}

int verificarOrdem (Tpessoa pessoa[], int quant){
	
	int i;
	
	quant--;
	
	for(i=0;i<quant;i++){
		
		// verificando se a proxima pessoa é mais velha		
		if(pessoa[i].idade > pessoa[i+1].idade){
			return 0; // não está ordenado
		}else{
			
			// caso tenham a mesma idade, verificar se o nome está ordenado
			if(pessoa[i].idade == pessoa[i+1].idade){
				// comparando os nomes
				if(strcmp(pessoa[i].nome, pessoa[i+1].nome) > 0){
					return 0; // não está ordenado
				}
			}
		}
	}
	return 1; // está ordenado
}

void preencherDados (Tpessoa pessoa[], int quant){
	
	strcpy(pessoa[0].nome, "Lisa");
	pessoa[0].idade = 18;
	pessoa[0].genero = 'F';
	
	strcpy(pessoa[1].nome, "Robert");
	pessoa[1].idade = 19;
	pessoa[1].genero = 'M';
	
	strcpy(pessoa[2].nome, "Melissa");
	pessoa[2].idade = 20;
	pessoa[2].genero = 'F';
	
	strcpy(pessoa[3].nome, "Mel");
	pessoa[3].idade = 20;
	pessoa[3].genero = 'F';
}

void exibir (Tpessoa pessoa[], int quant){
	
	int i;
	
	for(i=0;i<quant;i++){
		printf("Nome: %s\n", pessoa[i].nome);
		printf("Genero: %c\n", pessoa[i].genero);
		printf("Idade: %d\n", pessoa[i].idade);
	}
	printf("\n");
}
