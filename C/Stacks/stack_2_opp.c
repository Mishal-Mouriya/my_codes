//stack in reverse...now comes from opp order
#include <stdio.h>
#include <stdlib.h>

int top , size;
int *stack; // Global pointer

void push(int value) 
{
    if (top == -1) 
    {
        printf("Overflow\n");
    } else 
    {
        top--;
        stack[top] = value;
    }
}


void pop() 
{
    if (top == size) {
        printf("Underflow\n");
    } else {
        printf("%d deleted\n", stack[top]);
        top++;
    }
}

int isFull()
 {
    return (top == -1);
}


int main()
 {
    int choice, value, i;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    top=size;

    // Allocate memory for the global pointer
    stack = (int *)malloc(size * sizeof(int));

    printf("1-insert\n2-pop\n3-display\n4-check full\n5-exit\n");
    while (choice != 5) {
        printf("\n> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                for (i = top; i >-1 ; i--) printf("%d ", stack[i]);
                break;
            case 4:
                if (isFull()) printf("Stack is full");
                else printf("Not full");
                break;
        }
    }
    free(stack); // Clean up memory
    return 0;
}