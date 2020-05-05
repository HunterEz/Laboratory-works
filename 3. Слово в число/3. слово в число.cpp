//Мальцев Роман, лаб. 3, Перевод слова в число﻿
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	long long int n;
	char* ptn = (char*)&n;
	for (int i = 0; i < 8; i++)
	{
		cin >> *(ptn + i);
	}
	cout << n;
}
