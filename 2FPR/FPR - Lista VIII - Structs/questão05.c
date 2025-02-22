/*
	Quest�o 05:
		
		O hist�rico de um aluno � representado por um
		vetor de structs onde cada posi��o armazena o
		c�digo da disciplina cursada, semestre e ano
		que a cumpriu e a m�dia final na disciplina.
		Implementar uma fun��o que exiba o hist�rico
		do aluno com o seguinte formato:
		NomeDisciplina1 (c�digo1) M�diaDisciplina1
		NomeDisciplina2 (c�digo2) M�diaDisciplina2




		NomeDisciplinaN (c�digoN) M�diaDisciplinaN
		Coeficiente de rendimento: CR
		
		Observa��es:
		1. Para obter os dados da disciplina, um outro
		vetor de structs deve ser consultado. Este,
		por sua vez, armazena para cada disciplina
		do curso as seguintes informa��es: c�digo,
		nome e n�mero de cr�ditos;
		2. O coeficiente de rendimento consiste em
		uma m�dia ponderada de todos os graus
		atribu�dos �s disciplinas cursadas, onde os
		pesos s�o representados pelo n�mero de
		cr�ditos da disciplina;
		3. Todos os dados em negrito apresentados no
		formato do hist�rico devem ser obtidos a
		partir dos vetores.
*/

// importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

// definindo tipos
typedef struct{
	
	int codigo;
	char nome[31];
	int creditos;
	
} Tdisciplina;

typedef struct{
		
	Tdisciplina disciplinasCursadas;
	//int codigoDisciplina;
	int semestre;
	int ano;
	float mediaFinal;	
	
} Thistorico;

/* fun��es */

// fun��es principais
float calcularCR (Thistorico historicoNotas[], int tam);
void exibirHistorico (Thistorico historico[], int tam);

// fun��es auxiliares
void preencherDados (Thistorico historico[]);

void main(){
	
	/* Declara��o de vari�veis */
	// quantiidade de disciplinas cursadas pelo aluno
	int qntDsc = 4;
			
	// esse historico vai conter uma s�rie de informa��es, 
	// estas, declaradas no struct criado acima.
	Thistorico historicoAluno[qntDsc];
	
	preencherDados (historicoAluno);
	exibirHistorico (historicoAluno, qntDsc);
		
}

void exibirHistorico (Thistorico historico[], int tam){
	
	int i;
			
	float cr = calcularCR (historico, tam); // calculando o cr e guardando em uma variavel
	
	for(i=0;i<tam;i++){
		
		printf("Nome da Disciplina: %s\n", historico[i].disciplinasCursadas.nome); // Exibindo o nome da disciplina
		//printf("Codigo da disciplina: %d\n", historico[i].disciplinasCursadas.codigo);
		//printf("Ano cursado: %d\n", historico[i].ano);
		//printf("Semestre cursado: %d\n", historico[i].semestre);
		printf("Media Final: %.2f\n", historico[i].mediaFinal); // Exibindo a media
		//printf("Creditos necessarios: %d\n\n", historico[i].disciplinasCursadas.creditos);		
		
	}
	
	printf("Coeficiente de rendimento: %.2f\n\n", cr); // exibindo o CR	
}

float calcularCR (Thistorico historicoNotas[], int tam){
	
	int i;	
	
	float soma=0, mediaCR, somaCreditos=0;
	
	for(i=0;i<tam;i++){
		
		soma += historicoNotas[i].mediaFinal*historicoNotas[i].disciplinasCursadas.creditos;
		somaCreditos += historicoNotas[i].disciplinasCursadas.creditos;
	}
	mediaCR = soma/somaCreditos;
	return mediaCR;
}

void preencherDados(Thistorico historico[]){
	
	// dsp 1
	historico[0].ano = 2023;	
	historico[0].semestre = 2;
	historico[0].mediaFinal = 6.0;
	historico[0].disciplinasCursadas.codigo = 000001;
	historico[0].disciplinasCursadas.creditos = 6;
	strcpy(historico[0].disciplinasCursadas.nome, "1FAC");
	
	// dsp 2
	historico[1].ano = 2023;
	historico[1].semestre = 2;
	historico[1].mediaFinal = 9.5;
	historico[1].disciplinasCursadas.codigo = 000002;
	historico[1].disciplinasCursadas.creditos = 2;
	strcpy(historico[1].disciplinasCursadas.nome, "1LES");
	
	// dsp 3
	historico[2].ano = 2023;	
	historico[2].semestre = 2;
	historico[2].mediaFinal = 7.0;
	historico[2].disciplinasCursadas.codigo = 000003;
	historico[2].disciplinasCursadas.creditos = 4;
	strcpy(historico[2].disciplinasCursadas.nome, "1MAB");
	
	// dsp 4
	historico[3].ano = 2023;
	historico[3].semestre = 2;
	historico[3].mediaFinal = 6.2;
	historico[3].disciplinasCursadas.codigo = 000004;
	historico[3].disciplinasCursadas.creditos = 3;
	strcpy(historico[3].disciplinasCursadas.nome, "1MAC");
}
