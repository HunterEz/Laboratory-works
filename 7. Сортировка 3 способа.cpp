#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;


int* cr_mass(int n, int mass[])
{
	/*Создание массива*/
	cout << "Несортированый массив:" << '\t';
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 101 - 50;
		cout << mass[i] << " ";
	}
	cout << endl;
	return mass;
}


int* sort_1(int n, int mass[])
{/*Сортировка методом вставки*/
	int y;
	int j;
	for (int i = 1; i < n; i++)
	{
		y = mass[i];
		j = i - 1;
		while (j >= 0 && mass[j] > y)
		{
			mass[j + 1] = mass[j];
			j--;
			mass[j + 1] = y;
		}
		for (int i = 0; i < n; i++)
		{
			cout << mass[i] << " ";
		}
		cout << endl;
	}
	return mass;
}


int* sort_2(int n, int mass[])
{/*Сортировка методом пузырька*/
	int a;
	for (int i = 0; i < n; i++)
	{
		for (int j = (n - 1); j >= (i + 1); j--)
		{
			if (mass[j] < mass[j - 1])
			{
				a = mass[j];
				mass[j] = mass[j - 1];
				mass[j - 1] = a;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << mass[i] << " ";
		}
		cout << endl;
	}
	return mass;
}


int* sort_3(int n, int mass[])
{/*Сортировка методом выбора*/

	for (int i = 0; i < n - 1; i++)
	{
		int a = i;
		for (int j = i + 1; j < n; j++)
		{
			if (mass[j] < mass[a])
			{
				a = j;
			}
		}
		int b = mass[i];
		mass[i] = mass[a];
		mass[a] = b;
		for (int i = 0; i < n; i++)
		{
			cout << mass[i] << " ";
		}
		cout << endl;
	}
	return mass;
}








int* print_mass(int n, int mass[])
{/*Вывод массива*/
	cout << "Сортированый массив:" << '\t';
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	return mass;
}



int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(0));

	int n, k;

	cout << "Введите количество элементов массива: ";

	cin >> n;

	int* mass = new int[n];

	cr_mass(n, mass);

	cout << "1.Метод вставки\n";

	cout << "2.Метод обмена\n";

	cout << "3.Метод выбора\n";

	cout << "Введите номер способа сортировки: ";

	cin >> k;

	switch (k)
	{
	case 1:
		sort_1(n, mass); print_mass(n, mass); break;
	case 2:
		sort_2(n, mass); print_mass(n, mass); break;
	case 3:
		sort_3(n, mass); print_mass(n, mass); break;
	}
}

