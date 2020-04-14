//Мальцев Роман, лаб. 5, Динамические массивы двумерный
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int** cr_memory(int n, int m, int** mass)
{	/*Выделение памяти под массив*/
	
	for (int i = 0; i < n; i++)
	{
		mass[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mass[i][j] = rand() % 101 - 50;
			
		}

	}
	return mass;
}

int** cr_mass(int n, int m, int** mass)
{ /*печать*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
	
			cout << mass[i][j] << '\t';
		}
		cout << endl;
	}
	return mass;

}

void ch_mass(int n, int m,int k, int** &mass)
{	/*Добавление новых столбцов в начале массива*/
	
	int** mass2 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mass2[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{

			mass2[i][j] = rand() % 101 - 50;
			cout << mass2[i][j] << '\t';
		}
		for (int j = k; j < m ; j++)
		{
			mass2[i][j] = mass[i][j-k];
			cout << mass2[i][j] << '\t';
		}
		cout << endl;
		
	}
	mass = mass2;
}

 int** del_mass(int n, int** mass)
{	/*Удалиение массивов*/

	for (int i = 0; i < n; i++)
	{
		delete[] mass[i];
	}
		delete[] mass;
	return 0;
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, m, a;
	cout << " Введите количество строк и столбцов: \n";
	cin >> n >> m;
	cout << endl;
	int** mass = new int* [n];

	do
	{

		cout << "1.Формирование массива\n";

		cout << "2.Печать массива\n";

		cout << "3.Добавление в k столбцов в массив\n";

		cout << "4.Выход\n";

		cin >> a;

		switch (a)

		{

		case 1: cr_memory(n, m, mass); break;//выделение памяти и заполнение

		case 2: cr_mass(n, m, mass); break;//печать

		case 3:
			cout << " Введите количество новых столбцов в начале матрицы \n";
			cout << endl;

			int k;
			cin >> k;
			m += k;
			ch_mass(n, m, k, mass); break;//добавление

		}
	}
		while (a != 4);//выход
	
	del_mass(n, mass);
	return 0;
}
