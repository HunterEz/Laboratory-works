#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
#include <iostream>
using namespace std;

struct Node
{
	char* data;
	Node* next;
};

Node* pfirst , * plast;

Node* make_pointq()

{

	Node* p = new(Node);

	p->next = 0;

	char s[50];

	cout << "\n> ";

	cin >> s;
	p->data = new char[strlen(s) + 1];

	strcpy(p->data, s);

	return p;

}

Node* push(Node*& plast, Node*& pfirst)
{
	if (plast == NULL)
	{
		plast = make_pointq();
		pfirst = plast;
	}
	else
	{
		Node* temp = make_pointq();
		plast->next = temp;
		plast = temp;
	}
	return plast, pfirst;
}

Node* createque(int n)
{
	for (int i = 0; i < n; i++)
	{
		push(plast, pfirst);
	}

	return plast;
}

void show(Node* plast)
{

	Node* p = pfirst;

	while (p != 0)

	{

		cout << "\t" << p->data;

		p = p->next;

	}

}

Node* add_str(Node* plast)
{

	Node* p = pfirst;
	Node* help;
	Node* temp = new Node;
	Node* elem = new Node;
	cout << "Введите элемент: ";
	temp = make_pointq();
	help = p->next;
	while (p != 0)
	{
		if (!strcmp(p->data, temp->data))
		{
			if (help == NULL)
			{
				cout << "Введите значение нового элемента: ";
				Node* temp = make_pointq();
				plast->next = temp;
				plast = temp;
				return plast;
			}
			cout << "Введите значение нового элемента: ";
			elem = make_pointq();
			p->next = elem;
			elem->next = help;
			return plast;
			break;

		}

		p = p->next;
		if (p == 0)
		{
			cout << "Совпадений не обнаружено!" << endl;
			return plast;
		}
		help = p->next;
	}
	return plast;
}