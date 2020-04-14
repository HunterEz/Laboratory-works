#include <iostream>
#include <ctime>
using namespace std;

void fast_sort(int* mass, int n)
{
    int i = 0;
    int j = n - 1;
    int mid = mass[n / 2];
    do
    {
        while (mass[i] < mid)
        {
            i++;
        }
        while (mass[j] > mid)
        {
            j--;
        }
        if (i <= j)
        {
            int t = mass[i];
            mass[i] = mass[j];
            mass[j] = t;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
    {
        fast_sort(mass, j + 1);
    }
    if (i < n)
    {
        fast_sort(&mass[i], n - i);
    }
}
int inter(int* mass, int n, int elem)
{
    int mid, left = 0, right = n - 1;
    while (mass[left] <= elem && mass[right] >= elem)
    {
        mid = left + ((elem - mass[left]) * (right - left)) / (mass[right] - mass[left]);
        if (mass[mid] < elem)
        {
            left = mid + 1;
        }
        else if (mass[mid] > elem)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    if (mass[left] == elem)
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void boi_mur(char* txt, char* pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    bool u = false;
    int s1[256];
    int i;
    for (i = 0; i < 256; i++)
    {
        s1[i] = -1;
    }
    for (i = 0; i < m; i++)
    {
        s1[(int)pat[i]] = i;
    }
    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << "Найдено начало фрагмента на " << s + 1 << " символе" << endl;
            u = true;
            if (s + m < n)
            {
                s += m - s1[txt[s + m]];
            }
            else
            {
                s += 1;
            }
        }
        else
        {
            s += max(1, j - s1[txt[s + j]]);
        }
    }
    if (u == false)
    {
        cout << "Не найдено" << endl;
    }
}


void main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int p;
    do
    {

        cout << "1.Интерполяционный поиск\n";

        cout << "2.Поиск Бойера-Мура\n";

        cout << "3.Выход\n";

        cin >> p;

        switch (p)
        {

        case 1:
        {
            int elem, n, p;
            cout << "Введите количество элементов массива: ";
            cin >> n;
            int* mass = new int[n];
            cout << "Исходный массив: ";
            for (int i = 0; i < n; i++)
            {
                mass[i] = rand() % 100 - 50;
            }
            fast_sort(mass, n);
            for (int i = 0; i < n; i++)
            {
                cout << mass[i] << " ";
            }
            cout << endl;
            cout << "Искомый элемент: ";
            cin >> elem;
            inter(mass, n, elem);
            if (inter(mass, n, elem) == -1)
            {
                cout << "Элемент не найден";
            }
            else
            {
                cout << "Номер элемента: " << inter(mass, n, elem) + 1;
            }
            cout << endl;
            break;
        }

        case 2:
        {
            char txt[100];
            cout << "Введите текст: ";
            gets_s(txt);
            gets_s(txt);
            char pat[100];
            cout << endl << "Введите искомый фрагмент: ";
            gets_s(pat);
            boi_mur(txt, pat);
            break;
        }
        }
    } while (p != 3);
}