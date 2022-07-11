#include "mystring.h"
#include "iostream"

int main()
{
    mystring s("abcdefghi");

    std::cout << s.c_str() << "\n";

    std::cout << "hfksoik: " << strlen("hfksoik") << "\n";
    std::cout << "elemental: " << strlen("elemental") << "\n";
    std::cout << "q: " << strlen("q") << "\n";
 }