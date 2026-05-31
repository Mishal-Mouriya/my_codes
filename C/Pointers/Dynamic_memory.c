//On dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //getting user input and creation of variables
    int *x,*y,*arr,n,i;
    x=(int*)malloc(sizeof(int));
    y=(int*)malloc(sizeof(int));
    printf("enter 2 nos for arithmethic purposes");
    scanf("%d%d",x,y);


    //definintg array ptr using calloc and usere input
    printf("enter the no of elements in array pointer");
    scanf("%d",&n);
    arr=(int*)calloc(n,sizeof(int));
    printf("\n Now enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);     //because arr[i] means *(arr+i) i.e it includes a dereference   
    }

    //now i got everythin so i can do whatever i want with them

    //mutiplying
    printf("the multiplication of %d and %d is %d\n\n",*x,*y,*x * *y);
    printf("writing elements in reverse order is ");

    for(i=n-1;i>=0;i--)
    {
        printf("%d",arr[i]);        
    }

    free(arr);
    free(x);
    free(y);


}
