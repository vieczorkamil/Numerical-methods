#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

clock_t start, stop;
double time1, time2;

/*
	A program that compares the execution time of Horner's and the interaction algorithms
*/

float horner(int n, float a[], float x0)
{ //Horner scheme
    float b;
    b = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        b = (b * x0) + a[i];
    }
    return b;
}

float iteration(int n, float a[], float x0)
{ //iteration scheme
    float W = 0.0;
    for (int i = n; i >= 0; i--)
    {
        W = W + (a[i] * pow(x0, i));
    }
    return W;
}

int main()
{

    int n, i, j;
    float x0;

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
        cout << endl;
    }

    cout << "Pass x : ";
    cin >> x0;

    cout << "Horner scheme: " << horner(n, a, x0) << endl;
    cout << "Iteration scheme: " << iteration(n, a, x0) << endl;

    start = clock();
    for (i = 0; i < 1000000; i++)
        horner(n, a, x0);
    stop = clock();
    time1 = (double)(stop - start) / CLOCKS_PER_SEC;

    start = clock();
    for (i = 0; i < 1000000; i++)
        iteration(n, a, x0);
    stop = clock();
    time2 = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << "Time for a million iterations (Horner scheme) :" << time1 << " seconds" << endl;
    cout << "Time for a million iterations (Iteration scheme) :" << time2 << " seconds" << endl;

    system("pause");
    return 0;
}