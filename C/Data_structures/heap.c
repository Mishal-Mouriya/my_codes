#include <stdio.h>
#include <stdlib.h>

// Min heap
int heap[100];
int size = 0;

void swap(int i, int j) 
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}







void insert(int key) 
{
    if (size >= 99) 
    {
        printf("Heap Overflow\n");
        return;
    }
    
    heap[++size] = key; // Insert at the end
    int i = size;

    // Bubble up / Heapify up
    // As long as we aren't at the root and the current node is smaller than parent
    while (i > 1 && heap[i] < heap[i / 2]) 
    {
        swap(i, i / 2);
        i = i / 2;
    }
}

void delete(int key)
{
    int i;

    //finding the desired term

    for(i=0;i<=size;i++)
    {
        if(heap[i]==key)
        {
            break;
        }
    }


    if(i>size)
        {
            printf("\nThe key is not found\n");
            return;
        }

    heap[i]=heap[size]; //replacing with last element to maintain complete tree
    size--;

    int parent =i/2;

    if(i>1 && heap[i]<heap[parent]) //heap up
        {
            while (i > 1 && heap[i] < heap[i / 2]) 
            {
                swap(i, i / 2);
                i = i / 2;
            }
        }

    else   //heap down
        {
            

        while(1)
        {
          
            //finding largest of parent and children
            int lkid=2*i;
            int rkid=2*i+1;
            int smallest=i;

             

            if (lkid <= size && heap[lkid] < heap[smallest])
            {
                smallest = lkdi;
            }

            if (rkid <= size && heap[rkid] < heap[smallest])
            {
                smallest = rkid;
            }

            if (smallest == i)
            {
                break;
            }

            if(smallest == i)
            {
                break;
            }
            
            swap(i,smallest);
            i=smallest;           



        }       

        }

    

    

}


void display() 
{
    printf("\nHeap contents: ");

    for (int i = 1; i <= size; i++) 
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main() 
{
    int key;
    int choice = 0;
    
    printf("1. Insertion\n2. Deletion (Not implemented)\n3. Quit\n4. Display\n");
    
    while (choice != 3)
     {
        printf("\nEnter choice> ");
        
        
        if (scanf("%d", &choice) != 1)
         {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        if (choice == 1) 
        {
            printf("Enter value to insert> ");
            scanf("%d", &key); // Added this line
            insert(key);
            display();
        }
        
        else if (choice == 4)
        {
            display();
        }

    }

    return 0;
}