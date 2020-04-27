  
// Мальцев Роман, лаб. 20.1, Классы №1﻿
#include <iostream>
#include <cmath>
using namespace std;


struct triangle
{
	double first;
	double second;

	triangle()
	{
		first = 0;
		second = 0;

	};

	triangle(double f, double s)
	{
		first = f;
		second = s;
	};

	triangle(const triangle& b)
	{
		first = b.first;
		second = b.second;
	};

	~triangle()
	{


	}

	void Init(double f, double s)
	{
		first = f; second = s;
	}

	void Read()
	{
		cout << "\nfirst >> ";
		cin >> first;
		cout << "second >> ";
		cin >> second;
		cout << endl;
	}

	void Show()
	{
		cout << "\nfirst= " << first;
		cout << "\nsecond= " << second;
		cout << endl;
	}

	double hipotenuse(double f, double s)
	{
		return sqrt(f * f + s * s);
	}

};

triangle make_triangle(double f, double s)
{
	triangle pifagor;
	pifagor.Init(f, s);
	return pifagor;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Создаем треугольники alpha и beta\n";
	triangle alpha;
	triangle beta;

	alpha.Init(14.34, 16.54);
	cout << "Введите катеты треугольника beta";
	beta.Read();
	cout << "alpha:";
	alpha.Show();
	cout << "beta:";
	beta.Show();
	cout << "Гипотинуза треугольника alpha= " << alpha.hipotenuse(alpha.first, alpha.second) << endl;
	cout << "Гипотинуза треугольника beta= " << beta.hipotenuse(beta.first, beta.second) << endl;
	cout << "________________________________________________________\n";
	cout << "Работа с указателем:\n\n";
	triangle* ptria = new triangle;
	cout << "Создаем треугольник с катетами 12.54 и 43.65\n";
	ptria->Init(12.54, 43.65);
	ptria->Show();
	cout << "Гипотинуза треугольника= " << ptria->hipotenuse(ptria->first, ptria->second) << endl;
	cout << "________________________________________________________\n";
	cout << "Работа с массивами:\n\n";
	triangle* p_mass = new triangle[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите катеты треугольнка " << i + 1;
		p_mass[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{	
		cout << "Треугольник " << i + 1;
		p_mass[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Гипотинуза треугольника " << i + 1 << " = " << p_mass[i].hipotenuse(p_mass[i].first, p_mass[i].second);
		cout << endl;
	}
	cout << "________________________________________________________\n";
	cout << "Работа с функцией make:\n";
	double x;
	double y;
	cout << "\nВведите x >> ";
	cin >> x;
	cout << "\nВведите y >> ";
	cin >> y;
	triangle F = make_triangle(x, y);
	F.Show();
	system("pause");
	return 0;
}
