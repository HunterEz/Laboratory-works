#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


struct Node
{
	double data;
	Node* next;
};

Node* newlist(int n)
{
	Node* beg, * p, * r;
	beg = NULL;
	p = new Node;
	cout << "\n?";
	cin >> p->data;
	beg = p;
	for (int i = 2; i <= n; i++)
	{
		r = new Node;
		cout << "\n?";
		cin >> r->data;
		p->next = r;
		r->next = NULL;
		p = r;
	}
	return beg;
}

Node* make_list(int n)

{

	Node* beg;
	Node* p, * r;
	beg = new(Node);
	cout << "\n >";
	cin >> beg->data;
	beg->next = 0;
	p = beg;
	for (int i = 0; i < n - 1; i++)
	{
		r = new(Node);
		cout << "\n >";
		cin >> r->data;
		r->next = 0;
		p->next = r;
		p = r;
	}
	return beg;
}

void print_list(Node* beg)
{
	Node* p = beg;
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}

Node* del_point(int n, Node* beg)
{
	Node* p = beg;
	Node* help = p;
	for (int i = 0; (i < n); i++)
	{
		if (i % 2 != 0)
		{
			help->next = p->next;
		}
		else
		{
			
		}
		help = p;
		p = p->next;
	}
	return beg;
}



int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	Node* beg;
	cout << "Введите количество элементов в списке: ";
	cin >> n;
	beg = make_list(n);
	del_point(n, beg);
	cout << "Список без четных элементов:" << endl;
	print_list(beg);
}
