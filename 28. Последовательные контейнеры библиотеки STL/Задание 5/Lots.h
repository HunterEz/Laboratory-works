#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
class Lots
{
public:
	Lots();
	Lots(int s);
	Lots(const Lots<T>&);
	~Lots();
	void Print();
	void sum_elements();
	void delete_elem();
	T sreednee_arefm();
	void add_max();
	T find_min();
	T find_max();

private:
	int size;
	queue<T> q;
};

template <class T>
vector <T> copy_queue_to_vector(queue<T> q)
{
	vector<T> v;
	while (!q.empty())
	{
		v.push_back(q.front());
		q.pop();
	}
	return v;
}

template <class T>
queue<T> copy_vector_to_queue(vector<T> v)
{
	queue<T> q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
	}
	return q;
}

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
		q.push(a);
	}
	size = q.size();
}

template <class T>
Lots<T>::Lots(const Lots<T>& q)
{

	size = q.size;
	vector<T> v = copy_queue_to_vector(q);
	q = copy_vector_to_queue(v);
}

template <class T>
Lots<T>::~Lots()
{
}

template <class T>
void Lots<T>::Print()
{
	vector<T> v = copy_queue_to_vector(q);
	while (!q.empty())
	{
		cout << q.front() << "  ";
		q.pop();
	}
	cout << endl;
	q = copy_vector_to_queue(v);
}

template<class T>
void Lots<T>::sum_elements()
{
	T max = find_max();
	T min = find_min();
	T mima = min + max;
	cout << "min+max= " << mima;
	cout << endl;
	vector<T> v;
	for (int i = 0; !q.empty(); i++)
	{
		v.push_back(q.front() + mima) ;
		q.pop();
	}
	q = copy_vector_to_queue(v);
}

template <class T>
T Lots<T>::find_max()
{
	vector<T> v = copy_queue_to_vector(q);
	int n = q.size();
	T max = q.front();
	q.pop();
	for (int i = 1; i < n; i++)
	{
		if (max < q.front()) max = q.front();
		q.pop();
	}
	q = copy_vector_to_queue(v);
	return max;
}

template <class T>
T Lots<T>::find_min()
{
	vector<T> v = copy_queue_to_vector(q);
	int n = q.size();
	T min = q.front();
	q.pop();
	for (int i = 1; i < n; i++)
	{
		if (min > q.front()) min = q.front();
		q.pop();
	}
	q = copy_vector_to_queue(v);
	return min;
}

template <class T>
void Lots<T>::add_max()
{
	vector<T> v = copy_queue_to_vector(q);
	v.push_back(find_max());
	q = copy_vector_to_queue(v);
}

template <class T>
T Lots<T>::sreednee_arefm()
{
	vector<T> v = copy_queue_to_vector(q);
	T s;
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		s = s + q.front();
		q.pop();
	}
	q = copy_vector_to_queue(v);
	return s / n;
}

template <class T>
void Lots<T>::delete_elem()
{
	vector<T> v;
	setlocale(LC_ALL, "rus");
	T s = sreednee_arefm();
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


