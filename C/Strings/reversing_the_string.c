//Progrm to reverse the string using a library function
//That function is strrev(s)
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[100],revs[100];
    printf("Enter the string to be reversed");
    fgets(arr,100,stdin);
    strrev(arr);
    fputs((arr),stdout);
    //Therefpre the orginal array itself is changed
}