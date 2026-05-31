#include <stdio.h>

int search(int arr[],int key,int n);


int main()
{
    int i,n,returnvalue,key;
    //intializing array

    printf("enter the no of terms in the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the values of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the key you want to find in the array");
    scanf("%d",&key);

    returnvalue = search(arr,key,n);

    if(returnvalue!=0)
    {
        printf("The key is found at value %d",returnvalue);
    }
    else
    {
        printf("sorrry the key is not found");
        
    }
}

int search(int arr[],int key,int n)
{
    int i,index,mid,lb=0,ub=n-1,found;

    //using binomial search for revison



    found=0;
    while(lb<=ub)
    {
        mid=lb+(ub-lb)/2;

        if(arr[mid] == key)
        {
            found=1;
            break;            
        }
        else if(arr[mid]<key)
        {
            lb=mid+1;
        }
        else if(arr[mid]>key)
        {
            ub=mid-1;
        }

    }

    if(found==1)
    {
      return mid;
    }
    else
    {
        return 0;
    }    

}