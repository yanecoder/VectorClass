#pragma once
#include <iostream>
using namespace std;

template <typename t>
class Vector
{
    t* list;
    int size;
public:
    int counter = 0;

    Vector(int size)
    {
        list = new t[size];
        this->size = size;
        counter = size;
    }

    Vector(int size, t start)
    {
        list = new t[size];
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            list[i] = start;
        }
        counter = size;
    }

    Vector()
    {
        list = 0;
        size = 0;
        counter = size;
    }

    ~Vector()
    {
        if (list != 0)
        {
            delete[] list;
        }
    }

    t& operator[](int n)
    {
        if (abs(n) >= counter)
        {
            cout << "Denied to use allocated memory cells \nvec[" << n << "]\nallocated memory: " << counter << "\n";
            throw exception();
        }
        if (n < 0)
        {
            return list[counter + n];
        }
        return list[n];
    }

    void operator+(int n)
    {
        shiftMemoryCell(n);
    }

    void shiftMemoryCell(int n)
    {
        t* newList = new t[size + n];
        for (int i = 0; i < size; i++)
        {
            newList[i] = list[i];
        }

        delete[] list;
        list = newList;
        size += n;
    }

    void pushBack(t n)
    {
        if (size > counter)
        {
            list[counter] = n;
        }
        else
        {
            shiftMemoryCell(1);
            list[counter] = n;
        }
        counter++;

    }

    void popBack()
    {
        counter--;
    }

    void clear()
    {
        delete[] list;
        list = 0;
        counter = 0;
        size = 0;
    }

    void show()
    {
        for (int i = 0; i < counter; i++)
        {
            cout << list[i] << " ";
        }
    }
};

template <typename t>
ostream& operator << (ostream& show, Vector<t>& vec)
{
    for (int i = 0; i < vec.counter; i++)
    {
        show << vec[i] << " ";
    }
    return show;
}