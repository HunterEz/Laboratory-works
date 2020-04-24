#pragma once
#include <iostream>
#include <initializer_list>

using namespace std;



template <class T>
class Lots
{
public:
	Lots(int s, T k  );
	Lots(const Lots<T>& v);
	~Lots();
	Lots& operator=(const Lots<T>& v);
	T& operator[](int index);
	Lots operator-(const Lots<T>& v);
	int operator()();


	friend ostream& operator << <T> (ostream&, const Lots<T>&);
	friend istream& operator>> <T>(istream& in, Lots<T>& v);

private:
	int size;
	T* data;
};

template <class T>
Lots<T>::Lots(const Lots& v)
{
	size = v.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}
}

template <class T>
Lots<T>::Lots(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] =k;
	}
}

template <class T>
Lots<T>::~Lots()
{
	delete[]data;
	data = 0;
}

template <class T>

Lots<T>& Lots<T>::operator=(const Lots<T>& v)
{
	if (this == &v)return *this;
	size = v.size;
	if (data != 0) delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}

	return *this;
}

template <class T>
T& Lots<T>::operator[] (int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

template <class T>
Lots<T> Lots<T>::operator-(const Lots<T>& v)
{
	Lots<T> temp(size, data[0]);
	for (int i = 0; i < size; ++i)
	{
		temp.data[i] = v.data[i] - data[i];
	}
	return temp;
}

template <class T>
int Lots<T>::operator()()
{
	return size;
}
template <class T>
ostream& operator<<(ostream& out, const Lots<T>& v)
{
	for (int i = 0; i < v.size; ++i)
	{
		out << v.data[i] << " ";
	}
	return out;
}
template <class T>
istream& operator>>(istream& in, Lots<T>& v)
{
	for (int i = 0; i < v.size; ++i)
	{
		in >> v.data[i];
	}
	return in;
}
