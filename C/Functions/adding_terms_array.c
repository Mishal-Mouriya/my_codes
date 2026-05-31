#include <stdio.h>

int sum_array(int a[],int);

int main()
{
    int i,n,sum;
    //intializing array

    printf("enter the no of terms in the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the values of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }


    printf("\nsum of the array is %d",sum_array(arr,n));

    
    //printing the values of array to check if function modified it
    printf("Now the elements of array are>\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}



int sum_array(int arr[],int n)
{
    int sum=0,i;
    for(i=0;i<n;i++)
    {
        sum = sum + arr[i];
        arr[i]=1;//Testing for reference call
    }

    return sum;

}