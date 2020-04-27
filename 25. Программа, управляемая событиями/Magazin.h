#pragma once
#include "Print.h"
using namespace std;

class Magazin :
	public Print
{
public:
	Magazin(void);
public:
	~Magazin(void);
	void Show();
	void Input();
	Magazin(string, string, int);
	Magazin(const Magazin&);
	int Get_pages() { return pages; }
	void Set_pages(int);
	Magazin& operator=(const Magazin&);
protected:
	int pages;
};

