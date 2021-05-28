#include "Student.h"

#include <iostream>
using namespace std;

void InputStudent(Student& student)
{	
	cout << "Enter FIO: ";
	cin.getline(student.fio, 200);

	cout << "Enter date: " << endl;

	cout << "day: ";
	cin >> student.date.day;
	cout << "month: ";
	cin >> student.date.month;
	cout << "year: ";
	cin >> student.date.year;

	cin.ignore();		
}

void PrintStudent(const Student& student)
{
	cout << "FIO: " << student.fio << endl;
	PrintDate(student.date);
}
