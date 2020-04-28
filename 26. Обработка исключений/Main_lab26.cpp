// Мальцев Роман, лаб. 26, Обработка исключений
#include "Lots.h"
#include "Vector_realiz2.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main()

{
	setlocale(LC_ALL, "rus");
	int a;
	cout << "Выберите номер реализации(1 или 2): ";
	cin >> a;
	int	mass[2] = { 1,2 };
	if (a == 1)
	{
		try

		{

			Lots x(2, mass);

			cout << "Элементы группы: ";

			cout << x;

			cout << "Введите индекс\n";

			int i;

			cin >> i;

			cout << "Элемент с индексом " << i << "\n";

			cout << x[i] << endl;

			cout << "Вычитаем элемент!\n";

			--x;

			cout << x;

			cout << "Вычитаем элемент!\n";

			--x;

			cout << x;

			cout << "Вычитаем элемент!\n";

			--x;

		}
		catch (int)
		{
			cout << "ERROR!!!" << endl;
		}
		return 0;
	}
	else if (a == 2)
	{
		try

		{

			Lots2 x(2, mass);

			cout << "Элементы группы: ";

			cout << x;

			cout << "Введите индекс: ";

			int i;

			cin >> i;

			cout << "Элемент с индексом " << i << "\n";

			cout << x[i] << endl;

			cout << "Вычитаем элемент!\n";

			--x;

			cout << x;

			cout << "Вычитаем элемент!\n";

			--x;

			cout << x;

			cout << "Вычитаем элемент!\n";

			--x;

		}

		catch (error e)

		{
			e.what();
		}

		return 0;

	}
	else
	{
	cout << "Неверный номер!";
	return 0;
	}
}