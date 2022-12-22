#include <cstdlib>
#include <iostream>

int somme(int nombre1, int nombre2)
{
    return nombre1 + nombre2;
}

void inverser(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void replaceBySum(int &a, int &b, int &result)
{
    result = a + b;
}

void replaceBySum(int *a, int *b, int *result)
{
    *result = *a + *b;
}

void fillArrayWithInt(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

void sortArray(int array[], int size, bool isAsc)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (
                (isAsc && array[j] > array[j + 1]) || (!isAsc && array[j] < array[j + 1]))
            {
                inverser(array[j], array[j + 1]);
            }
        }
    }
}