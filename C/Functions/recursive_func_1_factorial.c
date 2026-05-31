//eg1 finding factorial

#include <stdio.h>

int fibp(int n);

int main()
{
    int n,rst;
    printf("enter the number for which you want factorial");
    scanf("%d",&n);
    rst=fibp(n);
    printf("\n factorial is %d",rst);
}


int fibp(int n)
{
    int product;
    if(n==1||n==0)
    {
        return 1;
    }
    else
    {
        product = n*fibp(n-1);
        return product;
    }
}