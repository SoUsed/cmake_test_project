#include "vector.h"
#include <iostream>

int main()
{
    vector<int> vec1(3,1);

    for(int i=0;i<3;i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << "\n";
}