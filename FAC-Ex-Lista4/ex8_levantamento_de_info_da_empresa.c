/*
Em uma empresa deseja-se
fazer um levantamento sobre algumas
informa��es dos seus 250 funcion�rios. Cada
funcion�rio dever� responder um
question�rio ao qual informar� os seguintes
dados: matr�cula, g�nero, idade, sal�rio e
tempo (em anos) de trabalho na empresa. A
execu��o do programa deve exibir os
seguintes itens:
a) Quantidade de funcion�rios que
ingressaram na empresa com menos
de 21 anos;
b) Quantidade de funcion�rios do
g�nero feminino;
c) M�dia salarial dos homens;
d) Matr�cula dos funcion�rios mais
antigo e mais novo.
*/


#include<stdio.h>
#include<ctype.h>

int main(){
	
	int i, matricula, idade, tempoServico, x=3;
	float salario;
	char genero;
	
	int contMenosQue21=0, contF=0, qntH=0, somaSH;
	float mediaSH;
	
	
	int maisNovo=100, maisAntigo=0, matMN, matMA;
	
	
	 
	for(i=1 ; i<=x ; i++){
				
		printf("Insira a matricula: ");
		scanf("%d", &matricula);
			
		printf("Insira o genero[M/F]: ");
		fflush(stdin);
		scanf("%c", &genero);
		genero = toupper(genero);
		
		printf("Insira a idade: ");
		scanf("%d", &idade);
		
		printf("Insira o tempo (em anos) de servico: ");
		scanf("%d", &tempoServico);
		
		printf("Insira o salario: ");
		scanf("%f", &salario);	
		
		//Obtendo quantidade de funcion�rios que ingressaram na empresa com menos de 21 anos	
		if(idade - tempoServico < 21){
			contMenosQue21++;	
		}
		
		//Obtendo quantidade de funcion�rios do g�nero feminino 
		if(genero == 'F'){
			contF++;
		}
		
		//somando o sal�rio dos homens
		if(genero == 'M'){
			qntH++;
			somaSH += salario;
		}
		
		//Obtendo a Matr�cula dos funcion�rios mais antigo e mais novo.
		if(idade > maisAntigo){ //mais novo
			maisAntigo = idade;
			matMA = matricula;
		}
		
		if(idade < maisNovo){ //mais antigo
			maisNovo = idade;
			matMN = matricula;
		}
	}
	
	//Exibindo (a) Quantidade de funcion�rios que ingressaram na empresa com menos de 21 anos
	printf("\n\nQnt de funcionarios que ingressaram com menos de 21: %d", contMenosQue21);	
	
	//M�dia salarial dos homens
	mediaSH = (float)somaSH/qntH;
	
	//Exibindo (b) Quantidade de funcion�rios do g�nero feminino
	printf("\n\nQuantidade de funcionarios do g�nero feminino: %d", contF);
	
	//Exibindo (c) M�dia salarial dos homens
	printf("\n\nM�dia salarial dos homens: %.2f", mediaSH);
	
	//Exibindo (d) a Matr�cula do funcion�rio mais antigo 
	printf("\n\nMatricula do funcionario mais antigo: %d", matMA);
	
	//Exibindo (d) a Matr�cula do funcion�rio mais novo 
	printf("\n\nMatricula do funcionario mais novo: %d", matMN);
	
}
