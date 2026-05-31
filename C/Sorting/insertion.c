//Insertion sort

#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;

void display()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionsort()
{
    int i, j, key;

    // Start from the second element (index 1)
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // The element we are currently positioning
        j = i - 1;

        /* Move elements of arr[0..i-1] that are smaller than key
           to one position ahead of their current position 
           (Change '<' to '>' for Ascending order) */
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place the key at its correct position
        arr[j + 1] = key;

        printf("Iteration %d (Inserted %d) -> ", i, key);
        display();
        printf("\n");
    }
}

int main() //hellow orld i am the great ms
{
    int i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*)calloc(n, sizeof(int));

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    display();
    printf("\n\n");

    insertionsort();

    printf("\nFinal sorted array (Descending): ");
    display();
    printf("\n");

    free(arr);
    return 0;
}