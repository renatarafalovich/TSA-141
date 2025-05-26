#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
int getValue();

/**
 * @brief Получает и проверяет размер массива
 * @return Размер массива
 */
size_t getSize();

/**
 * @brief Проверяет корректность размера массива
 * @param n Проверяемое значение размера
 * @return Завершает программу при n <= 0
 */
void checkN(const int n);

/**
 * @brief Заполняет массив случайными значениями
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param minn Минимальное значение
 * @param maxn Максимальное значение
 */
void fillArrayRandom(int* arr, const int n, const int minn, const int maxn);
/**
 * @brief Заполняет массив случайными значениями
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void fillArrayManualy(int* arr, const int n);
/**
 * @brief выводит массив
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void printArray(int* arr, const int n);
/**
 * @brief рассчитывает сумму элементов
 * @param arr Указатель на массив
 * @param n Размер массива
 */
int sumOfElements(int* arr, const int n);
/**
 * @brief сортирует значения массива
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void sortArray(int* arr, const int n);
/**
 * @brief ищет отрицательные значения в массиве
 * @param arr Указатель на массив
 * @param n Размер массива
 */
size_t getIndexOfFirstNegative(int* arr, const int n);
/**
 * @brief создает другой массив для сортировки 
 * @param arr Указатель на массив
 * @param n Размер массива
 */
int* copyArray(int* arr, const int n);
/**
* @brief Перечисление для выбора способа заполнения данных
* @param MANUALY Выбор ручного заполнения массива
* @param RANDOM Выбор автоматического заполнения массива
*/
enum FillMode { RANDOM, MANUALY };
/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main()
{
    size_t n = getSize();
    int* arr = new int[n];
    cout << "Select fill mode (0 - RANDOM, 1 - MANUAL): ";
    int select = getValue();

    switch (select)
    {
    case RANDOM:
        fillArrayRandom(arr, n, -10, 20);  // Изменен диапазон на [-10;20]
        break;
    case MANUALY:
        fillArrayManualy(arr, n);
        break;
    default:
        cout << "erorr" << endl;
        delete[] arr;
        return 1;
    }
    cout << "Original array: ";
    printArray(arr, n);

    // Задание 1: Сумма элементов с нечетными индексами
    int sumOddIndex = 0;
    for (size_t i = 1; i < n; i += 2) {
        sumOddIndex += arr[i];
    }
    cout << "Sum of elements with odd indices: " << sumOddIndex << endl;

    // Задание 2: Количество элементов > A и кратных 5
    cout << "Enter number A: ";
    int A = getValue();
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] > A && arr[i] % 5 == 0) {
            count++;
        }
    }
    cout << "Count of elements > " << A << " and multiples of 5: " << count << endl;

    // Задание 3: Деление четных элементов на первый элемент
    if (arr[0] != 0) {
        int* modifiedArr = copyArray(arr, n);
        for (size_t i = 1; i < n; i += 2) {  // Четные индексы (поскольку индексация с 0)
            modifiedArr[i] /= arr[0];
        }
        cout << "Array after dividing even-indexed elements by first element: ";
        printArray(modifiedArr, n);
        delete[] modifiedArr;
    }
    else {
        cout << "Cannot divide by zero (first element is 0)" << endl;
    }

    // Оригинальные выводы из кода
    cout << "Sum of elements multiples 3: " << sumOfElements(arr, n) << endl;
    size_t index = getIndexOfFirstNegative(arr, n);
    if (index == n)
    {
        cout << "No negative elements" << endl;
    }
    else
    {
        cout << "Index of first negative element: " << index + 1 << endl;
    }
    int* sortArr = copyArray(arr, n);
    sortArray(sortArr, n);
    cout << "Sorted array: ";
    printArray(sortArr, n);
    delete[] sortArr;
    delete[] arr;

    return 0;
}

// Остальные функции остаются без изменений
int getValue()
{
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

size_t getSize()
{
    cout << "Enter array size (n >= 1): ";
    int n = getValue();
    checkN(n);
    return static_cast<size_t>(n);
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Error: size must be >= 1" << endl;
        exit(1);
    }
}

void fillArrayRandom(int* arr, const int n, const int minn, const int maxn)
{
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (maxn - minn + 1) + minn;
    }
}

void fillArrayManualy(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "[" << i + 1 << "] = ";
        arr[i] = getValue();
    }
}

void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumOfElements(int* arr, const int n)
{
    int result = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)  
        {
            result += arr[i];
        }
    }
    return result;
}

size_t getIndexOfFirstNegative(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            return i;
        }
    }
    return n;
}

void sortArray(int* arr, const int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int* copyArray(int* arr, const int n)
{
    int* copyArr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}
