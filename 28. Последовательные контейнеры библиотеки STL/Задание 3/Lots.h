#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Lots
{
public:
	Lots();
	Lots(int s);
	~Lots();
	void Print();
	void sum_elem();
	void delete_elem();
	T sreednee_arefm();
	void add_max();
	T find_min();
	T find_max();
		
private:
	int size;
	vector <T> v;
};

template <class T>
Lots<T>::Lots()
{
	size = 0;
}

template <class T>
Lots<T>::Lots(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	size = v.size();
}

template <class T>
Lots<T>::~Lots()
{
}

template <class T>
void Lots<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "  ";
	cout << endl;
}

template <class T>
T Lots<T>::find_max()
{
	T max;
	max = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (max < v[i]) max = v[i];
	}
	return max;
}
template <class T>
T Lots<T>::find_min()
{
	T min;
	min = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (min > v[i]) min = v[i];
	}
	return min;
}
template <class T>
void Lots<T>::add_max()
{
	T max;
	max = find_max();
	v.insert(v.end(), max);
}
template <class T>
T Lots<T>::sreednee_arefm()
{
	T s ;
	for (int i = 0; i < v.size(); i++)
	{
		s = s+ v[i];
	}
	return s / v.size();
}
template <class T>
void Lots<T>::delete_elem()
{
	T s = sreednee_arefm();
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
template <class T>
void Lots<T>::sum_elem()
{
	T minmax = find_max() + find_min();
	cout << "max + min = " << minmax;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + minmax;
	}
}
