#ifndef ARRAY_H

template <class T, int size> class array
{
private:
    T* __array;
public:
    array()
    {
        __array = new T[size];
    }

    ~array()
    {
        delete [] __array;
    }
    //array(const array<T, size> &);
    //array(array<T, size> &&);

    //T& operator[](int);
    //void swap(int, int);
};

#endif // !ARRAY_H