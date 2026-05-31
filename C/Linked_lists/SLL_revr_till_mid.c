#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

// HELPER FUNCTION: Reverses any list passed to it and returns the NEW head
struct node* reverseList(struct node* head) {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
     {
        next = curr->next; // Save next node
        curr->next = prev; // Reverse the link
        prev = curr;       // Move prev forward
        curr = next;       // Move curr forward
    }
    return prev; // The new head of the reversed list, now current is at null.
}

int main() {
    int n, i;
    struct node *head = NULL, *tail = NULL, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // 1. DYNAMIC CREATION
    for (i = 0; i < n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        printf("Value for node %d: ", i + 1);
        scanf("%d", &newNode->value);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (n < 2) 
    {
        printf("List too short to reverse segments.\n");
        return 0;
    }


    // 2. FIND MIDDLE (Tortoise and Hare)
    struct node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 3. SPLIT THE LIST    (1-2-3-4-5-6-null = 1-2-3-null,4-5-6-null)
    // 'head' starts the first half. 'secondHalf' starts the second half.
    struct node* secondHalf = slow->next;
    slow->next = NULL;
    
    // 4. REVERSE BOTH PARTS
    
    struct node* firstPartTail = head; 
    struct node* newFirstHead = reverseList(head);
    struct node* newSecondHead = reverseList(secondHalf);

    // 5. STITCH THEM BACK TOGETHER    
    firstPartTail->next = newSecondHead;

    // 6. PRINT RESULT
    printf("\nReversed till middle result:\n");
    temp = newFirstHead;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}