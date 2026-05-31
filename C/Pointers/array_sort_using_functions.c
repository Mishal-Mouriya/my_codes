// program to sort the array
#include <stdio.h>

void sort(int *arr,int n);


int main() 
{
    int n,i;
    
    printf("Enter the no of values that u will enter\n");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input. Please enter 2 or more values.\n");
        return 1;
    }
    
    // Taking the values
    printf("enter the values now\n");
    int arr[n]; 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr,n);


    //now the array is sorted since it is a pointer changes made in function are permanent.

     //printing the sorted array
    printf("Hence the array is sorted--\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

}



//sorting function definition

void sort(int *arr,int n)
{
    int i,j,temp,ind;
for(i=0;i<n;i++)
    {
        
        //Finding min and exchange its value with the first of unsorted array
        ind = i;
        for(j=i;j<n;j++)
        {
            if(arr[j]<arr[ind])
            {
                ind=j;
            }
        }
    
        temp = arr[i];
        arr[i]=arr[ind];
        arr[ind]=temp;
    }
}