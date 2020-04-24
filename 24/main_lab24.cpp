// ������� �����, ���. 24, ������� �������
#include "Lots.h"		
#include "Money.h"
#include <iostream>

using namespace std;

/*
��������� � ���������� ���� int. 
����������� ��������: [] � ������� �� �������; 
() � ����������� ������� �������;
- � �������� ��������

Money ��� ������ � ��������� �������. 
����� ������ ���� ������������ ����� ������: 
���� long ��� ������ � ���� int ��� ������. 
������� ����� ����� ��� ������ �� ����� ������
���� �������� �� ����� ������������

*/

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "�������� � ������� ���������!\n";
	cout << "������� ���������� � � 5 ����������:\n";
	Lots<int> a(5,0);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	cout << endl;
	cout << "������� ���������� � � 10 ����������:\n";
	Lots<int> b(10,45);
	cout << b << "\n";
	cout << endl;
	cout << "������������ � � �:\n";
	b = a;
	cout << b << "\n";
	cout << endl;
	cout << "������� ���������� � � �������� 2 ����� 100:\n";
	a[2] = 100;
	cout << endl;
	cout << "������� ���������� � � 10 ����������\n";
	Lots<int> c(10,0);
	cout << endl;
	cout << "���������� � ������ �������� ��������� B � A:\n";
	c = b - a;
	cout << c << "\n";
	cout << "����� ����� �= " << a() << endl;

	system("pause");
	cout << endl;
	cout << "�������� � ������� Money!\n";
	Money F;
	cin >> F;
	cout << F;
	cout << endl;
	Money L;
	cin >> L;
	cout << L;
	cout << endl;
	Money FL;
	FL = F - L;
	cout << FL;
	cout << endl;
	system("pause");
	cout << "�������� ����������� �������������������� ������ ���������:\n";
	cout << "��� ����������������� ���� ������ Money:\n";
	cout << "������� ���������� ������ Money:\n";
	Money m;
	cin >> m;
	cout << m;
	cout << endl;
	cout << "������� ���������� ������ ��������� � ���������������� ���� ������ Money:\n";
	Lots<Money>Al(5, m);
	cin >> Al;
	cout << Al << endl; 
	cout << endl;
	cout << "������� ������ ���������� ������ ��������� � ���������������� ���� ������ Money:\n";
	Lots<Money>Bl(10, m);
	cout << Bl << endl;
	cout << endl;
	cout << "������� 3 ������� ������ ����������:\n";
	cout << Al[2] << endl;
	cout << "������ ������ ���������� = " << Al() << endl;
	Lots<Money>Cl(10, m);
	cout << endl;
	cout << "�������� �� ������ ���������� �������� ������:\n";
	Cl = Bl - Al;
	cout << Cl;
	cout << endl;
	cout << "������������ ������ ���������� ������ � ������ �:\n";
	Bl = Al;
	cout << Bl << endl;

	system("pause");
}