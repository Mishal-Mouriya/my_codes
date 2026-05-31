// The main mistake i made here is forgettig to reset the value of k ...therefore in each outer loop k value increased.
#include <stdio.h>
#include <stdbool.h>
void main() 
{
  int i,n,j,i_prime,n_i_prime,k=0,notfound;
  j=0;
  //PROTFRAM TO SEE WHETHER A NO CAN BE SUM OF 2 PRIME NOS
  printf("enter the no");
  scanf("%d",&n);
  
  for(i=1;i<= (n/2);i++)
  {
      //finding whether i is prime no
      for(j=1;j<=i;j++)
      {
          if(i%j==0)
          {
              k++;//no of factors
          }
      }
      
      
      if(k==2)
      {          //yes the i is prime
          i_prime=1;
      }
      
      else 
      {
          i_prime=0;
      }
      
      
      //checking for the other n0
      k=0;
      for(j=1;j<=(n-i);j++)
      {
          if((n-i) % j ==0)
          {
            k++;   
          }
      }
      
      if(k==2)
      {          //yes the i is prime
          n_i_prime =1;
      }
      
      else 
      {
         n_i_prime =0;
      }
      
      k=0;
      notfound=1;
      if(i_prime && n_i_prime)
      {
          printf("yes it is sum of prime nos %d and %d",i,n-i);
          notfound=0;
          break;
      }
      
      
  }
  
  if (notfound)
  {
      printf("sorry it is not a sum of prime nos");
  }
  
}