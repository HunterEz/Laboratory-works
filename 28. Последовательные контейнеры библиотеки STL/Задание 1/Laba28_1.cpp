// Мальцев Роман, лаб. 28(1), Последовательные контейнеры библиотеки STL
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<double>Vec;

Vec make_vector(int n)
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		double a = rand() % 100 - 50;
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
double find_max(Vec v)
{
	double max;
	max = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (max < v[i]) max = v[i];
	}
	return max;
}
double find_min(Vec v)
{
	double min;
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
double sreednee_arefm(Vec v)
{
	double s = 0;
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}
	return s / v.size();
}
void delete_elem(Vec& v)
{
	double s = sreednee_arefm(v);
	cout << "Среднее арефметическое вектора: " << s << endl;
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
	double minmax = find_max(v) + find_min(v);
	cout << "max + min = " << minmax;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += minmax;
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		vector<double> v;
		vector<double>::iterator vi = v.begin();
		int n;
		cout << "Введите количество элементов: ";
		cin >> n;
		v = make_vector(n);
		cout << "Созданый вектор: ";
		print_vector(v);
		add_max(v);
		cout << "Вектор с добавленым максимальным элементом: ";
		print_vector(v);
		cout << "Вектор с элементами больше среднего арефметического:\n";
		delete_elem(v);
		print_vector(v);
		cout << "Приабавление суммы наибольшего и наименьшего элемента ко всем элементам:\n";
		sum_elem(v);
		print_vector(v);
	}
	catch(int)
	{
		cout << "ERROR!";
	}
}