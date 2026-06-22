//lets do a random no generateor and using that a dice

#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));

    int roll = (rand()%6)+1;
    std::cout << roll;

    ///with this you can just create a random no generator using switch case
    //but too lazy right?

}