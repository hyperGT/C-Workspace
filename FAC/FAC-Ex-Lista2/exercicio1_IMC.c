#include <stdio.h>

int main(){
    
    float peso;
    float altura;

  printf("Insira seu peso: ");
  scanf("%f", &peso);
  printf("Insira sua altura: ");
  scanf("%f", &altura);

  float IMC;

  IMC = peso/(altura*altura);

  if (IMC < 18.5){
    printf("Abaixo do peso.");
  }
  else if (IMC < 25){
    printf("peso ideal");
  }
  else if (IMC < 30){
    printf("sobre-peso");
  }
  else if (IMC < 35){
    printf("Obesidade grau 1");
  }
  else if (IMC < 40){
    printf("Obesidade grau 2");
  }
  else {
    printf("Obesidade grau 3");
  }
    return 0;
}