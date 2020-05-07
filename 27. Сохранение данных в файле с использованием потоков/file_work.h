#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Money m;
	cout << "N? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		stream << m << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Money m;
	int i = 0;
	while (stream >> m)
	{
		cout << m << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Money m;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		if (i != k)temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, Money mm)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Money m; int i = 0; int l = 0;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			temp << mm;
			l++;
		}
		temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_end(const char* f_name, Money mm)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << mm;
	return 1;
}

int chang_file(const char* f_name, int k, Money mm)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Money m; int i = 0; int l = 0;
	char x;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			cout << m << " - is changing ... Continue[y/e]";
			cin >> x;
			if (x == 'n' || x == 'N') break;
			temp << mm;
			l++;
		}
		else temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int del_bolshe(const char* f_name, Money mm)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Money m;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		if (m.get_rub()+(m.get_cop()*100) < mm.get_rub()+(mm.get_cop()*100)) temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int one_ruble_fifty(const char* f_name, Money mm)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Money m;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		if (m.get_rub() + (m.get_cop() * 100) == mm.get_rub() + (mm.get_cop() * 100))
		{
			m++;
			temp << m;
		}
		else temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_more(const char* f_name, int k, int n)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Money m; int i = 0;  Money m1;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		if (i == n+1)
		{
			for (int i = 0; i < k; i++)
			{
				cin >> m1;
				temp << m1 << "\n";
			}
			
		}
		temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}