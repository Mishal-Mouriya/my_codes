// Online C compiler to run C program online
#include <stdio.h>

void main() 
{
int a,b;
   printf("enter 2 nos here");
   scanf("%d%d",&a,&b);
   
   
   b=a+b;
   a=b-a;
   b=b-a;
   printf("now b is %d and a is %d",b,a);
   
}
