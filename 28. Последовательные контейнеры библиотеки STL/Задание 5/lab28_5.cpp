// ������� �����, ���. 28(5), ���������������� ���������� ���������� STL
#include "Money.h"
#include <vector>
#include <iostream>
#include <queue>
#include "Lots.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	Lots<Money>v(5);
	v.Print();
	cout << "������ � ���������� ������������ ���������: ";
	v.add_max();
	v.Print();
	cout << "������ � ���������� ������ �������� ���������������:\n";
	v.delete_elem();
	v.Print();
	cout << "������������ ����� ����������� � ����������� �������� �� ���� ���������:\n";
	v.sum_elements();
	v.Print();
}