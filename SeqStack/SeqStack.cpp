#include <cstdio>
#include <cstring>
#include <new>
#define SIZE 50
#define INF nullptr
#pragma once



template <typename T>
class stack
{
private:
    int Size;
    int Length;
    bool Init;
    T* elem;

    bool reloc(int _size)
    {

        T* temp = new(std::nothrow) T[Size + _size];
        if (temp == nullptr)
            return false;
        memcpy(temp, elem, sizeof(T) * (Length + 1));
        delete elem;
        elem = temp;
        Size += _size;
        return true;
    }

public:
    stack()
    {
        Init = true;
        elem = new (std::nothrow) T[SIZE];
        if (elem == nullptr)Init = false;
        Size = SIZE;
        Length = -1;
    }

    int size() { return Size; }

    bool init() { return Init; }

    inline bool isEmpty() { return Length == -1; }

    T top()
    {
        T null = *(new T);
        if (Init == false)return (null);
        if (Length == -1)return (null);
        if (Length >= 2 && Length % SIZE == 0)
            if (!reloc(-SIZE))
                return (null);
        T tar = elem[Length];
        Length -= 1;
        return tar;
    }

    bool pop()
    {
        if (Init == false) return false;
        if (Length == -1) return true;
        if (Length >= 2 && Length % SIZE == 0)//Length start at 0!
            if (!reloc(-SIZE))
                return false;
        Length -= 1;
        return true;
    }

    bool push(T const& val)
    {
        if (Init == false)return false;
        if (Length + 2 > Size)
            if (reloc(SIZE) == false)
                return false;
        Length += 1;
        elem[Length] = val;
        return true;
    }

    bool destroy()
    {
        Init = false;
        delete elem;
        Length = -1;
        size = 0;
        return true;
    }

    bool clear()
    {
        Length = -1;
        size = 0;
        elem = new (std::nothrow) T[SIZE];
        if (elem == nullptr)
            return false;
        return true;
    }

    void stackTraverse(void(*p)(T)) 
    {
        for (int i = 0; i <= Length; i++)
        {
            p(elem[i]);
        }
    }
};
