//Hence successfully completed it!!

#include <stdio.h>

//swap function

 void swap(int *a, int*b)
{
    int temp;
    temp=*a;
    *a = *b;
    *b = temp;
}


int main() 

{
    int n,i,j,temp,swaphap=1;
    
    // Initializing the array

    printf("Enter the no of values that u will enter:\n");
    scanf("%d",&n);    
    
    printf("Enter the values of the array now\n"); 
    int arr[n]; 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }


    //Logic Bubble sort for ascening order 

   while (swaphap == 1) //while swaphappens
   {

    swaphap =0;
    for(i=1;i<n;i++)
    {   
        if(arr[i-1]>arr[i])
        {
            swap(&arr[i-1],&arr[i]);
            swaphap=1;
        }
    }
   }


   //printing th matrix
   printf("Hence the array is sorted--\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

}

