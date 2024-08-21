#include <stdio.h>

/*
Q04_lista_IX
Fazer uma fun��o que calcule o MDC (máximo
divisor comum) entre dois n�meros.

a ser� o maior valor sempre
b ser� o menor
a % b = r
*/

int mdc(int a, int b) {
  int resto;

  // a deve sempre ser maior, portanto:
  if (a < b) {
    int aux;
    aux = b; // b, que é o maior valor
    b = a;   // b receba a que é menor
    a = aux; // a recebe aux que é o antigo valor de b
  }

  while (1) {
    resto = a % b;
    a = b; 
    b = resto; 
    printf("a=%d, b=%d, r=%d ", a, b, resto); 
    if (resto == 0) {
      break;
    }
  }
  return a;
}

int main(void) {

  int a, b;

  printf("Digite dois valores para calcular o MDC: ");
  scanf("%d %d", &a, &b);

  int resultado = mdc(a, b);
  printf("O MDC entre %d e %d e %d", a, b, resultado);

  return 0;
}


