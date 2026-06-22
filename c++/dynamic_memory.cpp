//20/6/26

#include <iostream>
#include <cstdlib> // calloc(), free()

int main()
{
    int n;

    std::cout << "How many marks do you want to store? ";
    std::cin >> n;

    // calloc allocates memory AND initializes everything to 0
    int* marks_c = (int*)calloc(n, sizeof(int));

    // new[] allocates memory but does NOT initialize fundamental types
    int* marks_n = new int[n];

    
    std::cout << "calloc : " << marks_c[0] << "\n";
    std::cout << "new[]  : " << marks_n[0] << "  <-- garbage value\n";

    std::cout << "\nEnter marks using new[] array:\n";
    for(int i = 0; i < n; i++)
    {
        std::cout << "Mark " << i + 1 << ": ";
        std::cin >> marks_n[i];
    }   

    // Memory cleanup

    free(marks_c);      // for calloc/malloc
    delete[] marks_n;   // for new[]

    return 0;
}