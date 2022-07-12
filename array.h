#ifndef ARRAY_H

#include <iostream>

template <class T, size_t size> class array
{
private:
    T arr[size];
public:
    array(){};

    array(const array<T, size> & other)
    {
        for(size_t i=0;i<size;i++)
            arr[i] = other.arr[i];
    }
    
    array(array<T, size> && other)
    {
        arr = other.arr;

        other.arr = NULL;
    }


    T& operator[](size_t index)
    {
        return arr[index];
    }


    T& at(size_t index)
    {
        if(index < 0 || index >= size)
            throw "Index out of bounds!";
        return arr[index];
    }


    T* data()
    {
        return arr;
    }


    T& front()
    {
        return arr[0];
    }


    T& back()
    {
        return arr[size-1];
    }
};

#endif // !ARRAY_H