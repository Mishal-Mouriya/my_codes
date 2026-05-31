//Selection sort program hehe

#include <stdio.h>

int main() 
{
    int n, i, j,ind,temp;
    
    // Initializing the array
    printf("Enter the no of values that u will enter:\n");
    scanf("%d",&n);    
    
    printf("Enter the values of the array now\n"); 
    int arr[n]; 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //Logic of selection sort

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


    //printing the sorted array
    printf("Hence the array is sorted--\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }


}