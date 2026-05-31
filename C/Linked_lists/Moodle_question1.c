/*
                        The Following is the question

Yo


Implement the following operations:

1.Insert a node based on value:
Ensure the linked list is stored in ascending order after every insertion.
Find the Middle Element of the linked list.

2.Delete every Nth node
Given N=2, delete 2nd, 4th, 6th nodes etc., from the list.

3.Display the Linked List (Call this function after every operation).

*/


#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

// --- Helper: Display the list ---
void display(struct Node* head, char* label) 
{
    printf("%s: ", label);
    struct Node* curr = head;
    if (curr == NULL) 
    {
        printf("Empty\n");
        return;
    }
    while (curr != NULL) 
    {
        printf("%d", curr->data);
        if (curr->next != NULL) 
        {
            printf(" -> ");
        }
        curr = curr->next;
    }
    printf("\n");
}

// --- Operation 1: Sorted Insertion ---
void insertSorted(struct Node** head_ref, int val) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If list is empty or new value is smaller than head
    if (*head_ref == NULL || (*head_ref)->data >= val) 
    {
        newNode->next = *head_ref;
        *head_ref = newNode;
    }
    else 
    {
        struct Node* curr = *head_ref;
        while (curr->next != NULL && curr->next->data < val) 
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    display(*head_ref, "Inserted Node");
}

// --- Operation 2: Find Middle (Fast/Slow Pointer) ---
void findMiddle(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("Middle: List is empty\n");
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) 
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("Middle Element: %d\n", slow->data);
}

// --- Operation 3: Delete every Nth node ---
void deleteEveryNth(struct Node** head_ref, int n) 
{
    if (*head_ref == NULL || n <= 0) 
    {
        return;
    }

    if (n == 1) 
    {
        struct Node* curr = *head_ref;
        while (curr != NULL) 
        {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        *head_ref = NULL;
    }
    else 
    {
        struct Node* curr = *head_ref;
        struct Node* prev = NULL;
        int count = 1;

        while (curr != NULL) 
        {
            if (count % n == 0) 
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
            else 
            {
                prev = curr;
                curr = curr->next;
            }
            count++;
        }
    }
    display(*head_ref, "After Deletion");
}

int main() 
{
    struct Node* head = NULL;

    // Testing Insertions
    insertSorted(&head, 30);
    insertSorted(&head, 10);
    insertSorted(&head, 50);
    insertSorted(&head, 20);
    insertSorted(&head, 40);

    // Finding Middle
    findMiddle(head);

    // Deleting every 2nd node (N=2)
    deleteEveryNth(&head, 2);

    return 0;
}