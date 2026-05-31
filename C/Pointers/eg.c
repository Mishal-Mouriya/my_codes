//How pointer changes variable
//Discusses the concept of pointer to pointer.

#include <stdio.h>

int main()
{
    int var = 9;
    int *ptr = &var;
    int y=*ptr;

    printf("\n%d",y);
    *ptr = 10;
    *ptr--;
    printf("\n%d",var);
    printf("\n%d",*ptr);

}

   