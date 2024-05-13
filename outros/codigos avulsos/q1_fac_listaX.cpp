/*
Desenvolver uma função que, dado um número
inteiro n, exiba todos os números existentes no
intervalo definido por a e b (a < b), exceto
aqueles que forem múltiplos de n.
*/


/*
passo a passo:
1. Ter um valor de a e de b
2. ter o valor de n 
3. exibir todos os valores existentes no intervalo de a e b (via loop)
4. excluir todos os multiplos de n (Exemplo: n = 6, valores de a e b: 3 e 15, valores excluidos: 6, 12...)

definição de multiplos: todos os resultados possiveis de uma multiplicação M(x) de um valor por todos e 
por cada um dos numeros naturais.

testando M(6) = {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60,...}
*/

#include <stdio.h>

// prototypes
void notMuliple(int a, int b, int n);

int main(){
	
	int a, b, n;
	
	printf("Insert 'a': ");
	scanf("%d", &a);
	
	printf("Insert 'b': ");
	scanf("%d", &b);
	
	printf("Insert 'n': ");
	scanf("%d", &n);	
	
	notMuliple(a, b, n);
	
}

void notMuliple(int a, int b, int n){
	int i;
	
	for(i = a ; i <= b ; i++){
		
		//se for 3 resto de 6 for diferente de 0;;;é pq nao e multiplo
		if(i % n != 0){
		//exibindo todos os valores do intervalo a e b
		printf("%d, ", i);
		}				
	}
}


