#include "Money.h"
#include <iostream>
#include <string>
using namespace std;

Money& Money::operator=(const Money& m)
{
	if (&m == this)return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}

Money& Money::operator--()
{
	long temp = rub * 100 + cop;
	temp--;
	cop = temp % 100;
	rub = (temp - (temp % 100)) / 100;
	return *this;
}

Money Money::operator--(int)
{
	long temp = rub * 100 + cop;
	temp--;
	Money m(rub, cop);
	cop = temp % 100;
	rub = (temp - (temp % 100)) / 100;
	return *this;
}

void Money::operator==(const Money& m)
{

	double temp1 = rub * 100 + cop;
	double temp2 = m.rub * 100 + m.cop;
	bool rez;
	if (temp1 == temp2) { cout << rub << "," << cop << "==" << m.rub << "," << m.cop; }
	else { cout << rub << "," << cop << "!=" << m.rub << "," << m.cop; }
	cout << endl;
}

fstream& operator>>(fstream& fin, Money& m)
{
	fin >> m.rub;
	fin >> m.cop;
	return fin;
}

fstream& operator<<(fstream& fout, const Money& m)
{
	fout << m.rub << endl << m.cop << endl;
	return fout;

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

Money Money::operator-(const Money& m)
{
	long minus = (rub * 100 + cop) - (m.rub * 100 + m.cop);
	Money temp(((minus - (minus % 100)) / 100), minus % 100);
	return temp;
}

Money& Money::operator++()
{
	rub += 1;
	cop += 50;
	return *this;
}

Money Money::operator++(int)
{
	rub += 1;
	cop += 50;
	return *this;
}
