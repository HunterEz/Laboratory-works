#include "Magazin.h"
Magazin::Magazin(void) :Print()
{
	pages = 0;
}
Magazin::~Magazin(void)
{

}
Magazin::Magazin(string n, string a, int page) :Print(n, a)
{
	pages = page;
}
Magazin::Magazin(const Magazin& m)
{
	name = m.name;
	author = m.author;
	pages = m.pages;
}
void Magazin::Set_pages(int page)
{
	pages = pages;
}
Magazin& Magazin::operator=(const Magazin& m)
{
	if (&m == this) return *this;
	name = m.name;
	author = m.author;
	pages = m.pages;
	return *this;
}
void Magazin::Show()
{
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nPages: " << pages;
	cout << endl;
}
void Magazin::Input()
{
	cout << "\nEnter name: "; cin >> name;
	cout << "\nEnter author: "; cin >> author;
	cout << "\nEnter pages: "; cin >> pages;
	cout << endl;
}

