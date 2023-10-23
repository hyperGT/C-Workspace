#include <stdio.h>

int main(void) {

  /*
Construir um programa que permita ao usuário
calcular a área de uma figura geométrica. Para
isto, o usuário deverá escolher a figura desejada
([C]írculo, [R]etângulo, [Q]uadrado ou
[T]riângulo) e fornecer as informações
necessárias para que a área desta figura possa
ser calculada.
Notas:
1. Fórmulas para o cálculo das áreas:
a. Acírculo = π.raio2

, onde π = 3.14159;

b. Aretângulo = base.altura;
c. Aquadrado = lado2
;
d. Atriângulo = (base.altura)/2.
2. Caso o usuário escolha uma opção inválida,
uma mensagem de erro deve ser exibida e a
execução do programa terminada.
  */

  float c, r, q, t;
  int resp;

  printf("Digite \n| 1 - Circulo \n| 2 - Retangulo \n| 3 - Quadrado \n| 4 - "
         "Triangulo \n Insira o numero corresponde a operação desejada \n |  ");
  scanf(" %d", &resp);

  float raio, PI = 3.14159; // variaveis circulo
  switch (resp) {

  case 1:
    printf("Insira o valor do raio: ");
    scanf("%f", &raio);
    c = PI * (raio * raio);
    printf("A área do circulo inserido é %.2f", c);
    break;

    float base, altura; // variaveis retangulo / triangulo

  case 2:
    printf("Insira o valor da base: ");
    scanf("%f", &base);
    printf("Insira o valor da altura: ");
    scanf("%f", &altura);
    r = base * altura;
    printf("A área do retângulo é: %.0f", r);
    break;

    float lado; // variaveis quadrado
  case 3:
    printf("Insira o valor do lado do QUADRADO: ");
    scanf("%f", &lado);
    lado *= lado;
    q = lado;
    printf("A área do Quadrado é: %.0f", q);
    break;
  case 4:
    printf("Insira a base: ");
    scanf("%f", &base);
    printf("Insira a altura: ");
    scanf("%f", &altura);
    t = (base * altura) / 2;
    printf("A area do Triangulo é: %.0f", t);
    break;

  default:
    printf("Insira uma opção válida");
    break;
  }

  return 0;
}