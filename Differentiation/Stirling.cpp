#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
	Program to calculate the first derivative of a function at a point using Stirling formula
*/

int main()
{
	float x0, b, h;
	int n;
	cout << "Pass the point at which to calculate the first derivative of ln(x0) : x0 = " << endl;
	cin >> x0;
	cout << "Pass bottom or top line " << endl; //[x,b] or [b,x]
	cin >> b;
	cout << "Pass the step" << endl;
	cin >> h;
	if (b < x0)
		n = ceil(fabs(b - x0) / h);
	if (b > x0)
		n = floor(fabs(b - x0) / h);
	cout << "n = " << n << endl;
	float *x;
	x = new float[(2 * n) + 1];
	if (x0 < b)
		x[0] = x0 - (n * h);
	else
		x[0] = b;
	for (int i = 1; i < (2 * n) + 1; i++)
	{
		x[i] = x[i - 1] + h;
	}
	cout << "x:" << endl;
	for (int i = 0; i < (2 * n) + 1; i++)
	{
		cout << "x[" << i << "] = " << x[i] << endl;
	}
	float *y;
	y = new float[(2 * n) + 1];
	// y = function formula for differentiation in this example y = ln(x)
	for (int i = 0; i < (2 * n) + 1; i++)
	{
		y[i] = log(x[i]);
	}
	cout << "y:" << endl;
	for (int i = 0; i < (2 * n) + 1; i++)
	{
		cout << "y[" << i << "] = " << y[i] << endl; //ln (1.0) !=0 (!?)
	}
	float **delta = new float *[(2 * n)];
	for (int i = 0; i < (2 * n); i++)
	{
		delta[i] = new float[(2 * n) - i];
	}
	// difference tables
	for (int i = 0; i < (2 * n); i++)
	{
		for (int j = 0; j < (2 * n) - i; j++)
		{
			delta[j][i] = y[j + 1] - y[j];
			y[j] = delta[j][i];
		}
	}
	cout << "Difference tables :" << endl;
	for (int i = 0; i < (2 * n); i++)
	{
		for (int j = 0; j < (2 * n) - i; j++)
		{
			cout << delta[i][j] << "\t";
		}
		cout << endl;
	}
	//Calculate differentiation
	float f = 0.0, q;
	for (int i = 0; i < (2 * n); i = i + 2)
	{
		if (i == 0)
			q = 1;
		else if (i == 2)
			q = 6;
		else if (i == 4)
			q = 30;
		f += (1.0 / q /* 1/1  1/6  1/30  1/140 */) * ((delta[(((2 * n) - i) / 2)][i] + delta[((2 * n - i) / 2) - 1][i]) / 2);
	}
	f *= (1 / h);
	cout << "Approximate value (numerically calculated) of f(x)=x^4 at point x0 = " << x0 << " is equal:" << endl;
	cout << "ln(" << x0 << ") = " << f << endl;
	cout << "The absolute error in determining the derivative is equal = " << fabs(1 - f) << endl;
	delete[] x;
	delete[] y;
	delete[] delta;
	system("pause");
	return 0;
}