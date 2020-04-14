#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;



int NOD(int n1, int n2)
{
	int tmp;
	if (n1 == n2)
	{
		return n1;
	}
	int d = n1 - n2;
	if (d < 0) {
		d = -d;
		tmp = NOD(n1, d);
	}
	else
	{
		tmp = NOD(n2, d);
		return tmp;
	}
}


int NOK(int n1, int n2)
{
	int result;
	result = n1 * n2 / NOD(n1, n2);
	return result;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int n1, n2;
	cout << "Первое число равно: ";
	cin >> n1;
	cout << "Второе число равно: ";
	cin >> n2;
	cout << "Наименший общий делитель: " << NOD(n1, n2) << endl;
	cout << "Наименьшее общее кратное равно: ";
	cout << NOK(n1, n2);
	return 0;
}
