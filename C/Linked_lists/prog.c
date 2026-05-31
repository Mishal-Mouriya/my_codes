//code to rotate doubly liked list

#include <stdio.h>
#include <stdlib.h>
//defining node

struct node 
{
    int value;       
    struct node *next;
    struct node *prev; 
};



struct node *p,*head=NULL,*tmp;



void createnode(int value)
{

    //definiyion
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->value = value;
    new1->next=NULL;
    new1->prev=NULL;


    //case 1 if new1 is first element
    if(head == NULL)
    {
        head=new1;      
    }

    else
    {   
        for(p=head;p->next!=NULL;p=p->next)
        {

        }
        p->next=new1;
        new1->prev=p;
    }

    printf("%d is inserted",value);
}



void display()
{
    printf("\n");
    for(p=head;p!=NULL;p=p->next)
        {
            printf("%d->",p->value);
        }
    printf("null");
}


void rotate()
{
    if(head==NULL)
    {
        return;
    }

    else
    {
        int tmp;
        tmp=head->value;
        for(p=head;p->next!=NULL;p=p->next)
        {
            p->value = p->next->value;
        }
        p->value = tmp; //for last term alone...        

    }
}


int main()
{

    printf("1-creat node\n,2->rotate by k\n,3->display\n,4->display\n");
    int choice=0,k,val,i;

    while(choice!=4)
    {   
        printf("Enter your choice>");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value of node>");
                scanf("%d",&val);
                createnode(val);
                display();
                printf("\n");
                break;

            case 2:
                printf("give k to rotate k times>");
                scanf("%d",&k);
                for(i=0;i<k;i++)
                {
                    rotate();
                    printf("%d rotation--\n",i+1);
                    display();
                }
                break;
            
            case 3:
                display();
                break;       


        }


    }
    //Thanks for using this program;
    

}



