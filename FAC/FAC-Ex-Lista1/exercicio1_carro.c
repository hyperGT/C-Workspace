#include <stdio.h>

int main()
{

    /*O custo ao consumidor de um carro novo é a
soma do custo de fábrica com a porcentagem
do distribuidor e dos impostos (aplicados ao
custo de fábrica). Desenvolver um algoritmo
que calcule o custo ao consumidor de
determinado carro.*/

    float custoFabrica;
    float porcentagemDistribuidor;
    float porcentagemImpostos;

    // interação do usuario
    printf("Insira o custo de fabrica do carro: ");
    scanf("%f", &custoFabrica);

    printf("Insira a porcentagem do distribuidor (em decimal): ");
    scanf("%f", &porcentagemDistribuidor);

    printf("Insira a porcentagem dos impostos (em decimal): ");
    scanf("%f", &porcentagemImpostos);

    float custoConsumidor = custoFabrica + (custoFabrica * porcentagemDistribuidor) + (custoFabrica * porcentagemImpostos);

    printf("O custo ao consumidor do carro sera de: R$%.2f", custoConsumidor);
    
    return 0;
}