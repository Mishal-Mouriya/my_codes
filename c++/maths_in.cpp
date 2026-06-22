#include <iostream>
#include <cmath>

int main()
{
    double x,y,z;
    
    std::cout << "Enter one side";
    std::cin >>x;
    std::cout << "enter the other side";
    std::cin >>y;

    //some math functions
    //  z=abs(x)
    //  z=pow(x,6) basically x to the power 6
    //  z=sqrt(34)
    //  z=std::max(x,y)
    //  z=std::min(x,y)
    //  z= round(x)
    //  z=ceil(x)
    //  z=floor(x)

    //now finding hypotenuse

    z = sqrt(pow(x,2)+pow(y,2));
    std::cout << "The hypotenuse of triange having sides "<<x <<" and "<< y<<" is "<<z;
    


}