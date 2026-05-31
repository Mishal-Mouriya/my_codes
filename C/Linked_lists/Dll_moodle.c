// S.Mishal mouriya
// ec25i2021

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL;

void display() {
    struct node *p;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    for (p = head; p != NULL; p = p->next) {
        printf("%d <-> ", p->value);
    }
    printf("NULL\n");
}

// 1. Insert x at K-th position from the end
void insert_from_end(int x, int k) {
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->value = x;
    
    if (head == NULL) {
        new1->next = new1->prev = NULL;
        head = tail = new1;
        return;
    }

    struct node *curr = tail;
    int count = 1;
    
    // Traverse backwards from tail to find the K-th position
    while (curr != NULL && count < k) {
        curr = curr->prev;
        count++;
    }

    if (curr == NULL) {
        // If K is greater than list length, insert at the beginning
        new1->next = head;
        new1->prev = NULL;
        head->prev = new1;
        head = new1;
    } else if (curr == tail && k == 1) {
        // Insertion after the tail (making it the new last node)
        new1->next = NULL;
        new1->prev = tail;
        tail->next = new1;
        tail = new1;
    } else {
        // Insertion in the middle (before curr)
        new1->next = curr;
        new1->prev = curr->prev;
        if (curr->prev != NULL) curr->prev->next = new1;
        else head = new1; // Update head if curr was head
        curr->prev = new1;
    }
    printf("%d inserted at position %d from end.\n", x, k);
}

// 2. Delete nodes with odd values
void delete_odd() {
    struct node *p = head;
    while (p != NULL) {
        struct node *nextNode = p->next;
        if (p->value % 2 != 0) {
            if (p == head) {
                head = p->next;
                if (head) head->prev = NULL;
            } else if (p == tail) {
                tail = p->prev;
                if (tail) tail->next = NULL;
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            free(p);
        }
        p = nextNode;
    }
    printf("Odd values deleted.\n");
}

// 3. Swap nodes A and B (Link Swapping Only)
void swap(int a, int b) {
    if (a == b) return;

    struct node *nodeA = NULL, *nodeB = NULL, *curr = head;
    while (curr != NULL) {
        if (curr->value == a) nodeA = curr;
        if (curr->value == b) nodeB = curr;
        curr = curr->next;
    }

    if (!nodeA || !nodeB) {
        printf("One or both values not found in the list.\n");
        return;
    }

    // Capture neighbors
    struct node *prevA = nodeA->prev, *nextA = nodeA->next;
    struct node *prevB = nodeB->prev, *nextB = nodeB->next;

    // Adjust neighbors for Node A
    if (prevA) prevA->next = nodeB;
    else head = nodeB;
    if (nextA) nextA->prev = nodeB;
    else tail = nodeB;

    // Adjust neighbors for Node B
    if (prevB) prevB->next = nodeA;
    else head = nodeA;
    if (nextB) nextB->prev = nodeA;
    else tail = nodeA;

    // Swap A and B's own pointers
    // Check if nodes are adjacent to prevent circular references
    if (nodeA->next == nodeB) { // A is immediately before B
        nodeA->next = nextB;
        nodeA->prev = nodeB;
        nodeB->next = nodeA;
        nodeB->prev = prevA;
    } else if (nodeB->next == nodeA) { // B is immediately before A
        nodeB->next = nextA;
        nodeB->prev = nodeA;
        nodeA->next = nodeB;
        nodeA->prev = prevB;
    } else {
        nodeA->next = nextB;
        nodeA->prev = prevB;
        nodeB->next = nextA;
        nodeB->prev = prevA;
    }
    printf("Nodes %d and %d swapped via links.\n", a, b);
}

int main() {
    // Initializing 5 nodes manually as requested
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    struct node *n3 = (struct node*)malloc(sizeof(struct node));
    struct node *n4 = (struct node*)malloc(sizeof(struct node));
    struct node *n5 = (struct node*)malloc(sizeof(struct node));

    n1->value = 37; n2->value = 52; n3->n3; n3->value = 97; n4->value = 62; n5->value = 22;

    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
    n1->prev = NULL; n2->prev = n1; n3->prev = n2; n4->prev = n3; n5->prev = n4;

    head = n1; tail = n5;

    printf("Initial List:\n");
    display();

    int choice = 0, x, k, a, b;
    while (choice != 5) {
        printf("\n1. Insert (Pos from end)\n2. Delete Odd\n3. Swap (Links)\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and Kth position from end: ");
                scanf("%d %d", &x, &k);
                insert_from_end(x, k);
                display();
                break;
            case 2:
                delete_odd();
                display();
                break;
            case 3:
                printf("Enter values A and B to swap: ");
                scanf("%d %d", &a, &b);
                swap(a, b);
                display();
                break;
            case 4:
                display();
                break;
        }
    }
    return 0;
}