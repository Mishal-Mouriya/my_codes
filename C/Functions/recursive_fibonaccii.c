//eg2 finding term of fibonacci series

#include <stdio.h>

int fibp(int n);

int main()
{

    
    int n,rst;
    printf("enter the numberth term of fibonacci series");
    scanf("%d",&n);
    rst=fibp(n);
    printf("\n fibonacci term  is %d",rst);
}


int fibp(int n)
{
    int sum;
    if(n==1||n==0)
    {
        return n;
    }
    else
    {
        return fibp(n-1)+fibp(n-2);
    }
}