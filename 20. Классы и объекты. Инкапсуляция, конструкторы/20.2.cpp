  
// Мальцев Роман, лаб. 20.2, Классы №1
#include <iostream>
using namespace std;

class exam
{
public:
	string name;
	string subject;
	int marks;

	exam()
	{
		name = "";
		subject = "";
		marks = 0;
	};

	exam(string nam, string subj, int mark)
	{
		name = nam;
		subject = subj;
		marks = mark;
	};

	exam(const exam& b)
	{
		name = b.name;
		subject = b.subject;
		marks = b.marks;

	};

	~exam()
	{


	}

	void print_student()
	{
		cout << "Имя: " << name;
		cout << endl;
		cout << "Предмет: " << subject;
		cout << endl;
		cout << "Оценка: " << marks;
		cout << endl;
	}

	void set_student(string Name, string Subject, int Marks)
	{
		name = Name;
		subject = Subject;
		marks = Marks;
	}

	void copyprint(exam a)
	{
		a.print_student();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "__________________________________________\n";
	cout << "Без параметров:\n";
	exam bezparam;
	bezparam.print_student();
	cout << "__________________________________________\n";
	cout << "С парамтерами:\n";
	exam param("Malcev Roman Urjevich", "Math", 5);
	param.print_student();
	cout << "__________________________________________\n";
	cout << "Копирование:\n";
	exam forcopy;
	forcopy.set_student("Petrov Ivan Ivanovich", "IT", 4);
	exam copy(forcopy);
	copy.print_student();

	system("pause");
	return 0;
}
