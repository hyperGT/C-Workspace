/*
Em uma empresa deseja-se
fazer um levantamento sobre algumas
informações dos seus 250 funcionários. Cada
funcionário deverá responder um
questionário ao qual informará os seguintes
dados: matrícula, gênero, idade, salário e
tempo (em anos) de trabalho na empresa. A
execução do programa deve exibir os
seguintes itens:
a) Quantidade de funcionários que
ingressaram na empresa com menos
de 21 anos;
b) Quantidade de funcionários do
gênero feminino;
c) Média salarial dos homens;
d) Matrícula dos funcionários mais
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
		
		//Obtendo quantidade de funcionários que ingressaram na empresa com menos de 21 anos	
		if(idade - tempoServico < 21){
			contMenosQue21++;	
		}
		
		//Obtendo quantidade de funcionários do gênero feminino 
		if(genero == 'F'){
			contF++;
		}
		
		//somando o salário dos homens
		if(genero == 'M'){
			qntH++;
			somaSH += salario;
		}
		
		//Obtendo a Matrícula dos funcionários mais antigo e mais novo.
		if(idade > maisAntigo){ //mais novo
			maisAntigo = idade;
			matMA = matricula;
		}
		
		if(idade < maisNovo){ //mais antigo
			maisNovo = idade;
			matMN = matricula;
		}
	}
	
	//Exibindo (a) Quantidade de funcionários que ingressaram na empresa com menos de 21 anos
	printf("\n\nQnt de funcionarios que ingressaram com menos de 21: %d", contMenosQue21);	
	
	//Média salarial dos homens
	mediaSH = (float)somaSH/qntH;
	
	//Exibindo (b) Quantidade de funcionários do gênero feminino
	printf("\n\nQuantidade de funcionarios do gênero feminino: %d", contF);
	
	//Exibindo (c) Média salarial dos homens
	printf("\n\nMédia salarial dos homens: %.2f", mediaSH);
	
	//Exibindo (d) a Matrícula do funcionário mais antigo 
	printf("\n\nMatricula do funcionario mais antigo: %d", matMA);
	
	//Exibindo (d) a Matrícula do funcionário mais novo 
	printf("\n\nMatricula do funcionario mais novo: %d", matMN);
	
}
