// Learning C++ 
// Challenge 02_13
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>
#include <numeric>

int main(){
    int nums[] = {1,23,32,24,337,1241,326,43,142,364,-435};
    float result;
    float size = sizeof(nums) / (float) sizeof(nums[0]);

    result = std::accumulate(std::begin(nums), std::end(nums), 0)/size;
    
    std::cout << "The average is " << result << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
