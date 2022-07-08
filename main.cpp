#include <iostream>
#include "array.h"

int main() 
{
    array<int, 6> ar;
    for(int i=0;i<6;i++)
    {
        ar[i] = i*i;
    }

    for(int i=0;i<6;i++)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << "\n";

    try
    {
        int x = ar.at(23);
        int y = ar.at(-5153);
        std::cout << x << " | " << y << "\n";
    }
    catch(const char* errmsg)
    {
        std::cerr << errmsg << "\n";
    }

    std::cout << ar.front() << "\n";

    std::cout << ar.back() << "\n";

    ar.back() = 0;

    std::cout << ar.back() << "\n";
    
    return 0;
}
