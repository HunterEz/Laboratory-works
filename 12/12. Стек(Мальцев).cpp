#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <Windows.h>
using namespace std;

struct Stack
{
	char* data;
	Stack* prev;
};


Stack* plast = NULL;

Stack* make_point()

{

	Stack* p = new(Stack);

	char s[50];

	cout << "\n> ";

	cin >> s;
	p->data = new char[strlen(s) + 1];

	strcpy(p->data, s);

	return p;

}


Stack* push(Stack* plast)
{
	Stack* temp;
	temp = make_point();
	temp->prev = plast;
	plast = temp;
	return plast;
}

Stack* create_stek(int n)
{
	for (int i = 0; i < n; i++)
	{
		plast = push(plast);
	}
	return plast;
}

void pop(Stack* plast)
{
	Stack* temp = plast;
	plast = plast->prev;
	delete temp;
}

Stack* add_str(Stack* plast)
{

	Stack* p = plast;
	Stack* help;
	Stack* temp = new Stack;
	Stack* elem = new Stack;
	cout << "Введите элемент: ";
	temp = make_point();
	help = NULL;
	while (p != 0)
	{
		if (!strcmp(p->data, temp->data))
		{
			if (help == NULL)
			{
				cout << "Введите значение нового элемента: ";
				plast = push(plast);
				return plast;
			}

			cout << "Введите значение нового элемента: ";
			elem = make_point();
			elem->prev = p;
			help->prev = elem;
			break;
			return plast;

		}
		help = p;
		p = p->prev;
	}
	cout << "Совпадений не обнаружено!" << endl;
	return plast;
}

void Show(Stack* plast)
{

	Stack* temp = plast;

	while (temp != NULL)
	{
		cout << endl << ">\t" << temp->data;

		temp = temp->prev;

	}

}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	cout << "Задайте элементы стека" << endl;
	plast = create_stek(n);
	plast = add_str(plast);
	cout << "Стэк элементов:\n";
	Show(plast);
}


//Тип информационного поля char*. Добавить в стек элемент после элемента с заданным информационным полем.
