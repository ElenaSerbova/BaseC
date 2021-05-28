#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"

struct Student
{
	char fio[200];
	Date date;
};

void InputStudent(Student& student);
void PrintStudent(const Student& student);


#endif
