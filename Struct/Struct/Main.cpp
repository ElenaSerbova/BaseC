#include <iostream>
using namespace std;

#include "Date.h"
#include "Student.h"

void TestDate();
void TestStudent();
void TestStudentsStaticArray();

void AddStudent(Student*& students, int& size);
Student* FindByFio(Student* students, int size, const char* fio);

int main()
{
	//TestDate();
	//TestStudent();
	//TestStudentsStaticArray();

	int size = 3;
	Student* students = new Student[size];

	for (size_t i = 0; i < 3; i++)
	{
		InputStudent(students[i]);
	}
	
	AddStudent(students, size);

	for (size_t i = 0; i < size; i++)
	{
		PrintStudent(students[i]);
	}

	cout << "============== Find ===============" << endl;

	Student* john = FindByFio(students, size, "John Snow");
	if (john != nullptr)
	{
		PrintStudent(*john);
	}
	else
	{
		cout << "John Snow not found" << endl;
	}

	return 0;
}

void TestDate() {

	//struct Date date;
	Date date = { 0,0,0 };
	InitDate(date, 24, 5, 2021);
	PrintDate(date);

	Date today = GetToday();
	PrintDate(today);

}
void TestStudent()
{
	Student student1;
	InputStudent(student1);
	PrintStudent(student1);
}

void AddStudent(Student*& students, int& size)
{
	Student* tmp = new Student[size + 1]; //0 1 2 3

	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = students[i];
	}

	InputStudent(tmp[size]);

	delete[] students;
	students = tmp;

	size++;
}

Student* FindByFio(Student* students, int size, const char* fio)
{
	for (size_t i = 0; i < size; i++)
	{
		if (_stricmp(students[i].fio, fio) == 0) {
			return &students[i];
		}
	}

	return nullptr;
}
