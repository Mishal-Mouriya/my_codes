#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next; // Fixed typo 'stuct'
};




int size;
struct node *head = NULL, *p, *tmp;

void push(int val) {
    // 1. Check for overflow first
    int i = 0;
    for (p = head; p != NULL; p = p->next) {
        i++;
    }

    if (i >= size) {
        printf("\nStack Overflow! Cannot push %d\n", val);
        return; // Fixed 'return()'
    }

    // 2. Allocate memory for the new node
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    if (new1 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new1->value = val;
    
    // 3. Insert at the beginning (Top of Stack)
    new1->next = head;
    head = new1;
    printf("Pushed %d to stack.\n", val);
}

void pop() {
    if (head == NULL) {
        printf("\nStack Underflow!\n");
        return;
    }

    // Stack always pops from the head
    tmp = head;
    printf("\nPopped element: %d\n", head->value);
    head = head->next;
    free(tmp); // Always free memory to prevent leaks
}

void display() {
    if (head == NULL) {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\n--- STACK TOP ---\n");
    for (p = head; p != NULL; p = p->next) {
        printf("|   %d   |\n", p->value); // Added p->value here
    }
    printf("---------------\n");
}

int main() {
    int choice = 0, val;
    printf("Linked List Implementation of Stacks\n");
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &size);

    while (choice != 3) {
        printf("\n1.Push  2.Pop  4.Display  3.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break; // Added missing break
            case 4:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}