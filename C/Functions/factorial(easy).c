//function to provide factorial
#include <stdio.h>

int factorial(int *n);    //in declaration also i have to mention i am calling in ref.

int main()
{
    int n,result;
    printf("enter the number of n\n");
    scanf("%d",&n);
    result = factorial(&n);
    printf("The result is %d\n",result);
    printf("The value of n is %d",n);
}


int factorial(int *n)
{
    int product=1,i;
    for(i=1;i<=*n;i++)
    {
        product = product*i;
    }
    *n=*n+2;//cheking for call by reference
    return product;
}