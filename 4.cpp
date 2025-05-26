#include <iostream>
#include <cmath>
using namespace std;

/**
 * Вычисляет значение функции y = x + √x + ∛x - 2.5
 * @param x - аргумент функции
 * @return значение функции в точке x
 */
double functionY(double const x);

/**
 * Табулирует функцию на интервале [x0, xend] с шагом step
 * @param x0 - начальное значение x
 * @param xend - конечное значение x
 * @param step - шаг табуляции
 */
void tabulateFunction(double const x0, double const xend, double const step);

/**
 * @brief считывает значение с клавиатуры
 * @return введенное значение
 */
double get();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main() {
    cout << "Enter the start of the interval x min: ";
    double x0 = get();

    cout << "Enter the end of the interval x max: ";
    double xend = get();

    cout << "Enter the step ∆x: ";
    double step = get();

    if (step <= 0) {
        cout << "Step must be positive" << endl;
        return 1;
    }
    if (x0 > xend) {
        cout << "x min is greater than x max" << endl;
        swap(x0, xend);
    }

    tabulateFunction(x0, xend, step);
    return 0;
}

double functionY(double x) {
    if (x >= 0)
        return x + sqrt(x) + cbrt(x) - 2.5;
    return NAN;
}

void tabulateFunction(double x0, double xend, double step) //табулирование функции
{
    cout << "x | y(x)" << endl;
    for (double x = x0; x < xend + step; x += step) {
        cout << x << " | ";
        double y = functionY(x);
        if (isnan(y))
            cout << "undefined";
        else
            cout << y;
        cout << endl;
    }
}

double get() {
    double value = 0;
    cin >> value;
    if (cin.fail()) {
        cout << "Incorrect value" << endl;
        abort();
    }
    return value;
}
    
