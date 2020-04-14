// Мальцев Роман, лаб. 9 (Новач нумерация: 10), Работа с функциями (1–3-й столбцы ЛР7э)
#include <iostream>
#include <math.h>
using namespace std;
int* cr_mass(int n, int mass[])
{
	int var;
	cout << "Выберите способ ввода массива(0 - случайный, 1 - с клавиатуры): ";
	cin >> var;
	if (var == 0)
	{
		for (int i = 0; i < n; i++)
		{
			mass[i] = rand() % 101 - 50;
			cout << mass[i] << " ";
		}
	}
	else if (var == 1)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> mass[i];
		}
	}
	else
	{
		cout << "Не верно введен номер задания!";
	}
	cout << endl;
	return mass;
}

float Distance(float x1, float y1, int x0=0, int y0=0)
{
	return	(sqrt((pow(x1-x0, 2) + pow(y1-y0, 2))));
}

float Average(int n, int mass[], ...)
{
	float k;
	k = 0;
	float sum;
	sum = 0;
	float result;
	cout << "Нечетные 'лементы: ";
		for (int i=0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			cout << mass[i] << " ";
			sum = sum + mass[i];
			k++;
		}
	}
		cout << endl;
		result = sum / k;
		cout << result;
		return 0;
}

int sum(int k, ...)
{
	int* p = &k;
	int s = 0;
	for (int i=k; i != 0; i--)
	{
		s += *(++p);
	}
	return s / k;
}

template<class T>
T Del(T n, T mass[])
{
	int num;
	cout << "Введите номер удаляемого элемента: ";
	cin >> num;
	for (int i = (num-1); i < n; i++)
	{
		mass[i] = mass[i + 1];
	}
	cout << "Массив без элемента: ";
	for (int i = 0; i < (n-1); i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	
	return 0;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int var;
	cout << "Введите номер задания: ";
	cin >> var;
	if (var == 1)
	{
		float x1, y1;
		cout << "Введите координаты точки (x1 и y1): ";
		cin >> x1 >> y1;
		cout << Distance(x1, y1);
	}
	else if (var == 2)
	{
		int k;
		cout << "Введите количество элементов: ";
		cin >> k;
		cout << sum(k, 12, 48, 54, 18);
	}
	else if (var == 3)
	{
		int n;
		cout << "Введите количество элементов: ";
		cin >> n;
		int* mass = new int[n];
		cr_mass(n, mass);
		Del (n, mass);
	}
	else
	{
		cout << "Не верно введен номер задания!";
	}
}


