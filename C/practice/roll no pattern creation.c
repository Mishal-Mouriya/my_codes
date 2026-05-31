//Mishal Mouriya 
//ec25i1018

#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j,temp;
    
    //initialiing char array
    printf("enter the no of digits of your roll no\n");
    scanf("%d",&n);
    char str[n];
    char str1[n];
    printf("Enter your roll no>\n");
    scanf("%s",str);
    
    printf("%s\n",str);

    //now switching....
    for(i=0;i<n;i++)
    {
        //now shifting all terms by one
        temp=str[0];
        for( j=0;j<n-1;j++)//j stores  the index values.
        {
            str[j]=str[j+1];
        }
        str[n-1]=temp;

        //printing the shifted terms
        printf("%s\n",str);
    }
    return 0;
}