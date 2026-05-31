#include <stdio.h>
int main() 
{
    int i,j,k,size,rows,columns;
//program to build a cross shape

rows=20;
columns=20;
for(i=1;i<=rows;i++)
{
    for(j=1;j<=columns;j++)
    {
        if((j==i)||(j==columns-i)||(i==rows)||(i==1))
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
}
return 1;
}