//mERGE SORT



#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;
int *tmp; // Helper array for merging

void display()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void merge(int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    // Compare and copy elements into the temporary array
    while (i <= mid && j <= ub)
    {
        // Use '>=' for Descending order
        if (arr[i] >= arr[j])
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left subarray, if any
    while (i <= mid)
    {
        tmp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right subarray, if any
    while (j <= ub)
    {
        tmp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back from tmp to the original array
    for (k = lb; k <= ub; k++)
    {
        arr[k] = tmp[k];
    }
}

void mergesort(int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergesort(lb, mid);      // Left half
        mergesort(mid + 1, ub);  // Right half
        merge(lb, mid, ub);      // Merge them together
    }
}

int main()
{
    int i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) return 0;

    // Allocate memory for both the main and helper arrays
    arr = (int*)calloc(n, sizeof(int));
    tmp = (int*)calloc(n, sizeof(int));

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    display();
    printf("\n");

    mergesort(0, n - 1);

    printf("\nSorted array (Descending): ");
    display();
    printf("\n");

    // Clean up all allocated memory
    free(arr);
    free(tmp);

    return 0;
}


