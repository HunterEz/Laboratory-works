// ������� �����, ���. 28(3), ���������������� ���������� ���������� STL
#include "Lots.h"
#include "Money.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	Lots<Money> vec(5);
	vec.Print();
	vec.add_max();
	cout << "������ � ���������� ������������ ���������: ";
	vec.Print();
	cout << "������ � ���������� ������ �������� ���������������:\n";
	vec.delete_elem();
	vec.Print();
	cout << "������������ ����� ����������� � ����������� �������� �� ���� ���������:\n";
	vec.sum_elem();
	vec.Print();
}