#include <iostream>
#include <math.h>
using namespace std;


double f(double x)
{
	double f;
	f = 0.1 * pow(x, 2) - x * log(x);
	return f;

}

double f1(double x)
{
	double f1;
	f1 = 0.2 * x - 1 - log(x);
	return f1;

}


double f2(double x)
{
	double f2;
	f2 = 0.2 - 1 / x;
	return f2;

}

double Newton(double e)
{
	double x;
	double x0 = 0;
	int n = 1;
	cout << "Введите корень в промежутке от a до b: ";
	cin >> x;
	if ((f(x) * f2(x)) > 0) {

		while (1) {
			x = x - f(x) / f1(x);
			if (fabs(x - x0) < e) {
				break;
			}
			x0 = x;
			cout << "n=" << n++ << "\t" << "x= " << x << endl;
		}
		cout << "x=" << x << endl;
	}
	else {
		cout << "Метод не сходится!";
	}
	return 0;
}

double Popolam(double a, double b, double e)
{
	double x;
	int n = 1;
	while (1) {
		x = ((a + b) / 2);
		if (fabs(f(x)) < e)
		{
			break;
		}
		if (f(a) * f(x) < 0) {
			a = a;
			b = x;
		}
		else {
			a = x;
			b = b;
		}
		cout << "n=" << n++ << "\t" << "x= " << x << endl;
	}
	cout  << "x=" << x << endl;
	return 0;
}


double Iter(double e)
{
	double x1, x;
	int n = 1;
	cout << "x0= ";
	cin >> x;
	x1 = x;
	do {
		x = x1;
		x1 = x + f(x);
		cout << "n=" << n++ << "\t" << "x= " << x << endl;
	} while (fabs(x - x1) > e);

	cout << "x= " << x << endl;
	return 0;
}



void main()
{
	setlocale(LC_ALL, "rus");
	double a, b, e, ch;
	a = 1;
	b = 2;
	e = 0.000001;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "e=" << e << endl;
	cout << "Выберите метод: 1 - Метод Ньютон, 2 - Половинное деление 3 - Метод Итерации" << endl;
	cin >> ch;
	if (ch == 1) {
		Newton(e);
	}
	else if (ch == 2) {
		Popolam(a, b, e);
	}
	else if (ch == 3) {
		Iter(e);
	}
	else {
		cout << "Неверный ввод!";
	}
}
