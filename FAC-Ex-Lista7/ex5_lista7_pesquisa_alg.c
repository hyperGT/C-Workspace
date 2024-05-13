/*
QUESTÃO 05: Uma pesquisa foi feita
coletando informações (idade, altura e
peso) de um grupo de pessoas.
Pede-se a implementação de um programa
que proceda com a leitura de tais
informações (até que o usuário opte por
concluir a entrada de dados) e calcule:
- A quantidade de pessoas com idade
superior a 50 anos;
- A média de altura das pessoas com mais de
80 kg;
- O maior peso dentre as pessoas acima de
1.65 m de altura e com idade inferior a 30
anos.
*/

#include<stdio.h>
#include<ctype.h>


int main(){
	
	int idade, cont50=0, contAlt80=0;
	float altura, peso, mediaAltura80, somaAltura, maiorPeso=0;
	char resp;
	
	
	while(resp != 'N'){
		
		//obtendo a idade
		printf("Informe a idade: ");
		scanf("%d", &idade);
		
		if(idade>50){
			cont50++;
		}
		
		//obtendo o peso
		printf("Informe o peso: ");
		scanf("%f", &peso);
		
		//obtendo a altura
		printf("Informe a altura: ");
		scanf("%f", &altura);
		
		// Somando a altura das pessoas com mais de 80 kg para calcular a média dps
		if(peso > 80.0){
			
			contAlt80++;
			somaAltura += altura;
		}
		
		// obtendo o maior peso dentre as pessoas acima de 1.65 m de altura e com idade inferior a 30 anos.
		if(altura > 1.65 & idade < 30){
			
			if(peso > maiorPeso){
				maiorPeso = peso;
			}
		}
		
		//verificando se o usuario deseja continuar executando o programa			
		printf("deseja continuar? [S/N]: ");
		fflush(stdin);
		scanf("%c", &resp);
		resp = toupper(resp);
	}
	
	printf("Programa foi encerrado pelo usuario... \n");
	
	
	printf("==============\n");
	printf("Pessoas com idade superior a 50 anos: %d\n", cont50);
	
	//verificando se existe pessoas com mais de 80kg pra calcular o item b
	if(contAlt80 > 0){		
		mediaAltura80 = somaAltura/contAlt80;		
		printf("Media de altura das pessoas com mais de 80 kg: %.2f\n", mediaAltura80);		
	} else{
		printf("Nao ha ninguem que tenha mais de 80kg\n");
	
	}
	printf("O maior peso dentre as pessoas acima de 1.65 m de altura e com idade inferior a 30 anos e: %.2f\n", maiorPeso);
	printf("==============");
	
}
