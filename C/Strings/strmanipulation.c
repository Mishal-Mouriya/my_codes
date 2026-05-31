#include <stdio.h>
#include  <string.h>
int main()
{
   //String manipulation
   char str1[100];
   char str2[200];
   
   //lets cover the seven operations
   
  strcpy(str1,"valthukal");
  strcpy(str2,str1);
  printf("%s and %s\n",str1,str2);
  
  //2
  printf("%s\n",strcat(str1,str2));
  
  //3
  printf("%s",strncat(str1,str2,180));
  
 
}