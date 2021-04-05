#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
	Program to determine the value of the Newton interpolation polynomial
*/

void parallel_nodes(float a, float b, int n, float *z)
{
	float sum = fabs(b - a) / n;
	z[0] = a;
	for (int i = 1; i < n + 1; i++)
	{
		z[i] = z[i - 1] + sum;
	}
}
void value_y(int n, float *y, float nodes[])
{
	for (int i = 0; i < n + 1; i++)
	{
		y[i] = log(nodes[i]); // f(x)=ln(x)
	}
}
float factorial(int n)
{
	if (n < 2)
		return 1;
	return n * factorial(n - 1);
}

int main()
{
	float a, b, x;
	int n;
	cout << "Pass bottom and top line" << endl;
	cin >> a >> b;
	cout << "Pass the degree of the polynomial" << endl;
	cin >> n;
	cout << "Pass the point at which to determine the value of interpolation polynomial" << endl;
	cin >> x;
	float h = fabs(b - a) / n;
	float *z;
	z = new float[n + 1];
	parallel_nodes(a, b, n, z);
	float *y;
	y = new float[n + 1];
	value_y(n, y, z); //for f(x)=x^4
	float *p;
	p = new float[n + 1];
	for (int i = 0; i < 4; i++)
	{
		p[i] = y[i];
	}

	float **delta = new float *[n];
	for (int i = 0; i < n; i++)
	{
		delta[i] = new float[n - i];
	}
	// difference tables
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			delta[j][i] = p[j + 1] - p[j];
			p[j] = delta[j][i];
		}
	}

	cout << "Difference tables :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			cout << delta[i][j] << "\t";
		}
		cout << endl;
	}
	// Calculate interpolation polynomial value
	float w, product = 1;
	w = y[0];
	for (int i = 1; i <= n; i++)
	{
		product *= (x - z[i - 1]);
		w += (delta[0][i - 1]) * product / (factorial(i) * pow(h, i));
	}
	cout << "The value of the interpolation polynomial (Newton) at the point x = " << x << " is equal = " << w << endl;
	delete[] p;
	delete[] delta;
	delete[] y;
	delete[] z;
	system("pause");
	return 0;
}