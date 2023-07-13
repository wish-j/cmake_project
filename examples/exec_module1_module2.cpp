#include <iostream>

#include "module1/ClassMat.hpp"
#include "module2/ClassEigenMat.hpp"


int main()
{
    const auto instence = ClassMat();
    const auto instence2 = ClassEigenMat();
    
    std::cout << "Success!" << std::endl;

    return 0; 
}