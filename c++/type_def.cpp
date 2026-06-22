//17/6/26

/*
    typedef is a C/C++ keyword used to create a custom alias or shorthand name
     for an existing data type.
    It improves code readability and simplifies complex declarations 
    (e.g., typedef unsigned long ulong; allows you to just use ulong).
*/

#include <iostream>
#include <vector>

//typedef std::vector<std::pair<std::string,int>> pairlist_t; //convetnion to put _t
//typedef std::string text_t;

using pairlist_t = std::vector<std::pair<std::string,int>>;
using text_t = std::string;

//type def is replaced nowadays with using keyword since it works better with templates

int main()
{

    pairlist_t pair;
    text_t text = "Damn you1";


}