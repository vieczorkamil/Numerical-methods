#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
	Program to calculate the first derivative of a function at a point using Taylor formula
*/

int main()
{
	float x0, h;
	int n;
	cout << "Pass the point at which to calculate the first derivative of x^4 : x0 = " << endl;
	cin >> x0;
	cout << "Pass the maximum order of difference used to approximate the derivative" << endl;
	cin >> n;
	cout << "Pass the step" << endl;
	cin >> h;

	float *x;
	x = new float[n + 1];
	x[0] = x0;
	for (int i = 1; i < n + 1; i++)
	{
		x[i] = x[i - 1] + h;
	}
	cout << "x:" << endl;
	for (int i = 0; i < n + 1; i++)
	{
		cout << "x[" << i << "] = " << x[i] << endl;
	}

	float *y;
	y = new float[n + 1];
	// y = function formula for differentiation in this example y = x^4
	for (int i = 0; i < n + 1; i++)
	{
		y[i] = pow(x[i], 4);
	}
	cout << "y:" << endl;
	for (int i = 0; i < n + 1; i++)
	{
		cout << "y[" << i << "] = " << y[i] << endl;
	}

	float **delta = new float *[n];
	for (int i = 0; i < n; i++)
	{
		delta[i] = new float[(n)-i];
	}
	// difference tables
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n)-i; j++)
		{
			delta[j][i] = y[j + 1] - y[j];
			y[j] = delta[j][i];
		}
	}
	// difference tables
	cout << "Difference tables :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n)-i; j++)
		{
			cout << delta[i][j] << "\t";
		}
		cout << endl;
	}
	//Calculate differentiation
	float f = 0.0, pom;
	for (int i = 1; i < n; i++)
	{
		if (i == 1 || i == 2)
			pom = 1;
		else
			pom = ((11.0 - (i - 3)) / 12.0);
		f += pom * delta[(n) - (i + 1)][i];
	}
	f *= (1 / (h * h));
	cout << "Approximate value (numerically calculated) of f(x)=x^4 at point x0 = " << x0 << " is equal: " << f << endl;
	delete[] x;
	delete[] y;
	delete[] delta;
	system("pause");
	return 0;
}