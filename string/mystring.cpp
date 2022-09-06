#include "mystring.h"

mystring::mystring() {
  cur_size = 0;
  maxsize = 10;
  data = new char[maxsize];
}

mystring::mystring(const char *str) {
  cur_size = maxsize = strlen(str);
  data = new char[maxsize];

  for (size_t i = 0; i < maxsize; i++)
    data[i] = str[i];
}

mystring::mystring(mystring &other) {
  cur_size = other.cur_size;
  maxsize = other.maxsize;
  data = new char[maxsize];

  for (size_t i = 0; i < cur_size; i++)
    data[i] = other.at(i);
}

mystring::mystring(mystring &&other) {
  cur_size = other.cur_size;
  maxsize = other.maxsize;
  data = other.data;

  other.data = NULL;
  other.maxsize = 0;
  other.cur_size = 0;
}

void mystring::append(mystring &other) { append(other.c_str()); }

void mystring::append(const char *str) {
  for (size_t i = 0; i < strlen(str); i++)
    push_back(str[i]);
}

mystring &mystring::operator=(mystring &other) {
  if (data)
    delete[] data;

  cur_size = other.cur_size;
  maxsize = other.maxsize;
  data = new char[maxsize];

  for (size_t i = 0; i < cur_size; i++)
    data[i] = other[i];

  return *this;
}

mystring &mystring::operator=(const char *str) {
  if (data)
    delete[] data;

  cur_size = maxsize = strlen(str);
  data = new char[maxsize];

  for (size_t i = 0; i < maxsize; i++)
    data[i] = str[i];

  return *this;
}

mystring mystring::operator+(mystring &other) {
  mystring res = *this;
  res.append(other);
  return res;
}

mystring mystring::operator+(const char *str) {
  mystring res = *this;
  res.append(str);
  return res;
}

void mystring::push_back(char elem) {
  if (cur_size >= maxsize - 1)
    resize();

  data[cur_size++] = elem;
  data[cur_size] = '\0';
}

void mystring::pop_back() {
  if (cur_size == 0)
    throw "Vector is empty!";
  cur_size--;
  data[cur_size] = '\0';
}

const char *mystring::c_str() { return data; }