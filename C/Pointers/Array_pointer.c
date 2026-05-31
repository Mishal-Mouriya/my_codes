#include <stdio.h>
int main()
{
    double *p;
    double arr[100];
    p = arr;
    arr[0]=12;
    arr[3]=98;

    printf("\n\nAddress of the arr via pointer is %p\n",p);    
    printf("Address of the arr is %p\n",arr);
    printf(" value of where its points to is %f\n",*p);
    printf("The first eleement of the array %f\n\n",arr[0]);
    p=arr+3;
    printf("The address of 3rd element is %p and the value is %f",arr+3,*p);

    //From this we can saw that a pointeer to array points at first element and exists.
    //both array and &array give the base addrees of the array
}