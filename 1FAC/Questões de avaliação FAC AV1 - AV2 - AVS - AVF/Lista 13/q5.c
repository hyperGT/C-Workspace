/*
Questão 05:
Considerando o critério de avaliação da
FAETERJ-Rio, pede-se uma função que, dadas as
notas de um aluno, determine se ele está
aprovado (retornando 1) ou reprovado
(retornando 0).
Nota: a análise deve ser feita sobre as notas da AV1,
AV2 e, caso aplicável, da AVF também.
*/

#include <stdio.h>

// funções 
int aprovacaoAnalise(float av1, float av2, float *avF){
	
	// declaração de variaveis
	float mediaNotas, mediaFinal, avFinal;
	
	mediaNotas = (av1 + av2)/2; // obtendo a media das notas
	
	if(mediaNotas>=6){		
		return 1; // aprovado
	}else if(mediaNotas>=4){ // fazer avf
		
		printf("Media: %.1f\n", mediaNotas);
		
		printf("Insira a avf: ");
		scanf("%f", &avFinal);
		
		mediaFinal = (mediaNotas + avFinal)/2;
		
		printf("Media final: %.1f\n", mediaFinal);
		
		if(mediaFinal>=6){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
	
	
}

int main(){
	
	// declaração de variáveis
	float av1, av2, avF, resultado;
	
	printf("insira a av1: ");
	scanf("%f", &av1);
	
	printf("insira a av2: ");
	scanf("%f", &av2);	
	
	resultado = aprovacaoAnalise(av1, av2, &avF);
	
	if(resultado == 1){
		printf("Aluno aprovado");
	}else{
		printf("Aluno reprovado");
	}
		
}

