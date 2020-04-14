#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <Windows.h>
#include "dnode.h"
#include "queue.h"
#include "stack.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int n, a;

	do
	{

		cout << "1. Двусвязный список\n";

		cout << "2. Очередь\n";

		cout << "3. Стек\n";

		cout << "4. Выход\n";

		cin >> a;

		switch (a)

		{

		case 1:

			Node* beg;
			cout << "Введите количество элементов: ";
			cin >> n;
			beg = make_list(n);
			add_str(n, beg);
			n++;
			cout << "Новый список:\t";
			print_list(n, beg);
			cout << endl;
			break;

		case 2:
			Node * plast;
			cout << "Введите количесатво элементов: ";
			cin >> n;
			plast = createque(n);
			add_str(plast);
			cout << "Результат :" << endl << ">>";
			show(plast);
			cout << endl;
			break;

		case 3:
			Stack* plasts;
			cout << "Введите количество элементов: ";
			cin >> n;
			cout << "Задайте элементы стека" << endl;
			plasts = create_stek(n);
			plasts = add_str(plasts);
			cout << "Стэк элементов:\n";
			Show(plasts);
			break;

		}
	} while (a != 4);
		
}
