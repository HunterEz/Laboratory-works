#pragma once
#include <iostream>
using namespace std;

class Money
{
public:
	Money(void);
	Money(long, int);
	Money(const Money&);
	Money& operator = (const Money&);

	friend ostream& operator<< (ostream& out, const Money&);
	friend istream& operator>> (istream& in, Money&);

	Money operator-(const Money&m);
public:
	virtual ~Money(void) {};
private:
	long rub;
	int cop;
};

