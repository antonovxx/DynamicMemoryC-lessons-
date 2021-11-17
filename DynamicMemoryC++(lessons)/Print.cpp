//
//  Print.cpp
//  DynamicMemoryC++(lessons)
//
//  Created by Антон Курин on 16.11.2021.
//

#include "stdafx.h"

template <typename T>
void Print(T* array, const int size)
{
    for (int i = 0; i < size; ++i)
     {
        std::cout << array[i] << " ";
    }
}

template <typename T>
void Print(T** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
