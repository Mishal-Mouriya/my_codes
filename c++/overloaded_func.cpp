#include <iostream>

// Same function name, different parameters

int add(int a, int b) // Version 1: adds two integers
{
    return a + b;
}

double add(double a, double b) // Version 2: adds two doubles
{
    return a + b;
}

int main()
{
    std::cout << add(2, 3) << "\n";      // Calls int version
    std::cout << add(2.5, 3.5) << "\n";  // Calls double version

    return 0;
}