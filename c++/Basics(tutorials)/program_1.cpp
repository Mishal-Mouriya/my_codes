//17/6/26
//Here all the commands in highest form will be practiced _>basics

#include <iostream>



int main()
{   


    //This is how to output in C++

    int age = 11;
    std::cout << "hello grandpa your agie is " << age;


    //lets go over new data types

    bool runnign = false;
    std::string name = "Mishal Mouiriya";
    const double LENGTH = 7.90;   //now this value cant be  changed
                                 // constants are expected to be in captial etter for convention


    //next is getting user input
    std::cout << "\n" << "Enter your Name";
    std::getline(std::cin >> std::ws,name);  //This helps get the full string even ig it includes whitespaces
                                            //also removes \n or whitespace before user input

    std::cout << "Enter your age";    
    std::cin >> age;

    std::cout <<name <<" age is "<<age;

}