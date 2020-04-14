// Мальцев Роман, лаб. 13, Стороки (4 Новая методичка)
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	char str[256], c;
	int i, a, k, cnt = 0, lon;
	gets_s(str);
	lon = strlen(str);
	for (i = 0; i < lon; i++)
	{
		while (str[i] == ' ' && i < lon) i++;
		a = i;
		while (str[i] != ' ' && i < lon) i++;
		cnt++;
		if (cnt % 2 == 0)
		{
			for (k = a; k < i - (i - a) / 2; k++)
			{
				c = str[k];
				str[k] = str[i - (k - a) - 1];
				str[i - (k - a) - 1] = c;
			}
		}

	} 
	puts(str);
	cin.get();
	return 0;
}
