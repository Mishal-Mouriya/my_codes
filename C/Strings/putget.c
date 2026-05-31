#include <stdio.h>
#include <string.h>

int main()
{
    //See the slide and come hahahahahahahahah!!!!!
    char arr[100];
    printf("Enter the string to be printed\n");
    gets(arr);
    
    printf("The string is with length =%d--\t",strlen(arr));
    puts(arr);

    printf("Now using fgets and futs.Enter a string\n");
    fgets(arr,100,stdin);
    printf("The string is with lenth =%d--\t",strlen(arr));
    fputs(arr,stdout);
    printf("to see whether it has /n");

}