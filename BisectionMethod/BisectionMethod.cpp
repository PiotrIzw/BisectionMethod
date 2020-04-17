#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>
using namespace std;

class BisectionMethod {
public:
	double functionToCalculate(double x);
	double bisect(double a, double b, float precision);
};

double BisectionMethod::functionToCalculate(double x)
{
	return cos((x * x * x) - (2 * x));
}

double BisectionMethod::bisect(double a, double b, float precision)
{
	if (functionToCalculate(a) * functionToCalculate(b) < 0)
	{
		double x = a;
		while ((b - a) >= precision)
		{
			x = (a + b) / 2;
			cout << "a = " << a << ",  b = " << b << ",  x = " << x << endl;

			if (functionToCalculate(x) == 0.0){
				break;
			}
			else if (functionToCalculate(x) * functionToCalculate(a) < 0) {
				b = x;
			}
			else {
				a = x;
			}
		}
		return x;
	}
}



int main()
{

	BisectionMethod solution;
	double a, b, precision;

	cout << "Set range:" << endl;
	cout << "a) ";
	cin >> a;

	cout << "b) ";
	cin >> b;

	cout << "Set precision:" << endl;
	cin >> precision;

	cout << "x = " << solution.bisect(a, b, precision) << endl;

	system("Pause");
	return 0;
}
