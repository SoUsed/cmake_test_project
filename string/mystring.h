#include "vector.h"


size_t strlen(const char* str)
{
    size_t len = 0;
    for(;str[len]!='\0';len++) {}
    return len;
}


class mystring : public vector<char>
{
public:
    mystring()
    {
        cur_size = 0;
        maxsize = 10;
        data = new char[maxsize];
    }


    ~mystring()
    {
        delete [] data;
    }


    mystring(const char* str)
    {
        cur_size = maxsize = strlen(str);
        data = new char[maxsize];
        
        for(int i=0;i<maxsize;i++)
            data[i] = str[i];
    }


    mystring(mystring& other)
    {
        cur_size = other.cur_size;
        maxsize = other.maxsize;
        data = new char[maxsize];

        for(int i=0;i<cur_size;i++)
            data[i] = other.at(i);
    }


    void append(mystring& other)
    {
        for(int i=0;i<other.size();i++)
            push_back(other[i]);
    }


    void append(const char* str)
    {
        for(int i=0;i<strlen(str);i++)
            push_back(str[i]);
    }


    mystring& operator=(mystring& other)
    {
        delete [] data;
        cur_size = other.cur_size;
        maxsize = other.maxsize;
        data = new char[maxsize];

        for(int i=0;i<cur_size;i++)
            data[i] = other[i];

        return *this;
    }


    mystring& operator=(const char* str)
    {
        delete [] data;
        cur_size = maxsize = strlen(str);
        data = new char[maxsize];
        
        for(int i=0;i<maxsize;i++)
            data[i] = str[i];

        return *this;
    }


    mystring operator+(mystring& other)
    {
        mystring res = *this;
        res.append(other);
        return res;
    }


    mystring operator+(const char* str)
    {
        mystring res = *this;
        res.append(str);
        return res;
    }
};