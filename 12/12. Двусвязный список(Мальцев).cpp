#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <Windows.h>
using namespace std;


struct Node
{
	char* data;
	Node* next;
	Node* prev;
};


Node* make_point()

{

	Node* p = new(Node);

	p->next = 0; p->prev = 0;

	char s[50];

	cout << "\n> ";

	cin >> s;
	p->data = new char[strlen(s) + 1];

	strcpy(p->data, s);

	return p;

}
Node* make_list(int n)

{
	Node* p, * beg, * prev;

	beg = make_point();

	prev = beg;

	for (int i = 1; i < n; i++)

	{

		p = make_point();

		p->prev = prev;

		prev->next = p;

		prev = p;

	}

	return beg;

}


void print_list(int n, Node* beg)
{

	Node* p = beg;

	while (p != 0)

	{

		cout << p->data << "\t";

		p = p->next;

	}

}


Node* add_str(int n, Node* beg)
{
	Node* p = beg;
	Node* nextel;
	Node* temp = new Node;
	Node* elem = new Node;
	cout << "Введите элемент: ";
	temp = make_point();
	while (p != 0)

	{
		if (p->next == 0)
		{
			cout << "Недопустимый элемент!" << endl;
			return beg;
		}
		if (!strcmp(p->data, temp->data))
		{

			cout << "Введите значение нового элемента: ";
			elem = make_point();
			nextel = p->next;
			elem->prev = p;
			p->next = elem;
			nextel->prev = elem;
			elem->next = nextel;
			return beg;
		}

		p = p->next;

	}

	return beg;

}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	Node* beg;
	cout << "Введите количество элементов: ";
	cin >> n;
	beg = make_list(n);
	add_str(n, beg);
	n++;
	cout << "Новый список:\t";
	print_list(n, beg);
}

//Тип информационного поля char*. Добавить в список элемент после элемента с заданным информационным полем.