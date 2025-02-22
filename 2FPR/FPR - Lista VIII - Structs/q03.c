/*
Questão 03:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre os
funcionários de uma empresa: matricula (int),
nome (string), gênero (char) e salário (float).
Pede-se uma função que, dado um gênero,
desloque todos os funcionários deste gênero
para o início do vetor (e, consequentemente, os
funcionários do outro gênero ficarão ao final do
conjunto).
*/

// importação de bibliotecas
#include <stdio.h>
#include <string.h>

// definindo tipos
typedef struct{
	
	int matricula;
	char nome[31];
	char genero;
	float salario;
	
} Tfuncionario;

/* declarando funções */

// funções principais
void moveByGenre (Tfuncionario func[], int tam, char gen);

// funções auxiliares
void funcData (Tfuncionario func[], int tam);
void exibirFunc (Tfuncionario func[], int tam);

void main(){
	
	Tfuncionario func[5];
	char gen;

	funcData(func, 5);
	exibirFunc (func, 5);
	
	printf("Insira o genero [M/F] que deseja mover para o inicio: ");
	scanf("%c", &gen);
	
	moveByGenre (func, 5, gen);
	exibirFunc (func, 5);
}

void moveByGenre (Tfuncionario func[], int tam, char gen){
	
	int i, j;
	Tfuncionario aux;
	
	// Percorre o array de funcionários
	for(i=0, j=0;i<tam;i++){
		
		// Se o gênero do funcionário for o mesmo que gen, move para a frente
		if(func[i].genero == gen){
		
			// verifica se 'i' != 'j'
			if(i != j){
				
				aux = func[j]; // guardando a posicao j em uma auxiliar
				func[j] = func[i]; // alocando o funcionario para a posicao 'j'
				func[i] = aux;	// guardando na posicao 'i' o funcionario que estava na posicao 'j'
			}
			j++; // atualiza a posição que vai receber os dados do funcionario
		}
		
	}
			
}

void exibirFunc (Tfuncionario func[], int tam){
	
	int i;
	
	for(i=0;i<tam;i++){
		
		printf("Nome: %s\n", func[i].nome);		
		printf("Matricula: %d\n", func[i].matricula);
		printf("Genero: %c\n", func[i].genero);
		printf("Salario: %.2f", func[i].salario);
		printf("\n");
	}
	printf("\n");
}

void funcData (Tfuncionario func[], int tam){
	
	// funcionario 1
	func[0].matricula = 1044;
	strcpy(func[0].nome, "River");
	func[0].genero = 'M';
	func[0].salario = 1400;
	
	// funcionario 2
	func[1].matricula = 1034;
	strcpy(func[1].nome, "Mona");
	func[1].genero = 'F';
	func[1].salario = 1800;
	
	// funcionario 3
	func[2].matricula = 1078;
	strcpy(func[2].nome, "Lisa");
	func[2].genero = 'F';
	func[2].salario = 10000;
	
	// funcionario 4
	func[3].matricula = 1022;
	strcpy(func[3].nome, "Park-Jimin");
	func[3].genero = 'M';
	func[3].salario = 1900;
	
	// funcionario 5
	func[4].matricula = 1041;
	strcpy(func[4].nome, "Clara");
	func[4].genero = 'F';
	func[4].salario = 5400;
	
}
