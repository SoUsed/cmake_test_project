#ifndef ARRAY_H

#include <iostream>

template <class T, int size> class array
{
private:
    T __array[size];
public:
    array(){};
    //array(const array<T, size> &);
    //array(array<T, size> &&);


    T& operator[](int index)
    {
        return __array[index];
    }


    T& at(int index)
    {
        if(index < 0 || index >= size)
            throw "Index out of bounds!";
        return __array[index];
    }


    T* data()
    {
        return __array;
    }


    T& front()
    {
        return &__array[0];
    }


    T& back()
    {
        return &__array[size-1];
    }
};

#endif // !ARRAY_H