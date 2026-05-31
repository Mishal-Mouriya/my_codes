//Program to reverse the array

#include <stdio.h>

int main() 
{
  
    int n,reverse,first,last,i;
    printf("Enter the no of values that u will enter\n");
    scanf("%d",&n);
    
    //Taking the values
    printf("enter the values now");
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    //see the logic now
    for(i=0;i<n/2;i++)
    {
        first = arr[i];
        last = arr[n-i];
        arr[i] = last;
        arr[n-i] = first;
    }

    printf("\n hence the reversed array is\n");

    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}