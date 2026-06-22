//20/6/26

//ok we are going to do a very c++ thing
#include <iostream>

int main()
{
  std::string cars[] = {"maruthi","porsche","ford","suzuki"};
  for(std::string var : cars)   //similar to for x in list
  {
    std::cout << var<<"\n";
  }
    
}