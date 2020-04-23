#include <iostream>
#include "Triad.h"
#include "Date.h"
#include "Vector.h"
using namespace std;


// тройка чисел first second third (int)
// Определить методы изменения полей и увелечения полей на 1
// Создать произвольный класс Date с полями
// год месяц число. Переопределить методы увеличения
// полей на 1 и определить метод увелечения даты на n дней


void main()
{
	setlocale(LC_ALL, "rus");
	cout << "Работаем с базовым классом триада:\n";
	cout << "Создаем первую переменую и вводим ее с клавиатуры:\n";
	Triad a;
	cin >> a;
	cout << a;
	cout << "Создаем вторую переменую и вводим ее с параметрами:\n";
	Triad b(11, 22, 33);
	cout << b;
	cout << "Приравниваем первую переменную ко второй:\n";
	a = b;
	cout << a;
	cout << "Прибавили 1 ко всем полям:\n";
	a.plusone();
	cout << a;

	cout << "Выводим с помощью метода Show и указателя\n";
	Object* p = &a;
	p->Show();
	cout << endl;
	system("pause");
	cout << "_______________________________________________\n";

	cout << "Работаем с классом дата:\n";
	cout << "Создаем переменную\n";
	Date c;
	cin >> c;
	cout << c;

	cout << "Прибавили 1 ко всем полям:\n";
	c.plusoneD();
	cout << c;

	int n;
	cout << "Прибавляем дни к дате!\n";
	cout << "Введите количество дней: ";

	cin >> n;

	c.dobavlenje(n);

	cout << c;
	cout << endl;

	cout << "Выводим с помощью метода Show и указателя\n";
	p = &c;
	p->Show();
	system("pause");
	cout << "_______________________________________________\n";

	cout << "Работаем с классом Вектор:\n";

	Vector v(5);
	p = &a;
	v.Add(p);
	p = &c;
	v.Add(p);
	cout << v;
	system("pause");
}

