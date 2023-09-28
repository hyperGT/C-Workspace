#include <stdio.h>

int main() {

    float earthWeight;
    int planetNum;
    float planetGravity;
    float planetWeight;

    printf("\n1 - Mercurio\n2 - Venus\n3 - Marte\n4 - Jupiter\n5 - Saturno\n 6 - Urano");

    printf("\nEscolha um planeta digitando um numero de 1 a 6: ");
    scanf("%d", &planetNum);

    printf("\nInsira o peso do corpo na terra: ");
    scanf("%f", &earthWeight);

    if(planetNum == 1){
        planetGravity = 0.37;
    }
    else if (planetNum == 2)
    {
        planetGravity = 0.88;
    }
    else if (planetNum == 3)
    {
        planetGravity = 0.38;
    }
    else if (planetNum == 4)
    {
        planetGravity = 2.64;
    }
    else if (planetNum == 5)
    {
        planetGravity = 1.15;
    }
    else if (planetNum == 6)
    {
        planetGravity = 1.17;
    }
    else
    {
        printf("Insert a valid number!");
    }

    planetWeight = (earthWeight/10) * planetGravity; 
    
    printf("%.2lf", planetWeight);

    return 0;
}