#include "Tree.h"

Tree::Tree()
{
	beg = 0;
	cur = 0;
	size = 0;
}
Tree::~Tree(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
Tree::Tree(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
void Tree::Add()
{
	Object* p;
	cout << "1. Print" << endl;
	cout << "2. Magazin" << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		Print* a = new (Print);
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (x == 2)
		{
			Magazin* b = new Magazin;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
void Tree::Add(Object* o)
{
	Object* p = o;
	beg[cur] = p;
	cur++;
	return;
}
void Tree::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}
int Tree::operator()()
{
	return cur;
}
void Tree::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandEvent(e);
			p++;
		}
	}
}
void Tree::Del()
{
	if (cur == 0) return;
	cur--;
}


		