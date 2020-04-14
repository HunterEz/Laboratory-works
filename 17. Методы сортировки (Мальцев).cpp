// Мальцев Роман, лаб. 17, Методы сортировки массивов данных: подсчётом и быстрая
#include <ctime>
#include <iostream>
using namespace std;


void fast_sort(int* mass, int n)
{
	int i = 0;
	int j = n - 1;
	int mid = mass[n / 2];
	do
	{
		while (mass[i] < mid)
		{
			i++;
		}
		while (mass[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			int t = mass[i];
			mass[i] = mass[j];
			mass[j] = t;
			i++;
			j--;
		}

	} while (i <= j);

	for (int i = 0; i < n; i++)

	{

		cout << mass[i] << " ";

	}

	cout << endl;

	if (j > 0)
	{
		fast_sort(mass, j + 1);
	}
	if (i < n)
	{
		fast_sort(&mass[i], n - i);
	}
}

void CountingSort(int* mass, int* c, int n, int k)
{
	for (int i = 0; i < k; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		c[mass[i]] = c[mass[i]] + 1;
	}
	int i = 0;
	for (int j = 0; j < k; j++)
	{
		while (c[j] != 0)
	{
			mass[i] = j;

			c[j]--;

			i++;

			for (int i = 0; i < n; i++)

			{

				cout << mass[i] << " ";

			}

			cout << endl;
		}
	}
}

int* create_mass(int n)
{
	int swtc;

	int* mass = new int[n]; 

	cout << "1. Случайный ввод" << endl;

	cout << "2. Ввод с клавиатуры" << endl;

	cin >> swtc;

	if (swtc >2 || swtc < 1)

	{
		cout << "Не верный ввод" << endl;
	}

	switch (swtc)
	{
		case 1:
		{
			cout << "Исходный массив: ";

			for (int i = 0; i < n; i++)

			{

				mass[i] = rand() % 100 - 50;
	
				cout << mass[i] << " ";

			}
		}
		break;
		case 2:
		{
			cout << "Исходный массив: ";

			for (int i = 0; i < n; i++)

			{

				cin >> mass[i];

			}
		}
		break;
	}

	cout << endl;

	return mass;
}

int* create_mass2(int n)
{
	int swtc;

	int* mass2 = new int[n];

	cout << "1. Случайный ввод" << endl;

	cout << "2. Ввод с клавиатуры" << endl;

	cin >> swtc;

	if (swtc > 2 || swtc < 1)

	{
		cout << "Не верный ввод" << endl;
	}

	switch (swtc)
	{
	case 1:
	{
		cout << "Исходный массив: ";

		for (int i = 0; i < n; i++)

		{

			mass2[i] = rand() % 100;

			cout << mass2[i] << " ";

		}

	}
	break;
	case 2:
	{
		cout << "Исходный массив: ";

		for (int i = 0; i < n; i++)

		{

			cin >> mass2[i];

		}
	}
	break;
	}
	cout << endl;
	return mass2;
}

void print_mass(int n, int* mass)
{

	cout << "Сортированный массив: ";

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

	int n, a, k;

	int* mass, * mass2;

	do
	{

		cout << "1. Быстрая сортировка" << endl;

		cout << "2. Сортировка подсчетом" << endl;;

		cout << "3. Выход" << endl;

		cout << ">>";

		cin >> a;

		cout << endl;

		switch (a)
		{

		case 1:
		{
			cout << "Введите количество элементов массива: ";

			cin >> n;

			cout << endl;

			mass = create_mass(n);

			cout << endl;

			cout << "Процесс сортировки :" << endl;

			fast_sort(mass, n);

			cout << endl;

			print_mass(n, mass);

			cout << endl;

		} 
		break;
		case 2:
		{

			cout << "Введите количество элементов массива: ";

			cin >> n;

			cout << endl;

			mass2 = create_mass2(n);

			cout << endl;

			cout << "Введите верхнюю границу диапозона заданных чисел: " << endl;

			cin >> k;

			cout << endl;

			int* c = new int[k];

			cout << "Процесс сортировки :" << endl;

			CountingSort(mass2, c, n, k);

			cout << endl;

			print_mass(n, mass2);

			cout << endl;

		}
		break;
		}

	} while (a != 3);

	system("pause");

}
