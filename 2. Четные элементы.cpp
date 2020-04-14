//Мальцев Роман, лаб. 2, Поиск четных элементов
#include <iostream>
#include <stdlib.h>
using namespace std;

void main()
{
	int n, a, b;
	int Arr[100];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> Arr[i];
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			a = Arr[i];
			Arr[i] = -1;
			n++;
			for (int j = i + 1; j < n; j += 2)
			{
				b = Arr[j];
				Arr[j] = a;
				a = Arr[j + 1];
				Arr[j + 1] = b;
			}
			i++;
		}

	}

	for (int i = 0; i < n; i++)
		cout << Arr[i] << " ";
}
