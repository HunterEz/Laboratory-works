#include "Lots.h"

Lots::Lots(int s)
{
	if (s > MAX_SIZE) throw 1;

	size = s;

	beg = new int[s];

	for (int i = 0; i < size; i++)

		beg[i] = 0;
}

Lots::Lots(const Lots& l)

{
	size = l.size;

	beg = new int[size];

	for (int i = 0; i < size; i++)
	{
		beg[i] = l.beg[i];
	}

}

Lots::~Lots()

{
	if (beg != 0) delete[]beg;
}

Lots::Lots(int s, int* mas)

{
	if (s > MAX_SIZE) throw 1;

	size = s;

	beg = new int[size];

	for (int i = 0; i < size; i++)

		beg[i] = mas[i];

}

const Lots& Lots::operator =(const Lots& l)
{
	if (this == &l)return *this;

	if (beg != 0) delete[]beg;

	size = l.size;

	beg = new int[size];

	for (int i = 0; i < size; i++)

		beg[i] = l.beg[i];

	return*this;
}

ostream& operator<<(ostream& out, const Lots& l)

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

istream& operator >>(istream& in, Lots& l)

{

	for (int i = 0; i < l.size; i++)

	{

		cout << ">";

		in >> l.beg[i];

	}

	return in;

}

int Lots::operator [](int i)

{

	if (i < 0)throw 2;

	if (i >= size) throw 2;
	return beg[i];

}

Lots Lots::operator-(const Lots& v)
{
	Lots temp(size);
	for (int i = 0; i < size; ++i)
	{
		temp.beg[i] = v.beg[i] - beg[i];
	}
	return temp;
}

Lots Lots::operator--()

{

	if(size==0) throw 5;

	if (size == 1)
	{

		size = 0;

		delete[]beg;

		beg = 0;

		return *this;
	}

	Lots temp(size, beg);

	delete[]beg;

	size--;

	beg = new int[size];

	for (int i = 0; i < size; i++)

		beg[i] = temp.beg[i];

	return*this;

};

int Lots::operator()()
{
	return size;
}