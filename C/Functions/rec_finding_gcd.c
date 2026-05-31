#include <stdio.h>

int rec(int n1,int n2);

int main()
{
    int n1,n2,temp;
    printf("enter 2 nos for finding hcf");
    scanf("%d%d",&n1,&n2);
    
    while(n2!=0)
    {
        temp=n2;
        n2=n1%n2;
        n1=temp;
    }
    printf("\n\n%d",n1);
    
    //now in recursion

    printf("by rec %d",rec(n1,n2));

}

int rec(int n1,int n2)
{
    int temp;
    if(n2!=0)
    {
        rec(n2,n1%n2);
    }
    else{
        return n1;
    }
}
