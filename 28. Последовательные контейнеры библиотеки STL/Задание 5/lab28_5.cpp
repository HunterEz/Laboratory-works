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
	cout << "Âåêòîð ñ äîáàâëåíûì ìàêñèìàëüíûì ýëåìåíòîì: ";
	v.add_max();
	v.Print();
	cout << "Âåêòîð ñ ýëåìåíòàìè áîëüøå ñðåäíåãî àðåôìåòè÷åñêîãî:\n";
	v.delete_elem();
	v.Print();
	cout << "Ïðèàáàâëåíèå ñóììû íàèáîëüøåãî è íàèìåíüøåãî ýëåìåíòà êî âñåì ýëåìåíòàì:\n";
	v.sum_elements();
	v.Print();
}
