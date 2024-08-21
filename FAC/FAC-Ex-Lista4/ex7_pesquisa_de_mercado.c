/*
Uma determinada empresa fez
uma pesquisa de mercado para saber se as
pessoas gostaram ou não de um novo
produto que foi lançado. Para cada pessoa
entrevistada foram coletados os seguintes
dados: gênero (M ou F) e resposta (G
[Gostou] ou N [Não Gostou]). Sabendo-se
que foram entrevistadas X pessoas, faça um
programa que forneça:
a) Número de pessoas que gostaram do
produto;
b) Número de pessoas que não
gostaram do produto;
c) Informação dizendo em que gênero
o produto teve uma melhor
aceitação.
*/

#include<stdio.h>
#include<ctype.h>

int main(){
	
	int gostaram, naoGostaram, quantEntrevistados, contGM=0, contGF=0, contM=0, contF=0;
	char genero, resp;
	
	printf("Insira a quantidade de entrevistados: ");
	scanf("%d", &quantEntrevistados);
	
	int i;
	for(i=1;i<=quantEntrevistados;i++){
		
		printf("Insira genero do entrevistado [M/F]: ");
		fflush(stdin);
		scanf("%c", &genero);	
		genero = toupper(genero);
		
		printf("Insira a avaliacao [G/N]: ");	
		fflush(stdin);
		scanf("%c", &resp);
		resp = toupper(resp);	
	
		//item a: Número de pessoas que gostaram do produto;
		if(genero == 'M'){
			contM++;
			if(resp == 'G'){
				contGM++;				
			} 
		}
		if(genero == 'F'){
			contF++;
			if(resp == 'G'){
			contGF++;
			} 
		}		
		
	} //fim for
	
	gostaram = contGM + contGF;
	naoGostaram = quantEntrevistados-gostaram;
	
	//item c: Descobrir em que gênero o produto teve uma melhor aceitação 
	//(pega a quatidade/porcentagem de M que gostou e F e compara)
	// como pegar porcentagem? pega a quantidade total de M ou F e a de pessoas q gostaram, 
	//divide e por fim multiplica tudo por 100
	int percF = ((float)contGF/contF)*100;
	int percM = ((float)contGM/contM)*100;
	
	printf("Gostou: %d", gostaram);
	//item b: Número de pessoas que não gostaram do produto 
		//(basta pegar o total de entrevistados e subtrair pela quantidade de pessoas que gostaram do produto)
	printf("\nNao Gostou: %d", naoGostaram);
	
	if(percF>percM){
		printf("\nO produto obteve maior aceitacao entre as mulheres");
	}else{
		if(percM>percF){
			printf("\nO produto obteve maior aceitacao entre os homens");	
		}
		else{
			printf("\nO produto obteve aceitacao igual em ambos os generos");
		}
	}

}



