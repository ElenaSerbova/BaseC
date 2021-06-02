#include <iostream>
using namespace std;

#include "Date.h"
#include "Student.h"

void TestDate();
void TestStudent();
void TestStudentsStaticArray();

void AddStudent(Student*& students, int& size);
Student* FindByFio(Student* students, int size, const char* fio);

void SaveToFile(const char* path, Student* students, int size);
void ReadFromFile(const char* path, Student*& students, int& size);

int main()
{
	//TestDate();
	//TestStudent();
	//TestStudentsStaticArray();

	int size = 0;
	Student* students = nullptr;

	ReadFromFile("students.bin", students, size);
	system("pause");

	int choice;

	do {
		system("cls");
		cout << "1. Add new student" << endl;
		cout << "2. Find student" << endl;
		cout << "3. Print all students" << endl;
		cout << "4. Exit" << endl;

		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			AddStudent(students, size);
			break;
		case 2:
		{
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

			break;
		}
		case 3:

			for (size_t i = 0; i < size; i++)
			{
				PrintStudent(students[i]);
			}

			break;
		}

		system("pause");

	} while (choice != 4); 
	

	SaveToFile("students.bin", students, size);	

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

void SaveToFile(const char* path, Student* students, int size)
{
	FILE* file;
	errno_t errorCode = fopen_s(&file, path, "w");

	if (errorCode != 0)
	{
		cout << "Error code: " << errorCode << endl;
		return;
	}

	fwrite(&size, sizeof(int), 1, file);
	fwrite(students, sizeof(Student), size, file);

	fclose(file);
}

void ReadFromFile(const char* path, Student*& students, int& size)
{
	FILE* file;
	errno_t errorCode = fopen_s(&file, path, "r");

	if (errorCode != 0)
	{
		cout << "Error code: " << errorCode << endl;
		return;
	}

	/*while (!feof(file))
	{
		Student student;
		fread(&student, sizeof(Student), 1, file);

		PrintStudent(student);
	}*/

	fread(&size, sizeof(int), 1, file);

	students = new Student[size];
	fread(students, sizeof(Student), size, file);

	for (size_t i = 0; i < size; i++)
	{
		PrintStudent(students[i]);
	}

	fclose(file);
}
