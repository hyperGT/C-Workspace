#include <stdio.h>

int main(){

    /*Construir um algoritmo que calcule o peso ideal
de uma pessoa, de acordo com o seu gênero e
altura, utilizando as seguintes fórmulas:
* para homens: (72.7*h)-58
* para mulheres: (62.1*h)-44.7*/

    float idealWeight;
    float height;
    int genre;

    printf("Insert your height: ");
    scanf("%f", &height);

    printf("Are you a man or a woman? (identify yourself): 1 - for a guy and 2 - for a girl ");
    scanf("%i", genre);

    if (genre == 1)
    {
        idealWeight = (72.7 * height) - 58;
        printf("Hey man pay attention! your ideal weight is %f.2f", idealWeight);
    }
    if (genre == 2)
    {
        idealWeight = (62.1 * height) - 44.7;
        printf("Hey girl pay attention! your ideal weight is %f.2f", idealWeight);
    }



    
}