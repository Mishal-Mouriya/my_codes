//Alternate code for deletion of even values
//Dynamic creation
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};


// Keeping your global variables
struct node *p, *head = NULL, *tmp;


void display()
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *p;

    for (p = head; p->next != head; p = p->next)
    {
        printf("%d->", p->value);
    }
    printf("%d->head\n", p->value);                        //good
}



void create(int val)
{
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->value = val;


    if (head == NULL)
    {
        head = new1;
        new1->next = head;
    }

    else
    {
        // traversing till the last node
        for (p = head; p->next != head; p = p->next)
        {
        }
        p->next = new1;
        new1->next = head;
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

int main()
{
    int val, choice;
    printf("First lets create the linked list.\nGive 1 to add one more list and 0 to quit the process.\n");
    
    choice = 1;
    while (choice != 0)
    {
        printf("\nEnter your choice>");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter your value>");
            scanf("%d", &val);
            create(val);
            display();
        }
    }

    printf("\nNow even values will be deleted:\n");
    delete_even();
    display();

    return 0;
}

/*
1. The "Skipping" Bug
In your while loop, if you find an even value and delete it, you immediately move the pointer forward: p = p->next.
The Problem: If you have two even numbers in a row (e.g., 1 -> 2 -> 4 -> 3), your code will delete 2, then move p to point at 4. 
Because the loop then checks p->next, it will check 3 and completely skip the value 4.
The Fix: Only move p to p->next if you didn't delete a node. If you did delete a node, stay where you are and check the "new" next node.

2. The Head Deletion Issue
Your current logic handles the head at the very end of the function. If the head is even, you update it, but what if the new head is also even? 
Your current code only checks this once.
Additionally, if the list consists entirely of even numbers, the logic might get messy because p would eventually point to memory that has been freed.
*/