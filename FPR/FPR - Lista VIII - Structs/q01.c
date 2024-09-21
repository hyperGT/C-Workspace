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

// importação de bibliotecas
#include <stdio.h>
#include <string.h>

// definindo as constantes
#define TAM 5

// definição de tipos
typedef struct{
	
	int fabricacao; // ano de fabricacao do carro
	int modelo; // ano do modelo do carro

} TAno;

typedef struct {
		
		// placa, modelo, marca, cor, quilometragem, ano modelo/fabricação valor e tipo 
		// (usado ou 0 km, conforme o valor do campo quilometragem).
		
		char placa[8];
		char modelo[11];
		char marca[11];
		char tipo[11]; 
		char cor[21];
		
		TAno ano; // struct com as informações do ano 
		
		float km; // Quilometragem do carro
		
		float valor; // valor do carro
		
} Tcarro;

// funções auxiliares
void preencherDados (Tcarro agencia[], int tam);
void atualizarDados (Tcarro estoqueCarros[], int tam);
void exibirEstoque (Tcarro estoqueCarros[], int tam);
void exibirCarro (Tcarro estoqueCarros[], int p);

// funções principais
void filtrarExibicao (Tcarro carros[], int tam, char *modelo, int aF1, int aF2, float valorLimite);
void reajustarPreco (Tcarro carros[], int tam, float aumento);
int retirarDoEstoque (Tcarro carros[], int *tam, char *placaR);

void main(){
	
	int qntCar = TAM, escolha;
	Tcarro carro[qntCar];
	
	char modeloM[11];
	int a1, a2;
	float vLimite;
	
	float pAumento;
	char placa[8];
	int r;
	
	preencherDados(carro, qntCar);
	exibirEstoque(carro, qntCar);
	
	printf("\n - 1 \n - 2 \n - 3\n\n Insira qual operacao executar: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 1:	
			
			printf("Insira o modelo: ");
			fflush(stdin);
			gets(modeloM);
			
			printf("\nInsira o intervalo de ano de fabricacao: ");
			scanf("%d %d", &a1, &a2);
			
			printf("\nInsira o valor limite: ");
			scanf("%f", &vLimite);
			
			filtrarExibicao (carro, qntCar, modeloM, a1, a2, vLimite);
			
			break;
		case 2:
			
			printf("\n\n Insira a porcentagem de reajuste: ");
			scanf("%f", &pAumento);
			
			reajustarPreco (carro, qntCar, pAumento);
			//exibirEstoque(carro, TAM);
			
			break;
		case 3:
			
			printf("\n\n Escreva a placa do carro a ser retirado: ");
			fflush(stdin);
			gets(placa);
			
			r = retirarDoEstoque (carro, &qntCar, placa);
			
			if(r>0){
				printf("\n Carro %d de placa %s, retirado com sucesso do estoque!\n\nTamanho atualizado: %d\n", r, placa, qntCar);
				exibirEstoque(carro, qntCar);
			}else{
				printf("\n Nenhum carro com essa placa encontrado\n");
			}
			
			break;
		default:
			printf("Nenhuma operacao valida inserida");
			break;
	}
}


void filtrarExibicao (Tcarro carros[], int tam, char *modelo, int aF1, int aF2, float valorLimite){
	
	/*
	i. Exibir todos os carros do modelo m, ano de
	fabricação entre a1 e a2 (inclusive), com
	valor não superior a x reais;
	*/
	
	int i, cont=0;
	
	
	for(i=0;i<tam;i++){
		
		if((strcmp(carros[i].modelo, modelo)==0) &&
		(carros[i].ano.fabricacao>=aF1) &&
		(carros[i].ano.fabricacao<=aF2) &&
		(carros[i].valor<=valorLimite)){
			
			exibirCarro (carros, i);
			cont++;
		}
	}
	
	if(cont != 0){
		printf("\n\n%d carro(s) encontrado(s)", cont);
	}else{
		printf("\n\nNenhum carro encontrado");
	}
	
}


void reajustarPreco (Tcarro carros[], int tam, float aumento){
	
	/*
	ii. Reajustar os valores de todos os carros 0
	km, considerando um aumento de p %;
	*/	
	
	int i;	
	float percent;
	
	percent = (aumento/100);
	
	for(i=0;i<tam;i++){
		
		if(carros[i].km == 0){
			// Realiza o ajuste do valor do carro
			carros[i].valor += carros[i].valor*percent;
			// Exibe-o
			exibirCarro (carros, i);
		}
	}
}

