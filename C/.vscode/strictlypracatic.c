//this is strictly for practife only lets go 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};


int main()
{
    int key,value,data,i,k,j,choice;

    printf("Select your choice: 1. Insert \n2. Find Middle \n3. Delete every Nth node \n4. Display \n5. Exit"\n);

    while(choice!=5)
    {
        printf("Enter choice>");
        scanf("%d",&choice);

        if(choice==1)
        {
            //Insertion
            printf("enter key to insert");
            scanf("%d",&key);
            
            

        }
    }

}