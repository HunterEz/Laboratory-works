#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include <iostream>
using namespace std;

struct Stack
{
	char* data;
	Stack* prev;
};


Stack* plasts = NULL;

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
		plasts = push(plasts);
	}
	return plasts;
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
	cout << "������� �������: ";
	temp = make_point();
	help = NULL;
	while (p != 0)
	{
		if (!strcmp(p->data, temp->data))
		{
			if (help == NULL)
			{
				cout << "������� �������� ������ ��������: ";
				plast = push(plast);
				return plast;
			}

			cout << "������� �������� ������ ��������: ";
			elem = make_point();
			elem->prev = p;
			help->prev = elem;
			break;
			return plast;

		}
		help = p;
		p = p->prev;
	}
	cout << "���������� �� ����������!" << endl;
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