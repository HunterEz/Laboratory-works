#pragma once

#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

class Lots

{
	int size;
	int* beg;
public:
	Lots() { size = 0; beg = 0; }
	Lots(int s);
	Lots(int s, int* mas);
	Lots(const Lots& l);
	~Lots();
	const Lots& operator=(const Lots& l);
	int operator[](int i);
	int operator()();
	Lots operator-(const Lots& l);
	Lots operator--();
	friend ostream& operator<<(ostream& out, const Lots& v); friend istream& operator>>(istream& in, Lots& v);
};