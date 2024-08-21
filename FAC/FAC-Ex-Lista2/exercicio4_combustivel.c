#include <stdio.h>

int main(void){
    
    float route;
    float kmPerLiter;
    float fuelPrice;

    //i) o percurso (em quilômetros) da viagem;
    printf("Insira o percurso percorrido: ");
    scanf("%f", &route);

    //ii) o número de quilômetros que o carro percorre com um litro de combustível (km/l); 
    printf("\nInsira o numero de quilometros que o carro percorre com um litro de combustivel: ");
    scanf("%f", &kmPerLiter);

    //total km / 1l = tantos km

    float fuelConsume = route / kmPerLiter;

    //iii) o preço do litro do combustível.
    printf("Insira o preco do combustivel: ");
    scanf("%f", &fuelPrice);

    printf("i) %.2lf\nii) %.2lf\niii) %.2lf", route, kmPerLiter, fuelPrice);
    
    //"CM (consumo médio) = S (distância percorrida em quilômetros)/ v (quantidade de combustível utilizada em litros)"


    float totalCost = fuelConsume * fuelPrice;

    printf("\nConsumo medio de combustivel em litros: %.2lf", fuelConsume);
    printf("\nCusto total do combustivel: %.2lf", totalCost);


}