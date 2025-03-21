#include "Tempo.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#define TAM 4

/*
* Fazer uma fun��o que dado um valor inteiro representando uma quantidade de minutos,
* converta para o formato horas:minutos.
* Desenvolver um sistema para ranquear atletas de acordo com o tempo de conclus�o da corrida
*/

/* Structs */
struct type_atleta {
	int codigo;		
	Tempo *tempo;
};
// definindo um tipo
typedef struct type_atleta tAtleta;

/* Fun��es para ordena��o */
void troca(tAtleta *a, tAtleta *b);

int selecionaMenor(tAtleta *vAtleta, int tam, int inicio);

void ordenarAtletas(tAtleta *vAtleta, int tam);

void obtemMaiorTempo(int tempo, int *qtMaior, int *maiorT);

void cadastrarAtleta(int index, tAtleta *atleta);

void exibeAtletas(tAtleta *vAtletas, int tam);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	tAtleta vetAtletas[TAM];
	int tHoras, 
	tMinutos, 
	maiorTreino = -1, // maior tempo de treino
	qtMaiorTreino = 0; // quantidade de atletas que o fizeram
	
	int i;
	for(i=0;i<TAM;i++){				
		cadastrarAtleta(i+1, &vetAtletas[i]);
		
		obtemMaiorTempo(tpo_tempoParaSegundos(vetAtletas[i].tempo), &qtMaiorTreino, &maiorTreino);
		
		printf("\n===========\nCod do %d� Atleta: %d\nTempo percorrido: ", i+1, vetAtletas[i].codigo);
		tpo_exibe(vetAtletas[i].tempo);
	}
	
	// exibindo o maior tempo de treino e quantos atletas o fizeram
	printf("Maior tempo (em segundos): %i\n", maiorTreino);
	printf("Qnt de atletas que o fizeram: %i", qtMaiorTreino);
	
	exibeAtletas(vetAtletas, TAM);
	ordenarAtletas(vetAtletas, TAM);
	exibeAtletas(vetAtletas, TAM);
}

void cadastrarAtleta(int index, tAtleta *atleta){
	
	// definindo o c�digo do atleta
	atleta->codigo = 10 + index;
	
	int min;
	// definindo o tempo de conclus�o da corrida ou tempo total de treino
	printf("Insira o tempo do atleta n�%d (em minutos): ", index);
	scanf("%i", &min);	  
	
	atleta->tempo = tpo_cria(0, min, 0);
	
	return;
}

void exibeAtletas(tAtleta *vAtletas, int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("\n===========\nCod do %d� Atleta: %d\nTempo percorrido: ", i+1, vAtletas[i].codigo);
		tpo_exibe(vAtletas[i].tempo);
	}
	printf("\n\n");
}

void troca(tAtleta *a, tAtleta *b){
	tAtleta aux = *a;
	*a = *b;
	*b = aux;
}

int selecionaMenor(tAtleta *vAtleta, int tam, int inicio){
	int pMenor;
	int j;
	
	pMenor = inicio;	// inicializa a posicao do suposto menor valor
	for(j=inicio+1;j<tam;j++){		
		if (tpo_compara(vAtleta[j].tempo, vAtleta[pMenor].tempo) < 0) {
            pMenor = j;
        }
	}
	return pMenor;
}

void ordenarAtletas(tAtleta *vAtleta, int tam){
	
	/* 
	* Do menor ao maior tempo de treino ou 
	* menor ou maior tempo de conclus�o de uma corrida
	*/
	int i, tMenor;
	for(i=0;i<tam-1;i++){
		
		tMenor = selecionaMenor(vAtleta, tam, i);
		if(tMenor != i){
			troca(&vAtleta[i], &vAtleta[tMenor]);
		}
	}
	
}

void obtemMaiorTempo(int tempo, int *qtMaior, int *maiorT){
			
	if(tempo > (*maiorT)){
		*maiorT = tempo;
		*qtMaior = 1;
	}else if(tempo == (*maiorT)){
		(*qtMaior)++;
	}
	
	return;
}
