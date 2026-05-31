#include <stdio.h>
#include <string.h>

int main() {
    // 1. The main string (The Haystack)
    char text[] = "Learning C is powerful";

    printf("Original String: \"%s\"\n\n", text);

    // ---------------------------------------------------------
    // EXAMPLE 1: strchr (Find the character 'C')
    // ---------------------------------------------------------
    char *charResult = strchr(text, 'C');

    if (charResult != NULL) {
        printf("[strchr] Found 'C'!\n");
        // Printing the result pointer as a string shows the text FROM that point onwards
        printf(" -> Remainder of string: \"%s\"\n", charResult);
    } else {
        printf("[strchr] Character not found.\n");
    }

    // ---------------------------------------------------------
    // EXAMPLE 2: strstr (Find the substring "power")
    // ---------------------------------------------------------
    char *strResult = strstr(text, "power");

    if (strResult != NULL) {
        printf("\n[strstr] Found \"power\"!\n");
        // It points to the 'p' in "power" inside the original text
        printf(" -> Remainder of string: \"%s\"\n", strResult);
    } else {
        printf("\n[strstr] Substring not found.\n");
    }

    // ---------------------------------------------------------
    // EXAMPLE 3: Edge Case (Search for something not there)
    // ---------------------------------------------------------
    char *missingResult = strstr(text, "Java");

    if (missingResult == NULL) {
        printf("\n[Edge Case] Searching for \"Java\" returned NULL.\n");
        printf(" -> We successfully avoided a crash by checking for NULL!\n");
    }

    return 0;
}