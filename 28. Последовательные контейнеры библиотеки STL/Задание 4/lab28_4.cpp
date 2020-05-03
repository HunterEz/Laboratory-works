// Мальцев Роман, лаб. 28(4), Последовательные контейнеры библиотеки STL
#include "Money.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef vector<Money> Vec;
typedef queue<Money> Que;

Que make_queue(int n)
{
	Que q;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		q.push(m);
	}
	return q;
}

Vec copy_queue_to_vector(Que q)
{
	Vec v;
	while (!q.empty())
	{
		v.push_back(q.front());
		q.pop();
	}
	return v;
}

Vec make_vector(int n)
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		Money a(rand() % 10000, rand() % 100);
		v.push_back(a);
	}
	return v;
}

void print_queue(Que q)
{
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
Que copy_vector_to_queue(Vec v)
{
	Que q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
	}
	return q;
}
Money find_max(Que q)
{
	int n = q.size();
	Money max = q.front();
	q.pop();
	for (int i = 1; i <n; i++)
	{
		if (max < q.front()) max = q.front();
		q.pop();
	}
	return max;
}
Money find_min(Que q)
{
	int n = q.size();
	Money min = q.front();
	q.pop();
	for (int i = 1; i < n; i++)
	{
		if (min > q.front()) min = q.front();
		q.pop();
	}
	return min;
}
void add_max(Que& q)
{
	q.push(find_max(q));
}
Money sreednee_arefm(Que q)
{

	Money s;
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		s = s + q.front();
		q.pop();
	}
	return s / n;
}
void delete_elem(Que& q)
{
	Vec v;
	Money s = sreednee_arefm(q);
	cout << "Среднее арефметическое вектора: " << s << endl;
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		if (q.front() > s)
		{
			v.push_back(q.front());
		}
		q.pop();
	}
	q = copy_vector_to_queue(v);
}
void sum_elem(Que& q)
{
	int n = q.size();
	Money minmax = find_max(q) + find_min(q);
	cout << "max + min = " << minmax;
	cout << endl;
	Vec v = copy_queue_to_vector(q);
	for (int i = 0; i <n; i++)
	{
		v[i] = v[i] + minmax;
	}
	q = copy_vector_to_queue(v);
}


void main()
{
	setlocale(LC_ALL, "rus");
	Money m;
	Que q;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	q = make_queue(n);
	print_queue(q);
	add_max(q);
	cout << "Вектор с добавленым максимальным элементом: ";
	print_queue(q);
	cout << "Вектор с элементами больше среднего арефметического:\n";
	delete_elem(q);
	print_queue(q);
	cout << "Приабавление суммы наибольшего и наименьшего элемента ко всем элементам:\n";
	sum_elem(q);
	print_queue(q);
}