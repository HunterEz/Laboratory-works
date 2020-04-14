// Мальцев Роман, лаб. 8 (Новая нумерация : 7) , Функции и массивы (4э)
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

int** cr_memory2(int n, int m, int** mass)
{	/*Выделение памяти под массив*/

	for (int i = 0; i < n; i++)
	{
		mass[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
		cin>>	mass[i][j] ;

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

int** cr_mass2(int n, int m, int** mass2)
{ /*печать*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			cout << mass2[i][j] << '\t';
		}
		cout << endl;
	}
	return mass2;

}


void search(int n, int m, int** mass)
{
	bool Ind = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mass[i][j] < 0)
			{
				Ind = 1;
				cout << i << "- Строка с отрицательным элементом" << endl;
				break;
			}
		}
	}
	if (Ind == 0)
	{
		cout << "В массиве нет отрицательных элементов" << endl;
	}
}


int** ch_mass(int n, int m, int** mass, int** mass2)
{
	int k;
	k = 0;
	bool ind = 0;
	for (int i = 0; i < n; i++)
	{
		mass2[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < m; j++)
		{
			if (mass[i][j] < 0)
			{
				ind = 1;
				
			}
			
			
		}
		if (ind == 0)
		{
			for (int a = 0; a < m; a++)
			{
				mass2[k][a] = mass[i][a];
			}
			k++;
		}
		ind = 0;
	
	}
	for (k; k < n; k++)
	{
		for (int j = 0; j < m; j++)
		{
			mass2[k][j] = 0;
		}
	}
	return mass2;
}

int** del_mass(int n, int** mass, int** mass2)
{	/*Удалиение массивов*/

	for (int i = 0; i < n; i++)
	{
		delete[] mass[i];
	}
	delete[] mass;
	for (int i = 0; i < n; i++)
	{
		delete[] mass2[i];
	}
	delete[] mass2;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, m;
	int x;
	cout << " Введите количество строк и столбцов: \n";
	cin >> n >> m;
	cout << "Введите способ ввода: 0 - случайный, 1 - с клавиатуры" << endl;
	cin >> x;
	cout << endl;
	int** mass = new int* [n];
	int** mass2 = new int* [n];
	if (x == 0)
	{
		cr_memory(n, m, mass);
	}
	else if (x==1)
	{
		cr_memory2(n, m, mass);
	}
	else
	{
		cout << "Ошибка ввода";
		return 0;
	}
	cr_mass(n, m, mass);
	search(n, m, mass);
	ch_mass(n, m, mass, mass2);
	cr_mass2(n, m, mass2);
	del_mass(n, mass, mass2);
	return 0;
}
