
#include <iostream> // Подключение библиотеки для ввода-вывода

// Объявление функции получения значения типа int с проверки
int getValue();

// Объявление функции получения размера массива типа size_t
size_t getSize();

// Объявление функции проверки корректности введенного n
void checkN(const int n);

// Объявление функции для заполнения массива значениями, введёнными пользователем
void fillArray(int* arr, const int n);

// Объявление функции для вывода массива на экран
void printArray(int* arr, const int n);

// Объявление функции, вычисляющей сумму элементов с нечётными индексами
int sumOfElementsWithOddIndices(int* arr, const int n);

// Объявление функции для подсчёта элементов массива, больших A и делящихся на 5
int countElementsGreaterThanAAndDivisibleBy5(int* arr, const int n, int A);

// Объявление функции для деления элементов с чётными индексами на первый элемент массива
void divideEvenIndexElementsByFirst(int* arr, const int n);

// Объявление функции для получения первого элемента массива
int getFirstElement(int* arr, const int n);

using namespace std; // Использование пространства имен std

int main() // Точка входа программы
{
    size_t n = getSize(); // Получение размера массива n с проверкой
    int* arr = new int [n]; // Выделение динамической памяти под массив из n элементов
    fillArray(arr, n); // Заполнение массива значениями с помощью функции
    printArray(arr,n); // Вывод массива на экран

    // 1. Найти сумму элементов, имеющих нечётные индексы
    int sumOddIndices = sumOfElementsWithOddIndices(arr, n);
    cout<<"Sum of elements with odd indices: "<<sumOddIndices<<endl; // Вывод суммы

    // 2. Подсчитать количество элементов массива, которые больше A и делятся на 5
    cout<<"Enter number A: ";
    int A = getValue(); // Получение числа A с проверкой
    int count = countElementsGreaterThanAAndDivisibleBy5(arr, n, A); // Подсчёт подходящих элементов
    cout<<"Count of elements > A and divisible by 5: "<<count<<endl; // Вывод результата

    // 3. Разделить все элементы с чётными индексами на первый элемент массива
    // Перед этим проверка, что первый элемент не равен 0
    int firstElement = getFirstElement(arr, n); // Получение первого элемента массива
    if (firstElement != 0) // Проверка деления на ноль
    {
        divideEvenIndexElementsByFirst(arr, n); // Выполнение деления элементов
        cout<<"Array after dividing elements with even indices by first element: ";
        printArray(arr, n); // Вывод изменённого массива
    }
    else // Если первый элемент равен 0
    {
        cout<<"First element is zero, division not performed."<<endl;
    }

    delete[] arr; // Освобождение выделенной памяти

    return 0; // Завершение программы
}

// Реализация функции получения значения с проверкой
int getValue()
{
    int value = 0;
    cin>>value; // Ввод значения
    if (cin.fail()) // Проверка ошибок ввода
    {
        cout<<"Error"<<endl; // Сообщение об ошибке
        abort(); // Прерывание программы в случае ошибки
    }
    return value; // Возврат введенного значения
}

// Реализация функции получения размера массива с проверкой
size_t getSize()
{
    std::cout<<"Enter n"<<endl; // Запрос размера n
    int n = getValue(); // Ввод n
    checkN(n); // Проверка корректности n
    return (size_t)n; // Возврат в виде size_t
}

// Проверка корректности n (должно быть положительным)
void checkN(const int n)
{
    if (n<=0) // Если n не положительно
    {
        cout<<"Error"<<endl; // Сообщение об ошибке
        abort(); // Завершение программы
    }
}

// Заполнение массива значениями, введёнными пользователем
void fillArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++) // Итерация по индексам массива
    {
        cout<<"Enter arr["<<i+1<<"] = "; // Запрос значения для элемента i
        arr[i] = getValue(); // Ввод значения и запись в массив
    }
}

// Вывод массива на экран
void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++) // Итерация по элементам массива
    {
        cout<<arr[i]<<" "; // Вывод элемента и пробел
    }
    cout<<endl; // Перевод строки после вывода массива
}

// Подсчёт суммы элементов с нечётными индексами
int sumOfElementsWithOddIndices(int* arr, const int n)
{
    int result = 0; // Изначально сумма равна 0
    for (size_t i = 1; i < n; i += 2) // Итерация по нечётным индексам (1,3,5,...)
    {
        result += arr[i]; // Добавление элемента к сумме
    }
    return result; // Возврат суммы
}

// Подсчёт количества элементов, больших A и делящихся на 5
int countElementsGreaterThanAAndDivisibleBy5(int* arr, const int n, int A)
{
    int count = 0; // Изначально количество равно 0
    for (size_t i = 0; i < n; i++) // Итерация по всем элементам массива
    {
        if (arr[i] > A && arr[i] % 5 == 0) // Проверка условий
        {
            count++; // Увеличение счётчика
        }
    }
    return count; // Возврат результата
}

// Деление элементов с чётными индексами на первый элемент массива
void divideEvenIndexElementsByFirst(int* arr, const int n)
{
    int divisor = arr[0]; // Первый элемент массива как делитель
    for (size_t i = 0; i < n; i += 2) // Итерация по чётным индексам (0,2,4,...)
    {
        if (divisor != 0) // Проверка деления на ноль
        {
            arr[i] /= divisor; // Деление элемента на первый элемент
        }
        else // Если делитель равен 0
        {
            // Сообщение о невозможности деления
            cout<<"First element is zero, cannot divide."<<endl;
            break; // Выход из цикла
        }
    }
}

// Получение первого элемента массива
int getFirstElement(int* arr, const int n)
{
    return arr[0]; // Возврат первого элемента
}
