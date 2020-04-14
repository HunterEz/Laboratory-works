#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n = 10;
	cin >> n;
	void** pmass = new void* [2];
	pmass[0] = new int[n];
	pmass[1] = new float[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ((int*)pmass[0])[i] >> ((float*)pmass[1])[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << ((int*)pmass[0])[i] << '\t' << ((float*)pmass[1])[i] << endl;
	}
}