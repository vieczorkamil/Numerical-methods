#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/*
	Determining the interval for all real roots of a polynomial
*/

float top_line(int n, float a[])
{
    int counter = 0;
    float b;
    float beta = 0.01;
    while (counter != n)
    {
        counter = 0;
        //Horner scheme
        b = a[n];
        if (b > 0)
            counter++;
        else
        {
            beta += 0.01;
            continue;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            b = (b * beta) + a[i];
            if (b >= 0)
                counter++;
            else
            {
                beta += 0.01;
                continue;
            }
        }
    }
    return beta;
}

float bottom_line(int n, float a[])
{
    int counter = 0;
    float b;
    float alfa = 0.01;
    //conversion of a polynomial
    int u = n;
    for (int i = n; i >= 0; i--)
    {
        a[i] = a[i] * pow(-1, u);
        if (i % 2 == 1)
            a[i] = a[i] * (-1.0);
    }
    while (counter != n)
    {
        counter = 0;
        //Horner scheme
        b = a[n];
        if (b > 0)
            counter++;
        else
        {
            alfa += 0.01;
            continue;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            b = (b * alfa) + a[i];
            if (b >= 0)
                counter++;
            else
            {
                alfa += 0.01;
                continue;
            }
        }
    }
    return -alfa;
}

int main()
{

    int n, i, j;
    float alfa = 0.01, beta = 0.01, b;

    cout << "Pass n: ";
    cin >> n;

    float *a;
    a = new float[n];

    cout << endl
         << "Pass an: ";
    for (i = n; i >= 0; i--)
    {
        cout << "Pass the value of the coefficient at x^" << i << ": ";
        cin >> a[i];
    }
    cout << "Top line of function roots : " << top_line(n, a) << endl;
    cout << "Bottom line of function roots : " << bottom_line(n, a) << endl;
    cout << "[-alfa ; beta] = [" << bottom_line(n, a) << " ; " << top_line(n, a) << "]" << endl;
    system("pause");
    return 0;
}