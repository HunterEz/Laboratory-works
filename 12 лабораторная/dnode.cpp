#define _CRT_SECURE_NO_WARNINGS
#include "dnode.h"
#include <iostream>
using namespace std;

struct Node
{
	char* data;
	Node* next;
	Node* prev;
};


Node* make_pointd()

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

	beg = make_pointd();

	prev = beg;

	for (int i = 1; i < n; i++)

	{

		p = make_pointd();

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
	temp = make_pointd();
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
			elem = make_pointd();
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

