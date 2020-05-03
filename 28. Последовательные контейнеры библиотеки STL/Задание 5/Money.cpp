#include "Money.h"
#include <iostream>
using namespace std;

Money& Money::operator=(const Money& m)
{
	if (&m == this)return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}

Money Money::operator+(const Money& m)
{
	int temp1 = rub * 100 + cop;
	int temp2 = m.rub * 100 + m.cop;
	Money p;
	p.cop = (temp1 + temp2) % 100;
	p.rub = (temp1 + temp2) / 100;
	return p;
}

Money Money::operator/(const Money& m)
{
	int temp1 = rub * 100 + cop;
	int temp2 = m.rub * 100 + m.cop;
	Money p;
	p.cop = (temp1 / temp2) % 100;
	p.rub = (temp1 / temp2) / 100;
	return p;
}

Money Money::operator/(const int& m)
{
	int temp1 = rub * 100 + cop;
	Money p;
	p.cop = (temp1 / m) % 100;
	p.rub = (temp1 / m) / 100;
	return p;
}

bool Money::operator<(const Money& m)
{
	if (rub < m.rub) return true;
	if (rub == m.rub && cop < m.cop) return true;
	return false;
}

bool Money::operator>(const Money& m)
{
	if (rub > m.rub) return true;
	if (rub == m.rub && cop > m.cop) return true;
	return false;
}

istream& operator>> (istream& in, Money& m)
{
	cout << "rub?"; in >> m.rub;
	cout << "cop?"; in >> m.cop;
	return in;
}

ostream& operator<<(ostream& out, const Money& m)
{
	return (out << m.rub << "," << m.cop);
}

