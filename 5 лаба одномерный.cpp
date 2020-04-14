// Мальцев Роман, лаб. 5, Динамичемкие массивы двумерный
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int* cr_mass(int n, int mass[])
{ /*Создание массива*/
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 101 - 50;
	}
	return mass;
}

int* chg_mass(int &n, int mass[])
{	/*Удалиение четных элементов*/
	int b = 0;
	for (int i = 0 + b; i < n + b; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = i - b; j < n+1; j++)
			{
				mass[j] = mass[j + 1];

			}
			n--;
			b++;
		}
	}
	return mass;
}

void print_mass(int n, int mass[])
{	/*Вывод итогового массива*/
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, k;
	
	cout << "Введите количество элементов массива \n";
	cin >> n;
	int* mass = new int[n];
	do

	{

		cout << "1.Формирование массива\n";

		cout << "2.Печать массива\n";

		cout << "3.Удаление четных элементов из массива\n";

		cout << "4.Выход\n";

		cin >> k;

		switch (k)

		{

		case 1:
			cr_mass(n, mass); break;//выделение памяти и заполнение

		case 2:
			 print_mass(n, mass); break;//печать

		case 3:
			chg_mass(n, mass); break;//Удаление 

		}
	}
		while (k != 4);//выход
	
	
	
	delete[] mass;
	return 0;
}

