#include "Date.h"

Date::Date(void) :Triad()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::~Date(void)
{

}
Date::Date(int d, int m, int y) :Triad()
{
	day = d;
	month = m;
	year = y;
}

Date::Date(const Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}


void Date::Set_day(int d)
{
	day = d;
}
void Date::Set_month(int m)
{
	month = m;
}
void Date::Set_year(int y)
{
	year = y;
}

void Date::plusoneD()
{
	day = day + 1;
	month = month + 1;
	year = year + 1;
}

void Date::dobavlenje(int n)
{
	day = day + n;
	if (day > 31) {
		month = month + (day / 31);
		if (month > 12)
		{
			year = year + (month / 12);
			month = month % 12;
		}
		day = (day % 31);
	}
}

Date& Date:: operator=(const Date& d)
{
	if (&d == this)return *this;
	day = d.day;
	month = d.month;
	year = d.year;
	return*this;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "\nDay: "; in >> d.day;
	cout << "\nMonth: "; in >> d.month;
	cout << "\nYear: "; in >> d.year;
	return in;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << "\nDAY: " << d.day;
	out << "\nMONTH: " << d.month;
	out << "\nYEAR: " << d.year;
	out << "\n";
	return out;
}

void Date::Show()
{
	cout << "\nDAY: " << day;
	cout << "\nMONTH: " << month;
	cout << "\nYEAR: " << year;
	cout << "\n";
}
