#pragma once
#include <iostream>

class Iterator
{
	friend class Vector;
public:
	Iterator() { elem = 0; };
	Iterator(const Iterator& it) { elem = it.elem; }

	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }

	void operator++() { ++elem; }
	void operator++(int)  { ++elem; }
	void operator--() { --elem; }
	void operator--(int) { --elem; }
	void operator+(const int k);


	int& operator*() const { return *elem; }
private:
	int* elem;
};

using namespace std;
class Vector
{
public:
	Vector(int s, int k = 0);
	Vector(const Vector& v);
	~Vector();
	Vector& operator=(const Vector& v);
	int& operator[](int index);
	Vector operator*(const Vector& v);
	int operator()();

	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);

	Iterator first() { return beg; }
	Iterator last() { return end; }
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};

