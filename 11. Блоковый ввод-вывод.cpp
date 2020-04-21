// Мальцев Роман, лаб. 11 (Новый порядок: 8 (8з)), Структуры данных
//Структура "Информация":
//• Носитель;
//• Объем;
//• Название;
//• Автор.
//Удалить первый элемент с заданным объемом информации, добавить элемент перед элементом с указанным номером.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Information
{
	Information* next;
	char Carrier[50];
	int Volume;
	char Name[50];
	char Author[50];
};
Information* create_obj(...)
{
	Information* p = new Information;
	cout << "\nВведите наименование носителя ифнормации: ";
	cin >> p->Carrier;
	cout << "\nВведите объем информации: ";
	cin >> p->Volume;
	cout << "\nВведите название ифнормации: ";
	cin >> p->Name;
	cout << "\nВведите наименование автора ифнормации: ";
	cin >> p->Author;
	cout << endl;
	p->next = 0;
	return p;
}
Information* create_list(Information*& first, int n)
{
	Information* p = first;
	Information* r;
	for (int i = 1; i < n; i++)
	{
		r = create_obj();
		p->next = r;
		p = r;
	}
	return first;
}
void print_list(Information* first)
{
	Information* p = first;
	while (p)
	{
		cout << "Носитель:" << p->Carrier << '\t';
		cout << "Объем:" << p->Volume << '\t';
		cout << "Название:" << p->Name << '\t';
		cout << "Автор" << p->Author << endl;
		p = p->next;
	}
}
Information* delete_obj(Information*& first, float k, int n)
{
	Information* p = first;
	Information* ptr = 0;
	if (first->Volume == k)
	{
		first = first->next;
		delete p;
		return first;
	}
	else {
		for (int i = 1; i < n && p->next != 0; i++)
		{
			if (p->next->Volume == k)
			{
				ptr = p->next;
				p->next = ptr->next;
				delete ptr;
				return first;
			}
			p = p->next;
			if (p->next == 0)
			{
				return first;
			}
		}
	}
}
Information* add_obj(Information*& first, int num)
{
	Information* p = first;
	for (int i = 0; i < num - 1 && p->next != 0; i++)
	{
		p = p->next;
	}
	if (p != 0)
	{
		Information* r = create_obj();
		r->next = p->next;
		p->next = r;
		return first;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string path = "Information.txt";
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия!";
	}
	else
	{
		int num, n;
		float k;
		cout << "Введите количество объектов:";
		cin >> n;
		cout << endl;
		Information* first = create_obj();
		create_list(first, n);
		Information* p = first;
		
		while (p)
		{
			
			fout << "Изначальные данные:\n";
			fout << "Носитель: " << p->Carrier << '\t';
			fout << "Объем: " << p->Volume << '\t';
			fout << "Название: " << p->Name << '\t';
			fout << "Автор: " << p->Author << endl;
			fout << "_______________________________________________________________\n";
			p = p->next;
		}
		p = first;
		fout << endl;
		cout << "Укажите Объем:";
		cin >> k;
		delete_obj(first, k, n);
		p = first;
		while (p)
		{
		
			fout << "Данные после удаления:\n";
			fout << "Носитель: " << p->Carrier << '\t';
			fout << "Объем: " << p->Volume << '\t';
			fout << "Название: " << p->Name << '\t';
			fout << "Автор: " << p->Author << endl;
			fout << "_______________________________________________________________\n";
			p = p->next;
		}
		p = first;
		fout << endl;
		cout << "Укажите номер элемента:";
		cin >> num;
		cout << endl;
		add_obj(first, num-1);
		while (p)
		{
			
			fout << "Данные после добавления:\n";
			fout << "Носитель: " << p->Carrier << '\t';
			fout << "Объем: " << p->Volume << '\t';
			fout << "Название: " << p->Name << '\t';
			fout << "Автор: " << p->Author << endl;
			fout << "_______________________________________________________________\n";
			p = p->next;
		
		}
	}
	cout << "_______________________________________________________________\n";
	fout.close();
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия!";
	}
	else
	{
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();
	system("pause");
}
