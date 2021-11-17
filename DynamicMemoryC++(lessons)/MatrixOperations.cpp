//
//  MatrixOperations.cpp
//  DynamicMemoryC++(lessons)
//
//  Created by Антон Курин on 16.11.2021.
//

#include "MatrixOperations.hpp"
#include "stdafx.h"

template <typename T>
T** allocate(const int rows, const int cols)
{
    T** matrix = new T*[rows]{};
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new T[cols]{};
    }
    return matrix;
}


template <typename T>
void clear(T** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete [] matrix [i];
    }
    delete [] matrix;
}


template <typename T>
T** push_row_back(T** matrix, int& rows, const int cols)
{
    T** buffer = new T*[rows + 1];
    
    for (int i = 0; i < rows; ++i)
    {
        buffer[i] = matrix[i];
    }
    delete [] matrix;
    
    matrix = buffer;
    
    matrix[rows] = new T[cols]{};
    
    rows++;
    
    return matrix;
    
}

template <typename T>
T** push_row_front(T** matrix, int& rows, const int cols)
{
    T** buffer = new T*[rows + 1]{};
    
    for (int i = 0; i < rows; ++i)
    {
        buffer[i + 1] = matrix[i];
    }
    
    delete [] matrix;
    
    matrix = buffer;
    
    matrix[0] = new T[cols]{};
    
    rows ++;
    
    return matrix;
}


template <typename T>
T** insert_rows(T** matrix, int& rows, const int cols, int index)
{
    T** buffer = new T*[rows + 1]{};
    for (int i = 0; i < index; ++i)
    {
        buffer[i] = matrix[i];
    }
    buffer[index] = new T[cols]{};
    
    for (int i = index; i < rows; ++i)
    {
        buffer[i + 1] = matrix[i];
    }
    delete[] matrix;
    
    matrix = buffer;
    
    rows++;
    
    return matrix;
}

template <typename T>
T** pop_row_back(T** matrix, int& rows, const int cols)
{
    rows --;
    T** buffer = new T*[rows - 1]{};
    for(int i = 0; i < rows; ++i)
    {
        buffer[i] = matrix[i];
    }
    delete [] matrix[rows];
    delete [] matrix;
    
    matrix = buffer;
    
    return matrix;
}

template <typename T>
T** pop_row_front(T** matrix, int& rows, const int cols)
{
    rows --;
    T** buffer = new T*[rows - 1]{};
    for (int i = 0; i < rows; ++i)
    {
        buffer[i] = matrix[i + 1];
    }
    delete [] matrix[rows];
    delete [] matrix;
    matrix = buffer;
    return matrix;
}

template <typename T>
T** erase_row(T** matrix, int& rows, const int cols, int index)
{
    T** buffer = new T*[rows - 1]{};
    for (int i = 0; i < index; ++i)
    {
        buffer[i] = matrix[i];
    }
    for (int i = index; i < rows; ++i)
    {
        buffer[i - 1] = matrix[i];
    }
    delete [] matrix;
    
    matrix = buffer;
    
    rows --;
    
    return matrix;
}

template <typename T>
void push_col_back(T** matrix, const int rows, int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        T* buffer = new T[cols + 1]{};
        for (int j = 0; j < cols; ++j)
        {
            buffer[j] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = buffer;
    }
    cols ++;
}

template <typename T>
void push_col_front(T** matrix, const int rows, int& cols) // добавление в начало
{
    for (int i = 0; i < rows; ++i)
    {
        T* buffer = new T[cols + 1]{};
        for (int j = 0; j < cols; ++j)
        {
            if(j == 0)
            {
                buffer[0] = 0;
            }
            buffer[j + 1] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = buffer;
    }
    cols ++;
}

template <typename T>
void insert_col(T** matrix, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; ++i)
    {
        T* buffer = new T[cols + 1]{};
        int currentCol = 0;
        for (int j = 0; j < cols; ++j)
        {
            if(j == index)
            {
                buffer[index] = 0;
                currentCol ++;
            }
            buffer[currentCol] = matrix[i][j];
            currentCol ++;
        }
        delete[] matrix[i];
        
        matrix[i] = buffer;
    }
    cols ++;
}

template <typename T>
void pop_col_back(T** matrix, const int rows, int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        T* buffer = new T[cols - 1]{};
        for (int j = 0; j < cols - 1; ++j)
        {
            buffer[j] = matrix[i][j];
        }
    
        delete [] matrix[i];
        
        matrix[i] = buffer;
    }
    cols --;
}

template <typename T>
void pop_col_front(T** matrix, const int rows, int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        T* buffer = new T[cols - 1]{};
        for (int j = 0; j < cols; ++j)
        {
            buffer[j] = matrix[i][j + 1];
        }
        
        delete [] matrix [i];
        
        matrix [i] = buffer;
    }
    cols --;
}

template <typename T>
void erase_col(T** matrix, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; ++i)
    {
        T* buffer = new T[cols - 1]{};
        int currentCol = 0;
        for (int j = 0; j < cols; ++j)
        {
            if(j != index)
            {
                buffer[currentCol] = matrix[i][j];
                currentCol ++;
            }
        }
        delete[] matrix[i];
        matrix[i] = buffer;
    }
    cols--;
}
