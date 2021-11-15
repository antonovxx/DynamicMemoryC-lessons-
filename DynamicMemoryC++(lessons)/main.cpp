#include <iostream>
//#define ARRAYS
#define MATRIX

template <typename T> T** allocate(const T rows, const T cols);

template <typename T> void clear(T** matrix, const T rows);

void FillRand(int* array, const int size);
template <typename T> void FillRand(T** matrix, const T rows, const T cols);

void Print(int* array, const int size);
void Print(int** matrix, const int rows, const int cols);

void Push_back(int* array, int& size, int value);
void Push_front(int*& array, int& size, int value);
void insert(int*& array, int& size, int value, int index);
void pop_back(int*& array, int& size);
void pop_front(int*& array, int& size);
int* erase(int* array, int& size, int index);

template <typename T> T** push_row_back(T** matrix, T& rows, T cols);
template <typename T> T** push_row_front(T** matrix, T& rows, T cols);
template <typename T> T** insert_rows(T** matrix, T& rows, T cols, T index);

template <typename T> T** pop_row_back(T** matrix, T& rows, T cols);
template <typename T> T** pop_row_front(T** matrix, T& rows, T cols);
template <typename T> T** erase_row(T** matrix, T& rows, T cols, T index);

template <typename T> void push_col_back(T** matrix, T rows, T& cols);
template <typename T> void push_col_front(T** matrix, T rows, T& cols);
template <typename T> void insert_col(T** matrix, T rows, T& cols, T index = 2);

template <typename T> void pop_col_back(T** matrix, T rows, T& cols);
template <typename T> void pop_col_front(T** matrix, T rows, T& cols);
template <typename T> void erase_col(T** matrix, T rows, T& cols, T index = 1);




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
    
    cout << "\nInsert column: "<< endl;
    
    insert_col(matrix, rows, cols);
    Print(matrix, rows, cols);
    
    cout << endl;
    
    cout << "\nErase column: "<< endl;

    erase_col(matrix, rows, cols);
    Print(matrix, rows, cols);

    clear(matrix, rows);

#endif


    return 0;
}
template <typename T>
T** allocate(const T rows, const T cols)
{
    T** matrix = new T*[rows]{};
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new T[cols]{};
    }
    return matrix; // возвращаем адрес массива на место вызова функции
}

template <typename T>
void clear(T** matrix, const T rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix [i];
    }
    delete [] matrix;
}


template <typename T>
T** push_row_back(T** matrix, T& rows, T cols)
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
T** push_row_front(T** matrix, T& rows, T cols)
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
T** insert_rows(T** matrix, T& rows, T cols, T index)
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
T** pop_row_back(T** matrix, T& rows, T cols)
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
T** pop_row_front(T** matrix, T& rows, T cols)
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
T** erase_row(T** matrix, T& rows, T cols, T index)
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
    delete [] matrix[rows];
    delete [] matrix;
    
    matrix = buffer;
    
    rows --;
    
    return matrix;
}

template <typename T>
void push_col_back(T** matrix, T rows, T& cols)
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
void push_col_front(T** matrix, T rows, T& cols) // добавление в начало
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
void insert_col(T** matrix, T rows, T& cols, T index)
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
void pop_col_back(T** matrix, T rows, T& cols)
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
void pop_col_front(T** matrix, T rows, T& cols)
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
void erase_col(T** matrix, T rows, T& cols, T index)
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
template <typename T>
void FillRand(T** matrix, const T rows, const T cols)
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



