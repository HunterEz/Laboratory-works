#include "Print.h"
#include <iostream>
using namespace std;

Print::Print(void)
{
	name = "";
	author = "";
}
Print::~Print(void)
{

}
Print::Print(string n, string a)
{
	name = n;
	author = a;
}
Print::Print(const Print& p)
{
	name = p.name;
	author = p.author;
}
void Print::Set_name(string n)
{
	name = n;
}
void Print::Set_author(string a)
{
	author = a;
}
Print& Print::operator=(const Print& p)
{
	if (&p == this) return *this;
	name = p.name;
	author = p.author;
	return *this;
}
void Print::Show()
{
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
	cout << endl;
}
void Print::Input()
{
	cout << "\nEnter name: "; cin >> name;
	cout << "\nEnter author: "; cin >> author;
	cout << endl;
}
void Print::HandEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "Name: " << Get_name() << endl;
			break;
		}
	}
}