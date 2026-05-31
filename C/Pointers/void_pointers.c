//concept of void pointers
#include <stdio.h>
int main()
{
    float num = 98;
    void *ptr;
    ptr=&num;

    printf("Now typecasting to float %f\n",*((float*)ptr));
    printf("Now typecasting int to character --%c\n",*((char*)ptr));
    printf("Now typecasting to integer itself %d",*((int*)ptr));
    
    //No use it will not convert or do stuff.
}