//ok lets do templates

#include <iostream>

template<typename T,typename U>  //when 2 different datatypes used but we dont know the xact type
                                //we only know that input 2 nos belong to two differnt ones

auto sum(T a,U b)     //auto lets compiler decide the return type
{
    return a+b;
}

int main()
{
    int a ;
    double b;

    std::cout << "enter 2 nos";
    std::cin >> a;
    std::cin >> b;
    std::cout << sum(a,b);

}




/*

FUNCTION TEMPLATE

Problem:
--------
Suppose we want a function that returns the larger of two values.

Without templates we would need:

int max(int a, int b);
double max(double a, double b);
char max(char a, char b);

Notice that the LOGIC is identical.Only the data type changes.
Function templates solve this problem.


Syntax:
-------
template <typename T> 

T = placeholder for a data type
The compiler replaces T with the actual type
when the function is called.


How it works:
-------------
When the compiler sees:
myMax(10, 20);

it generates something similar to:
int myMax(int a, int b)

When it sees:
myMax(2.5, 3.5);
it generates something similar to:
double myMax(double a, double b)


Advantages:
-----------
1. Write code once.
2. Reuse for many data types.
3. Avoid repeated overloaded functions.
4. Type is chosen automatically.


Think of it like a blueprint:
Template = blueprint

myMax<int>()    -> builds an int version
myMax<double>() -> builds a double version
myMax<char>()   -> builds a char version

*/