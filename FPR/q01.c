/*
Q01 - Structs

Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:

i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

// definindo as constantes
#define TAM 2

//definição de tipos
typedef struct{
	
	int fabricacao; // ano de fabricacao do carro
	int modelo; // ano do modelo do carro

} Ano;

typedef struct {
		
		// placa, modelo, marca, cor, quilometragem, ano modelo/fabricação valor e tipo 
		// (usado ou 0 km, conforme o valor do campo quilometragem).
		
		char placa[8];
		char modelo[11];
		char marca[11];
		char tipo[11]; 
		char cor[21];
		
		Ano ano; // struct com as informações do ano 
		
		float quilometragem; // Quilometragem do carro
		
		float valor; // valor do carro
		
} Tcarro;

// funções auxiliares
void preencherDados(Tcarro estoqueCarros[], int tam);
void exibirEstoque(Tcarro estoqueCarros[], int tam);

// funções principais
void filtrarExibicao (Tcarro carros[], int tam, char *modelo, int aF1, int aF2, float valorLimite);

void main(){
		
	Tcarro carro[TAM];		
	int resp;
	
	char modeloM[11];
	int a1, a2;
	float vLimite;
	
	preencherDados(carro, TAM);	
	exibirEstoque(carro, TAM);
	
	printf("\n - 1 \n - 2 \n - 3\n\n Insira qual operacao executar: ");
	scanf("%d", &resp);
	
	switch(resp){
		case 1:						
			
			printf("Insira o modelo: ");
			fflush(stdin);
			gets(modeloM);
			
			printf("\nInsira o intervalo de ano de fabricacao: ");
			scanf("%d %d", &a1, &a2);
			
			printf("\nInsira o valor limite: ");
			scanf("%f", &vLimite);
			
			filtrarExibicao (carro, TAM, modeloM, a1, a2, vLimite);
			
			break;
			
		default:
			printf("Nenhuma operacao valida inserida");
	}
}


void filtrarExibicao (Tcarro carros[], int tam, char *modelo, int aF1, int aF2, float valorLimite){
	
	/*
	i. Exibir todos os carros do modelo m, ano de
	fabricação entre a1 e a2 (inclusive), com
	valor não superior a x reais;
	*/
	
	int i, cont=0;
	
	// Exibindo todos os carros do modelo m
	for(i=0;i<tam;i++){
		
		if((strcmp(carros[i].modelo, modelo)==0) &&
		(carros[i].ano.fabricacao>=aF1) &&
		(carros[i].ano.fabricacao<=aF2) &&
		(carros[i].valor<=valorLimite)){
			
			printf("Carro: %d\n", i+1);
			printf("Placa: %s\n", carros[i].placa);
			printf("Modelo: %s\n", carros[i].modelo);
			printf("Marca: %s\n", carros[i].marca);
			printf("Quilometragem: %.2f\n", carros[i].quilometragem);
			printf("Valor: %.2f\n", carros[i].valor);
			printf("Ano de fabricacao: %d\n", carros[i].ano.fabricacao);
			printf("Ano do modelo: %d\n", carros[i].ano.modelo);
			printf("Tipo: %s", carros[i].tipo);
			printf("\n\n");
			cont++;
		}
	}
	
	if(cont != 0){
		printf("\n\n%d carro(s) encontrado(s)", cont);
	}else{
		printf("\n\nNenhum carro encontrado");
	}
	
}

void preencherDados(Tcarro estoqueCarros[], int tam){
	
	int i;
	
	// 
	for(i=0; i<tam; i++){
		
		printf("Insira a placa do carro %d: ", i+1);
		fflush(stdin);
		gets(estoqueCarros[i].placa);
		
		printf("Insira o modelo do carro %d: ", i+1);
		fflush(stdin);
		gets(estoqueCarros[i].modelo);
		
		printf("Insira a marca do carro %d: ", i+1);
		fflush(stdin);
		gets(estoqueCarros[i].marca);
		
		printf("Insira a quilometragem do carro %d: ", i+1);
		scanf("%f", &estoqueCarros[i].quilometragem);
		
		printf("Insira o valor do carro %d: ", i+1);
		scanf("%f", &estoqueCarros[i].valor);
		
		
		if(estoqueCarros[i].quilometragem > 0){ 
			strcpy(estoqueCarros[i].tipo, "usado");
		}else{
			strcpy(estoqueCarros[i].tipo, "0km");
		}
		
		// Adicionando leitura do ano de fabricação e do modelo
        printf("Insira o ano de fabricacao do carro %d: ", i+1);
        scanf("%d", &estoqueCarros[i].ano.fabricacao);
        
        printf("Insira o ano do modelo do carro %d: ", i+1);
        scanf("%d", &estoqueCarros[i].ano.modelo);
	}
	
}

void exibirEstoque(Tcarro estoqueCarros[], int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		printf("Carro: %d\n", i+1);
		printf("Placa: %s\n", estoqueCarros[i].placa);
		printf("Modelo: %s\n", estoqueCarros[i].modelo);
		printf("Marca: %s\n", estoqueCarros[i].marca);
		printf("Quilometragem: %.2f\n", estoqueCarros[i].quilometragem);
		printf("Valor: %.2f\n", estoqueCarros[i].valor);
		printf("Ano de fabricacao: %d\n", estoqueCarros[i].ano.fabricacao);
		printf("Ano do modelo: %d\n", estoqueCarros[i].ano.modelo);
		printf("Tipo: %s", estoqueCarros[i].tipo);
		printf("\n\n");
		
	}
}


