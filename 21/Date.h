#pragma once
#include "Triad.h"
class Date :
	public Triad
{
public:
	Date(void);
public:
	~Date(void);
	void Show();
	Date(int, int, int);
	Date(const Date&);

	int Get_day() { return day; }
	int Get_month() { return month; }
	int Get_year() { return year; }

	void Set_day(int);
	void Set_month(int);
	void Set_year(int);

	void plusoneD();

	void dobavlenje(int);

	Date& operator=(const Date&);

	friend istream& operator >> (istream& in, Date& d);
	friend ostream& operator << (ostream& out, const Date& d);

protected:
	int day;
	int month;
	int year;
};

