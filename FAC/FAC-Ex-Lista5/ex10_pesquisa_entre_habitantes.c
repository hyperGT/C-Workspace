/*
Quest�o 10 - Lista V:
Foi feita uma pesquisa entre os habitantes
de uma regi�o e coletados os dados de
altura e g�nero das pessoas. Fa�a um
programa que leia as informa��es de 50
pessoas e informe:
- a maior e a menor alturas
encontradas;
- a m�dia de altura das mulheres;
- a m�dia de altura da popula��o;
- o percentual de homens na
popula��o.
*/

#include<stdio.h>
#include<ctype.h>

#define QUANT 5

int main(){
	
	//coletados os dados de altura e g�nero das pessoas.
	char genero;
	float altura, maiorAlt=0, menorAlt=100,
	mediaF, somaAltF, somaAltM, mediaAltGeral, somaAltGeral;
	int i, contF=0; //5 = 100%
	
	//TODO: lendo a qnt de habitantes que a pesquisa foi feita 
	
	for(i=1; i<=QUANT; i++){
		
		printf("Insira o genero [M/F]: ");
		fflush(stdin);
		scanf("%c", &genero);
		genero = toupper(genero);
		
		printf("Insira a altura: ");
		scanf("%f", &altura);
		
		//verificando genero e contabilizando a qnt de mulheres
		if(genero == 'F'){
			contF++;
			somaAltF+=altura;
		}
		
		if(genero == 'M'){
			somaAltM+=altura; 
		}
		
		//A maior altura encontrada
		if(altura>maiorAlt){
			maiorAlt = altura;
		} 
		else if(altura<menorAlt){ //A menor altura encontrada
			menorAlt = altura;
		}
	}
	
	//maior altura encontrada
	printf("Maior altura encontrada: %.2f\n", maiorAlt);
	
	//menor altura encontrada
	printf("Menor altura encontrada: %.2f\n", menorAlt);
	
	//A m�dia de altura das mulheres
	mediaF = somaAltF/contF;
	
	//exibindo a m�dia de altura das mulheres
	printf("Media de altura das mulheres: %.2f\n", mediaF);

	//a m�dia de altura da popula��o
	somaAltGeral = somaAltM + somaAltF;
	mediaAltGeral = somaAltGeral/QUANT;
	
	//exibindo a m�dia de altura da popula��o
	printf("Media de altura da populacao: %.2f\n", mediaAltGeral);
	
	//descobrindo o percentual de homens na popula��o.
	int qntM = QUANT-contF;
	float percM = ((float)qntM/QUANT)*100;
	//percM = ((float)(qntM-contF)/QUANT)*100;
	printf("Qnt de homens na populacao: %d\n", qntM);
	printf("Percentual de homens na populacao: %.1f", percM);
}
