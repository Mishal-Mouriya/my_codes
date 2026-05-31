#include <stdio.h>
#include <stdlib.h>

int front=1;
int rear=-1;
int size;

void enqu(int val)
{   
    if(rear==size-1)
    {
        printf("overflow");
        return();
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    qu[rear]=val;
    printf("%d enquesued\n");   

}

void dequ()
{
    if(front==-1 || front>rear)
    {
        printf("underflow");
        return;
    }
    else
    {
        if(front==size-1)
        {
            printf("queue is used completly");
            front++;
        }
        front++;
    }
}

void display()
{
    if(front==-1)
    {
        printf("stack empty");
        return();
    }
    for(i=front;i<=rear,i++)
    {
        printf("%d",&qu[i]);
    }
}


//reversing elements of queue using stack
int main()
{
    int val,choice=0;
    //array implementation of queue
    printf("enter the max size of array");
    scanf("%d",&size);
    int que;
    int *qu = que;

    printf("operations of qu>\n1.enqu\n2.dequ\n3.disp\n4.exit");
    
    {

        printf("\nchoice>");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("enter value>")
            scanf("%d",&val);
            enqu(val);
        }
        if(choice==2)
        {
            dequ();
        }
        if(choice==3)
        {
            display();
        }

    }

}