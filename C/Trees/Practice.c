//My program 2 complete within 1 hour..
//Merge sort
#include<stdio.h>
#include<stdlib.h>

int*arr;
int*temp;

void merge(int lb,int mid,int ub)
{
    int i =lb;
    int j=mid+1;
    int k=lb;
    
    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else if(arr[i]>arr[j])
        {
             temp[k++]=arr[j++];
        }
    }
    
    //putting the ramaining elemets in the list
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=ub)
    {
         temp[k++]=arr[j++];
    }
    
    //ok now copy this to array
    for(k=lb;k<=ub;k++)
    {
        arr[k]=temp[k];
    }
}

//Merge sort function
void mergesort(int lb,int ub)
{
    if(lb<ub)
    {
        printf("hi");
        int mid = (lb+ub)/2;
        mergesort(lb,mid);
        mergesort(mid+1,ub);
        merge(lb,mid,ub);
    }
}
    

int main()
{
    int n,i,j;
    printf("enter the no of elements you want>");
    scanf("%d",&n);
    int arr1[n];
    int temp1[n];
    arr = arr1;
    temp=temp1;
    
    //getting input
    printf("enter the n values>\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Given elemetns are >>>");
      for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }

    printf("\n");
    mergesort(0,n-1);
    printf("\nsorted element list is ->");
     for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
    
    
}