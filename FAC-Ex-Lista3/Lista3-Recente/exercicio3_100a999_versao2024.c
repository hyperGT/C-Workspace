#include <stdio.h>

int main(void) {
  /*
  Implementar um programa que leia um valor
inteiro n1. Se este não estiver no intervalo de
100 a 999, uma mensagem deve ser exibida ao
usuário informando que o número é inválido e,
em seguida, a execução do programa terminará.
Caso o valor esteja no intervalo definido, o

programa deverá criar um novo valor n2 (e exibi-
lo ao final) contendo os mesmos algarismos de

n1, porém em ordem crescente.
Exemplos:
n1 514
n2 145
n1 929
n2 299
n1 124
n2 124
Nota:
Como definido no enunciado, n1 consiste em um
número inteiro positivo, com 3 algarismos. n2
também será um único número!
  */

  /*=============================

  Resolução

  primeiramente inicializo as variaveis - n1 para entrada do usuario, n2 para a saida e de auxilio - 
  em seguida, a logica completa do
  algoritmo é implementada. Sei que para poder comparar os valores que compõe o
  numero por inteiro preciso iguala-los como inteiros, exemplo: valor 596,
  preciso que a centena 500 se torne uma unidade, o 90 também, já sendo o 6 uma
  unidade então não há o que fazer, depois disso, posso compara-los criando um
  algoritmo de ordenação, nesse caso fiz com a estrutura de seleção if-else. A ideia é trocar
  as posições conforme a comparação é feita. Conhecendo o funcionamento do
  algoritmo, implemento um modelo onde inicializo uma variavel temporaria logo
  após o if, para logo poder fazer as substituições.
  Assim, caso a centena atual seja maior que a dezena, a centena andaria uma
  casa para a direita e a dezena tomaria seu lugar, estando no lugar da dezena,
  comparariamos com a unidade, caso seja maior, a centena tomaria o lugar
  da unidade tambem, e por fim a dezena x unidade, a unidade estaria no lugar da
  dezena e a dezena na centena, e substituiriamos caso fosse preciso.

  ===============================*/

  // input do usuario
  int n1;
  // output
  int n2;
  // variaveis correspondentes para centenas, dezenas e unidades e auxiliar
  int centena, dezena, unidade, aux;

  printf("Insira um valor de 100 a 999: ");
  scanf("%d", &n1);

  // verificando se n1 é maior que 999 ou menor que 100
  if (!(n1 < 100 || n1 > 999)) {

    centena = n1 / 100;      // 5
    dezena = (n1 / 10) % 10; // 9
    unidade = n1 % 10;       // 9

    // a centena atual deve andar uma casa para direita
    if (centena > dezena) {
      aux = centena;
      centena = dezena;
      dezena = aux;
    }

    // a centena tem que se tornar a unidade
    if (centena > unidade) {
      aux = centena;
      centena = unidade;
      unidade = aux;
    }

    // por fim compara a dezena atual com a unidade
    if (dezena > unidade) {
      aux = dezena;
      dezena = unidade;
      unidade = aux;
    }

    n2 = (centena * 100) + (dezena * 10) + unidade; 
    // printf("%d %d %d\n", centena, dezena, unidade);

    printf("\nn1: %d\nn2: %d", n1, n2);

  } else {
    printf("Valor inválido, escolha um valor de 100 a 999");
  }

  return 0;
}
