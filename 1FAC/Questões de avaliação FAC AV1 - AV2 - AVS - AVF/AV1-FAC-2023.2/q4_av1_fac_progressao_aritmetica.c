/*

Solicita-se o desenvolvimento de um programa que
leia n valores inteiros, onde n tamb�m � fornecido
pelo usu�rio.
Ao final, o programa deve informar se os valores, na
ordem na qual foram informados, representam uma
Progress�o Aritm�tica (PA).
Nota: uma PA consiste em uma sequ�ncia de
valores iniciada por a1 (primeiro termo) e cada
novo termo � calculado a partir da soma do
anterior com um n�mero especial e constante para
a sequ�ncia, chamado raz�o da PA.

*/

/*

Primeiro o usuario entra com o valor que ser� o tamanho da P.A indicando a quantidade de numeros inteiros que se vai ler.

Um loop vai fazer com que o usu�rio possa entrar com n numeros inteiros, assim construindo uma sequencia de valores.

mas...como fazer uma verificar se � ou n�o uma P.A?

5, 10, 15, 

guarde o primeiro valor e pegue a diferen�a com o segundo, no caso acima 10 - 5 = 5. 
Pegue essa diferen�a e some com o segundo 

observe o prox valor.

quebrar essa sequencia em partes(pares: a1 com a2, a2 com a3)
*/

#include<stdio.h>

int main(){
	
	int n; 
	int valorInserido; // a3 (desnecess�rio mas o importante � estar funcionando)
	int diff1, diff2; // penultima diferen�a vs diferen�a atual
	int verify = 1; // verify = 0(false) ou 1(true) booleana
	int a1, a2;
	
	
	if(n <= 2){
		verify = 1; // sequencia de 1 ou 2 termos � sempre uma P.A
	}else{
		
		printf("Insira o valor de n: ");
		scanf("%d", &n);
		
		printf("Insira o 1� valor(a1): ");
		scanf("%d", &a1); // 5
		
		printf("Insira o 2� valor(a2): ");
		scanf("%d", &a2); // 5
		
		diff1 = a2 - a1;
		
		//printf("\nDiferen�a inicial: %d", diff1);
				
		//segundo passo: sequencia de valores
		int i = 1, cont = 3; // esse cont a� � s� pra fins de contagem
		while(i <= (n-2)){
			
			printf("\nInsira o %d� valor(a%d): ", cont, cont);
			scanf("%d", &valorInserido); // 10, 15, 20, 25
			
			//printf("\nValor inserido: %d", valorInserido);
			
			diff2 = valorInserido - a2;
			a2 = valorInserido;		
			
			//terceiro passo: verificar se � P.A ou n
			if(diff1 == diff2){
				verify = 1; // Isso significa que � uma P.A
				diff1 = diff2;
			}
			else{
				verify = 0; // deu false, logo n�o � uma P.A								
			}
	
			cont++;		
			i++;				
		}
	}
	
	if(verify == 1){
		printf("\nA sequencia digitada E uma P.A");
	}
	else if(verify == 0){
		printf("\nA sequencia digitada NAO e uma P.A");
	}
		
}

