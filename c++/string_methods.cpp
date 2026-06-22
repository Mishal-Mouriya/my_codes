//ok so since stringa are speical of c++ we need to learn it

#include <iostream>

int main()
{
    //getting string
    std::string text;
    std::cout << "enter any string to work with>>";
    std::getline(std::cin >> std::ws,text);

    //string methods
    int length = text.length();
    
    std::string text1= text.append("ehlogbg");    

    std::cout << text1.at(5);                    //prints the character at 12th index

    text1.insert(1,"#");                          //insertion
    
    text.clear(); //deletes 

    std::cout << text.find(" ");

    text1.erase(0,2);                             //2 position is not included


    if(text.empty())                              //checks whether empty or not
    {
        std::cout << "Deleted";
    }
    

}

