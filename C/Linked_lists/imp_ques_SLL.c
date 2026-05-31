/* QUWESTION:::::


Submit a PDF file with the code and proper indentation and comments on or before 26.01.26 by 06:00 PM.

You are given a singly linked list, where each node contains:
Data (Integer)
Pointer to the next node


Implement the following operations:Insert a node based on value:
Ensure the linked list is stored in ascending order after every insertion.
Find the Middle Element of the linked list.Delete every Nth node
Given N=2, delete 2nd, 4th, 6th nodes etc., from the list.
Display the Linked List (Call this function after every operation).

 Select your choice: 1. Insert 2. Find Middle 3. Delete every Nth node 4. Display 5. Exit
Enter Choice: 1
Enter value to insert: 30
Linked List after insertion: 30

Enter Choice: 1
Enter value to insert: 10
Linked List: 10 -> 30

Enter Choice: 1
Enter value to insert: 50
Linked List: 10 -> 30 -> 50

Enter Choice: 1
Enter value to insert: 20
Linked List: 10 -> 20 -> 30 -> 50

Enter Choice: 1
Enter value to insert: 40
Linked List after insertion: 10 -> 20 -> 30 -> 40 -> 50

Enter Choice: 2
Linked List: 10 -> 20 -> 30 -> 40 -> 50
Middle Element: 30

Enter Choice: 3
Enter N: 2
Before Deletion: Linked List: 10 -> 20 -> 30 -> 40 -> 50
After Deletion: Linked List: 10 -> 30 -> 50

Enter Choice: 4
Linked List: 10 -> 30 -> 50

Enter Choice: 5
Exitin
*/





//S.Mishal mouriya 
//ec25i2021

#include <stdio.h>
#include <stdlib.h>


//defining node
struct node 
{
    int value;       
    struct node *next; 
};

struct node *p, *head;

// Insertion Function
void insert(int val) {
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->value = val;
    new1->next = NULL; 

    if (head == NULL) 
    {
        head = new1;
    } 
    else {
        
        if (head->value >= new1->value) 
        {
            new1->next = head;
            head = new1;
        } 
        else
        {
            for (p = head; p != NULL; p = p->next) 
            {
                // Insertion at the end
                if (p->next == NULL)
                {
                    p->next = new1;
                    break; 
                }

                // Insertion in the middle
                else if (p->value <= new1->value && p->next->value >= new1->value) 
                {
                    new1->next = p->next;
                    p->next = new1;
                    break; 
                }
            }
        }
    }

    printf("%d is inserted\n", val);
}


//Function for displaying the result
void display() 
{
    printf("\n"); 
    for (p = head; p != NULL; p = p->next) 
    {
        printf("%d->", p->value);
    }
    printf("NULL\n");
}


struct node* middle()
{
    // 1. Handle empty list
    if (head == NULL) return NULL;

    struct node *slow = head;
    struct node *fast = head;

    //Hare tortoise alogorithm
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;          // Moves 1 step
        fast = fast->next->next;    // Moves 2 steps
    }

    // 4. Return AFTER the loop is finished
    return slow;
}




void del(int n) {
    
    if (head == NULL || n <= 0) return;

    
    if (n == 1) //delete everything
    {
        struct node *temp;
        while (head != NULL) 
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        return;
    }

    struct node *curr = head;
    struct node *prev = NULL;
    int i = 1; // track the current node's position

    while (curr != NULL) 
    {
        if (i % n == 0)
         {
            // 2. The Deletion Logic
            
            
            prev->next = curr->next;            
            struct node *temp = curr;
            curr = curr->next; // Move curr to the next node before freeing
            free(temp);
        }

        else 
        {
            // 3. The "Keep" Logic
            // Just move both pointers forward
            prev = curr;
            curr = curr->next;
        }
        i++; 
    }
}



int main() 
{
    //initialization

    int val, choice; 
    head = NULL;    
    int n,exit=0;

    while (exit ==0) 
    {
        //asking choice to the user
        printf("Select your choice: 1. Insert 2. Find Middle 3. Delete every Nth node 4. Display 5. Exit ");
        scanf("%d", &choice); 
        

        switch (choice) 
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val); 
                insert(val);
                display();
                break;

           
            
            case 2:
                printf("Midlle value is %d",middle()->value);
                break;

            case 3:
                printf("Enter n to delete every nth node");
                scanf("%d",&n);
                del(n);
                break;

            case 4:
                display();
                break;

            case 5:
                exit=1;
                break;            

        }
    }
    return 0;
}