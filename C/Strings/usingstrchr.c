#include <stdio.h>          // Standard Input/Output library
#include <string.h>         // Required for the strchr() function

int main()
{
    char arr[100];          // The "Street" (array) to hold text
    char target;            // The character we want to find
    char *addresst;        // Variable to hold the ADDRESS found

    // --- 1. INPUT THE STRING ---

    printf("Enter string: ");
    fgets(arr, 100, stdin); // Reads text (keeps the \n at end)

    // --- 2. INPUT THE TARGET CHAR ---
    
    printf("Find char: ");
    // Note the space " %c". It skips the \n left by fgets
    scanf(" %c", &target);  

    // --- 3. THE SEARCH (strchr) ---
    // Looks for 'target' inside 'arr'.
    // Returns ADDRESS if found, or NULL if not.
    addresst = strchr(arr, target); 

    // --- 4. CHECK & CALCULATE ---
    if(addresst != NULL)   // If the pointer is NOT null...
    {
        // MATH: (Found Address) - (Start Address) = Index
        int index = addresst - arr; 

        printf("\n--- RESULTS ---\n");
        // %p prints the Hexadecimal Memory Address
        printf("Address found: %p \n", addresst);
        
        // %d prints the calculated Index (Position)
        printf("Index calculated: %d \n", index);  
        
        // %s prints string starting from that addresst
        printf("Printing %%s:    %s", addresst); 
    }
    else
    {
        printf("Character not found.");
    }

    return 0;
}
//You can use this program as base for switching out a particular character if it occurs only one time.