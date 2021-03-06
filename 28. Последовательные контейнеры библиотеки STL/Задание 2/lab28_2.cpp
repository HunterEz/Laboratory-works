// Мальцев Роман, лаб. 28(2), Последовательные контейнеры библиотеки STL
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Money.h"
using namespace std;
typedef vector<Money>Vec;

Vec make_vector(int n)
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		Money a(rand() % 100000 , rand() % 99 );
		v.push_back(a);
	}
	return v;
}
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

Money find_max(Vec v)
{
	Money max;
	max = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (max < v[i]) max = v[i];
	}
	return max;
}
Money find_min(Vec v)
{
	Money min;
	min = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (min > v[i]) min = v[i];
	}
	return min;
}

void add_max(Vec& v)
{
	v.insert(v.end(), find_max(v));
}
Money sreednee_arefm(Vec v)
{
	Money s;
	for (int i = 0; i < v.size(); i++)
	{
		s = s + v[i];
	}
	return s / v.size();
}


void delete_elem(Vec& v)
{
	Money s = sreednee_arefm(v);
	cout << "Ñðåäíåå àðåôìåòè÷åñêîå âåêòîðà: " << s << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < s)
		{
			v.erase(v.begin() + i);
			i--;
		}
	}
}


void sum_elem(Vec& v)
{
	Money minmax = find_max(v) + find_min(v);
	cout << "max + min = " << minmax;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + minmax;
	}
}


void main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		vector<Money> v;
		vector<Money>::iterator vi = v.begin();
		int n;
		cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ: ";
		cin >> n;
		v = make_vector(n);
		cout << "Ñîçäàíûé âåêòîð: ";
		print_vector(v);
		add_max(v);
		cout << "Âåêòîð ñ äîáàâëåíûì ìàêñèìàëüíûì ýëåìåíòîì: ";
		print_vector(v);
		cout << "Âåêòîð ñ ýëåìåíòàìè áîëüøå ñðåäíåãî àðåôìåòè÷åñêîãî:\n";
		delete_elem(v);
		print_vector(v);
		cout << "Ïðèàáàâëåíèå ñóììû íàèáîëüøåãî è íàèìåíüøåãî ýëåìåíòà êî âñåì ýëåìåíòàì:\n";
		sum_elem(v);
		print_vector(v);
	}
	catch (int)
	{
		cout << "ERROR!";
	}
}
