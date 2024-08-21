#include <stdio.h>

/*
QUEST�O 06:
        Desenvolver uma fun��o que, dado um n�mero inteiro N, calcule o valor do
        seguinte somat�rio:

                S= 1+((n-1)^1)/1! + (n-2)^2/2! + (n-3)^3/3! + ...
+1^(n-1)/((n-1)!)
*/

// prototipo da fun��o
int somatorio(int num);
int potenciacao(int exp, int base);
int fatorial(int num);

// main
int main(void) {

  // declara��o de variaveis
  int num;

  printf("Digite um n�mero: ");
  scanf("%d", &num);

  // chamando a fun��o
  int pot = somatorio(num);

  printf("%d", pot);

  return 0;
}
// fun��o
int fatorial(int num) {
  int fat = 1, i;

  // 4! = 1.2.3.4 = 24
  // la�o para calcular o fatorial
  for (i = 2; i <= num; i++) {
    fat *= i;
  }

  return fat;
}
int potenciacao(int exp, int base) {
  int i, pot = 1;

  for (i = 1; i <= exp; i++) {
    pot = pot * base;
  }

  return pot;
}

int somatorio(int num) {
  // declara��o de variaveis
  int i, j, fat = 1, soma = 1;

  // 3! = 3.2.1 = 6
  // la�o para calcular tudo

  for (i = 1; i < num; i++) {
    soma += potenciacao(i, num - 1) / fatorial(i);
  }

  return soma;
}
