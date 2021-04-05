#include <iostream>
#include <cstdio>
#include <cmath>

#define PI 3.14159265359

using namespace std;

float factorial(float a)
{
    if (a == 1.0)
        return 1.0;
    if (a > 1.0)
        return a * factorial(a - 1.0);
}

int main()
{
    //program that determines the value of cos(x)
    int i = 1;
    double x;
    /*
        w = result
        eps = precision
        r = rest
    */
    double w = 1.0, eps, r;
    r = 1.0;
    cout << "Pass a value x for the function cos(x) ";
    cin >> x;
    x = fmod(x, 2 * PI);
    cout << "Pass precision eps: ";
    cin >> eps;
    while (abs(r) > eps)
    {
        if (i % 2 == 0)
        {
            r = ((pow(x, 2 * i)) / (factorial(2 * i)));
            w = w + r;
            i++;
        }
        else
        {
            r = (-1.0) * pow(x, 2 * i) / factorial(2 * i);
            w = w + r;
            i++;
        }
    }

    cout << "Approximate value cos(x) = " << w << endl;
    cout << "Number of iterations: " << i << endl;
    cout << "Value for functions from the library cmath.h: cos(x) = " << cos(x) << endl;
    system("PAUSE");
    return 0;
}
