#include <stdio.h>

int main()
{
    // Dimensions: A is R1 x C1, B is C1 x C2, C is R1 x C2
    int R1, C1, C2; 
    int row, col, sum_index; // Loop variables

    // --- Input Matrix A Dimensions (R1 x C1) ---
    printf("Enter the no of rows and columns of Matrix A: ");
    if (scanf("%d%d", &R1, &C1) != 2) return 1;
    int matA[R1][C1];

    // --- Input Matrix A Elements ---
    for(row = 0; row < R1; row++)
    {
        printf("enter %d elements of %dth row: ", C1, row + 1);
        for(col = 0; col < C1; col++)
        {
            if (scanf("%d", &matA[row][col]) != 1) return 1;
        }
    }

    // --- Input Matrix B Dimensions (C1 x C2) ---
    printf("Enter the no of columns of Matrix B (Rows must be %d): ", C1);
    if (scanf("%d", &C2) != 1) return 1;
    int matB[C1][C2]; 

    // --- Input Matrix B Elements ---
    for(row = 0; row < C1; row++)
    {
        printf("enter %d elements of %dth row: ", C2, row + 1);
        for(col = 0; col < C2; col++)
        {
            if (scanf("%d", &matB[row][col]) != 1) return 1;
        }
    }
    
    int matC[R1][C2]; // Product matrix is R1 x C2

    // --- Matrix Multiplication: C = A * B ---
    for(row = 0; row < R1; row++)
    {
        for(col = 0; col < C2; col++)
        {
            matC[row][col] = 0; 
            
            for(sum_index = 0; sum_index < C1; sum_index++)
            {
                // C[row][col] += A[row][sum_index] * B[sum_index][col]
                matC[row][col] += matA[row][sum_index] * matB[sum_index][col];
            }
        }
    }

    // --- Print Product Matrix C ---
    printf("\nProduct Matrix C (%dx%d):\n", R1, C2);
    for(row = 0; row < R1; row++)
    { 
        for(col = 0; col < C2; col++)
        {
            printf("%d\t", matC[row][col]);
        }
        printf("\n");
    }

    return 0;
}