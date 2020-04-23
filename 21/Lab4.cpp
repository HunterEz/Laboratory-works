#include <iostream>
#include "Triad.h"
#include "Date.h"
#include "Vector.h"
using namespace std;


// ������ ����� first second third (int)
// ���������� ������ ��������� ����� � ���������� ����� �� 1
// ������� ������������ ����� Date � ������
// ��� ����� �����. �������������� ������ ����������
// ����� �� 1 � ���������� ����� ���������� ���� �� n ����


void main()
{
	setlocale(LC_ALL, "rus");
	cout << "�������� � ������� ������� ������:\n";
	cout << "������� ������ ��������� � ������ �� � ����������:\n";
	Triad a;
	cin >> a;
	cout << a;
	cout << "������� ������ ��������� � ������ �� � �����������:\n";
	Triad b(11, 22, 33);
	cout << b;
	cout << "������������ ������ ���������� �� ������:\n";
	a = b;
	cout << a;
	cout << "��������� 1 �� ���� �����:\n";
	a.plusone();
	cout << a;

	cout << "������� � ������� ������ Show � ���������\n";
	Object* p = &a;
	p->Show();
	cout << endl;
	system("pause");
	cout << "_______________________________________________\n";

	cout << "�������� � ������� ����:\n";
	cout << "������� ����������\n";
	Date c;
	cin >> c;
	cout << c;

	cout << "��������� 1 �� ���� �����:\n";
	c.plusoneD();
	cout << c;

	int n;
	cout << "���������� ��� � ����!\n";
	cout << "������� ���������� ����: ";

	cin >> n;

	c.dobavlenje(n);

	cout << c;
	cout << endl;

	cout << "������� � ������� ������ Show � ���������\n";
	p = &c;
	p->Show();
	system("pause");
	cout << "_______________________________________________\n";

	cout << "�������� � ������� ������:\n";

	Vector v(5);
	p = &a;
	v.Add(p);
	p = &c;
	v.Add(p);
	cout << v;
	system("pause");
}

