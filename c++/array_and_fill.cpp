//20/6/26
//also usage of fill function very importan
//passing arrays plus passsing reference hence all passing concpets covered

#include <iostream>
#include <algorithm>

int find(int arr[],const int &size,int &element);  //pass by reference and const parametere concepts added

int main()
{

                          //part 1 - array to function

  int array[]={2,4,5,6,2,1,56,77,73,1,78};
  int size = sizeof(array)/sizeof(int);
  int element=77;

  find(array,size,element);



                            //part -2 usage of fill function
   int numbers[5];

    /*
        std::fill(start, end, value);
        start -> first element
        end   -> one position past the last element
        value -> value to fill with
    */

    std::fill(numbers, numbers + 5, 10);

    // Print array
    for(int num : numbers)
    {
        std::cout << num << " ";
    }


}

int find(int arr[],const int &size,int &element)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(element==arr[i])
        {
            std::cout <<"element "<<element<<" found at positon "<<i<<"\n";
        }
    }
}