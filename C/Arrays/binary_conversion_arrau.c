//revised
//Printing binary equivalent of decimal no using array

#include <stdio.h>
#include <math.h>
int main()
{
    int num,i,j,dig,n,num1;
    printf("Enter the number");
    scanf("%d",&num);
    
    num1=num;
    int arr[100];

    //converting to binary and storing in array
    i=0;

    while(num1 !=0)
    {
       arr[i]=num1%2;
        num1 = num1/2;
        i++;
    }

    //Printing the values
    printf("\n Therefore the binary no of %d is",num);

    for(j=i-1;j>=0;j--)
    {
        printf("%d",arr[j]);
    }

}