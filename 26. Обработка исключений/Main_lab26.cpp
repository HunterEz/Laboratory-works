// ������� �����, ���. 26, ��������� ����������
#include "Lots.h"
#include "Vector_realiz2.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main()

{
	setlocale(LC_ALL, "rus");
	int a;
	cout << "�������� ����� ����������(1 ��� 2): ";
	cin >> a;
	int	mass[2] = { 1,2 };
	if (a == 1)
	{
		try

		{

			Lots x(2, mass);

			cout << "�������� ������: ";

			cout << x;

			cout << "������� ������\n";

			int i;

			cin >> i;

			cout << "������� � �������� " << i << "\n";

			cout << x[i] << endl;

			cout << "�������� �������!\n";

			--x;

			cout << x;

			cout << "�������� �������!\n";

			--x;

			cout << x;

			cout << "�������� �������!\n";

			--x;

		}
		catch (int)
		{
			cout << "ERROR!!!" << endl;
		}
		return 0;
	}
	else if (a == 2)
	{
		try

		{

			Lots2 x(2, mass);

			cout << "�������� ������: ";

			cout << x;

			cout << "������� ������: ";

			int i;

			cin >> i;

			cout << "������� � �������� " << i << "\n";

			cout << x[i] << endl;

			cout << "�������� �������!\n";

			--x;

			cout << x;

			cout << "�������� �������!\n";

			--x;

			cout << x;

			cout << "�������� �������!\n";

			--x;

		}

		catch (error e)

		{
			e.what();
		}

		return 0;

	}
	else
	{
	cout << "�������� �����!";
	return 0;
	}
}