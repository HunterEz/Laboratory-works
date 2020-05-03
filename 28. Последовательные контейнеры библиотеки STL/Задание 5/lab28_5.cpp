// Мальцев Роман, лаб. 28(5), Последовательные контейнеры библиотеки STL
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
	cout << "Вектор с добавленым максимальным элементом: ";
	v.add_max();
	v.Print();
	cout << "Вектор с элементами больше среднего арефметического:\n";
	v.delete_elem();
	v.Print();
	cout << "Приабавление суммы наибольшего и наименьшего элемента ко всем элементам:\n";
	v.sum_elements();
	v.Print();
}