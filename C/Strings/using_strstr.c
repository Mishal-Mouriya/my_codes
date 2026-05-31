#include <stdio.h>          // Standard Input/Output library
#include <string.h>         // Required for strstr() and strlen()

int main()
{
    char arr[100];          // The main text
    char target[100];       // The substring to find
    char *addresst;         // Pointer to hold the found address

    // --- 1. INPUT THE STRING ---
    printf("Enter string: ");
    fgets(arr, 100, stdin); 

    // --- 2. INPUT THE TARGET STRING ---
    printf("Target string: ");
    
    
    fgets(target, 100, stdin); 

    // FIX 2: Remove the newline (\n) from target
    // If we don't do this, strstr searches for "word\n" instead of "word"
    size_t len = strlen(target);
    if (len > 0 && target[len - 1] == '\n') 
    {
        target[len - 1] = '\0'; // Replace \n with \0
    }

    // --- 3. THE SEARCH (strstr) ---
    
    addresst = strstr(arr, target);    
    if(addresst != NULL) 
    {
        // MATH: Pointer Subtraction for Index
        int index = addresst - arr; 

        printf("\n--- RESULTS ---\n");
        printf("Address found: %p \n", addresst);
        printf("Index calculated: %d \n", index);  
        
        // This prints from the found word to the end
        printf("Printing %%s:    %s", addresst); 
    }
    else
    {
        printf("String not found.");
    }

    return 0;
}