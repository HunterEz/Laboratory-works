// Мальцев Роман, лаб. 28(3), Последовательные контейнеры библиотеки STL
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
	cout << "Вектор с добавленым максимальным элементом: ";
	vec.Print();
	cout << "Вектор с элементами больше среднего арефметического:\n";
	vec.delete_elem();
	vec.Print();
	cout << "Приабавление суммы наибольшего и наименьшего элемента ко всем элементам:\n";
	vec.sum_elem();
	vec.Print();
}