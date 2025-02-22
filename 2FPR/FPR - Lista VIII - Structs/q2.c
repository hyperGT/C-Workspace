/*
Questão 02:
Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
-> Determinar a quantidade de pessoas que
fazem aniversário no mês M;
-> Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.
*/

// importação de bibliotecas
#include <stdio.h>
#include <string.h>

// declaração de constantes
#define TAM 3

// definição de tipos
typedef struct{	
	
	int dia, mes;
	
} Tdata;

typedef struct{
	
	char nome[31];
	Tdata dataNasc;
	
} Tpessoa;

/* declaração de funções */

// funções principais
int aniversariantesMes (Tpessoa pessoa[], int tam, int mes);
void exibirAniversariantes (Tpessoa pessoa[], int tam, Tdata d1, Tdata d2);

// funções auxiliares
void exibirPessoas (Tpessoa pessoa[], int tam);
void exibirPessoa (Tpessoa pessoa[], int pos);
void preencherInfos (Tpessoa pessoa[], int tam);

void main(){
	
	int m, qntAniver, esc;
	Tpessoa pessoa[TAM];
	Tdata data1, data2;
	
	preencherInfos (pessoa, TAM);	
	exibirPessoas (pessoa, TAM);
	
	printf("\n\nEscolha a operacao [1/2]: ");
	scanf("%d", &esc);
	
	switch(esc){
		case 1:
			printf("\nInsira o mes para visualizar a quantidade de aniversariantes: ");
			scanf("%d", &m);
			
			qntAniver = aniversariantesMes (pessoa, TAM, m);
			
			if(qntAniver>0){
				printf("Quantidade de Aniversariantes do mes %d: %d", m, qntAniver);
			}else{
				printf("Nenhum aniversariante encontrado nesse mes\n");
			}			
			break;
		case 2: 
			
			data1.dia = 10;
			data1.mes = 1;		//data1: 10/01
			
			data2.dia = 31;
			data2.mes = 3;		//data2: 31/3
			
			exibirAniversariantes(pessoa, TAM, data1, data2);
			
			break;
		default:
			printf("Operacao invalida inserida");
			break;
	}
	
}

int aniversariantesMes (Tpessoa pessoa[], int tam, int mes){
	
	/*
		-> Determinar a quantidade de pessoas que	
		fazem aniversário no mês M;
	*/
	
	int i, cont=0;
	
	for(i=0;i<tam;i++){
		
		if(pessoa[i].dataNasc.mes == mes){
			exibirPessoa (pessoa, i);
			cont++;
		}
	}
	return cont;
}

void exibirAniversariantes (Tpessoa pessoa[], int tam, Tdata d1, Tdata d2){
	
	int i, cont=0;
	
	for(i=0;i<tam;i++){
	
		// compara se esta entre a data 1 e a data 2, caso sim, exibe.
		if(verificaAniver (pessoa[i].dataNasc, d1, d2)==1){
			exibirPessoa (pessoa, i);
			cont++;
		}
	
	}
	
	if(cont == 0){
		printf("\n\n;-;\n\n Nenhum aniversariante no intervalo especificado\n\n");
	}
}

int verificaAniver (Tdata data, Tdata dataInicio, Tdata dataFim){
			
	// verificando se o mes esta no intervalo
	if((data.mes > dataInicio.mes) && (data.mes < dataFim.mes)){
		return 1;
	}else{
		// se os meses de d1 (inicio) e d2 (fim) forem iguais, compara os dias
		if((dataInicio.mes == dataFim.mes) && (data.dia >= dataInicio.dia) && (data.dia <= dataFim.dia)){
			return 1;
		}else{
			// se o mes do aniversariante for igual ao mes de inicio, compara o dia com o dia de inicio
			if((data.mes == dataInicio.mes) && (data.dia >= dataInicio.dia)){
				return 1;					
			}else{
				// se o mes do aniversariante for igual ao mes final, compara o dia com o dia final
				if((data.mes == dataFim.mes) && (data.dia <= dataFim.dia)){
					return 1;
				}
			}
		}			
	}
	
	return 0;	
}

void exibirPessoas (Tpessoa pessoa[], int tam){
	
	int i;
	
	for(i=0;i<tam;i++){
		printf("Nome: %s\n", pessoa[i].nome);
		printf("Data de nascimento: %d/%d ", pessoa[i].dataNasc.dia, pessoa[i].dataNasc.mes);
		printf("\n");
	}
}

void preencherInfos (Tpessoa pessoa[], int tam){
	
	strcpy(pessoa[0].nome, "Geovanna");
	pessoa[0].dataNasc.dia = 21;
	pessoa[0].dataNasc.mes = 1;
	
	strcpy(pessoa[1].nome, "Alex");
	pessoa[1].dataNasc.dia = 13;
	pessoa[1].dataNasc.mes = 1;
	
	strcpy(pessoa[2].nome, "Gabriel");
	pessoa[2].dataNasc.dia = 28;
	pessoa[2].dataNasc.mes = 3;
	
}

void exibirPessoa (Tpessoa pessoa[], int pos){
	
	printf("\n\n");
	printf("Nome: %s\n", pessoa[pos].nome);
	printf("Data de nascimento: %d/%d \n\n", pessoa[pos].dataNasc.dia, pessoa[pos].dataNasc.mes);
	
	
}
