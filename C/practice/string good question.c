/*Question 2=Write a C program which accepts your name as input and converts the vowels into 0 and consonants into 1, and stores the binary digits form in another integer array. The program should then compute the decimal, hexadecimal and octal equivalent of the integer array.

Sample input1: VIMALAN

Sample output1: decimal = 85, octal = 0125, hexadecimal = ox55

Sample input2: AMALAN

Sample output2: decimal = 21, octal = 025, hexadecimal = ox15*/

//Mishal Mouriya 
//ec25i1018

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{

    //All initialization
    int n,i,j,temp,digit=0;
    char str[100];    
    printf("enter your name in caps;\n");
    scanf("%s",str);
    n= strlen(str);
    int bin[n];

    //CONVERTING TO UPPERCASE STRINGS
    for(i=0;i<n;i++)
    {
        str[i]= toupper(str[i]);
    }

    //converting to binary in another string
    for(i=0;i<n;i++)
    {
        if(str[i]=='A'||str[i]=='E'||str[i]=='O'||str[i]=='I'||str[i]=='U')
        {
            bin[i]=0;
        }
        else
        {
           bin[i]=1;
        }
    }
    printf("the binary value is >>\n");

    for(i=0;i<n;i++)
    {
        printf("%d",bin[i]);
    }


    //converting to decimal
    for(i=0;i<n;i++)
    {
        digit+=bin[i]*pow(2,n-1-i);
    }

    printf("\ndecimal is %d,octal is %o,hexa is %x",digit,digit,digit);    
    return 0;
}
