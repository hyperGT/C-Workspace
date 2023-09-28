#include <stdio.h>

int main()
{
    int a, b, c;
    int i;

    printf("Digite o valor de i (1, 2 ou 3): ");
    scanf("%d", &i);

    printf("Digite três valores a, b e c separados por espaço: ");
    scanf("%d %d %d", &a, &b, &c);

    if (i == 1)
    {
        if (a <= b && a <= c)
        { // se a é maior que b e b > c
            printf("%d %d %d", a, (b <= c) ? b : c, (b > c) ? b : c);
        }
        else if (b <= a && b <= c)
        {
            printf("%d %d %d", b, (a <= c) ? a : c, (a > c) ? a : c);
        }
        else
        {
            printf("%d %d %d", c, (a <= b) ? a : b, (a > b) ? a : b);
        }
    }
    else if (i == 2)
    { // ordem decrescente
        if (a >= b && a >= c)
        {
            printf("%d %d %d", a, (b >= c) ? b : c, (b < c) ? b : c);
        }
        else if (b >= a && b >= c)
        {
            printf("%d %d %d", b, (a >= c) ? a : c, (a < c) ? a : c);
        }
        else
        {
            printf("%d %d %d", c, (a >= b) ? a : b, (a < b) ? a : b);
        }
    }
    else if (i == 3)
    {
        if (b >= a && b >= c)
        {
            // 2 comparações feitas : composições: a, b, c && c, b, a
            printf("%d %d %d", (a <= c) ? a : c, b, (a > c) ? a : c);
        }
        else if (a >= b && a >= c)
        {
            printf("%d %d %d", (b <= c) ? b : c, a, (b > c) ? b : c);
        }
        else if (c >= a && c >= b)
        {
            printf("%d %d %d", (a <= b) ? a : b, c, (a > b) ? a : b);
        }
    }
    else
    {
        printf("O valor de i deve estar entre 1 a 3");
    }
    return 0;
}