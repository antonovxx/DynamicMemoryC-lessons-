//
//  MatrixOperations.hpp
//  DynamicMemoryC++(lessons)
//
//  Created by Антон Курин on 16.11.2021.
//

#ifndef MatrixOperations_hpp
#define MatrixOperations_hpp

#include <stdio.h>

template <typename T> T** allocate(const int rows, const int cols);
template <typename T> void clear(T** matrix, int rows);


template <typename T> T** push_row_back(T** matrix, int& rows, const int cols);
template <typename T> T** push_row_front(T** matrix, int& rows, const int cols);
template <typename T> T** insert_rows(T** matrix, int& rows, const int cols, int index);

template <typename T> T** pop_row_back(T** matrix, int& rows, const int cols);
template <typename T> T** pop_row_front(T** matrix, int& rows, const int cols);
template <typename T> T** erase_row(T** matrix, int& rows, const int cols, int index);

template <typename T> void push_col_back(T** matrix, const int rows, int& cols);
template <typename T> void push_col_front(T** matrix, const int rows, int& cols);
template <typename T> void insert_col(T** matrix, const int rows, int& cols, int index = 2);

template <typename T> void pop_col_back(T** matrix, const int rows, int& cols);
template <typename T> void pop_col_front(T** matrix, const int rows, int& cols);
template <typename T> void erase_col(T** matrix, const int rows, int& cols, int index = 1);


#endif /* MatrixOperations_hpp */
