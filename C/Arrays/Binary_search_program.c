#include <stdio.h>

int main() 
{
    int n, i, key, ub, lb, mid, found;
    
    // Checking the values
    printf("Enter the no of values that u will enter:\n");
    if (scanf("%d", &n) != 1 || n < 2) 
    {
        printf("Invalid input. Please enter 2 or more values.\n");
        return 1;
    }
    
    // Taking the values of a sorted array
    printf("Enter the values of a sorted array now:\n"); 
    int arr[n]; 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Now lets recieve the value to search
    printf("Enter the value to be searched: ");
    scanf("%d", &key);

    // Logic for binary search
    ub = n - 1; // upper bound (index of last element)
    lb = 0;     // lower bound (index of first element)
    found = 0;

    // The search continues as long as a valid range (lb <= ub) exists.
    while (lb <= ub) 
    {
        mid = lb + (ub - lb) / 2;
        
        if (arr[mid] == key)
        {
            printf("The value you searched for is found at index %d\n", mid);
            found = 1; // MISTAKE 1: Moved this line BEFORE break
            break;     // Exit the loop immediately
        }
        else if (arr[mid] < key) // Key is in the upper half
        {
            lb = mid + 1; // Move lower bound to the right of mid
        }
        else // Key is in the lower half (arr[mid] > key)
        {
            ub = mid - 1; // Move upper bound to the left of mid
        }
    }

    // If it is not found, this is shown
    if (found == 0)
    {
        printf("Your requested value is not in the array.\n");
    }
    
    return 0; // Style Improvement C
}