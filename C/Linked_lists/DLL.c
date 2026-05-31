//Doubly linked list dynamic creation and insertion ascending order

#include<stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;

void display()
{
    struct node *p;
    for(p=head;p->next!=NULL;p=p->next)
    {
        printf("%d->",p->value);
    }
    printf("%d->null",p->value);
    printf("\n");
}



int main()
{
    //insertion in ascending order but for double linked list;

    struct node *new1=NULL,*p;
    int val,choice=0;


    while(choice!=2)
    {
        printf("Enter 1 to insert and 2 to exit\n");
        scanf("%d",&choice);

        if(choice==1)
        {
            //insertion
            printf("enter the value for linked list\n");
            scanf("%d",&val);

            //creation of new1 node
            struct node *new1 = (struct node*)malloc(sizeof(struct node));
            new1->value=val;
            new1->prev=NULL;
            new1->next=NULL;

            //now conditions for insertion
            if(head == NULL)
            {
                head = new1;
                continue;
            }

            else if(head->value > new1->value)
            {
                //insertion at the beginning
                new1->next=head;
                head->prev=new1;
                head=new1;
            }

            else
            {
                for(p=head;p!=NULL;p=p->next)
                {
                    if((p->next==NULL)&&(new1->value > p->value))
                    {
                        //insertion at the end
                        p->next=new1;
                        new1->prev=p;
                    }
                    else if((p->value<new1->value)&&(p->next->value>new1->value))
                    {
                        //insertion in the middle
                        new1->next=p->next;
                        new1->prev=p;
                        p->next->prev=new1;
                        p->next=new1;
                    }
                }


            }

        }
        display();


    }
    

}