//
//  ArraysOperations.cpp
//  DynamicMemoryC++(lessons)
//
//  Created by Антон Курин on 16.11.2021.
//

#include "ArraysOperations.hpp"

#include "stdafx.h"

template <typename T>
void Push_back(T*& array, int& size, T value)
{
    T* buffer = new T[size + 1]{};

    for (int i = 0; i < size; ++i)
    {
        buffer[i] = array[i];
    }

    delete [] array;

    array = buffer;

    array[size] = value;

    size ++;

}

template <typename T>
void Push_front(T*& array, int& size, T value)
{
    T* buffer = new T[size + 1]{};
    for (int i = 0; i < size; ++i)
    {
        buffer[i + 1] = array[i];
    }
    delete [] array;

    array = buffer;

    array[0] = value;

    size ++;

}

template <typename T>
void insert(T*& array, int& size, T value, int index)
{
    T* buffer = new T[size + 1]{};
    for (int i = 0; i < index; ++i)
    {
        buffer[i] = array[i];
    }

    buffer[index] = value;

    for (int i = index; i < size; ++i) {
        buffer[i + 1] = array[i];
    }
    delete [] array;

    array = buffer;

    size ++;
}

template <typename T>
void pop_back(T*& array, int& size)
{
    size--;
    T* buffer = new T[size];
    for (int i = 0; i < size; ++i)
    {
        buffer[i] = array[i];
    }
    delete[] array;

    array = buffer;
}

template <typename T>
void pop_front(T*& array, int& size)
{
    size --;
    T* buffer = new T[size];
    for (int i = 0; i < size; ++i)
    {
        buffer[i] = array[i + 1];
    }
    delete[] array;
    array = buffer;

}

template <typename T>
void erase(T*& array, int& size, int index)
{
    T* buffer = new T[size];
    for (int i = 0; i < index; ++i)
    {
        buffer[i] = array[i];
    }

    for (int i = index; i < size; ++i)
    {
        buffer[i - 1]  = array[i];
    }
    delete [] array;

    size--;

    array = buffer;

}
