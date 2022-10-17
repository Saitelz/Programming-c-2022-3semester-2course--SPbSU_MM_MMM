#pragma once
#include <iostream>

template<typename type>
class Vector
{
private:

    int v_size;
    int v_capacity;
    type* v_data;

public:

    Vector(int v_size = 0, int v_capacity = 0, type* v_data = nullptr) :v_size(v_size), v_capacity(v_capacity), v_data(v_data) {}
    Vector(const Vector& Vector)  : v_size(Vector.v_size), v_capacity(Vector.v_capacity), v_data(Vector.v_data) {}
    ~Vector()
    {
        delete[] v_data;
    }

    int size()
    {
        return v_size;
    }

    type& operator[] (int i)
    {
        return v_data[i];
    }

    type max(type a, type b)
    {
        if (a > b)
        {
            return a;
        }
        else return b;
    }

    type min(type a, type b)
    {
        if (a < b)
        {
            return a;
        }
        else return b;
    }

    void resize(int newsize)
    {
        if (newsize <= v_capacity)
        {
            v_size = newsize;
            return;
        }

        int newcapacity = max(newsize, v_size * 2);
        type* new_data = new type[newcapacity];

        for (int i = 0; i < min(v_size, newsize); ++i)
        {
            new_data[i] = v_data[i];
        }

        for (int i = 0; i < newsize; ++i)
        {
            new_data[i] = type();
        }

        delete[] v_data;
        v_data = new_data;
        v_size = newsize;
        v_capacity = newcapacity;
    }

    void push_back(type var)
    {
        resize(v_size + 1);
        v_data[v_size - 1] = var;
    }

    void insert(int itr, type var)
    {
        resize(v_size + 1);

        for (int i = v_size - 1; i > itr; --i)
        {
            v_data[i] = v_data[i - 1];
        }

        v_data[itr] = var;
    }

    friend std::ostream& operator<<(std::ostream& out, Vector<type>& a)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            out << a[i] << " ";
        }

        return out;
    }
};