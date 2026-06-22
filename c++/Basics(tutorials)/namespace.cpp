//17/6/26
#include <iostream>

/* ok next lets go over namespaces-> 2 or more variablles can cont1ain same 
       var name but they must have unique name space we will see example
            */


namespace first{ int x=1;}
namespace second{int x=2;}

int main()
{
     using namespace first;   //if you use x first is selected as default
     
     std::cout <<x<< "\n";
     std::cout << second::x;   //prefix needed to access the data

     using namespace std;

     //now no longer need to prefix string and cout

     string name = "Mishal mouriya";
     cout << "\n" << name;

     //but this is not recommended as it can cause conflicts
     //instead we can use this

     using std::string;
     using std::cout;

     //now you can do same as above but safer

}