#include <stdio.h>
#include <stdlib.h>

// Initialize front to -1 for an empty queue
int front = -1; 
int rear = -1;
int size;
int *qu; // Declare qu globally so functions can see it

void enqu(int val)
{   
    if(rear == size - 1)
    {
        printf("overflow\n");
        return; // Fixed: return; instead of return();
    }
    if(front == -1)
    {
        front = 0;
    }
    rear++;
    qu[rear] = val;
    printf("%d enqueued\n", val); // Fixed: added 'val' argument
}

void dequ()
{
    if(front == -1 || front > rear)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        // Removed the extra check for size-1 to keep it simple
        printf("%d dequeued\n", qu[front]);
        front++;
    }
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("queue empty\n");
        return;
    }
    int i; // Declare i
    for(i = front; i <= rear; i++) // Fixed: semicolon instead of comma
    {
        printf("%d ", qu[i]); // Fixed: removed '&' to print value
    }
    printf("\n");
}

int main()
{
    int val, choice = 0;
    printf("enter the max size of array: ");
    scanf("%d", &size);

    // FIX: Correct calloc usage to allocate the array memory
    qu = (int*)calloc(size, sizeof(int));

    printf("operations of qu>\n1.enqu\n2.dequ\n3.disp\n4.exit\n");
    
    // Minimal change: added a while loop so you can actually test it
    while(choice != 4)
    {
        printf("\nchoice> ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            printf("enter value> ");
            scanf("%d", &val);
            enqu(val);
        }
        else if(choice == 2)
        {
            dequ();
        }
        else if(choice == 3)
        {
            display();
        }
    }

    free(qu); // Freeing memory
    return 0;
}                                                                                                                                                                                                                                                                                                                                              #include <stdio.h>
#include <stdlib.h>

// Initialize front to -1 for an empty queue
int front = -1; 
int rear = -1;
int size;
int *qu; // Declare qu globally so functions can see it

void enqu(int val)
{   
    if(rear == size - 1)
    {
        printf("overflow\n");
        return; // Fixed: return; instead of return();
    }
    if(front == -1)
    {
        front = 0;
    }
    rear++;
    qu[rear] = val;
    printf("%d enqueued\n", val); // Fixed: added 'val' argument
}

void dequ()
{
    if(front == -1 || front > rear)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        // Removed the extra check for size-1 to keep it simple
        printf("%d dequeued\n", qu[front]);
        front++;
    }
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("queue empty\n");
        return;
    }
    int i; // Declare i
    for(i = front; i <= rear; i++) // Fixed: semicolon instead of comma
    {
        printf("%d ", qu[i]); // Fixed: removed '&' to print value
    }
    printf("\n");
}

int main()
{
    int val, choice = 0;
    printf("enter the max size of array: ");
    scanf("%d", &size);

    // FIX: Correct calloc usage to allocate the array memory
    qu = (int*)calloc(size, sizeof(int));

    printf("operations of qu>\n1.enqu\n2.dequ\n3.disp\n4.exit\n");
    
    // Minimal change: added a while loop so you can actually test it
    while(choice != 4)
    {
        printf("\nchoice> ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            printf("enter value> ");
            scanf("%d", &val);
            enqu(val);
        }
        else if(choice == 2)
        {
            dequ();
        }
        else if(choice == 3)
        {
            display();
        }
    }

    free(qu); // Freeing memory
    return 0;
}