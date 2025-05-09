#include <iostream>
#include <limits>
#include <cmath> // Для sqrt и cbrt
double getValue();
void checkStep(const double step);
double getY(const double x);
bool isDomain(const double x);

using namespace std;
int main()
{
    cout << "Enter xn: ";
    double xstart = getValue();
    cout << "Enter xk: ";
    double xend = getValue();
    cout << "Enter step: ";
    double step = getValue();
    checkStep(step);
    for (double x = xstart; x < xend + step; x += step) 
{
        cout << "x = " << x;
        if (isDomain(x)) 
{
            cout << " y = " << getY(x) << endl;
        } 
        else 
        {
            cout << " not in domain" << endl;
        }
    }
    return 0;
}

double getValue() {
    double value;
    cin >> value;
    if (cin.fail()) 
    {
        cout << "Incorrect value" << endl;
        abort();
    }
    return value;
}

void checkStep(const double step) 
{
    if (step <= 0) 
    {
        cout << "Error value" << endl;
        abort();
    }
}

double getY(const double x) 
{
    return x + sqrt(x) + cbrt(x) - 2.5;
}

bool isDomain(const double x)  
{
    // Для определения допустимости вычисления sqrt(x), x должен быть >= 0
    return x >= 0;
}
