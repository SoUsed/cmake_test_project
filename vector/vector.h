#include <iostream>

template <typename T> class vector {
protected:
  size_t maxsize;
  size_t cur_size;
  T *data;

  void resize();

public:
  vector();

  virtual ~vector();

  vector(vector<T> &other);

  vector(vector<T> &&other);

  vector(size_t inital_size, T fill_value);

  T &operator[](int index);

  T &at(size_t index);

  T &front();

  T &back();

  T *getdata();

  bool empty();

  size_t size();

  size_t max_size();

  void clear();

  void push_back(T elem);

  void pop_back();
};