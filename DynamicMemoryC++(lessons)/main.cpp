#include <iostream>
//#define ARRAYS
#define MATRIX

int** allocate(const int rows, const int cols);
void clear(int** matrix, const int rows);

void FillRand(int* array, const int size);
void FillRand(int** matrix, const int rows, const int cols);

void Print(int* array, const int size);
void Print(int** matrix, const int rows, const int cols);

void Push_back(int* array, int& size, int value);
void Push_front(int*& array, int& size, int value);
void insert(int*& array, int& size, int value, int index);
void pop_back(int*& array, int& size);
void pop_front(int*& array, int& size);
int* erase(int* array, int& size, int index);

int** push_row_back(int** matrix, int& rows, int cols);
int** push_row_front(int** matrix, int& rows, int cols);
int** insert_rows(int** matrix, int& rows, int cols, int index);

int** pop_row_back(int** matrix, int& rows, int cols);
int** pop_row_front(int** matrix, int& rows, int cols);
int** erase_row(int** matrix, int& rows, int cols, int index);

void push_col_back(int** matrix, int rows, int& cols);
void push_col_front(int** matrix, int rows, int& cols);
void insert_col(int** matrix, int rows, int& cols, int index = 2);

void pop_col_back(int** matrix, int rows, int& cols);
void pop_col_front(int** matrix, int rows, int& cols);
void erase_col(int** matrix, int rows, int& cols, int index = 1);




int main()
{
    using namespace std;

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
    array = erase(array, size, index);

    Print(array, size);


    delete [] array;
    
#endif
#ifdef MATRIX

    int rows;
    cout << "Rows: "; cin >> rows;
    int cols;
    cout << "Columns: "; cin >> cols;

    int** matrix = allocate(rows, cols);
    
    FillRand(matrix, rows, cols);
    Print(matrix, rows, cols);
    
//    cout << endl;
    
//    int index;
//    cout << "\nEnter index: "; cin >> index;
//
//    cout << endl;
//
//    cout << "\nInsert row: " << endl;
//    matrix = insert_rows(matrix, rows, cols, index);
//    Print(matrix, rows, cols);
//
//    cout << "\nErase row: "<< endl;
//
//    matrix = erase_row(matrix, rows, cols, index);
//    Print(matrix, rows, cols);
    
    cout << endl;
    
//    insert_col(matrix, rows, cols);
//    Print(matrix, rows, cols);
    
    cout << endl;
   
    erase_col(matrix, rows, cols);
    Print(matrix, rows, cols);

    clear(matrix, rows);



#endif


    return 0;
}

int** allocate(const int rows, const int cols)
{
    int** matrix = new int*[rows]{};
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols]{};
    }
    return matrix; // возвращаем адрес массива на место вызова функции
}

void clear(int** matrix, const int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix [i];
    }
    delete [] matrix;
}

int** push_row_back(int** matrix, int rows, int& cols)
{
    int** buffer = new int*[rows + 1];
    
    for (int i = 0; i < rows; ++i)
    {
        buffer[i] = matrix[i];
    }
    delete [] matrix;
    
    matrix = buffer;
    
    matrix[rows] = new int[cols]{};
    
    rows++;
    
    return matrix;
    
}

int** push_row_front(int** matrix, int& rows, int cols)
{
    int** buffer = new int*[rows + 1]{};
    
    for (int i = 0; i < rows; ++i)
    {
        buffer[i + 1] = matrix[i];
    }
    
    delete [] matrix;
    
    matrix = buffer;
    
    matrix[0] = new int[cols]{};
    
    rows ++;
    
    return matrix;
}


int** insert_rows(int** matrix, int& rows, int cols, int index)
{
    int** buffer = new int*[rows + 1]{};
    for (int i = 0; i < index; ++i)
    {
        buffer[i] = matrix[i];
    }
    buffer[index] = new int[cols]{};
    
    for (int i = index; i < rows; ++i)
    {
        buffer[i + 1] = matrix[i];
    }
    delete[] matrix;
    
    matrix = buffer;
    
    rows++;
    
    return matrix;
}

int** pop_row_back(int** matrix, int& rows, int cols)
{
    rows --;
    int** buffer = new int*[rows - 1]{};
    for(int i = 0; i < rows; ++i)
    {
        buffer[i] = matrix[i];
    }
    delete [] matrix;
    
    matrix = buffer;
    
    return matrix;
}

int** pop_row_front(int** matrix, int& rows, int cols)
{
    rows --;
    int** buffer = new int*[rows - 1]{};
    for (int i = 0; i < rows; ++i)
    {
        buffer[i] = matrix[i + 1];
    }
    delete [] matrix;
    matrix = buffer;
    return matrix;
}

int** erase_row(int** matrix, int& rows, int cols, int index)
{
    int** buffer = new int*[rows - 1]{};
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

void push_col_back(int** matrix, int rows, int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols + 1]{};
        for (int j = 0; j < cols; ++j)
        {
            buffer[j] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = buffer;
    }
    cols ++;
}

void push_col_front(int** matrix, int rows, int& cols) // добавление в начало
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols + 1]{};
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

void insert_col(int** matrix, int rows, int& cols, int index)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols + 1]{};
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

void pop_col_back(int** matrix, int rows, int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols - 1]{};
        for (int j = 0; j < cols - 1; ++j)
        {
            buffer[j] = matrix[i][j];
        }
        
        delete [] matrix[i];
        
        matrix[i] = buffer;
    }
    cols --;
}

void pop_col_front(int** matrix, int rows, int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols - 1]{};
        for (int j = 0; j < cols; ++j)
        {
            buffer[j] = matrix[i][j + 1];
        }
        
        delete [] matrix [i];
        
        matrix [i] = buffer;
    }
    cols --;
}

void erase_col(int** matrix, int rows, int& cols, int index)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols - 1]{};
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

void FillRand(int* array, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        *(array + i) = rand() % 100;
    }
}

void Print(int* array, const int size)
{
    for (int i = 0; i < size; ++i)
     {
        std::cout << array[i] << " ";
    }
}

void Push_back(int*& array, int& size, int value)
{
    int* buffer = new int[size + 1]{};

    for (int i = 0; i < size; ++i)
    {
        buffer[i] = array[i];
    }

    delete [] array;

    array = buffer;

    array[size] = value;

    size ++;

}

void Push_front(int*& array, int& size, int value)
{
    int* buffer = new int[size + 1]{};
    for (int i = 0; i < size; ++i)
    {
        buffer[i + 1] = array[i];
    }
    delete [] array;

    array = buffer;

    array[0] = value;

    size ++;

}

void insert(int*& array, int& size, int value, int index)
{
    int* buffer = new int[size + 1]{};
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

void pop_back(int*& array, int& size)
{
    size--;
    int* buffer = new int[size];
    for (int i = 0; i < size; ++i)
    {
        buffer[i] = array[i];
    }
    delete[] array;

    array = buffer;
}

void pop_front(int*& array, int& size)
{
    size --;
    int* buffer = new int[size];
    for (int i = 0; i < size; ++i)
    {
        buffer[i] = array[i + 1];
    }
    delete[] array;
    array = buffer;

}

int* erase(int* array, int& size, int index)
{
    int* buffer = new int [size];
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

    return array;

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

void Print(int** matrix, const int rows, const int cols)
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



