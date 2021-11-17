//
//  ArraysOperations.hpp
//  DynamicMemoryC++(lessons)
//
//  Created by Антон Курин on 16.11.2021.
//

#ifndef ArraysOperations_hpp
#define ArraysOperations_hpp

#include <stdio.h>

template <typename T> void Push_back(T*& array, int& size, int value);
template <typename T> void Push_front(T*& array, int& size, int value);
template <typename T> void insert(T*& array, int& size, int value, int index);
template <typename T> void pop_back(T*& array, int& size);
template <typename T> void pop_front(T*& array, int& size);
template <typename T> void erase(T*& array, int& size, int index);


#endif /* ArraysOperations_hpp */
