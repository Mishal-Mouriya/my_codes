#include <stdio.h>

char f;

//Declaring a function
void x(char);

int main()
{
    printf("enter i for indian and f for french");
    scanf("%c",&f);
    x(f);  //using the function
}

//defining the function

void x(char f)
{
    if (f=='i')
    {
        printf("Namaste");
    }
    if (f=='f')
    {
        printf("Bonjour");
    }
}