int retirarDoEstoque (Tcarro carros[], int *tam, char *placaR){
	
	/*iii. 
	Retirar do estoque um determinado veículo,
	dada a sua placa.
	*/	
	
	int i, j;
	
	i=0;
	while(i<*tam){
				
		if(strcmp(carros[i].placa, placaR)==0){
			for(j = i+1; j<*tam; j++){
				// Move os elementos subsequentes para preencher o espaço
				carros[j-1] = carros[j];
			}
			// Decrementa o tamanho do estoque
			(*tam)--;
			// Retorna o índice do carro removido
			return i;
		}
		i++;
	}
	
	// Retorna -1 se o veículo não for encontrado
	return -1;	
}


void preencherDados(Tcarro agencia[], int tam){
	
	
	//1º carro
	strcpy (agencia[0].placa, "ABC1234");
	strcpy (agencia[0].modelo, "HB20");
	strcpy (agencia[0].marca, "HYUNDAI");
	strcpy (agencia[0].cor, "PRATA");
	agencia[0].km = 20000;
	agencia[0].ano.modelo = 2016;
	agencia[0].ano.fabricacao = 2015;
	agencia[0].valor = 25000;
	strcpy (agencia[0].tipo, "USADO");	
	
	//2º carro
	strcpy (agencia[1].placa, "BCD2345");
	strcpy (agencia[1].modelo, "CIVIC");
	strcpy (agencia[1].marca, "HONDA");
	strcpy (agencia[1].cor, "BRANCA");
	agencia[1].km = 0;
	agencia[1].ano.modelo = 2022;
	agencia[1].ano.fabricacao = 2022;
	agencia[1].valor = 90000;
	strcpy (agencia[1].tipo, "0KM");	
	
	//3º carro
	strcpy (agencia[2].placa, "CDE3456");
	strcpy (agencia[2].modelo, "HB20");
	strcpy (agencia[2].marca, "HYUNDAI");
	strcpy (agencia[2].cor, "PRETA");
	agencia[2].km = 45000;
	agencia[2].ano.modelo = 2017;
	agencia[2].ano.fabricacao = 2017;
	agencia[2].valor = 35000;
	strcpy (agencia[2].tipo, "USADO");	
	
	//4º carro
	strcpy (agencia[3].placa, "EFG4567");
	strcpy (agencia[3].modelo, "HB20");
	strcpy (agencia[3].marca, "HYUNDAI");
	strcpy (agencia[3].cor, "AZUL");
	agencia[3].km = 58000;
	agencia[3].ano.modelo = 2019;
	agencia[3].ano.fabricacao = 2018;
	agencia[3].valor = 40000;
	strcpy (agencia[3].tipo, "USADO");	
	
	//5º carro
	strcpy (agencia[4].placa, "FGH5678");
	strcpy (agencia[4].modelo, "ECOSPORT");
	strcpy (agencia[4].marca, "FORD");
	strcpy (agencia[4].cor, "VERDE");
	agencia[4].km = 0;
	agencia[4].ano.modelo = 2022;
	agencia[4].ano.fabricacao = 2022;
	agencia[4].valor = 85000;
	strcpy (agencia[4].tipo, "0KM");	
	
}

void atualizarDados (Tcarro estoqueCarros[], int tam){
	int i;
	
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
		scanf("%f", &estoqueCarros[i].km);
		
		printf("Insira o valor do carro %d: ", i+1);
		scanf("%f", &estoqueCarros[i].valor);
		
		
		if(estoqueCarros[i].km > 0){ 
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
		printf("Quilometragem: %.2f\n", estoqueCarros[i].km);
		printf("Valor: %.2f\n", estoqueCarros[i].valor);
		printf("Ano de fabricacao: %d\n", estoqueCarros[i].ano.fabricacao);
		printf("Ano do modelo: %d\n", estoqueCarros[i].ano.modelo);
		printf("Tipo: %s", estoqueCarros[i].tipo);
		printf("\n\n");
		
	}
}

void exibirCarro (Tcarro carro[], int p){
		
	printf("Carro: %d\n", p+1);
	printf("Placa: %s\n", carro[p].placa);
	printf("Modelo: %s\n", carro[p].modelo);
	printf("Marca: %s\n", carro[p].marca);
	printf("Quilometragem: %.2f\n", carro[p].km);
	printf("Valor: %.2f\n", carro[p].valor);
	printf("Ano de fabricacao: %d\n", carro[p].ano.fabricacao);
	printf("Ano do modelo: %d\n", carro[p].ano.modelo);
	printf("Tipo: %s", carro[p].tipo);
	printf("\n\n");
}
