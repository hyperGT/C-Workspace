/*
Uma determinada empresa fez
uma pesquisa de mercado para saber se as
pessoas gostaram ou n�o de um novo
produto que foi lan�ado. Para cada pessoa
entrevistada foram coletados os seguintes
dados: g�nero (M ou F) e resposta (G
[Gostou] ou N [N�o Gostou]). Sabendo-se
que foram entrevistadas X pessoas, fa�a um
programa que forne�a:
a) N�mero de pessoas que gostaram do
produto;
b) N�mero de pessoas que n�o
gostaram do produto;
c) Informa��o dizendo em que g�nero
o produto teve uma melhor
aceita��o.
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
	
		//item a: N�mero de pessoas que gostaram do produto;
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
	
	//item c: Descobrir em que g�nero o produto teve uma melhor aceita��o 
	//(pega a quatidade/porcentagem de M que gostou e F e compara)
	// como pegar porcentagem? pega a quantidade total de M ou F e a de pessoas q gostaram, 
	//divide e por fim multiplica tudo por 100
	int percF = ((float)contGF/contF)*100;
	int percM = ((float)contGM/contM)*100;
	
	printf("Gostou: %d", gostaram);
	//item b: N�mero de pessoas que n�o gostaram do produto 
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



