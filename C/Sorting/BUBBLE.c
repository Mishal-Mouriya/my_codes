//BUbble sort program


#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;

// Function to print the current state of the array
void display()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Bubble sort implementation
void bubblesort()
{
    int i, j, tmp;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    
    if (n == 1)
    {
        printf("Single element array is already sorted.\n");
        return;
    }

    // Outer loop runs n-1 times
    for (i = 0; i < n - 1; i++)
    {
        // Inner loop for adjacent comparisons
        for (j = 0; j < n - i - 1; j++)
        {
            // Swap if elements are in the wrong order
            // Change '<' to '>' for Ascending order
            if (arr[j] < arr[j + 1]) 
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        
        printf("Iteration %d -> ", i + 1);
        display();
        printf("\n");
    }
}

int main()
{
    int i;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Dynamic memory allocation
    arr = (int*)calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    display();
    printf("\n\n");

    bubblesort();

    printf("\nFinal sorted array (Descending): ");
    display();
    printf("\n");

    // Clean up memory
    free(arr);
    return 0;
}