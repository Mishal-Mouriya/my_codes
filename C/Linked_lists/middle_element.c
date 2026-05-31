
#include <stdio.h>
#include <stdlib.h>

int main()
{

    //creation
    struct node 
    {
        int value;
        struct node* next;
    };

    //now creating nodes or node pointers
    
    struct node  *n1,*n2,*n3,*n4,*n5,*head,*fast,*slow,*p;
    n2 = (struct node*)malloc(sizeof(struct node));
    n3 = (struct node*)malloc(sizeof(struct node));
    n1 = (struct node*)malloc(sizeof(struct node));
    n4 = (struct node*)malloc(sizeof(struct node));
    n5 = (struct node*)malloc(sizeof(struct node));
   

    //forming links

    n1 ->next= n2;
    n2-> next=n3;
    n3->next=n4;
    head=n1; 
    
    n4->next = n5;
    n5->next = NULL ;
    int i=1;

    //Transversing through the linked list and getting value
    for(p=head;p != NULL;p = p->next)
    {
        printf("enter value of node %d",i);
        i++;
        scanf("%d",&p->value);
    }    
    
        
//Algorithm for finding the middle term;
fast =head;
slow = head;
while((fast->next!=NULL)  && (fast->next->next!=NULL)  )
{
    slow=slow->next;
    fast=fast->next->next;
}
//slow it the middle term
printf("\n\nThe value of middle node is %d",slow->value);
}