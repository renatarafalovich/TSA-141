#include <iostream>
#include <cmath>

using namespace std;
/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
int getValue();

/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
double getDouble();

/**
 * @brief проверяет, что введенное значение удовлетваряет условию n>=0
 * @param n считанное значение
*/
void checkN(const int n);

/**
 * @brief Рассчитывает сумму n первых членов ряда
 * @param n заданное число членов
 * @return сумму n первых членов ряда
*/
double sumN(const int n);

/**
 * @brief Рассчитывает следующий член ряда через рекуррентное выражение
 * @param current текущий член ряда
 * @param i текущий индекс (начиная с 1)
 * @return следующий член ряда
*/
double getNext(const double current, const int i);

/**
 * @brief проверяет, что введенное значение удовлетваряет условию e>0
 * @param e считанное значение
*/
void checkE(const double e);

/**
 * @brief Рассчитывает сумму членов ряда, пока по модулю член не станет меньше e
 * @param e заданная точность
 * @return сумму членов ряда, не превышающих по модулю e
*/
double sumE(const double e);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Введите число членов ряда для рассчета последовательности: ";
    int n = getValue();
    checkN(n);
    cout<<"Сумма "<<n<<" членов ряда равна "<<sumN(n)<<endl;
    cout<<"Введите погрешность для рассчета последовательности: ";
    double e = getDouble();
    checkE(e);
    cout<<"Сумма членов ряда с точностью е равна "<<sumE(e)<<endl;;
    return 0;
}

int getValue()
{
    int value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Ошибка ввода"<<endl;
        abort();
    }
    return value;
}

double getDouble()
{
    double value = 0.0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Ошибка ввода"<<endl;
        abort();
    }
    return value;
}

void checkN(const int n)
{
    if (n < 0)
    {
        cout << "Ошибка ввода"<< endl;
        abort();
    }
}

double sumN(const int n)
{
    // Первый член: k=0
    const double first = 1.0; // (-1)^0/0! = 1
    double current = first;
    double result = first;
    for (int i = 1; i < n; i++)
    {
        current = getNext(current, i);
        result += current;
    }
    return result;
}

double getNext(const double current, const int i)
{
    // Следующий член: current * (-1)/i
    return current * (-1.0) / i;
}

void checkE(const double e)
{
    if (!(e > 0))
    {
        cout << "Ошибка ввода"<< endl;
        abort();
    }
}

double sumE(const double e)
{
    // Начинаем с первого члена
    const double first = 1.0; // k=0
    double current = first;
    double result = current;
    int i = 1;
    while (abs(current) > e)
    {
        current = getNext(current, i);
        result += current;
        i++;
    }
    return result;
}
