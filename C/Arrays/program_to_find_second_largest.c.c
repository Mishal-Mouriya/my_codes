//Program to find the largest and second largest
#include <stdio.h>

int main() 
{
    int n, larg, i, selarg;
    
    printf("Enter the no of values that u will enter\n");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input. Please enter 2 or more values.\n");
        return 1;
    }
    
    // Taking the values
    printf("enter the values now\n");
    int arr[n]; 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Initializing largest and second largest from the first two elements (Correct)
    if (arr[0] > arr[1])
    {
        larg = arr[0];
        selarg = arr[1];
    }
    else 
    {
        larg = arr[1];
        selarg = arr[0];
    }

    // Now moving on to the loop - Start from i=2 for efficiency
    // We already checked arr[0] and arr[1], so we can skip them.
    for (i = 2; i < n; i++) 
    {
        if (arr[i] > larg) // New number is strictly the largest
        {
            selarg = larg; // Old largest becomes second largest
            larg = arr[i]; // Current element becomes new largest
        }
        else if (arr[i] > selarg) // New number is between largest and second largest
        {
            // Note: We use > instead of >= to handle cases like {10, 5, 10} correctly, 
            // ensuring selarg remains 5 and doesn't get set to 10 twice.
            selarg = arr[i];
        }
    }
    
    // ⭐ Final Correction: Corrected printf syntax
    printf("Hence the largest no is %d and second largest is %d\n", larg, selarg);
    
    return 0;
}