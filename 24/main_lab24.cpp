// Мальцев Роман, лаб. 24, Шаблоны классов
#include "Lots.h"		
#include "Money.h"
#include <iostream>

using namespace std;

/*
МНОЖЕСТВО с элементами типа int. 
Реализовать операции: [] – доступа по индексу; 
() – определение размера вектора;
- – разность множеств

Money для работы с денежными суммами. 
Число должно быть представлено двумя полями: 
типа long для рублей и типа int для копеек. 
Дробная часть числа при выводе на экран должна
быть отделена от целой частизапятой

*/

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "Работаем с классом МНОЖЕСТВО!\n";
	cout << "Создаем переменную А с 5 элементами:\n";
	Lots<int> a(5,0);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	cout << endl;
	cout << "Создаем переменную В с 10 элементами:\n";
	Lots<int> b(10,45);
	cout << b << "\n";
	cout << endl;
	cout << "Приравниваем В к А:\n";
	b = a;
	cout << b << "\n";
	cout << endl;
	cout << "Элемент переменной А с индексом 2 равен 100:\n";
	a[2] = 100;
	cout << endl;
	cout << "Создаем переменную С с 10 элементами\n";
	Lots<int> c(10,0);
	cout << endl;
	cout << "переменная С равена разности элементов B и A:\n";
	c = b - a;
	cout << c << "\n";
	cout << "Вывод длины А= " << a() << endl;

	system("pause");
	cout << endl;
	cout << "Работаем с классом Money!\n";
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
	cout << "Выполним тестировани параметризированного класса Множество:\n";
	cout << "Для пользовательского типа данных Money:\n";
	cout << "Создаем переменную класса Money:\n";
	Money m;
	cin >> m;
	cout << m;
	cout << endl;
	cout << "Создаем переменную класса Множества с пользовательским типо данных Money:\n";
	Lots<Money>Al(5, m);
	cin >> Al;
	cout << Al << endl; 
	cout << endl;
	cout << "Создаем вторую переменную класса Множества с пользовательским типо данных Money:\n";
	Lots<Money>Bl(10, m);
	cout << Bl << endl;
	cout << endl;
	cout << "Выводим 3 элемент первой переменной:\n";
	cout << Al[2] << endl;
	cout << "Размер первой переменной = " << Al() << endl;
	Lots<Money>Cl(10, m);
	cout << endl;
	cout << "Вычитаем из второй переменной элементы первой:\n";
	Cl = Bl - Al;
	cout << Cl;
	cout << endl;
	cout << "Приравниваем вторую переменную первой и выводи её:\n";
	Bl = Al;
	cout << Bl << endl;

	system("pause");
}