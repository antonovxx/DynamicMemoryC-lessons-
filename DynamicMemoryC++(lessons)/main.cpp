#include <iostream>

void FillRand(int* array, const int size);
void Print(int* array, const int size);
void Push_back(int* array, int& size, int value);
void Push_front(int*& array, int& size, int value);
void insert(int*& array, int& size, int value, int index);
void pop_back(int*& array, int& size);
void pop_front(int*& array, int& size);
void erase(int*& array, int& size, int index);

int main()
{
    using namespace std;
    
    
    int size;
    cout << "Enter size: "; cin >> size;
    int *array = new int[size];
    
    FillRand(array, size);
    Print(array, size);
    
//    int value;
//    cout << "Enter value: "; cin >> value;
//
    int index;
    cout << "Enter index: "; cin >> index;
    
    cout << endl;
    erase(array, size, index);
    Print(array, size);

    
    delete [] array;
    
    
    return 0;
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

void erase(int*& array, int& size, int index)
{
    int* buffer = new int [size];
    for (int i = 0; i < index; ++i)
    {
        buffer[i] = array[i];
    }
    
    for (int i = index; i < size; ++i)
    {
        buffer[i - 1] = array[i];
    }
    delete [] array;
    
    size--;
    
    array = buffer;
    
}
