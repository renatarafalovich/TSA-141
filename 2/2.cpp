#include <iostream>
#include <cmath> // Для использования M_PI и pow
#include <iomanip> // Для форматирования вывода
using namespace std;

/**
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return введенное значение
 */
double getValue();

/**
 * @brief вычисляет объем шара
 * @param radius - радиус шара
 * @return объем шара
 */
double calculateVolume(double radius);

/**
 * @brief вычисляет площадь поверхности шара
 * @param radius - радиус шара
 * @return площадь поверхности шара
 */
double calculateSurfaceArea(double radius);

/**
 * @brief проверяет, что радиус положительный
 * @param radius - радиус шара
 */
void checkR(double radius);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main() 
{
    cout << "Enter the radius of the sphere: ";
    double radius = getValue();

  checkR(radius);


    cout << fixed << setprecision(2); // Устанавливаем вывод с двумя знаками после запятой

    cout << "Volume of the sphere: " << calculateVolume(radius) << endl;
    cout << "Surface area of the sphere: " << calculateSurfaceArea(radius) << endl;

    return 0;
}

double getValue()
{
    double value=0;
    cin >> value;
    if (cin.fail()) 
    {
        cout << "Incorrect input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return getValue(); // Рекурсивный вызов
    }
    return value;
}

double calculateVolume(double radius) 
{
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double calculateSurfaceArea(double radius) 
{
    return 4.0 * M_PI * pow(radius, 2);
}  

void checkR(double radius)
{
    if (radius < 0) 
    {
        cout << "Radius cannot be negative." << endl;
       abort();
    }
} 
