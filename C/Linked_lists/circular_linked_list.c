//This has everything we have discussed so far



//S.Mishal Mouriya
//ec25i2021

#include <stdio.h>
#include <stdlib.h>


struct node
{
    int value;
    struct node *next;
};

struct node *p,*head,*lbo,*k,*tmp,*curr,*prev;//last before one


void display()
{
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        for(p=head;p->next != head;p=p->next)
        {
            printf("%d->",p->value);
        }
        printf("%d->",p->value);

    }    
}



void delete_even()
{
    if (head == NULL) return;

    // Step 1: Fix the Head Deletion Issue
    // We need the last node to update its 'next' pointer if the head changes
    struct node *last;
    for (last = head; last->next != head; last = last->next);

    // Using a while loop here ensures that if the NEW head is also even, it gets deleted
    //head corner case alone
    while (head != NULL && head->value % 2 == 0) //head even..
    {
        tmp = head;
        if (head->next == head) { // Only one node in list
            head = NULL;
            printf("%d (head) is deleted\n", tmp->value);
            free(tmp);
            return;
        } 
        else 
        {
            head = head->next;
            last->next = head;
            printf("%d (head) is deleted\n", tmp->value);
            free(tmp);
        }
    }

    // Step 2: Fix the "Skipping" Bug
    p = head;
    // We check p->next so we can stay at 'p' and delete the next node
    while (p != NULL && p->next != head)
    {
        if ((p->next->value) % 2 == 0)
        {
            tmp = p->next;
            p->next = p->next->next;
            printf("%d is deleted\n", tmp->value);
            free(tmp);
            // Notice: We do NOT do p = p->next here. 
            // This stays on the same node to check the new p->next.
        }
        else
        {
            p = p->next; // Only move forward if we didn't delete anything
        }
    }
}  



void reverse() //using do while loop
{
    if (head == NULL) return;

    // 1. Find the last node to act as the initial 'prev'
    p = head;
    while(p->next != head) {
        p = p->next;
    }

    prev = p;    // Original last node
    curr = head; // Original head
    
    // 2. The Reversal Loop
    struct node *next_node;
    do 
    {
        next_node = curr->next; // Save the actual next node
        curr->next = prev;      // Flip the pointer
        prev = curr;            // Move prev forward
        curr = next_node;       // Move curr forward
    } while (curr != head);

    // 3. Update the head to the last node we processed
    head = prev; 
}

void insert(int k,int val)
{
    int count=1;

    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        p=head;

        do{   
            if(count%k==0)
            {
                struct node *new1=(struct node*)malloc(sizeof(struct node));
                new1->value=val;
                new1->next=NULL;

                
                //insertion happens
                new1->next=p->next;
                p->next=new1;
                p=new1->next;
                count=1;//counter reseted
            }
            else
            {
                p=p->next;
                count++;
            }

        }while(p!=head);
        

    }
}

int main()
{
    int choice,i,k,val;
    
    //creating a linked list 
    struct node *n1=(struct node*)malloc(sizeof(struct node));
    struct node *n2=(struct node*)malloc(sizeof(struct node));
    struct node *n3=(struct node*)malloc(sizeof(struct node));
    struct node *n4=(struct node*)malloc(sizeof(struct node));
    struct node *n5=(struct node*)malloc(sizeof(struct node));

    //Assigning values
    n2->value=15;
    n3->value=20;
    n4->value=25;
    n5->value=35;
    n1->value=10;
    
    //linking
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n1;
    
    head=n1;
    
    //now lets move to choice and functions
   
    
    choice=0;
    printf("Enter Choice:\n1. Insert Node at Every Kth Position\n2. Delete Nodes with Even Values\n3. Reverse the Circular Linked List\n4. Display Linked List\n5. Exit");
    printf("\n");
    display();
    while (choice!=5)
    {
        printf("Enter choice");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
            
                printf("\nEnter the value of k");
                scanf("%d",&k);
                printf("\nEnter the value to be inserted");
                scanf("%d",&val);
                insert(k,val);
                display();
                break;
            
            case 2:
                delete_even();
                display();
                break;
            
            case 3:
                reverse();
                display();
                break;
            
            case 4:
                display();
                break;
        }
    }
    printf("Thank you for using the program");
}