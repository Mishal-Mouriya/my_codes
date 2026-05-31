//Discusses the concept of pointer to pointer.

#include <stdio.h>

int main()
{
    int var = 9;
    int *ptr = &var;

    // CORRECT DECLARATION: ptr2 is a pointer to a pointer
    int **ptr2 = &ptr; 

    printf("1. The address of var is: %p\n",ptr);
    printf("2. The value in ptr (which is addr of var) via ptr2 is: %p\n", *ptr2);
    
    // THE FIX: Use ** to jump two steps
    printf("3. The value in var is: %d\n", **ptr2); 
    printf("size of ptr is %d, size of **ptr2 is %d",sizeof(ptr),sizeof(ptr2));

    return 0;

}