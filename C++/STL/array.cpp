// implementation and operations on arrays using c++ STL library

#include <iostream>
#include <array>

int main(){
    //create an array
    std::array<int, 4> arr {10,20,30,40};
    
    // size
    std::cout << "Size of the array --> " << arr.size() << std::endl;

    // element access
    std::cout << "Element at index 2 --> " << arr.at(2) << std::endl; 

    // first element
    std::cout << "First element --> " << arr.front() << std::endl;

    // last element
    std::cout << "Last element --> " << arr.back() << std::endl;
    
    // is empty
    std::cout << "is array empty --> " << arr.empty();
    
    std::cin.get();
    return 0;
}   