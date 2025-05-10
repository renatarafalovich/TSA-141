
#include <iostream>

int getValue();

size_t getSize();

void checkN(const int n);

void fillArray(int* arr, const int n);

void printArray(int* arr, const int n);

int sumOfElementsWithOddIndices(int* arr, const int n);

int countElementsGreaterThanAAndDivisibleBy5(int* arr, const int n, int A);

void divideEvenIndexElementsByFirst(int* arr, const int n);

int getFirstElement(int* arr, const int n);

using namespace std;

int main()
{
    size_t n = getSize();
    int* arr = new int [n];
    fillArray(arr, n);
    printArray(arr,n);
    
    // 1. Найти сумму элементов, имеющих нечетные индексы
    int sumOddIndices = sumOfElementsWithOddIndices(arr, n);
    cout<<"Sum of elements with odd indices: "<<sumOddIndices<<endl;

    // 2. Подсчитать количество элементов массива, значения которых больше заданного числа А и кратных 5.
    cout<<"Enter number A: ";
    int A = getValue();
    int count = countElementsGreaterThanAAndDivisibleBy5(arr, n, A);
    cout<<"Count of elements > A and divisible by 5: "<<count<<endl;

    // 3. Разделить все элементы массива с четными номерами на первый элемент (который не равен 0)
    // Перед этим проверим, что первый элемент не равен 0
    int firstElement = getFirstElement(arr, n);
    if (firstElement != 0)
    {
        divideEvenIndexElementsByFirst(arr, n);
        cout<<"Array after dividing elements with even indices by first element: ";
        printArray(arr, n);
    }
    else
    {
        cout<<"First element is zero, division not performed."<<endl;
    }

    delete[] arr;

    return 0;
}

int getValue()
{
    int value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Error"<<endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    std::cout<<"Enter n"<<endl;
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n<=0)
    {
        cout<<"Error"<<endl;
        abort();
    }
}

void fillArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout<<"Enter arr["<<i+1<<"] = ";
        arr[i] = getValue();
    }
}

void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// 1. Найти сумму элементов с нечетными индексами
int sumOfElementsWithOddIndices(int* arr, const int n)
{
    int result = 0;
    for (size_t i = 1; i < n; i += 2)
    {
        result += arr[i];
    }
    return result;
}

// 2. Подсчитать количество элементов > A и кратных 5
int countElementsGreaterThanAAndDivisibleBy5(int* arr, const int n, int A)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > A && arr[i] % 5 == 0)
        {
            count++;
        }
    }
    return count;
}

// 3. Разделить все элементы с четными номерами на первый элемент (индекс 0)
void divideEvenIndexElementsByFirst(int* arr, const int n)
{
    int divisor = arr[0];
    for (size_t i = 0; i < n; i += 2)
    {
        if (divisor != 0)
        {
            arr[i] /= divisor;
        }
        else
        {
            // Если первый элемент равен 0, деление невозможно
            cout<<"First element is zero, cannot divide."<<endl;
            break;
        }
    }
}

// Получить первый элемент массива
int getFirstElement(int* arr, const int n)
{
    return arr[0];
}
