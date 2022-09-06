#include "vector.h"

template <typename T> void vector<T>::resize() {
  maxsize *= 2;
  T *newdata = new T[maxsize];

  for (size_t i = 0; i < cur_size; i++) {
    newdata[i] = data[i];
  }

  delete[] data;
  data = newdata;
}

template <typename T> vector<T>::vector() {
  maxsize = 10;
  cur_size = 0;
  data = new T[maxsize];
}

template <typename T> vector<T>::~vector() { delete[] data; }

template <typename T> vector<T>::vector(vector<T> &other) {
  maxsize = other.maxsize;
  cur_size = other.cur_size;
  data = new T[maxsize];

  for (size_t i = 0; i < cur_size; i++) {
    data[i] = other.data[i];
  }
}

template <typename T> vector<T>::vector(vector<T> &&other) {
  maxsize = other.maxsize;
  cur_size = other.cur_size;

  data = other.data;

  other.data = NULL;
  other.maxsize = 0;
  other.cur_size = 0;
}

template <typename T> vector<T>::vector(size_t inital_size, T fill_value) {
  maxsize = cur_size = inital_size;
  data = new T[inital_size];

  for (size_t i = 0; i < inital_size; i++)
    data[i] = fill_value;
}

template <typename T> T &vector<T>::operator[](int index) {
  return data[index];
}

template <typename T> T &vector<T>::at(size_t index) {
  if (index < 0 || index >= cur_size)
    throw "Index out of bounds!";
  return data[index];
}

template <typename T> T &vector<T>::front() { return data[0]; }

template <typename T> T &vector<T>::back() { return data[cur_size - 1]; }

template <typename T> T *vector<T>::getdata() { return data; }

template <typename T> bool vector<T>::empty() { return !cur_size; }

template <typename T> size_t vector<T>::size() { return cur_size; }

template <typename T> size_t vector<T>::max_size() { return maxsize; }

template <typename T> void vector<T>::clear() { cur_size = 0; }

template <typename T> void vector<T>::push_back(T elem) {
  if (cur_size >= maxsize)
    resize();

  data[cur_size++] = elem;
}

template <typename T> void vector<T>::pop_back() {
  if (cur_size == 0)
    throw "Vector is empty!";
  cur_size--;
}

template class vector<int>;
template class vector<double>;
template class vector<char>;