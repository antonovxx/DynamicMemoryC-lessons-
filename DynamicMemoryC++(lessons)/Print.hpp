//
//  Print.hpp
//  DynamicMemoryC++(lessons)
//
//  Created by Антон Курин on 16.11.2021.
//

#ifndef Print_hpp
#define Print_hpp

#include <stdio.h>
template <typename T> void Print(T* array, const int size);
template <typename T> void Print(T** matrix, const int rows, const int cols);

#endif /* Print_hpp */
