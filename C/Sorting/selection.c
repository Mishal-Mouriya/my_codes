//Yaay selection sort


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

void selectionsort()
{
    int i, j, min_idx, tmp;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            // Use '>' for Descending, '<' for Ascending
            if (arr[j] > arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            tmp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = tmp;
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

    selectionsort();

    printf("\nFinal sorted array: ");
    display();
    printf("\n");

    free(arr);
    return 0;
}