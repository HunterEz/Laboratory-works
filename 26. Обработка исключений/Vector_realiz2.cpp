#include "Vector_realiz2.h"
#include "Error.h"

Lots2::Lots2(int s)
{
	if (s > MAX_SIZE2) throw error("Vector length more than max size\n");

	size = s;

	beg = new int[s];

	for (int i = 0; i < size; i++)

		beg[i] = 0;
}

Lots2::Lots2(const Lots2& l)

{
	size = l.size;

	beg = new int[size];

	for (int i = 0; i < size; i++)
	{
		beg[i] = l.beg[i];
	}

}

Lots2::~Lots2()

{
	if (beg != 0) delete[]beg;
}

Lots2::Lots2(int s, int* mas)

{
	if (s > MAX_SIZE2) throw error("Vector length more than max size\n");

	size = s;

	beg = new int[size];

	for (int i = 0; i < size; i++)

		beg[i] = mas[i];

}

const Lots2& Lots2::operator =(const Lots2& l)
{
	if (this == &l)return *this;

	if (beg != 0) delete[]beg;

	size = l.size;

	beg = new int[size];

	for (int i = 0; i < size; i++)

		beg[i] = l.beg[i];

	return*this;
}

ostream& operator<<(ostream& out, const Lots2& l)

{
	if (l.size == 0) out << "Empty\n";

	else

	{

		for (int i = 0; i < l.size; i++)

			out << l.beg[i] << " ";

		out << endl;

	}

	return out;

}

istream& operator >>(istream& in, Lots2& l)

{

	for (int i = 0; i < l.size; i++)

	{

		cout << ">";

		in >> l.beg[i];

	}

	return in;

}

int Lots2::operator [](int i)

{

	if (i < 0)throw error("index < 0");

	if (i >= size) throw error("index > size");
	return beg[i];

}

Lots2 Lots2::operator-(const Lots2& v)
{
	Lots2 temp(size);
	for (int i = 0; i < size; ++i)
	{
		temp.beg[i] = v.beg[i] - beg[i];
	}
	return temp;
}

Lots2 Lots2::operator--()

{

	if (size == 0) throw error("Lots is empty");

	if (size == 1)
	{

		size = 0;

		delete[]beg;

		beg = 0;

		return *this;
	}

	Lots2 temp(size, beg);

	delete[]beg;

	size--;

	beg = new int[size];

	for (int i = 0; i < size; i++)

		beg[i] = temp.beg[i];

	return*this;

};

int Lots2::operator()()
{
	return size;
}