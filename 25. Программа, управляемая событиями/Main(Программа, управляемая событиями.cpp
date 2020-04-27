  
// Мальцев Роман, лаб. 25, Программа, управляемая событиями
#include <iostream>
#include "Tree.h"
#include "Print.h"
#include "Dialog.h"
#include "Magazin.h"
using namespace std;


void main()
{
	setlocale(LC_ALL, "rus");
	cout << "m: Создать группу\n+: Добавить элемент\n-: Удалить элемент\ns: Информация о членах группы\n";
	cout << "z: Информация о названиях элементов группы\nq: Конец работы\n";
	Dialog D;
	D.Execute();
}
