/*
Faça um algoritmo para calcular a conta final de
um hóspede de um hotel, considerando que:
a) Devem ser obtidos o nome do hóspede, o
tipo do apartamento utilizado (A, B, C ou D),
o número de diárias utilizadas pelo hóspede
e o valor do consumo interno do hóspede;
b) O valor da diária é determinado pela
seguinte tabela:
Tipo de Apartamento Valor da diária
A R$ 350,00
B R$ 275,00
C R$ 200,00
D R$ 150,00
c) O valor da taxa de serviço equivale a
10% da conta.
A conta a ser apresentada ao cliente deve
conter: o nome do hóspede, o tipo do
apartamento, o valor total das diárias, o
valor do consumo interno, o subtotal, o
valor da taxa de serviço e o total geral.
*/

#include<stdio.h>
#include<ctype.h>

int main(){
		
	char nome[40], tipoApt;
	int nDiarias; 
	float valorDiaria, conInterno, subtotal, valorTotalDiarias, total;
	
	//obtido o nome do hospede
	printf("Insira o nome do hospede: ");
	scanf("%s", &nome);
	
	//obtendo o tipo do apartamento
	printf("Insira o tipo do apartamento do hospede(A, B, C ou D): ");
	fflush(stdin);
	scanf("%c", &tipoApt);
	tipoApt = toupper(tipoApt);
	
	//obtendo a quantidade de diárias utilizadas pelo hóspede	
	printf("Insira a quantidade de diarias utilizadas pelo hospede: ");
	scanf("%d", &nDiarias);
	
	//obtendo o valor do consumo interno do hóspede
	printf("Insira o valor do consumo interno do hospede: ");
	scanf("%f", &conInterno);
	
	
	//atribuindo os valores da diaria de acordo com o tipo do apartamento  	
	switch(tipoApt){
		case 'A':
			valorDiaria = 350;	
			break;
		case 'B':
			valorDiaria = 275;
			break;
		case 'C':
			valorDiaria = 200;
			break;
		case 'D':
			valorDiaria = 150;
			break;
		default:
			printf("tipo de apartamento inserido nao existe");	
			break;
	}
	
	//calculando o subtotal (sem a taxa de serviço de 10%)
	valorTotalDiarias = (valorDiaria*nDiarias);
	subtotal = valorTotalDiarias + conInterno;
	
	// calculando o total (agora adicionando as taxas e os descontos caso exista)
	total = subtotal + (subtotal*0.1);

	
			
	//A conta do hóspede com nome, tipo do apartamento, o valor total das diárias, valor do consumo interno 
	printf("\n\n====Conta a pagar====");
	printf("\n\nNome do hospede: %s\n", nome);
	printf("Tipo do apartamento: %c\n", tipoApt);	
	printf("Valor total da diaria: %.2f\n", valorTotalDiarias);
	printf("Valor total do consumo interno: %.2f\n\n", conInterno);
	printf("	Subtotal: %.2f\n\n", subtotal);
	printf("	total: %.2f\n\n", total);
}
