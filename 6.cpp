#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std;

/**
 * @brief считывает значение с клавиатуры и проверяет
 * @return введенное значение
 */
int getValue();

/**
 * @brief считывает значение с клавиатуры n и использует для проверки checkN()
 * @return введенное значение массива
 */
size_t getSize();

/**
 * @brief проверяет, что размер массива положительный
 * @param n - количество элементов массива
 * @throws завершает программу, если n <= 0
 */
void checkN(const int n);

/**
 * @brief заполняет массив значениями, введёнными пользователем.
 * @param arr  массив для заполнения
 * @param n - размер массива
 * @details заполняет каждый элемент через getValue()
 */
void fillArray(int* arr, const int n);

/**
 * @brief заполняет массив случайными числами в диапазоне [-10, 20].
 * @param arr - массив для заполнения
 * @param n - размер массива
 * @details использует rand() для генерации значений
 */
void fillArrayRandom(int* arr, const int n);

/**
 * @brief создает копию массива
 * @param arr - исходный массив
 * @param n - размер массива
 * @return указатель на новый массив-копию
 */
int* copyArray(int* arr, const int n);

/**
 * @brief выводит элементы массива в консоль
 * @param arr - указатель на массив
 * @param n - размер массива (выводит n элементов)
 */
void printArray(const int* arr, const int n);

/**
 * @brief вычисляет сумму элементов с нечётными индексами
 * @param arr - указатель на массив
 * @param n - количество элементов
 * @return int - сумма элементов с нечётными индексами
 */
int sumOfOddIndexedElements(const int* arr, const int n);

/**
 * @brief подсчитывает количество элементов, больших A и кратных 5
 * @param arr - указатель на массив
 * @param n - количество элементов
 * @param A - число для сравнения
 * @return количество элементов, удовлетворяющих условию
 */
int countElementsGreaterThanAAndMultipleOf5(const int* arr, const int n, int A);

/**
 * @brief делит элементы с чётными индексами на первый элемент
 * @param arr - указатель на массив
 * @param n - количество элементов
 * @details первый элемент должен быть не равен 0
 */
void divideEvenIndexedByFirstElement(int* arr, const int n);

enum Range
{
    min_r = -10,
    max_r = 20
};

enum {
    FArray = 1,
    FRandom = 2
};

/**
* @brief точка входа в программу
* @return 0, если программа выполнена корректно, иначе 1
*/
int main()
{
    srand(time(0)); //инициализирование генератора rand(), чтобы при каждом запуске программы были разные случайные числа 
    size_t n = getSize(); //size_t беззнаковый целочисленный тип, используется  для индексов и размера массива 
    int* arr = new int[n]; //int* — это указатель на целое число, используетсяс для передачи массивов в функции 
    cout << "Enter the way to fill array: " << (int)FArray << " to find manually, " << (int)FRandom << " to fill randomly ? ";
    int choice = getValue();
    switch (choice)
    {
    case FArray:
        fillArray(arr, n);
        break;
    case FRandom:
        fillArrayRandom(arr, n);
        break;
    default:
        cout << "Invalid choice" << endl;
        delete[] arr;
        break;
    }
    int* arrCopy = copyArray(arr, n); // Создаем копию исходного массива 
    cout << "Original array: ";
    printArray(arr, n);
    
    // 1. Сумма элементов с нечётными индексами
    cout << "Sum of elements with odd indices: " << sumOfOddIndexedElements(arrCopy, n) << endl;
    
    // 2. Количество элементов > A и кратных 5
    cout << "Enter number A: ";
    int A = getValue();
    cout << "Count of elements greater than " << A << " and multiple of 5: " 
         << countElementsGreaterThanAAndMultipleOf5(arrCopy, n, A) << endl;
    
    // 3. Деление элементов с чётными индексами на первый элемент
    if (arrCopy[0] == 0) {
        cout << "First element is zero, cannot divide" << endl;
    } else {
        divideEvenIndexedByFirstElement(arrCopy, n);
        cout << "Array after dividing even indexed elements by first element: ";
        printArray(arrCopy, n);
    }
    
    cout << "Original array: ";
    printArray(arr, n);

    delete[] arr;
    delete[] arrCopy;
    return 0;
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Error" << endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    cout << "Enter n: ";
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Error" << endl;
        abort();
    }
}

void fillArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i + 1 << "] = ";
        arr[i] = getValue();
    }
}

void fillArrayRandom(int* arr, const int n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = min_r + rand() % (max_r - min_r + 1);  // Генерация числа в диапазоне[-10, 20]
    }
}

int* copyArray(int* arr, const int n)
{
    int* newArr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }
    return newArr;
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumOfOddIndexedElements(const int* arr, const int n)
{
    int result = 0;
    for (size_t i = 1; i < n; i += 2) // Индексы 1, 3, 5 и т.д.
    {
        result += arr[i];
    }
    return result;
}

int countElementsGreaterThanAAndMultipleOf5(const int* arr, const int n, int A)
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

void divideEvenIndexedByFirstElement(int* arr, const int n)
{
    int firstElement = arr[0];
    for (size_t i = 0; i < n; i += 2) // Индексы 0, 2, 4 и т.д.
    {
        arr[i] /= firstElement;
    }
}
