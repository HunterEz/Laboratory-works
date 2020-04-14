#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int** cr_memory(int n, int m, int** mass)
{	/*Выделение памяти под массив*/
	
	for (int i = 0; i < n; i++)
	{
		mass[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mass[i][j] = rand() % 101 - 50;
			
		}

	}
	return mass;
}

int** cr_mass(int n, int m, int** mass)
{ /*печать*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
	
			cout << mass[i][j] << '\t';
		}
		cout << endl;
	}
	return mass;

}

void ch_mass(int n, int m,int k, int** &mass)
{	/*Добавление новых столбцов в начале массива*/
	
	int** mass2 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mass2[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{

			mass2[i][j] = rand() % 101 - 50;
			cout << mass2[i][j] << '\t';
		}
		for (int j = k; j < m ; j++)
		{
			mass2[i][j] = mass[i][j-k];
			cout << mass2[i][j] << '\t';
		}
		cout << endl;
		
	}
	mass = mass2;
}

 int** del_mass(int n, int** mass)
{	/*Удалиение массивов*/

	for (int i = 0; i < n; i++)
	{
		delete[] mass[i];
	}
		delete[] mass;
	return 0;
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, m, a;
	cout << " Введите количество строк и столбцов: \n";
	cin >> n >> m;
	cout << endl;
	int** mass = new int* [n];

	do
	{

		cout << "1.Формирование массива\n";

		cout << "2.Печать массива\n";

		cout << "3.Добавление в k столбцов в массив\n";

		cout << "4.Выход\n";

		cin >> a;

		switch (a)

		{

		case 1: cr_memory(n, m, mass); break;//выделение памяти и заполнение

		case 2: cr_mass(n, m, mass); break;//печать

		case 3:
			cout << " Введите количество новых столбцов в начале матрицы \n";
			cout << endl;

			int k;
			cin >> k;
			m += k;
			ch_mass(n, m, k, mass); break;//добавление

		}
	}
		while (a != 4);//выход
	
	del_mass(n, mass);
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int razmer;

vector<string> surnames = {
"Иванов","Петров","Сидоров","Тесла","Маск","Эйнштейн","Ньютон","Гук","Кюри","Сталин","Ленин","Маркс"
};

vector<string> names = {
"Иван","Петр","Сидор","Никола","Илон","Альберт","Исаак","Роберт","Мария","Иосиф","Владимир","Карл","Алексей","Михаил","Дмитрий"
};

vector<string> patronymics = {
"Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович","Владимирович","Карлович","Алексеевич","Михаилович","Дмитриевич"
};


class Person
{


public:

	string name;
	string surname;
	string patronymic;
	unsigned int passpotr;
	unsigned long int number;
	int colision = NULL;



};



class Hesh {

public:
	Person** persontabl = new Person * [razmer];
	Person* hashtabl[1000];
	int kolis = 0;
	int a = 26;

	void create_list()
	{


		cout << "Введите количество элементов: ";

		cin >> razmer;

		cout << "Список данных:\n";

		cout << endl;

		for (int i = 0; i < razmer; i++)
		{

			Person* pers = new Person;

			pers->name = names[rand() % 15];

			pers->surname = surnames[rand() % 12];

			pers->patronymic = patronymics[rand() % 15];

			pers->passpotr = rand() * rand() % 999999 + 100000;

			pers->number = rand() * rand() % 999999999 + 100000000; // 9 символов

			pers->colision = NULL;

			persontabl[i] = pers;

			cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";

			cout << persontabl[i];

			cout << endl;

		}

		cout << endl;

	}

	void hash_table(Hesh newtable)
	{

		for (int i = 0; i < 1000; i++)
		{
			hashtabl[i] = NULL;
		}
		create_table(newtable);
	}

	void create_table(Hesh newtable)
	{
		for (int i = 0; i < razmer; i++)
		{




			if (hashtabl[heshfunk(persontabl[i]->number, a)] != 0)
			{

				kolis++;

				int k = 0;

				if (heshfunk(persontabl[i]->number, a) == 999 && hashtabl[heshfunk(persontabl[i]->number, a)] != 0)
				{
					int j = 0;

					while (hashtabl[j] != 0)
					{

						j++;

					}

					hashtabl[j] = persontabl[i];

					cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";

					cout << " Новый индекс элемента: " << j;

					hashtabl[j]->colision = j;

					cout << endl << " Коллизия\n";

					goto skip;

				}
				while (hashtabl[heshfunk(persontabl[i]->number, a) + k] != 0)
				{
					k++;
					if (heshfunk(persontabl[i]->number, a) + k == 999 && hashtabl[heshfunk(persontabl[i]->number, a) + k] != 0)
					{
						int j = 0;
						while (hashtabl[j] != 0)
						{
							j++;
						}
						hashtabl[j] = persontabl[i];
						cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";
						hashtabl[j]->colision = j;
						cout << " Новый индекс элемента: " << j;
						cout << endl << " Коллизия\n";

						goto skip;
					}
				}

				hashtabl[heshfunk(persontabl[i]->number, a) + k] = persontabl[i];
				cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";

				cout << " Новый индекс элемента: " << heshfunk(persontabl[i]->number, a) + k;
				hashtabl[heshfunk(persontabl[i]->number, a) + k]->colision = heshfunk(persontabl[i]->number, a) + k;
				cout << " Коллизия\n";

			}
			else
			{
				hashtabl[heshfunk(persontabl[i]->number, a)] = persontabl[i];
			}
		skip:;

		}
		cout << endl;
		cout << "Количество коллизий при размере хэш-таблицы " << razmer << " элементов: " << kolis;
		cout << endl;
	}

	int heshfunk(int key, int size)
	{

		if (key < 100000000 || key > 999999999)
		{
			cout << "Неверный ввод!";
			return 0;
		}

		int g = key / 10000000;
		int l = key / 100000000 / g;
		int h = size * 0.1343 * (key % 256) + g + l;

		return  h;
	}

	void delete_elem()
	{
		cout << "Введите мобильный номер или номер элемента:";
		int num;
		int k;
		cin >> num;
		if (num < 1000)
		{
			k = num;
		}
		else
		{
			k = heshfunk(num, a);
		}
		if (k != heshfunk(hashtabl[k]->number, a)) kolis--;
		hashtabl[k] = NULL;
	}

	void add_elem()
	{
		int num;
		int k;
		cin >> num;
		k = heshfunk(num, a);

	}

	void search()
	{
		int k;
		int g;
		bool tr = 0;
		bool ser = 0;
		cout << "Введите искомый номер: ";
		cin >> k;
		g = heshfunk(k, a);
		for (int i = 0; i < 1000; i++)
		{

			hashtabl[i];
			if (hashtabl[i] != NULL)
			{
				if (g == i)
				{
					tr = 1;

					if (hashtabl[i + 1] != NULL)
					{
						if (hashtabl[i + 1]->number == k)
						{
							cout << 1 << endl;
							cout << "Элемент " << hashtabl[i + 1]->colision;
							cout << endl;
							cout << hashtabl[hashtabl[i + 1]->colision]->surname << " " << hashtabl[hashtabl[i + 1]->colision]->name << " " << hashtabl[hashtabl[i + 1]->colision]->patronymic << endl << hashtabl[hashtabl[i + 1]->colision]->passpotr << "\t" << hashtabl[hashtabl[i + 1]->colision]->number << "\t";
							cout << endl;
						}
						else
						{
							cout << 2 << endl;
							cout << "Элемент " << g;
							cout << endl;
							cout << hashtabl[i]->surname << " " << hashtabl[i]->name << " " << hashtabl[i]->patronymic << endl << hashtabl[i]->passpotr << "\t" << hashtabl[i]->number << "\t";
							cout << endl;
						}
					}
					else
					{
						cout << 3 << endl;
						cout << "Элемент " << g;
						cout << endl;
						cout << hashtabl[i]->surname << " " << hashtabl[i]->name << " " << hashtabl[i]->patronymic << endl << hashtabl[i]->passpotr << "\t" << hashtabl[i]->number << "\t";
						cout << endl;
					}
				}
			}
		}
		if (tr == 0)
		{
			cout << "Элемент не найден!\n";
		}
	}

	void print_Hesh()
	{
		int b = 0;
		cout << "Данные" << "\t\t\t\t Номер в таблице\n";
		for (int i = 0; i < 1000; i++)
		{

			if (hashtabl[i] != 0) {

				cout << hashtabl[i]->surname << " " << hashtabl[i]->name << " " << hashtabl[i]->patronymic << endl << hashtabl[i]->passpotr << "\t" << hashtabl[i]->number << "\t";
				if (hashtabl[i]->colision != NULL)
				{
					cout << '\t' << hashtabl[i]->colision;
					cout << endl;
				}
				else
				{
					cout << '\t' << heshfunk(hashtabl[i]->number, a);
					cout << endl;
				}
				b++;
			}
		}
		cout << "Элементов в таблице: ";
		cout << b << endl;
		cout << "Элементов с коллизией: " << kolis;
		cout << endl;
	}

	void deletef()
	{
		for (int i = 0; i < razmer; i++)
		{
			delete[] persontabl[i];
		}
		delete[] persontabl;
	}
};

Hesh printka(Hesh newtable)
{
	int a = 0;
	newtable.hash_table(newtable);

	for (int i = 0; i < 1000; i++)
	{
		if (newtable.hashtabl[i] != 0) {
			a++;
		}
	}
	cout << "Элементов в таблице: ";
	cout << a << endl;
	return newtable;


}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int swt;
	Hesh newtable;
	newtable.create_list();
	do
	{

		cout << "1.Формирование и заполнение хэш таблицы\n";

		cout << "2.Печать хэш таблицы\n";

		cout << "3.Удаление элемента\n";

		cout << "4.Добавление элемента\n";

		cout << "5.Поиск элемента\n";

		cout << "6.Выход\n";

		cin >> swt;

		switch (swt)

		{

		case 1: newtable = printka(newtable); break;//cjplfybt

		case 2: newtable.print_Hesh(); break;//печать

		case 3:	newtable.delete_elem(); break;//добавление

		case 5: newtable.search(); break;// поиск

		}
	} while (swt != 6);//выход
	newtable.deletef();
}

/*
int heshfunk(int key, int size)
{
	int g = key / 10000000;
	int l = key / 100000000 / g;
	int h = size * 0.1343 * (key % 256)+g+l;

	return  h;
}

int main()
{
	srand(time(0));
	int mass[1000];
	int number;
	int max = 0;
	int temp;
	int elem = 0;
	int a = 26;
	int d = 0;
	for (int i = 0; i < 1000; i++)
	{
		mass[i] = NULL;
	}
	for (int i = 0; i < 10000000; i++)
	{
		number = rand() * rand() % 999999999 + 100000000;
		temp = heshfunk(number, a);
		if (temp > max) {
			max = temp;
		}

		if (mass[temp] != 0) {
			d++;
		}
		mass[temp] = number;


	}
	cout << endl;
	cout << '\t' << max << '\t' << d << '\t' << elem++;
}
	*/


	// ФИО, №паспорта, №телефона
	// ключ №телефона

	// H(k) = [M(kAmod1)], 0 < A < 1, mod1 – получение дробной части, [] – получение целой части
	//	Метод открытой адресации
