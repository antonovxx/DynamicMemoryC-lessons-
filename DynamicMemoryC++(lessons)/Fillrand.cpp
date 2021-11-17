//
//  Fillrand.cpp
//  DynamicMemoryC++(lessons)
//
//  Created by Антон Курин on 16.11.2021.
//

#include <stdio.h>
#include "stdafx.h"

void FillRand(int* array, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        *(array + i) = rand() % 100;
    }
}

void FillRand(double* array, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        *(array + i) = rand() % 1000;
        *(array + i) /= 100;
    }
}

void FillRand(int** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

void FillRand(double** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = rand() % 1000;
            matrix[i][j] /= 100;
        }
    }
}
