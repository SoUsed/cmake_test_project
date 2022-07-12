#include <iostream>

template <typename T>
class vector
{
protected:
    size_t maxsize;
    size_t cur_size;
    T* data;


    void resize()
    {
        maxsize *= 2;
        T* newdata = new T[maxsize];

        for(size_t i=0;i<cur_size;i++)
        {
            newdata[i] = data[i];
        }

        delete [] data;
        data = newdata;
    }


public:
    vector()
    {
        maxsize = 10;
        cur_size = 0;
        data = new T[maxsize];
    }

    
    virtual ~vector()
    {
        delete [] data;
    }


    vector(vector<T> & other)
    {
        maxsize = other.maxsize;
        cur_size = other.cur_size;
        data = new T[maxsize];

        for(size_t i=0;i<cur_size;i++)
        {
            data[i] = other.data[i];
        }
    }


    vector(vector<T> && other)
    {
        maxsize = other.maxsize;
        cur_size = other.cur_size;

        data = other.data;

        other.data = NULL;
        other.maxsize = 0;
        other.cur_size = 0;
    }

    
    vector(size_t inital_size, T fill_value)
    {
        maxsize = cur_size = inital_size;
        data = new T[inital_size];

        for(size_t i=0;i<inital_size;i++)
            data[i] = fill_value;
    }


    T& operator[](int index)
    {
        return data[index];
    }


    T& at(int index)
    {
        if(index < 0 || index >= cur_size)
            throw "Index out of bounds!";
        return data[index];
    }


    T& front()
    {
        return data[0];
    }


    T& back()
    {
        return data[cur_size-1];
    }


    T* getdata()
    {
        return data;
    }


    bool empty()
    {
        return !cur_size;
    }


    size_t size()
    {
        return cur_size;
    }


    size_t max_size()
    {
        return maxsize;
    }


    void clear()
    {
        cur_size = 0;
    }


    void push_back(T elem)
    {
        if(cur_size >= maxsize)
            resize();
        
        data[cur_size++] = elem;
    }


    void pop_back()
    {
        if(cur_size==0) throw "Vector is empty!";
        cur_size--;
    }
};