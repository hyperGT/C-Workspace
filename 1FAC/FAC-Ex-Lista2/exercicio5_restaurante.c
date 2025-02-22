#include <stdio.h>

int main()
{

    printf("Nos envie seu pedido: \nCachorro quente - codigo:100 - preco: 3,50\nBauru simples - codigo: 101 - preco 4,50\nBauru com ovo - codigo: 102 - preco: 5,20\nHamburger - codigo: 103 preco: 3,00\nCheeseburger - codigo: 104 - preco: 4,00\nRefrigerante - codigo: 105 preco: 2,50");

    int orderID;
    printf("\nDigite o codigo do pedido: ");
    scanf("%d", &orderID);

    switch (orderID)
    {
    case 100:
        printf("\nCachorro quente registrado\n");
        printf("Preço: R$3,50");
        break;
    case 101:
        printf("\nBauru simples registrado\n");
        printf("Preço: R$4,50");
        break;
    case 102:
        printf("\nBauru com ovo registrado\n");
        printf("Preço: R$5,20");
        break;
    case 103:
        printf("\nHamburguer registrado\n");
        printf("Preço: R$3,00");
        break;
    case 104:
        printf("\nCheeseburguer registrado\n");
        printf("Preço: R$4,00");
        break;
    case 105:
        printf("\nRefrigerante registrado\n");
        printf("Preço: R$2,50");
        break;
    default:
        printf("\nPedido invalido ou indisponivel no momento");
        break;
    }
}