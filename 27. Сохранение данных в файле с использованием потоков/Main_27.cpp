// Мальцев Роман, лаб. 27, Сохранение данных в файле с использованием потоков
#include "file_work.h"	
#include "Money.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	Money m, m1, m2, m3;
	int n, k, c, kol;
	char file_name[30];
	do
	{
		cout << "\n1. Создание файл";
		cout << "\n2. Печать файла";
		cout << "\n3. Удалить объект из файла";
		cout << "\n4. Добавить объект в файла";
		cout << "\n5. Изменить объект в файле";
		cout << "\n6. Удалить объекты из файла, которые больше заданного значения";
		cout << "\n7. Увеличить все записи с заданным значением на 1 рубль 50 копеек";
		cout << "\n8. Добавить K записей после записи с номером N";
		cout << "\n0. Выход\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "Название файла? "; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Нельзя создать файл\n";
			break;

		case 2:
			cout << "Название файла? "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Файл пустой\n";
			if (k < 0) cout << "Нельзя открыть файл\n";
			break;
		case 3:
			cout << "Название файла? "; cin >> file_name;
			int nom; cout << "Номер? "; cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0) cout << "Нельзя открыть файл\n";
			break;
		case 4:
			cout << "Название файла? "; cin >> file_name;
			cout << "Номер? "; cin >> nom;
			cout << "Новая переменная:\n";
			cin >> m1;
			k = add_file(file_name, nom, m1);
			if (k < 0) cout << "Нельзя открыть файл\n";
			if (k == 0) k = add_end(file_name, m1);
			break;
		case 5:
			cout << "Название файла? "; cin >> file_name;
			cout << "Номер? "; cin >> nom;
			cout << "Новая переменная:\n";
			cin >> m2;
			k = chang_file(file_name, nom, m2);
			if (k < 0) cout << "Нельзя открыть файл\n";
			if (k == 0) cout << "Нет такой записм\n";
			break;
		case 6:
			cout << "Название файла? "; cin >> file_name;
			cout << "Введите значание разделяющей переменной\n";
			cin >> m;
			k = del_bolshe(file_name, m);
			if (k < 0) cout << "Нельзя открыть файл\n";
			if (k == 0) cout << "Нет такой записм\n";
			break;
		case 7:
			cout << "Название файла? "; cin >> file_name;
			cout << "Введите значание переменной\n";
			cin >> m3;
			k = one_ruble_fifty(file_name, m3);
			if (k < 0) cout << "Нельзя открыть файл\n";
			if (k == 0) cout << "Нет такой записм\n";
			break;
		case 8:
			cout << "Название файла? "; cin >> file_name;
			cout << "Введите номер элемента\n";
			cin >> n;
			cout << "Введите количество элементов\n";
			cin >> kol;
			k = add_more(file_name, kol, n);
			if (k < 0) cout << "Нельзя открыть файл\n";
			if (k == 0) cout << "Нет такой записм\n";
			break;
		}
	} while (c != 0);
	system("pause");
}