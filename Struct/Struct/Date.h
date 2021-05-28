#pragma once

#ifndef DATE_H
#define DATE_H

typedef unsigned int uint;

struct Date
{
	uint day;
	uint month;
	uint year;
};

void InitDate(Date& date, uint day, uint month, uint year);
void PrintDate(Date date);
Date GetToday();

#endif
