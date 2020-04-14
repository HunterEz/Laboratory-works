#include <iostream>
#include <stack>
using namespace std;

stack<int> start;
stack<int> help;
stack<int> result;


void create_stack()
{
	int n, k, a;
	cout << "������� ���������� ��������� � �����: ";
	cin >> n;
	
	cout << "�������� ������ ����� �����:" << endl;
	cout << "1. ���� � ����������" << endl;
	cout << "2. ��������� ����" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> k;
			start.push(k);
		}
	}break;
	case 2:
	{
		for (int i = 1; i <= n; i++)
		{
			start.push(k = rand() % 100 - 50);
		}
	}break;
	}
	
	cout << "����������� ����: " << endl;

	while (!start.empty())

	{
		k = start.top();
		start.pop();
		help.push(k);
		cout << '\t' << k << endl;
	}
	
	while (!help.empty())

	{
		k = help.top();
		help.pop();
		start.push(k);
	}
	
}

void sort_stack()
{
	int min, elem;
	while (!start.empty())
	{
		min = start.top();
		start.pop();
		help.push(min);
		while (!start.empty())
		{
			elem = start.top();
			start.pop();
			if (elem < min)min = elem;
			help.push(elem);
		}
		while (!help.empty())
		{
			elem = help.top();
			help.pop();
			if (elem == min)result.push(elem);
			else start.push(elem);
		}
	}
}

void print_result()
{
	cout << "������������� ����: " << endl ;
	while (!result.empty()) {
		cout << '\t' << result.top() << endl;
		result.pop();
	}
}


void main()
{
	setlocale(LC_ALL, "Russian");
	create_stack();
	sort_stack();
	print_result();
	system("pause");
}