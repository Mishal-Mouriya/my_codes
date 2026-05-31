// Online C compiler to run C program online
//just put %d and display values but i am too lazy to do that 
#include <stdio.h>
void main()
{
   int n1,n2,n3;
   printf("enter 3 nos");
   scanf("%d%d%d",&n1,&n2,&n3);


   if(n1>n2)
   {
      if(n1>n3) 
           {
         printf("n1 is the greates");
      
      }
      else
      {
         printf("n3 is the greatest");
      }
   }
   else
   {
      if (n2>n3)
      {
         printf("n2 is the greatst");
      }
      else
      {
         printf("n3 is the greatest");
      }
   }
}