#include "iostream"
#include "mystring.h"

int main() {
  mystring s("abcdefghi");

  std::cout << s.c_str() << "\n";

  std::cout << "hfksoik: " << mystring::strlen("hfksoik") << "\n";
  std::cout << "elemental: " << mystring::strlen("elemental") << "\n";
  std::cout << "q: " << mystring::strlen("q") << "\n";
}