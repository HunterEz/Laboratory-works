
#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Money
{
	long rub;
	int cop;
public:
	Money() { rub = 0; cop = 0; };
	Money(long r, int c) { rub = r; cop = c; }
	Money(const Money& m) { rub = m.rub; cop = m.cop; }
	~Money() { };
	long get_rub() { return rub; }
	int get_cop() { return cop; }
	void set_rub(long r) { rub = r; }
	void set_cop(int c) { cop = c; }

	Money& operator=(const Money&);
	Money& operator--();
	Money operator--(int);
	void operator==(const Money& m);
	Money operator-(const Money& m);
	Money& operator++();
	Money operator++(int);

	friend fstream& operator>>(fstream& fin, Money& m);
	friend fstream& operator<<(fstream& fout, const Money& m);

	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);

};