#include <stdio.h>
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
	int tempo, codigo;		
};
typedef struct type_atleta tAtleta;


/* Fun��es �teis */
int divisaoInteira(int dividendo, int divisor, int *quoc, int *resto);
int converterHorario(int minutos, int *rHoras, int *rMinutos);

/* Fun��es para ordena��o */
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
		
		if(vAtleta[j].tempo < vAtleta[pMenor].tempo){
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

/*
* Fun��es relacionadas � estrutura atleta
*/
void obtemMaiorTempo(int tempo, int *qtMaior, int *maiorT); // de treino

void cadastrarAtleta(int index, tAtleta *atleta){
	
	// definindo o c�digo do atleta
	atleta->codigo = 10 + index;
	
	// definindo o tempo de conclus�o da corrida ou tempo total de treino
	printf("Insira o tempo do atleta n�%d: ", index);
	scanf("%i", &atleta->tempo);
	
	return;
}

void exibeAtletas(tAtleta *vAtletas, int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("\n===========\nCod do %d� Atleta: %d\nTempo percorrido: %dmin\n", i+1, vAtletas[i].codigo, vAtletas[i].tempo);
	}
	printf("\n\n");
}

int main(){
	
	tAtleta vetAtletas[TAM];
	int tHoras, 
	tMinutos, 
	maiorTreino = -1, // maior tempo de treino
	qtMaiorTreino = 0; // quantidade de atletas que o fizeram
	
	int i;
	for(i=0;i<TAM;i++){				
		cadastrarAtleta(i+1, &vetAtletas[i]);
		
		obtemMaiorTempo(vetAtletas[i].tempo, &qtMaiorTreino, &maiorTreino);
		
		converterHorario(vetAtletas[i].tempo, &tHoras, &tMinutos);		
		printf("\n===========\nCod do %d� Atleta: %d\nTempo percorrido: %02ih:%02im\n\n", i+1, vetAtletas[i].codigo, tHoras, tMinutos);
	}
	
	// exibindo o maior tempo de treino e quantos atletas o fizeram
	printf("Maior tempo: %i\n", maiorTreino);
	printf("Qnt de atletas que o fizeram: %i", qtMaiorTreino);
	
	exibeAtletas(vetAtletas, TAM);
	ordenarAtletas(vetAtletas, TAM);
	exibeAtletas(vetAtletas, TAM);
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

int divisaoInteira(int dividendo, int divisor, int *quoc, int *resto){
	
	if(divisor == 0){
		return -1;
	}
	
	*quoc = dividendo / divisor;
	*resto = dividendo % divisor;
	
	return 1;		
}

int converterHorario(int minutos, int *rHoras, int *rMinutos){
	
	if(divisaoInteira(minutos, 60, rHoras, rMinutos) > 0){		
		return 1;
	}else{
		return -1;
	}
	
}
