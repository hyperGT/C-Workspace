/*
QUEST�O 07:
Desenvolver um programa no qual o
usu�rio entre com v�rios n�meros inteiros
e positivos e imprima o produto(resultado da multiplica��o) dos
n�meros �mpares e a soma dos n�meros
pares.
*/

#include<stdio.h>

int main(){
		
	int n=1, prodImp=1, somaPos=0, contI=0;
	
	
	
	while(n>0){ //para quando o usuario digitar um valor negativo

		printf("Insira um numero inteiro: ");
		scanf("%d", &n);

		if(n>0){			
			if(n%2!=0){
				prodImp*=n;
				contI++;
			}else{
				somaPos+=n;
			}
		}

	}

	//exibindo a soma dos pares
	printf("\nSoma dos pares: %d", somaPos);

	if(contI>0){ // exibindo o produto dos impares
		printf("\nProduto dos Impares: %d", prodImp*1);
	}else{
		printf("\nProduto dos Impares: %d", contI);	
	}
	
	printf("\n\n");
}
