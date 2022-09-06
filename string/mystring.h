#include "vector.h"

class mystring : public vector<char> {
public:
  static size_t strlen(const char *str) {
    size_t len = 0;
    for (; str[len] != '\0'; len++) {
    }
    return len;
  }

  mystring();
  mystring(const char *str);
  mystring(mystring &other);
  mystring(mystring &&other);

  void append(mystring &other);
  void append(const char *str);

  mystring &operator=(mystring &other);

  mystring &operator=(const char *str);

  mystring operator+(mystring &other);

  mystring operator+(const char *str);

  void push_back(char elem);

  void pop_back();

  const char *c_str();
};