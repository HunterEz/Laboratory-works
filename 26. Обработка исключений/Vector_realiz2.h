#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE2 = 30;

class Lots2

{
	int size;
	int* beg;
public:
	Lots2() { size = 0; beg = 0; }
	Lots2(int s);
	Lots2(int s, int* mas);
	Lots2(const Lots2& l);
	~Lots2();
	const Lots2& operator=(const Lots2& l);
	int operator[](int i);
	int operator()();
	Lots2 operator-(const Lots2& l);
	Lots2 operator--();
	friend ostream& operator<<(ostream& out, const Lots2& v); friend istream& operator>>(istream& in, Lots2& v);
};