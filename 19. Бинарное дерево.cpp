// Мальцев Роман, лаб. 19, Бинарное дерево﻿
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct node
{
	int data;
	node* left, * right;
};

node* tree = NULL;

int* mass;

void push(int a, node** t)
{

	if ((*t) == NULL)
	{
		(*t) = new node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}

	push(rand() % 100, &(*t)->left);

	push(rand() % 100, &(*t)->right);
	return;
}

void print(node* t, int u)
{

	if (t == NULL) {
		return;

	}

	else
	{
		print(t->left, ++u);
		for (int i = 0; i < u; ++i) cout << "    ";
		cout << "--->" << t->data << endl;
		u--;
	}
	print(t->right, ++u);
}

int Run(node* t, int*& mass, int& g)
{
	if (t != NULL)
	{
		mass[g] = t->data;
		g++;
	}
	if (t)
	{

		Run(t->left, mass, g);
		Run(t->right, mass, g);
	}
	return 0;
}

void search(node* t,  int &list)
{
	if (t != NULL)
	{
		if (t->left == NULL && t->right == NULL)
		{
			list++;
		}
	}
	if (t)
	{

		search(t->left, list);
		search(t->right, list);
	}
}

void sort(node** e, int a)
{

	if ((*e) == NULL)
	{
		(*e) = new node;

		(*e)->data = a;

		(*e)->left = (*e)->right = NULL;

		return;

	}

	if (a > (*e)->data) sort(&(*e)->left, a);

	else sort(&(*e)->right, a);

}

void free(node** tree)
{
	if (*tree != NULL)    
	{
		free(&(*tree)->left);   
		free(&(*tree)->right); 
		delete* tree;
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int n = 4;
	int g = 0;
	int al;
	int* mass = new int[n];
	do
	{ 
		cout << "1. Создание сбалансированного дерева" << endl;
		cout << "2. Печать дерева" << endl;
		cout << "3. Преобразование в дерево поиска" << endl;
		cout << "4. Подсчет количества листьев" << endl;
		cout << "5. Удаление дерева" << endl;
		cout << "6. Выход" << endl;
		cin >> al;
		switch (al)
		{
		
		case 1:
		{
			for (int i = n; i > 0; i--)
			{
				push(rand() % 100, &tree);
			}
			break;
		}
		case 2:
		{
			cout << "Ваше дерево:\n\n\n";
			print(tree, 0);
			cout << endl;
			break;
		}
		case 3:
		{
			Run(tree, mass, g);
			free(&tree);
			tree = NULL;
			for (int i = 0; i < g; i++)
			{
				int a;
				a = mass[i];
				sort(&tree, a);
			}
			break;
		}
		case 4:
		{
			int list;
			list = 0;
			search(tree, list);
			cout << "Количество листьев: " << list << endl;
			break;
		}
		case 5:
		{
			free(&tree);
			tree = NULL;
			break;
		}
		
		}
		}
	while (al!=6);
		system("pause");
		free(&tree);
	
	return 0;
}
