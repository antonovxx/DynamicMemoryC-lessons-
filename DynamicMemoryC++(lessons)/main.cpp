#include "stdafx.h"

#include "Fillrand.h"

#include "Print.hpp"
#include "Print.cpp"

#include "ArraysOperations.hpp"
#include "ArraysOperations.cpp"

#include "MatrixOperations.hpp"
#include "MatrixOperations.cpp"


//#define ARRAYS
#define MATRIX


int main()
{

#ifdef ARRAYS
    int size;
    cout << "Enter size: "; cin >> size;
    
    int *array = new int[size];

    FillRand(array, size);
    Print(array, size);

    int value;
    cout << "\nEnter value: "; cin >> value;

    int index;
    cout << "\nEnter index: ";
    std::cout << std::endl;
    
    cin >> index;

    cout << endl;
    erase(array, size, index);

    Print(array, size);


    delete [] array;
    
#endif
#ifdef MATRIX

    
    int rows;
    cout << "Rows: "; cin >> rows;
    int cols;
    cout << "Columns: "; cin >> cols;

    int** matrix = allocate<int>(rows, cols);
    
    FillRand(matrix, rows, cols);
    Print(matrix, rows, cols);
    
    cout << endl;
    
    int index;
    cout << "\nEnter index: "; cin >> index;

    cout << endl;

    cout << "\nInsert row: " << endl;
    matrix = push_row_back(matrix, rows, cols);
    Print(matrix, rows, cols);
    

    cout << "\nErase row: "<< endl;

    matrix = erase_row(matrix, rows, cols, index);
    Print(matrix, rows, cols);
    
    cout << endl;
    
    insert_col(matrix, rows, cols);
    Print(matrix, rows, cols);
    
    cout << endl;
    
    erase_col(matrix, rows, cols);
    Print(matrix, rows, cols);

    clear(matrix, rows);

#endif
    return 0;
}









