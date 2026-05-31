//S.Mishal mouriya
//ec25i2021

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *head,*p,*tail,*tmp,*tmp1,*tmp2,*N1,*P1,*P2,*N2,*k;


void display()
{
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%d=",p->value);
    }
    printf("NULL");
    printf("\n");
}


//insert function
void insert(int x,int k)
{
    
    int ins=0,count=1;
    
    //creating node
    struct node *new1=(struct node*)malloc(sizeof(struct node));
    new1->value=x;
    
    if(k==0)
        {
            //insertion at end
            tail->next=new1;
            new1->next=NULL;
            new1->prev=tail;
            ins=1;
            tail=new1;
        }
        
    else
    {
       
        for(p=tail;p!=NULL;p=p->prev)
        {
              
            if((count==k) && (p==head))
            {
               
                //insertion at beginning
                new1->next=p;
                p->prev=new1;
                head=new1;
                ins=1;
                
            }
            
            else if(count==k)
            {
                // Insertion in the middle
                
                new1->next=p;
                new1->prev=p->prev;
                p->prev->next=new1;
                p->prev=new1;
                ins=1;
            }
           
            count++;
        }
    }
    
    
    if(ins==1){
        printf("\n%d is inserted\n",x);
    }
    else
    {
        printf("\ngive a proper value\n");
    }
    
    
}



void delete_odd()
{
    //deletion of nodes at beginning,middle and end
    
    while((head->value%2)==1)
    {
        if((head->value%2)==1)
        {
            //deletion of head
            tmp=head;
            head=head->next;
            head->prev=NULL;
            free(tmp);
        }
    }
 
    p=head;
    while(p!=NULL)
    { 
        
        
            if(p==tail)
            {
                printf("hi");
                //deletion at the end
                tmp=p;
                tail=p->prev;
                p->prev->next=NULL;
                free(tmp);
            }
            
            if((p!=tail)&&((p->value)%2==1))
            {
                //deletion in the middle
                tmp=p;
                p->prev->next=p->next;
                p->next->prev=p->prev;
                free(p);
            }
            
            //if both doesnt happen
            if(!(((p!=tail)&&((p->value)%2==1))  || ((p==tail)&&((p->value)%2==1))) )
            {
                p=p->next;
            }
            
    }

}




void swap(int a,int b)
{
    //covering the corner cases
    if((head->value==a)||(head->value==b)||(tail->value==b)||(tail->value==a))
    {
        printf("tail and head values cant be given\n");
        return;
    }
    
    
    if(a==b)
    {
        printf("both values cannot be same");
        return;
    }
    
    
    
    //finding nodes having a and b
    
   
    k=head;
    while(k!=NULL)
    {
        printf("hi");
        if(k->value==a)
        {
            tmp1=k;
            printf("a found");
        }
        
        if(k->value==b)
        {
            tmp2=k;
            printf("b found");
        }
        k=k->next;
    }
    
    //Actual swapping process

    N1=tmp1->next;
    P1=tmp1->prev;
    N2=tmp2->next;
    P2=tmp2->prev;
    
    P1->next=tmp2;
    P2->next=tmp1;
    N1->prev=tmp2;
    N2->prev=tmp1;
    
    tmp1->next=N2;
    tmp1->prev=P2;
    tmp2->next=N1;
    tmp2->prev=P1;
}






int main()
{
    
    //creating DLL
    
    struct node *n1=(struct node*)malloc(sizeof(struct node));
    struct node *n2=(struct node*)malloc(sizeof(struct node));
    struct node *n3=(struct node*)malloc(sizeof(struct node));
    struct node *n4=(struct node*)malloc(sizeof(struct node));
    struct node *n5=(struct node*)malloc(sizeof(struct node));
    
    
    n1->value=37;
    n2->value=52;
    n3->value=97;
    n4->value=62;
    n5->value=22;
    
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    
    n1->prev=NULL;
    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;
    n5->prev=n4;
    
    head=n1;
    tail=n5;
    
    
    display();
    //implementation using switch case
    int choice=0,x,k,a,b;
    
    
    
    //various choices
    while(choice!=5)
    {
        
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the value>");
                scanf("%d",&x);
                printf("enter the position>");
                scanf("%d",&k);
                insert(x,k);
                display();
                break;
                
            case 4:
                display();
                break;
                
            case 2:
                delete_odd();
                display();
                break;
                
            case 3:
                printf("enter 2 values");
                scanf("%d%d",&a,&b);
                swap(a,b);
                display();
                break;
                
                
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
    
}