#include "Triad.h"

Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}
Triad::~Triad(void)
{

}
Triad::Triad(int f, int s, int t)
{
	first = f;
	second = s;
	third = t;
}
Triad::Triad(const Triad& t)
{
	first = t.first;
	second = t.second;
	third = t.third;
}

void Triad::Set_first(int f)
{
	first = f;
}
void Triad::Set_second(int s)
{
	second = s;
}
void Triad::Set_third(int t)
{
	third = t;
}

void Triad::plusone()
{
	first = first + 1;
	second = second + 1;
	third = third + 1;
}

Triad& Triad:: operator=(const Triad& t)
{
	if (&t == this)return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return*this;
}

istream& operator>>(istream& in, Triad& t)
{
	cout << "\nFirst: "; in >> t.first;
	cout << "\nSecond: "; in >> t.second;
	cout << "\nThird: "; in >> t.third;
	return in;
}
ostream& operator<<(ostream& out, const Triad& t)
{
	out << "\nFIRST: " << t.first;
	out << "\nSECOND: " << t.second;
	out << "\nTHIRD: " << t.third;
	out << "\n";
	return out;
}

void Triad::Show()
{
	cout << "\nFIRST: " << first;
	cout << "\nSECOND: " << second;
	cout << "\nTHIRD: " << third;
	cout << endl;
}