#include "Money.h"

Money::Money(void)
{
	rub = cop = 0;
}
Money::Money(long r, int c)
{
	cop = c;
	rub = r;
}
Money::Money(const Money& m)
{
	rub = m.rub;
	cop = m.cop;
}

Money& Money::operator=(const Money& m)
{
	
	rub = m.rub;
	cop = m.cop;
	return *this;
}


istream& operator>> (istream& in, Money& m)
{
	cout << "rub?"; in >> m.rub;
	cout << "cop?"; in >> m.cop;
	return in;
}

ostream& operator<<(ostream& out, const Money& m)
{
	out << m.rub << "," << m.cop;
	return out;
}

Money Money::operator-(const Money &m)
{
	long minus = (rub * 100 + cop) - (m.rub * 100 + m.cop);
	Money temp(((minus - (minus % 100)) / 100), minus % 100);
	return temp;
}