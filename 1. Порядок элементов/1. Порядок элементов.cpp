// Мальцев Роман, лаб. 1, Порядок элементов
#include <iostream>
#include <stdlib.h>
using namespace std;
void main()
{
	int Arr[100];
	int n;
	int k = 0;
	bool g = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> Arr[i];
	}
	
	while (k < n-1 &&(g==1))
	{
		if(Arr[k]<Arr[k+1])
		{
			g = 1;
		}
		else
		{
			g = 0;
		
		}
		k++;
	}
	
	cout << g;
}
