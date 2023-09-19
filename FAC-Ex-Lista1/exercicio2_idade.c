#include <stdio.h>

int main(void){

    //NOTA: Decidi fazer em ingles pq o vs code enche o saco

    int age;

    printf("Insert the swimmer age: ");
    scanf("%i", &age);

    if (age <= 4)
    {
        printf("class: infant A");        
    }
    else if (age <= 7)
    {
        printf("class: infant B");
    }
    else if (age <= 10)
    {
        printf("class: infant C");
    }
    else if (age <= 13)
    {
        printf("class: young A");
    }
    else if (age <= 17)
    {
        printf("class: young B");
    }
    else
    {
        printf("class: Adult");
    }
    
    
    
    

    return 0;
}