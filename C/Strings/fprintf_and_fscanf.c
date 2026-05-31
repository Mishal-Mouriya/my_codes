#include <stdio.h>

int main()
{
    FILE *fp;                   // The file pointer
    char name[50];
    int age;

    // --- PART 1: WRITING TO FILE (fprintf) ---
    
    fp = fopen("data.txt", "w"); // Open file for Writing
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter Name (No spaces): ");
    scanf("%s", name);          // Read from keyboard
    printf("Enter Age: ");
    scanf("%d", &age);          // Read from keyboard

    // Write this data into the file
    // Notice: It looks exactly like printf, just with 'fp' first.
    fprintf(fp, "%s %d", name, age); 
    
    fclose(fp);                 // Always close the file!
    printf("Data saved to data.txt.\n\n");


    // --- PART 2: READING FROM FILE (fscanf) ---

    // Clear variables to prove we are reading from file
    char nameRead[50];
    int ageRead;

    fp = fopen("data.txt", "r"); // Open file for Reading

    // Read from the file
    // Notice: It looks exactly like scanf, just with 'fp' first.
    fscanf(fp, "%s %d", nameRead, &ageRead);

    printf("--- Data Read from File ---\n");
    printf("Name: %s\n", nameRead); // distinct from 'name' variable
    printf("Age:  %d\n", ageRead);

    fclose(fp);

    return 0;
}