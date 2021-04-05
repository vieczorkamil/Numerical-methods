#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
	Program to determine the value of the Lagrange interpolation polynomial for parallel nodes and Chebyshev nodes
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
void Chebyshev_nodes(float a, float b, int n, float *zc)
{
	for (int i = 0; i < n + 1; i++)
	{
		zc[i] = (1.0 / 2.0) * ((b - a) * cos((2 * i + 1) * M_PI / (2 * n + 2)) + a + b);
	}
}
void value_y(int n, float *y, float nodes[])
{
	for (int i = 0; i < n + 1; i++)
	{
		y[i] = pow(nodes[i], 4); // f(x)=x^4
	}
}
float value_lagrange(float x, int n, float nodes[], float y[])
{
	float sum;
	float W = 0.0;
	for (int j = 0; j < n + 1; j++)
	{
		sum = y[j];
		for (int i = 0; i < n + 1; i++)
		{
			if (i != j)
				sum *= (x - nodes[i]) / (nodes[j] - nodes[i]);
		}
		W += sum;
	}
	return W;
}

int main()
{
	float a = -10, b = 10, x;
	int n;
	cout << "Pass the degree of the polynomial" << endl;
	cin >> n;
	cout << "Pass the point at which to determine the value of interpolation polynomial" << endl;
	cin >> x;
	float *z;
	float *zc;
	float *y;
	float *yc;
	z = new float[n + 1];
	zc = new float[n + 1];
	y = new float[n + 1];
	yc = new float[n + 1];
	parallel_nodes(a, b, n, z);
	Chebyshev_nodes(a, b, n, zc);
	value_y(n, y, z);
	value_y(n, yc, zc);

	cout << "Parallel nodes :" << endl;
	for (int i = 0; i < n + 1; i++)
	{
		cout << "z[" << i << "] = " << z[i] << endl;
	}

	cout << "The value of the interpolation polynomial (Lagrange'a) at the point x = ";
	cout << x << " is equal = " << value_lagrange(x, n, z, y) << endl;

	//Czebyszew
	cout << "Chebyshev nodes :" << endl;
	for (int i = 0; i < n + 1; i++)
	{
		cout << "zc[" << i << "] = " << zc[i] << endl;
	}

	cout << "The value of the interpolation polynomial (Lagrange'a) at the point x = ";
	cout << x << " is equal = " << value_lagrange(x, n, zc, yc) << endl;

	delete[] z;
	delete[] zc;
	delete[] y;
	delete[] yc;

	system("pause");
	return 0;
}